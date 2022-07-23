#pragma once
#include <FlatEngine.h>

using namespace FlatEngine;

class GameUI {
public:
    enum class MenuState{
		MainMenu,
		GameMenu,
        DeathMenu
	};
    static void InitUI();
    static void Update();
	static MenuState m_MenuState;
private:
    static void DrawMainMenu();
    static void DrawGameMenu();
    static void DrawDeathMenu();
};

