#pragma once
#include "player.h"
namespace FlatMan {
	class Save {
	public:
		static void Init();
		static void Load();
		static void LoadPlayers();
		static void SavePlayer(PlayerComponent& player);
		static void ResetPlayerSave();
	};
}

