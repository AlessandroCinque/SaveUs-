#pragma once
#pragma once
#include <iostream>
#include <string> 
#include<glm.hpp>
#include "AudioManager.h"
#include "InputManager.h"
#include "ScreenManager.h"
#include"TextureManager.h"
#include "Sprite.h"
#include "Animation.h"
#include "Text.h"
#include "Audio.h"
#include"SFX.h"
#include "Sprite.h"
#include "GameObject.h"
class Cloud : public GameObject
{
public:
	Cloud();
	virtual ~Cloud();
	void Init(glm::vec2 position, glm::vec2 velocity);

	virtual void Update();
	virtual void Draw();
private:
	static int s_Clouds;
	

	Sprite m_image;
	glm::vec2 m_position;
	glm::vec2 m_velocity;

};
