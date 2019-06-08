#include "Dwarf.h"



Dwarf::Dwarf()
{
}


Dwarf::~Dwarf()
{
	TheTexture::Instance()->UnloadFromMemory(TextureManager::TEXTURE_DATA, TextureManager::CUSTOM_DATA, "DWARF");
}

void Dwarf::Init(glm::vec2 position)
{
	TheTexture::Instance()->LoadTextureFromFile("Assets/Sprites/Dwarf_Attack.png", "DWARF");
	m_health = 51.0f;

	m_damage = 1.0;
	m_position = position;
	m_target = m_position;
	std::string tag = "dwarf";
	SetTag(tag);
	m_image.SetTexture("DWARF");
	m_image.SetTextureCell(0, 0);
	m_image.SetSpriteDimension(tile_size, tile_size);
	m_image.SetTextureDimension(8, 16, 38, 32);
	//===================== ANIMATIONS =============================
	m_anim.SetTexture("DWARF");
	m_anim.SetAnimationVelocity(50.0f);
	m_anim.SetSpriteDimension(tile_size, tile_size);
	m_anim.SetTextureDimension(7, 1, 32, 32);
	m_anim.IsAnimationLooping() = true;
	//============ Collisions =================
	collision.SetPosition(m_position.x, m_position.y);
	collision.SetDimension(tile_size, tile_size);
}

void Dwarf::Draw()
{
	if (!m_AmAttack && !m_flipped) 
	{
		m_image.Draw((int)m_position.x,(int)m_position.y);
	}
	else if (!m_AmAttack && m_flipped)
	{
		m_image.Draw((int)m_position.x, (int)m_position.y, 0, Sprite::HORIZONTAL);
	}
	//============ Drawing Attack ============
	else if (m_AmAttack && !m_flipped)
	{
		m_anim.Draw((int)m_position.x, (int)m_position.y);
		m_AmAttack = false;
	}
	else if (m_AmAttack && m_flipped)
	{
		m_anim.Draw((int)m_position.x, (int)m_position.y, 0, Sprite::HORIZONTAL);
		m_AmAttack = false;
	}
	
}

void Dwarf::Update(int level[16][30], bool readyToAttack)
{
	float time = SDL_GetTicks() / 1000.0f;
	delay -= time;
	int actualPosX = (int)m_position.x / tile_size;
	int actualPosY = (int)m_position.y / tile_size;

	//std::cout<< actualPosX <<std::endl;

	keys = TheInput::Instance()->GetKeyStates();
	KeyState key;
	key = TheInput::Instance()->GetKeyStates();

	if (key[SDL_SCANCODE_K] && readyToAttack)
	{
		m_AmAttack = true;
		IMAttacking(m_AmAttack);
		delay = 3.0f;
	}
	else 
	{
		m_AmAttack = false;
		IMAttacking(m_AmAttack);
	}

	if (m_target == m_position)
	{
		if (key[SDL_SCANCODE_A] && level[actualPosY][actualPosX - 1] != 3)
		{
			m_flipped = true;
			m_target.x -= tile_size;
		}
		else if (key[SDL_SCANCODE_D] && level[actualPosY][actualPosX + 1] != 3)
		{
			m_flipped = false;
			m_target.x += tile_size;
		}
		else if (key[SDL_SCANCODE_W] && level[actualPosY - 1][actualPosX] != 3)
		{
			m_target.y -= tile_size;
		}
		else if (key[SDL_SCANCODE_S] && level[actualPosY + 1][actualPosX] != 3)
		{
			m_target.y += tile_size;
		}
	}
	else
	{
		if (m_target.x > m_position.x) { m_position.x += m_speed; }

		else if (m_target.x < m_position.x) { m_position.x -= m_speed; }

		if (m_target.y > m_position.y) { m_position.y += m_speed; }

		else if (m_target.y < m_position.y) { m_position.y -= m_speed; }

	}
}

