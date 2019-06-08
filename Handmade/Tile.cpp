#include "Tile.h"



Tile::Tile(std::string tile,glm::vec3 pos)
{

	std::string tag = "Tile";
	SetTag(tag);
	m_sprite.SetTexture(tile);
	m_sprite.SetSpriteDimension(tile_size, tile_size);
	m_sprite.SetTextureDimension(1, 1, tile_size, tile_size);
	m_position = pos;
}


Tile::~Tile()
{
}

//void Tile::Init()
//{
//	
//}

void Tile::Draw()
{
	m_sprite.Draw((int)m_position.x, (int)m_position.y);
}

void Tile::Update()
{
}

