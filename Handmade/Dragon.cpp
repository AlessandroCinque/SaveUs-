#include "Dragon.h"



Dragon::Dragon()
{
}


Dragon::~Dragon()
{
}
void Dragon::Init(glm::vec2 position)
{
	m_health = 15.0f;
	attacking = false;
	m_damage = 2.5f;
	m_arrived = false;
	TheTexture::Instance()->LoadTextureFromFile("Assets/Sprites/Dragon.png", "DRAGON");

	m_position = position;
	m_target = m_position;
	std::string tag = "dragon";
	SetTag(tag);
	m_image.SetTexture("DRAGON");
	m_image.SetSpriteDimension(tile_size, tile_size);
	m_image.SetTextureDimension(1, 1, 1468, 1208);

	//============== Collision ==========
	collision.SetDimension(tile_size, tile_size);

}
void Dragon::Draw()
{

	m_image.Draw((int)m_position.x, (int)m_position.y);

}

void Dragon::Update(glm::vec2 target)
{
	float time = SDL_GetTicks() / 10000.0f;
	delay -= time;
	distance.x = target.x - m_position.x;
	distance.y = target.y - m_position.y;
	total_distance = sqrt(distance.x * distance.x + distance.y * distance.y);

	if (total_distance > tile_size)
	{
		m_arrived = false;
		m_position.x += (0.5 * distance.x * m_speed / total_distance);
		m_position.y += (0.5 * distance.y * m_speed / total_distance);
	}
	else
	{
		m_arrived = true;
	}

	if (!m_arrived)
	{
		attacking = false;
		delay = 100.0f;
	}
	else if (attacking)
	{
		attacking = false;
		delay = 100.0f;
	}
	else if (m_arrived && delay <= 0)
	{
		attacking = true;
	}
	collision.SetPosition(m_position.x, m_position.y);
	m_health = GetHealth();

	m_isAlive = Alive();

	std::cout << "DRAGON:" << m_health << std::endl;
}