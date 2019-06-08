#include "Pause.h"
#include"Game.h"


Pause::Pause(GameStates* preaviusState) : GameStates(preaviusState)
{
	TheTexture::Instance()->LoadTextureFromFile("Assets/Textures/Pause.png", "Pause");
	

	m_image.SetTexture("Pause");
	m_image.SetSpriteDimension(1024, 768);
	m_image.SetTextureDimension(1, 1, 1024, 768);
}


Pause::~Pause()
{
	TheTexture::Instance()->UnloadFromMemory(TextureManager::TEXTURE_DATA, TextureManager::CUSTOM_DATA, "Pause");
	TheTexture::Instance()->ShutDown();
}

void Pause::Update()
{
	TheScreen::Instance()->Update();

	//update input handling by listening for input events
	TheInput::Instance()->Update();

	//read keyboard state
	keys = TheInput::Instance()->GetKeyStates();
	KeyState key;
	key = TheInput::Instance()->GetKeyStates();

	if (keys[SDL_SCANCODE_ESCAPE])
	{
		m_isAlive = m_isActive = false;

	}
	if (keys[SDL_SCANCODE_Q])
	{
		TheTexture::Instance()->UnloadFromMemory(TextureManager::TEXTURE_DATA, TextureManager::CUSTOM_DATA, "Pause");
		m_isAlive = m_isActive = false;
		m_preaviusState->SetActive(true);

	}
}

void Pause::Draw()
{
	m_image.Draw();
}
