#pragma once
#include "GameStates.h"
#include "InputManager.h"
#include "ScreenManager.h"
#include"TextureManager.h"
#include "Sprite.h"
#include "Animation.h"
#include "Text.h"
#include "Audio.h"

class EndState :
	public GameStates
{
public:
	EndState(GameStates* preaviusState);
	~EndState();
public:
	virtual void Update();
	virtual void Draw();
private:
	Sprite m_image;
	KeyState m_keys;
	const Uint8* keys = nullptr;
};

