#include "MenuState.h"
#include"Game.h"



MenuState::MenuState(GameStates* preaviusState) :GameStates(preaviusState)
{
	TheTexture::Instance()->LoadTextureFromFile("Assets/Textures/Menu.png", "Menu");
	TheTexture::Instance()->LoadFontFromFile("Assets/Fonts/Helmswald.ttf", 100, "FONT");
	
	m_image.SetTexture("Menu");
	m_image.SetSpriteDimension(1024, 768);
	m_image.SetTextureDimension(1, 1, 1024, 768);
	//m_text.Init();
	m_text.SetFont("FONT");
	m_text.SetColor(255, 10, 10);
	m_text.SetText("Hellooooo");
	m_text.SetSize(400, 200);

}


MenuState::~MenuState()
{
	TheTexture::Instance()->UnloadFromMemory(TextureManager::TEXTURE_DATA, TextureManager::CUSTOM_DATA, "Menu");
	TheTexture::Instance()->ShutDown();
}

void MenuState::Update()
{
	TheScreen::Instance()->Update();

	//update input handling by listening for input events
	TheInput::Instance()->Update();

	//read keyboard state
	keys = TheInput::Instance()->GetKeyStates();
	KeyState key;
	key = TheInput::Instance()->GetKeyStates();

	if (keys[SDL_SCANCODE_1]) 
	{
		m_isAlive = m_isActive = false;
		TheGame::Instance()->ChangeState(new PlayState(this));
	
	}
	if (keys[SDL_SCANCODE_ESCAPE])
	{
		m_isAlive = m_isActive = false;

	}
}

void MenuState::Draw()
{
	m_image.Draw();
	m_text.Draw(10 * tilesize ,10 * tilesize);
}
