#include "Door.h"

Door::Door()
{
	m_position = { 0, 0 };

	m_health = 999;
	m_damage = 0;
	m_speed = 0;

	initHitbox({ 120, 120 });
	initSprite();

	m_sprite.setFillColor(sf::Color(255, 0, 255));

	m_ID = -1;
	m_unlocked = false;
}

Door::Door(sf::Vector2f spawnPosition, int ID)
{
	m_position = spawnPosition;

	m_health = 999;
	m_damage = 0;
	m_speed = 0;

	initHitbox({ 120, 120 });
	initSprite();

	m_sprite.setFillColor(keyColors[ID]);

	m_ID = ID;
	m_unlocked = false;
}

void Door::unlock(int ID)
{
	if (ID == m_ID)
	{
		LOG("Door unlocked");
		m_unlocked = true;
		m_hitbox.setSize({ 0, 0 });
	}
}

void Door::update(sf::RenderWindow& window, float deltaTime)
{
	if (m_unlocked) return;
	draw(window);
}
