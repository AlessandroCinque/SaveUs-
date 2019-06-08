#pragma once
#include "GameStates.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<fstream>
#include <string>
#include <algorithm>
#include "AudioManager.h"
#include "InputManager.h"
#include "ScreenManager.h"
#include "TextureManager.h"
#include "Sprite.h"
#include "Animation.h"
#include "Text.h"
#include "Audio.h"
#include "SFX.h"
#include "Pause.h"
#include "AABB.h"
//==========================
#include "Tile.h"
#include "Dwarf.h"
#include "Orc.h"
#include "Font.h"
#include "Dragon.h"
//==========================
#include <vector>
#define TOTAL_ORCS 3
// this define is 5 cause I need an element to be always false otherwise the socre would increase forever!
#define TOTAL_POINTS 5
class PlayState :
	public GameStates
{
public:
	PlayState(GameStates* preaviusState);
	~PlayState();
public:
	virtual void Draw();
	virtual void Update();
	bool FillArray();
private:
	std::fstream Filler;
	bool OrcIsAlive = true;
	bool reach[TOTAL_ORCS] = { true,true,true };
	bool OrcsKilled = false;
	bool DragonKilled = false;
	bool m_endGame = false;
	bool m_Pause = false;
	float dwarf_health;
	Sprite m_image;
	Dwarf dwarf;
	Orc orc1;
	Orc orc2;
	Orc orc3;
	Dragon dragon;
	Text m_text;
	Text m_text1;
	float wait;
	float lastTick;
	std::vector<Tile*> tiles;
	int m_TileSize = 48;
	const int m_arrayY = 16;
	const int m_arrayX = 30;
	int Floor[16][30];
	int m_score;
	std::vector<GameObject*> gameObjects;
	std::vector<Orc*> orcs;
	
	const Uint8* keys = nullptr;

};

