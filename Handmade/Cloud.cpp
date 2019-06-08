#include "Cloud.h"



int Cloud::s_Clouds = 0;

Cloud::Cloud()
{
}

void Cloud::Init(glm::vec2 position, glm::vec2 velocity)
{
	m_position = position;
	m_velocity = velocity;
	if (s_Clouds == 0)
	{
		TheTexture::Instance()->LoadTextureFromFile("Assets/Textures/Clouds.png", "CLOUD");

	}
	s_Clouds++;
	std::string tag = "cloud";
	SetTag(tag);
	m_image.SetTexture("CLOUD");
	m_image.SetTextureCell(rand() % 3, 0);
	m_image.SetSpriteDimension(320, 100);
	m_image.SetTextureDimension(3, 1, 512, 160);

}

void Cloud::Update()
{
	m_position += m_velocity;
}

void Cloud::Draw()
{
	m_image.Draw(m_position.x, m_position.y);
}

Cloud::~Cloud()
{
	s_Clouds--;
	if (s_Clouds == 0)
	{
		TheTexture::Instance()->UnloadFromMemory(TextureManager::TEXTURE_DATA, TextureManager::CUSTOM_DATA, "CLOUD");
	}
}
