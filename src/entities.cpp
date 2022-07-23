#include "entities.h"
#include "assets.h"
PlayerComponent* Entities::m_Player = nullptr;
std::vector<Entity> Entities::fruits;
static Ref<Scene> m_ActiveScene;
void Entities::InitEntities(const Ref<Scene> activeScene) {
	m_ActiveScene = activeScene;
	Entity pacman = activeScene->CreateEntity("PacMan");
	pacman.GetComponent<TransformComponent>().Scale = glm::vec3(.5f);
	pacman.GetComponent<TransformComponent>().Translation = glm::vec3(9.0f, 0.0f, 1.8f);
	pacman.AddComponent<NativeScriptComponent>().Bind<PlayerComponent>();
	pacman.AddComponent<MeshRendererComponent>(Assets::pacmanModel, Resources::GetDefaultShader(), WHITE);

	//create bunch of fruits keep them in an array then iterate over their Transform to find if player touched them.

	static std::vector<glm::vec3> fruit_positions;

	//Mid top
	fruit_positions.emplace_back(glm::vec3(5.0f, 0.0f, 1.0f));
	fruit_positions.emplace_back(glm::vec3(9.50f, 0.0f, 1.0f));
	fruit_positions.emplace_back(glm::vec3(14.0f, 0.0f, 1.0f));

	//Mid bottom
	fruit_positions.emplace_back(glm::vec3(5.0f, 0.0f, 4.6f));
	fruit_positions.emplace_back(glm::vec3(9.50f, 0.0f, 4.6f));
	fruit_positions.emplace_back(glm::vec3(14.0f, 0.0f, 4.6f));

	fruit_positions.emplace_back(glm::vec3(1.0f, 0.0f, -1.9f));
	fruit_positions.emplace_back(glm::vec3(1.0f, 0.0f, 1.0f));
	fruit_positions.emplace_back(glm::vec3(1.0f, 0.0f, 4.6f));

	fruit_positions.emplace_back(glm::vec3(-2.0f, 0.0f, -1.9f));
	fruit_positions.emplace_back(glm::vec3(-2.0f, 0.0f, 1.0f));
	fruit_positions.emplace_back(glm::vec3(-2.0f, 0.0f, 4.6f));

	fruit_positions.emplace_back(glm::vec3(-4.5f, 0.0f, -1.9f));
	fruit_positions.emplace_back(glm::vec3(-4.5f, 0.0f, 1.0f));
	fruit_positions.emplace_back(glm::vec3(-4.5f, 0.0f, 4.6f));

	fruit_positions.emplace_back(glm::vec3(-7.5f, 0.0f, -1.9f));
	fruit_positions.emplace_back(glm::vec3(-7.5f, 0.0f, 1.0f));
	fruit_positions.emplace_back(glm::vec3(-7.5f, 0.0f, 4.6f));

	fruit_positions.emplace_back(glm::vec3(17.0f, 0.0f, -1.9f));
	fruit_positions.emplace_back(glm::vec3(17.0f, 0.0f, 1.0f));
	fruit_positions.emplace_back(glm::vec3(17.0f, 0.0f, 4.6f));

	fruit_positions.emplace_back(glm::vec3(20.0f, 0.0f, -1.9f));
	fruit_positions.emplace_back(glm::vec3(20.0f, 0.0f, 1.0f));
	fruit_positions.emplace_back(glm::vec3(20.0f, 0.0f, 4.6f));

	fruit_positions.emplace_back(glm::vec3(25.0f, 0.0f, -1.9f));
	fruit_positions.emplace_back(glm::vec3(25.0f, 0.0f, 1.0f));
	fruit_positions.emplace_back(glm::vec3(25.0f, 0.0f, 4.6f));

	fruit_positions.emplace_back(glm::vec3(23.0f, 0.0f, -1.9f));
	fruit_positions.emplace_back(glm::vec3(23.0f, 0.0f, 1.0f));
	fruit_positions.emplace_back(glm::vec3(23.0f, 0.0f, 4.6f));

	for(auto& fruitPos : fruit_positions) {
		Entity fruit = activeScene->CreateEntity("Fruit");
		fruit.GetComponent<TransformComponent>().Translation = fruitPos;
		fruit.AddComponent<MeshRendererComponent>().colors[0] = RED;
		fruit.GetComponent<TransformComponent>().Scale = glm::vec3(0.3f);
		fruits.emplace_back(fruit);
	}
}
void Entities::RemoveFruit(int i) {
	m_Player->m_Score++;
	m_ActiveScene->DestroyEntity(fruits[i]);
	fruits.erase(fruits.begin() + i);
}