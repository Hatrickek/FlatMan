#include "gameUI.h"
#include "assets.h"
#include "entities.h"
GameUI::MenuState GameUI::m_MenuState = MenuState::MainMenu;

static float buttonWidth = 500.0f;
static float buttonHeight = 70.0f; 

static float windowWidth;
static float windowHeight;

void GameUI::InitUI(){

}
void GameUI::Update(){
	switch(m_MenuState) {
	case MenuState::MainMenu:
		DrawMainMenu();
		break;
	case MenuState::GameMenu:
		DrawGameMenu();
		break;
	case MenuState::DeathMenu:
		DrawDeathMenu();
	break;
	default:
		DrawMainMenu();	
		break;
	}
	if(Input::GetKeyDown(Key::Escape)){
		m_MenuState = MenuState::MainMenu;
	}
	windowWidth = Window::GetWindowSize().x;
	windowHeight = Window::GetWindowSize().y;
}
void GameUI::DrawGameMenu(){
	static ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings;
	const ImGuiViewport* viewport = ImGui::GetMainViewport();
	ImGui::SetNextWindowPos(viewport->WorkPos);
	ImGui::SetNextWindowSize(viewport->WorkSize);
	ImGui::PushStyleColor(ImGuiCol_WindowBg, 0.0f);

	static int testLevel = 1;
	ImGui::Begin("GameUI", NULL, flags);

	ImGui::Text("Score: %d", Entities::m_Player->m_Score);
	ImGui::Text("Level: %d", testLevel);

	ImGui::End();
	ImGui::PopStyleColor();
}
void GameUI::DrawMainMenu(){
	static ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings;
	const ImGuiViewport* viewport = ImGui::GetMainViewport();
	ImGui::SetNextWindowPos(viewport->WorkPos);
	ImGui::SetNextWindowSize(viewport->WorkSize);
	ImGui::PushStyleColor(ImGuiCol_WindowBg, 0.7f);

	ImGui::Begin("MainMenu", NULL, flags);

	
	ImGui::SetCursorPosY(100.0f);
	ImGui::SetCursorPosX((windowWidth - Assets::titleLogo->m_Width) * 0.5f);
	ImGui::Image(reinterpret_cast<void*>(Assets::titleLogo->m_ID), ImVec2(Assets::titleLogo->m_Width,Assets::titleLogo->m_Height), ImVec2{ 0, 1 }, ImVec2{ 1, 0 });

	ImGui::SetCursorPosY(325.0f);

	ImGui::SetCursorPosX((windowWidth - buttonWidth) * 0.5f);
	if(ImGui::Button("START", ImVec2(buttonWidth, buttonHeight))){
		m_MenuState = MenuState::GameMenu;
	}
	ImGui::SetCursorPosX((windowWidth - buttonWidth) * 0.5f);
	ImGui::Button("SETTINGS", ImVec2(buttonWidth, buttonHeight));
	
	ImGui::SetCursorPosX((windowWidth - buttonWidth) * 0.5f);
	if(ImGui::Button("QUIT", ImVec2(buttonWidth, buttonHeight))){
		Window::CloseWindow(Window::GetOpenGLWindow());
	}

	ImGui::PushFont(Assets::font_24);
	ImGui::SetCursorPosX(windowWidth - ImGui::CalcTextSize("Made with Flat Engine.").x - 30);
	ImGui::SetCursorPosY(windowHeight - 40);
	ImGui::Text("Made with Flat Engine.");
	ImGui::PopFont();

	ImGui::End();
	ImGui::PopStyleColor();
}
void GameUI::DrawDeathMenu(){
	static ImGuiWindowFlags flags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoSavedSettings;
	const ImGuiViewport* viewport = ImGui::GetMainViewport();
	ImGui::SetNextWindowPos(viewport->WorkPos);
	ImGui::SetNextWindowSize(viewport->WorkSize);
	ImGui::PushStyleColor(ImGuiCol_WindowBg, 0.7f);

	ImGui::Begin("GameOverUI", NULL, flags);

	ImGui::SetCursorPosX((windowWidth - ImGui::CalcTextSize("GAME OVER!").x) * 0.5f);
	ImGui::SetCursorPosY(150);
	ImGui::Text("GAME OVER!");

	ImGui::SetCursorPosX((windowWidth - ImGui::CalcTextSize("GAME OVER!").x) * 0.5f);
	ImGui::Text("SCORE: %d", Entities::m_Player->m_Score);
	ImGui::PushItemWidth(500.0f);
	char buff0[256] = {};
	ImGui::SetCursorPosX((windowWidth - buttonWidth) * 0.5f);
 	if(ImGui::InputText("NAME:", buff0, FE_ARRAYSIZE(buff0))){
		Entities::m_Player->m_Name = std::string(buff0);
	}
	ImGui::PopItemWidth();
	ImGui::SetCursorPosX((windowWidth - buttonWidth) * 0.5f);
	if(ImGui::Button("RETRY", ImVec2(buttonWidth, buttonHeight))){
		m_MenuState = MenuState::GameMenu;
	}
	ImGui::SetCursorPosX((windowWidth - buttonWidth) * 0.5f);
	if(ImGui::Button("EXIT", ImVec2(buttonWidth, buttonHeight))){
		Window::CloseWindow(Window::GetOpenGLWindow());
	}
	ImGui::End();
	ImGui::PopStyleColor();	
}