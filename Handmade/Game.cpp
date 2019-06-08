#include "Game.h"



Game::Game()
{
	m_state = nullptr;
}



bool Game::Initialise(const std::string& filename)
{
	if (!LoadGameData(filename))
	{
		std::cout << "something went wrong with the .ini" << std::endl;
		return false;
	}
	// HERE YOU ARE ENABLING THE TEXT , FONT , OR WHATEVER YOU WANT TO CALL IT!!!!
	if (!TheTexture::Instance()->Initialize())
	{
		return false;
	}

	int m_screenWidth = std::stoi(m_gameData["Width"]);
	int m_screenHeight = std::stoi(m_gameData["Height"]);
	std::string gameName = m_gameData["Name"];
	bool isFullScreen = std::stoi(m_gameData["FullScreen"]);
	if (!TheScreen::Instance()->Initialize(gameName.c_str(), m_screenWidth, m_screenHeight))
	{
		std::cout << "Cannot read the file properly" << std::endl;
		return false;
	}

	return true;
}

bool Game::Run()
{
	while (!m_endGame)
	{
		//Update and draw only what's active
		while (gameStates.front()->isAlive())
		{		
			TheScreen::Instance()->Update();

			//update input handling by listening for input events
			TheInput::Instance()->Update();

			//read keyboard state
			keys = TheInput::Instance()->GetKeyStates();
			KeyState key;
			key = TheInput::Instance()->GetKeyStates();
			
			gameStates.front()->Update();
			

			
			
			gameStates.front()->Draw();
			TheScreen::Instance()->Draw();
		}
		if (!gameStates.front()->isAlive()) 
		{
			//If is not Alive anymore,remove it
			RemoveState(gameStates.front());
		
		}
		
		//If there are no more states,shut everything down.
		m_endGame = gameStates.empty();
		
	}

	return true;
}

bool Game::LoadGameData(const std::string & filename)
{
	std::string LineString;
	std::vector<std::string> subStrings;
	std::fstream dataFile(filename, std::ios_base::in);
	if (!dataFile)
	{
		return false;
	}

	while (!dataFile.eof())
	{
		std::getline(dataFile, LineString);
		ParseString(LineString, subStrings, '=');
		m_gameData[subStrings[0]] = subStrings[1];
		subStrings.clear();
	}
	return true;
}

void Game::AddState(GameStates* state)
{
	gameStates.push_front(state);
}

void Game::ChangeState(GameStates* state)
{
	gameStates.push_back(state);
}

void Game::RemoveState(GameStates* state)
{
	delete gameStates.front();
	gameStates.pop_front();
}
