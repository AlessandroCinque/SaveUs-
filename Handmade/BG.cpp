#include "BG.h"



BG::BG()
{
	
}


BG::~BG()
{
	//you have to do it specifically otherwise you gonna unload other stuff
	TheTexture::Instance()->UnloadFromMemory(TextureManager::TEXTURE_DATA, TextureManager::CUSTOM_DATA, "BG");
}

void BG::Init()
{
	TheTexture::Instance()->LoadTextureFromFile("Assets/Textures/Background.jpg", "BG");
	


	std::string tag = "backGround";
	SetTag(tag);
	background.SetTexture("BG");
	background.SetSpriteDimension(1024, 768);
	background.SetTextureDimension(1, 1, 1024, 768);

}

void BG::Update()
{
}

void BG::Draw()
{
	background.Draw(0, 0, 0, Sprite::HORIZONTAL);
}
