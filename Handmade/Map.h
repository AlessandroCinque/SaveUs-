#pragma once
#include "Tile.h"
#include "GameObject.h"
class Map :
	public GameObject
{
public:
	Map();
	~Map();
	virtual void Draw();

private:
	int floor[30][16];
};

