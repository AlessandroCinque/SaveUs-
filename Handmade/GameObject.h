#pragma once
#include <iostream>
#include <string> 
#include<glm.hpp>

class GameObject
{
public:
	GameObject() {};
	virtual ~GameObject() {};


	void SetTag(std::string& tag) { m_tag = tag; };

	// POSITION!!!!!
	void SetPosition(float x, float y) {m_position = glm::vec2(x, y);};
	const glm::vec2 GetPosition() {return m_position;};
	// ATTTACK!
	void SetDamage(float damage) { m_damage = damage; }
	float GetDamage() { return m_damage;}

	void IMAttacking(bool Attacking) {attacking = Attacking;}
	const bool AmIAttacking() { return attacking; }

	
	//======================================
	void ApplyDamage(float damage) { m_health -= damage; if (m_health <= 0) { m_health = 0; m_isAlive = false; } }
	// HEALTH
	void SetHealth(float health) { m_health = health; }
	const float GetHealth() { return m_health; }

	const std::string GetTag() {return m_tag;};
	virtual void Draw() {};
	virtual void Update() {};


	void SetisVisible(bool isVisible) { m_isVisible = isVisible; }
	void SetisActive(bool isActive) { m_isActive = isActive; }
	void SetisAlive(bool isAlive) { m_isAlive = isAlive; }

	bool isVisible() { return m_isVisible; }
	bool isActive() { return m_isActive; }
	bool Alive() { return m_isAlive; }
protected:
	int tile_size = 48;
	std::string m_tag;
	glm::vec2 m_position;
	float m_health;
	bool attacking = false;
	float m_damage;

	bool m_isVisible = true;
	bool m_isActive = true;
	bool m_isAlive = true;
};

