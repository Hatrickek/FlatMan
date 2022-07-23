#pragma once
#include <FlatEngine.h>
using namespace FlatEngine;

class Assets{
public:
	static void LoadAssets();
	static Ref<Model> pacmanModel;
	static Ref<Model> pacmanModel_Closed;
	static ImFont* font_64;
	static ImFont* font_24;
	static Ref<Texture> titleLogo;
};