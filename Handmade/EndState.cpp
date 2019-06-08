#include "EndState.h"
#include"Game.h"


EndState::EndState(GameStates* preaviusState) :GameStates(preaviusState)
{
	TheTexture::Instance()->LoadTextureFromFile("Assets/Textures/End.png", "End");


	std::string tag = "End";

	m_image.SetTexture("End");
	m_image.SetSpriteDimension(1024, 768);
	m_image.SetTextureDimension(1, 1, 1024, 768);
}


EndState::~EndState()
{
	TheTexture::Instance()->UnloadFromMemory(TextureManager::TEXTURE_DATA, TextureManager::CUSTOM_DATA, "End");
	TheTexture::Instance()->ShutDown();
	//close down game screen 
	//TheScreen::Instance()->ShutDown();
}

void EndState::Update()
{
	TheScreen::Instance()->Update();

	//update input handling by listening for input events
	TheInput::Instance()->Update();

	//read keyboard state
	keys = TheInput::Instance()->GetKeyStates();
	KeyState key;
	key = TheInput::Instance()->GetKeyStates();
	if (keys[SDL_SCANCODE_3])
	{
		m_isAlive = m_isActive = false;
		TheGame::Instance()->ChangeState(new MenuState(this));
	}
	if (keys[SDL_SCANCODE_ESCAPE])
	{
		m_isAlive = m_isActive = false;
	}
}

void EndState::Draw()
{
	m_image.Draw();
}
