#pragma once
#include <iostream>
#include <string> 
#include<glm.hpp>
#include<ctime>
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

class Font :
	public GameObject
{
public:
	Font();
	~Font();
	void Init();
	virtual void Draw();
private:
	Text m_text;
};

