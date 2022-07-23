#pragma once
#include "player.h"

class Entities{
public:
	static void InitEntities(Ref<Scene> activeScene);
	static void RemoveFruit(int i);
	static PlayerComponent* m_Player;
	static std::vector<Entity> fruits;
};