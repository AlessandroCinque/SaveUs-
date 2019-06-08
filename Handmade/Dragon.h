#pragma once
#include <iostream>
#include <string> 
#include<glm.hpp>
#include<ctime>
#include "InputManager.h"
#include"TextureManager.h"

#include "Animation.h"
#include "Text.h"
#include "Audio.h"
#include"SFX.h"
#include "Sprite.h"
#include "GameObject.h"
#include "AABB.h"
class Dragon:public GameObject
{
public:
	Dragon();
	~Dragon();
	void Init(glm::vec2 position);
	virtual void Update(glm::vec2 target);
	virtual void Draw();
	bool GetInReach() { return m_arrived; }
	float GetDistance() { return total_distance; }
private:
	Sprite m_image;
	AABB collision;

	float total_distance;
	glm::vec2 distance;
	glm::vec2 m_position;
	glm::vec2 m_target;
	// this bool is for avoid loopings in the if statements
	bool repeated = true;
	bool m_arrived = false;
	float m_speed = 5.0f;
	float delay;
};

