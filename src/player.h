#pragma once
#include <string>
#include <FlatEngine.h>
using namespace FlatEngine;

class PlayerComponent : public ScriptableEntity {
public:
	void OnCreate();
	void OnUpdate(float deltaTime);
	void OnDestroy();
	std::string m_Name;
	int m_Score;
	float m_Speed;

private:
	enum class Direction{
		FORWARD,
		BACKWARD,
		LEFT,
		RIGHT
	};
	void UpdateInput(float deltaTime);
	void UpdateCollision() const;
	Direction m_CurrentDirection;
	TransformComponent* m_Transform;
	Ref<Model> m_CurrentModel;
};