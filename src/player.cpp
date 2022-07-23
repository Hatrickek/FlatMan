#include "player.h"
#include "assets.h"
#include "save.h"
#include "entities.h"
#include "gameUI.h"

void PlayerComponent::OnCreate() {
	m_Transform = &this->GetComponent<TransformComponent>();
	m_Speed = 8.0f;
	m_Name = "totos";
	Entities::m_Player = this;
}
void PlayerComponent::OnUpdate(float deltaTime) {
	if(GameUI::m_MenuState == GameUI::MenuState::GameMenu) {
		UpdateInput(deltaTime);
		UpdateCollision();
	}
}
void PlayerComponent::UpdateCollision() const {
	const float axisThreshold = 0.8f;
	for(int i = 0; i < Entities::fruits.size(); i++) {
		if(std::abs(Entities::fruits[i].GetComponent<TransformComponent>().Translation.x - m_Transform->Translation.x) < axisThreshold) {
			if(std::abs(Entities::fruits[i].GetComponent<TransformComponent>().Translation.y - m_Transform->Translation.y) < axisThreshold) {
				if(std::abs(Entities::fruits[i].GetComponent<TransformComponent>().Translation.z - m_Transform->Translation.z) < axisThreshold) {
					Entities::RemoveFruit(i);
				}
			}
		}
	}
}
void PlayerComponent::UpdateInput(float deltaTime) {
	if(Input::GetKey(Key::D)) {
		m_CurrentDirection = Direction::RIGHT;
	}
	if(Input::GetKey(Key::A)) {
		m_CurrentDirection = Direction::LEFT;
	}
	if(Input::GetKey(Key::W)) {
		m_CurrentDirection = Direction::FORWARD;
	}
	if(Input::GetKey(Key::S)) {
		m_CurrentDirection = Direction::BACKWARD;
	}
	switch(m_CurrentDirection) {
	case Direction::FORWARD:
		m_Transform->Rotation.y = 160.0f;
		m_Transform->Translation.z -= this->m_Speed * deltaTime;
		break;
	case Direction::BACKWARD:
		m_Transform->Rotation.y = 0.0f;
		m_Transform->Translation.z += this->m_Speed * deltaTime;
		break;
	case Direction::RIGHT:
		m_Transform->Rotation.y = -80.0f;
		m_Transform->Translation.x += this->m_Speed * deltaTime;
		break;
	case Direction::LEFT:
		m_Transform->Rotation.y = 80.0f;
		m_Transform->Translation.x -= this->m_Speed * deltaTime;
		break;
	}
}

void PlayerComponent::OnDestroy() {
}
