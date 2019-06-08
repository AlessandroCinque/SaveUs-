#pragma once
#include <iostream>
#include <string> 
#include<glm.hpp>
#include<ctime>
#include "AudioManager.h"
#include "InputManager.h"
#include "ScreenManager.h"
#include"TextureManager.h"
#include "Sprite.h"
#include "Text.h"
#include "Audio.h"
#include"SFX.h"
#include "Animation.h"
#include "GameObject.h"
#include "AABB.h"
#include "Orc.h"
enum Tiles {GRASS = 0, WALL = 3};
class Dwarf :
	public GameObject
{
public:
	Dwarf();
	~Dwarf();
	void Init(glm::vec2 position);
	virtual void Update(int level[16][30], bool readyToAttack);
	virtual void Draw();
	void SetScore(int score) { m_score += score; }
	int GetScore() { return m_score; }
	// This is a trick access the collision.
	AABB GetCollision() { return collision; }
	/*void SetPosition(glm::vec2 OrcPosition) { m_position = OrcPosition; }
	glm::vec2 GetPosition() { return m_position; }*/

private:
	Sprite m_image;
	Animation m_anim;
	AABB collision;

	
	//glm::vec2 m_position;
	glm::vec2 m_target;
	glm::vec2 m_enemy;
	
	float delay;
	int m_score = 0;
	
	float m_speed = 4.0f;
	bool m_moveAgain = true;
	bool m_flipped = false;
	bool m_AmAttack = false;
	const Uint8* keys = nullptr;
};

