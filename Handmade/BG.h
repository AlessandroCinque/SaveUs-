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
#include "GameObject.h"
class BG : public GameObject
{
public:
	BG();
	virtual ~BG();

	void Init();
	virtual void Update();
	virtual void Draw();
private:
	Sprite background;
	Audio music;
};

