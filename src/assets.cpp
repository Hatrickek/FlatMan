#include "assets.h"

Ref<Model> Assets::pacmanModel;
Ref<Model> Assets::pacmanModel_Closed;
Ref<Texture> Assets::titleLogo;
ImFont* Assets::font_24;
ImFont* Assets::font_64;
void Assets::LoadAssets(){
	pacmanModel = CreateRef<Model>(FileSystem::getPath("resources/objects/Pacman.obj"));
	pacmanModel_Closed = CreateRef<Model>(FileSystem::getPath("resources/objects/Pacman_Closed.obj"));
	ImGuiIO& io = ImGui::GetIO();
	io.Fonts->Clear();
	font_64 = io.Fonts->AddFontFromFileTTF(FileSystem::getPath("resources/fonts/Hyperjump-Bold.ttf").c_str(), 64.0f);
	font_24 = io.Fonts->AddFontFromFileTTF(FileSystem::getPath("resources/fonts/Hyperjump-Bold.ttf").c_str(), 24.0f);
	io.Fonts->Build();
    titleLogo = CreateRef<Texture>(FileSystem::getPath("resources/sprites/titleLogo.png").c_str());

}