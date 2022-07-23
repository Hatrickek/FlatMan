#include "gamelayer.h"
#include "save.h"
#include "gameUI.h"
#include "player.h"
#include "assets.h"
#include "entities.h"

GameLayer::GameLayer() : Layer("Game Layer") {
}

void GameLayer::OnAttach() {
	using namespace FlatEngine;
	Renderer::SetFrameBufferSizeType(Renderer::FrameBufferSizeType::Fullscreen);
	Renderer::InitRenderer();
	Renderer::CreateGBuffer();
	Renderer::CreateSSAOBuffers();
	
	Assets::LoadAssets();

	Input::SetCursorState(Input::CursorState::NORMAL, Window::GetOpenGLWindow());
	Ref<Camera> m_PlayerCamera = CreateRef<Camera>(glm::vec3(0.0f, 0.0f, 5.0f));
	m_PlayerCamera->cameraMod = CameraMod::STATIC;
	m_PlayerCamera->SetPosition(glm::vec3(8.5, 23, 21));
	m_PlayerCamera->SetYaw(-90.0f);
	m_PlayerCamera->SetPitch(-45.0f);
	Renderer::AddCamera(m_PlayerCamera);
	Resources::InitResources();
	Lighting::ambientLight = 0.3f;
	
	GameUI::InitUI();

	FlatMan::Save::Init();
	FlatMan::Save::Load();

	Ref<Scene> newScene = CreateRef<Scene>();
	//TODO: A better scene loading API
	SceneSerializer serializer(newScene);
	if(serializer.Deserialize("resources/scenes/level1.scene")) {
		m_ActiveScene = newScene;
	}
	Entities::InitEntities(m_ActiveScene);

}

void GameLayer::OnUpdate(float deltaTime) {
	using namespace FlatEngine;
	Renderer::GetCamera(0)->OnUpdate();
	Renderer::ClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	Renderer::Clear();

	Renderer::GetGbuffer()->Begin();
	glm::mat4 projection = Renderer::GetCamera(0)->GetProjectionMatrix();
	glm::mat4 view = Renderer::GetCamera(0)->GetViewMatrix();
	glm::mat4 model = glm::mat4(1.0f);
	Resources::GetSSAOGeometryShader()->use();
	Resources::GetSSAOGeometryShader()->setMat4("projection", projection);
	Resources::GetSSAOGeometryShader()->setMat4("view", view);

	m_ActiveScene->OnUpdate(Timestep::GetDeltaTime());

	Renderer::GetGbuffer()->End();

	Renderer::GetSSAOBuffer()->BeginSSAOTexture(projection, Renderer::GetGbuffer()->gPosition, Renderer::GetGbuffer()->gNormal);
	Draw::RenderQuad();
	Renderer::GetSSAOBuffer()->EndSSAOTexture();

	Renderer::GetSSAOBuffer()->BeginSSAOBlurTexture();
	Draw::RenderQuad();
	Renderer::GetSSAOBuffer()->EndSSAOBlurTexture();

	Lighting::UpdateLighting();

	Draw::RenderQuad();
}

void GameLayer::OnImGuiRender() {
	if(Input::GetKeyDown(Key::F))
		GameUI::m_MenuState = GameUI::MenuState::DeathMenu;
	GameUI::Update();
	//ImGui::ShowDemoWindow();
}


void GameLayer::OnDetach() {
	glfwTerminate();
}