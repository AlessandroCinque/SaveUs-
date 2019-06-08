#include "PlayState.h"
#include"Game.h"



PlayState::PlayState(GameStates* preaviusState) :GameStates(preaviusState)
{
	TheScreen::Instance()->SetClearColor(100, 149, 237);
	
	if(!FillArray())
	{
		std::cout << "it cannot find Level1.txt!!!" << std::endl;
	}
	TheTexture::Instance()->Initialize();
	//initialize audio
	//TheAudio::Instance()->Initialize();
	m_score = 0;
	orcs.push_back(&orc1);
	orcs.push_back(&orc2);
	orcs.push_back(&orc3);
	dwarf.Init(glm::vec2(1* m_TileSize, 1* m_TileSize));
	orcs[0]->Init(glm::vec2(8 * m_TileSize, 1 * m_TileSize));
	orcs[1]->Init(glm::vec2(29 * m_TileSize, 14 * m_TileSize));
	orcs[2]->Init(glm::vec2(2 * m_TileSize, 15 * m_TileSize));
	dragon.Init(glm::vec2(2 * m_TileSize, 19 * m_TileSize));
	TheTexture::Instance()->LoadFontFromFile("Assets/Fonts/Helmswald.ttf", 50, "FONT");
	m_text.SetFont("FONT");
	m_text.SetColor(255, 10, 10);
	m_text.SetSize(150, 100);
	
	m_text1.SetFont("FONT");
	m_text1.SetColor(255, 10, 10);
	m_text1.SetSize(150, 100); 
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tile/rpgTile040.png", "Grass");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tile/rpgTile061.png", "Wall");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tile/rpgTile024.png", "Dirt");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tile/rpgTile174.png", "Door");
	for (int y = 0; y < 16; y++)	{
		for (int x = 0; x < 30; x++)
		{
			if (Floor[y][x] == 3)
			{
				tiles.push_back(new Tile("Wall", glm::vec3(x * m_TileSize, y * m_TileSize, 0)));
			}
			else if (Floor[y][x] == 1)
			{
				tiles.push_back(new Tile("Grass", glm::vec3(x * m_TileSize, y * m_TileSize, 0)));
			}
			else if (Floor[y][x] == 2)
			{
				tiles.push_back(new Tile("Door", glm::vec3(x * m_TileSize, y * m_TileSize, 0)));
			}
		}
	}

	//=========== PAUSE MENU ====================
	TheTexture::Instance()->LoadTextureFromFile("Assets/Textures/Pause.png", "Pause");
	m_image.SetTexture("Pause");
	m_image.SetSpriteDimension(1024, 768);
	m_image.SetTextureDimension(1, 1, 1024, 768);
	lastTick = SDL_GetTicks();
}


PlayState::~PlayState()
{
	
	TheTexture::Instance()->UnloadFromMemory(TextureManager::TEXTURE_DATA, TextureManager::CUSTOM_DATA, "Grass");
	TheTexture::Instance()->UnloadFromMemory(TextureManager::TEXTURE_DATA, TextureManager::CUSTOM_DATA, "Wall");
	TheTexture::Instance()->UnloadFromMemory(TextureManager::TEXTURE_DATA, TextureManager::CUSTOM_DATA, "Dirt");
	TheTexture::Instance()->UnloadFromMemory(TextureManager::TEXTURE_DATA, TextureManager::CUSTOM_DATA, "Pause");


	TheTexture::Instance()->UnloadFromMemory(TextureManager::FONT_DATA, TextureManager::ALL_DATA);
	TheAudio::Instance()->UnloadFromMemory(AudioManager::MUSIC_AUDIO, AudioManager::ALL_AUDIO);
	TheAudio::Instance()->UnloadFromMemory(AudioManager::SFX_AUDIO, AudioManager::ALL_AUDIO);
	//close down audio 
	TheAudio::Instance()->ShutDown();

	/*TheTexture::Instance()->ShutDown();*/


	gameObjects.clear();
	tiles.clear();
}

void PlayState::Draw()
{
	
	for (auto it = tiles.begin(); it != tiles.end(); it++)
	{
		(*it)->Draw();
	}
	m_text.Draw(1 * m_TileSize, 14 * m_TileSize);
	m_text1.Draw(8 * m_TileSize, 14 * m_TileSize);
	dwarf.Draw();
	if (dragon.Alive()) { dragon.Draw(); }
	
	for (auto it = orcs.begin(); it != orcs.end(); it++)
		{
			(*it)->Draw();

		}
	if (m_Pause) 
	{
		m_image.Draw();
	}
	
	TheScreen::Instance()->Draw();

}

void PlayState::Update()
{
	TheScreen::Instance()->Update();

	//update input handling by listening for input events
	TheInput::Instance()->Update();

	//read keyboard state
	keys = TheInput::Instance()->GetKeyStates();
	KeyState key;
	key = TheInput::Instance()->GetKeyStates();

	if (!dwarf.Alive())
	{
		m_isAlive = m_isActive = false;
		TheGame::Instance()->ChangeState(new EndState(this));

	}
	
	if (keys[SDL_SCANCODE_RETURN] && wait <= 0 && !m_Pause)
	{
		//m_isAlive = m_isActive = false;
		//m_isActive = false;
		m_Pause = true;
		//TheGame::Instance()->AddState(new Pause(this));
		wait = 5;
	}
	
	else if (keys[SDL_SCANCODE_RETURN] && wait <= 0 && m_Pause)
	{
		wait = 5;
		m_Pause = false;

	}
	wait -= lastTick;
	// I actually don't know why,but it works only after few clicks.I also tested it with break points.
	if (TheInput::Instance()->IsXClicked())
	{
		m_isAlive = m_isActive = false;
		m_endGame = true;
	}

	if (keys[SDL_SCANCODE_ESCAPE])
	{
		m_isAlive = m_isActive = false;

	}
	if (!m_Pause) 
	{

		if (dwarf.Alive()) 
		{
			reach[4] = dragon.GetInReach();
			dwarf.Update(Floor, &reach[4]);
			for (int i = 0; i < 3; i++)
			{
				reach[i] = orcs[i]->GetInReach();
				//without referencing the reach you got to kill the orcs in a certain order, and we do not like it
				dwarf.Update(Floor, &reach[i]);

			}
			
		}
		
		glm::vec2 DwarfPos = dwarf.GetPosition();
		for (auto it = orcs.begin(); it != orcs.end(); it++)
		{
			(*it)->Update(DwarfPos);
		}
		
		for (int i = 0; i < 3; i++)
		{
			if (!orcs[0]->Alive()&& !orcs[1]->Alive()&& !orcs[2]->Alive()&& !OrcsKilled)
			{
				m_score = 333.f;
				dwarf.SetScore(m_score);
				OrcsKilled = true;
			}

		}

		if (dwarf.GetScore() >= 200 && dragon.Alive())
		{
			dragon.Update(DwarfPos);
			
		}
		if (!dragon.Alive() && !DragonKilled)
		{
			m_score = 1111.f;
			dwarf.SetScore(m_score);
			DragonKilled = true;

		}
	//================ Attacking checks!! ===================
		if (dwarf.AmIAttacking()) 
		{
			if (dragon.GetInReach()) 
			{
				dragon.ApplyDamage(dwarf.GetDamage());
			}
			//If you use the itinerator in this case you would kill all the orcs instead of kill them one by one
			for (int i = 0; i < 3; i++) 
			{
				if (orcs[i]->GetInReach()) 
				{
					orcs[i]->ApplyDamage(dwarf.GetDamage());
				}
			}
		}
		for (auto it = orcs.begin(); it != orcs.end(); it++)
		{
			if ((*it)->AmIAttacking())
			{
				dwarf.ApplyDamage((*it)->GetDamage());

			}
		}
		if (dragon.AmIAttacking()) 
		{
			dwarf.ApplyDamage(dragon.GetDamage());
		}
		
		// it says "remove if" but indeed is just moving it,is the "orcs.erase(" that actually removes them.
		orcs.erase(std::remove_if(orcs.begin(), orcs.end(), [](Orc* a) { return !a->Alive(); }), orcs.end());
		if (!dragon.Alive()) 
		{
			m_isAlive = m_isActive = false;
			TheGame::Instance()->ChangeState(new EndState(this));
		}
	
	}

	dwarf_health = dwarf.GetHealth();
	m_text.SetText("Health= " + std::to_string(dwarf_health));
	m_text1.SetText("Score= " + std::to_string(dwarf.GetScore()));

}

bool PlayState::FillArray()
{
	std::string LineString;
	std::vector<std::string> subStrings;
	Filler.open("Data/Level1.ini", std::ios_base::in | std::ios_base::out);
	if (!Filler)
	{
		std::cout << "it cannot find Level1.txt!!!" << std::endl;
		return false;
	}
	ParseString(LineString, subStrings, ',');
	int y = 16;
	int x = 30;
	
	for (y = 0; y < 16; y++) 
	{
		for (x = 0; x < 30; x++)
		{
			
			Filler >> Floor[y][x];
		}
	}
	return true;
}


