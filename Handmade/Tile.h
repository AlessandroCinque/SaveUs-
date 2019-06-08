#pragma once
#include "GameObject.h"
#include <iostream>
#include <string> 
#include<glm.hpp>
#include "ScreenManager.h"
#include"TextureManager.h"
#include "Sprite.h"
class Tile :
	public GameObject
{
public:
	Tile(std::string tile, glm::vec3 pos);
	~Tile();

	
	virtual void Update();
	virtual void Draw();
private:
	Sprite m_sprite;
	int tile_size = 48;

};

