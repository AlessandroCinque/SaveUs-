#pragma once
#include "GameStates.h"
#include "InputManager.h"
#include "ScreenManager.h"
#include"TextureManager.h"
#include "Sprite.h"
#include "Animation.h"
#include "Text.h"
#include "Audio.h"
#include "Font.h"


class MenuState :
	public GameStates
{
public:
	MenuState(GameStates* preaviusState);
	virtual ~MenuState();
public:
	virtual void Update();
	virtual void Draw();
private:
	Sprite m_image;
	Font m_font;
	Text m_text;
	KeyState m_keys;

	int tilesize = 50;
	const Uint8* keys = nullptr;
};

