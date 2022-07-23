#pragma once
#include <FlatEngine.h>

using namespace FlatEngine;

class GameLayer : public FlatEngine::Layer {
public:
		GameLayer();
		virtual ~GameLayer() = default;
		void OnAttach() override;
		void OnDetach() override;

		void OnUpdate(float deltaTime) override;
		void OnImGuiRender() override;
		
	private:
		Ref<Scene> m_ActiveScene;
};