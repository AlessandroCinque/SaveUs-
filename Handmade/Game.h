#pragma once
#include <SDL.h> 
#include"Singleton.h"

#include <iostream>
#include<fstream>
#include <string>
#include "AudioManager.h"
#include "InputManager.h"
#include "ScreenManager.h"
#include"TextureManager.h"
#include "Sprite.h"
#include "Animation.h"
#include "Text.h"
#include "Audio.h"
#include"SFX.h"
#include <vector>
#include <deque>

#include"GameStates.h"
#include "MenuState.h"
#include "PlayState.h"
#include "EndState.h"
#include"Tools.h"

class Game
{
public:
	friend class Singleton<Game>;

	GameStates* m_state;
public:
	bool Initialise(const std::string& filename);
	bool Run();
	void AddState(GameStates* state);
	void ChangeState(GameStates* state);

private:
	bool LoadGameData(const std::string& filename);
	void RemoveState(GameStates* state);

private:
	Game();
	Game(const Game&);
	Game& operator=(const Game&);

	
	std::map<std::string, std::string> m_gameData;
	std::deque<GameStates*> gameStates;
	std::vector<GameObject*> gameObjects;
	const Uint8* keys = nullptr;

	bool m_endGame = false;

};

typedef Singleton<Game> TheGame;