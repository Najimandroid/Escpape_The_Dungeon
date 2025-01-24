#include "Door.h"

Door::Door()
{
	m_position = { 0, 0 };

	m_health = 999;
	m_damage = 0;
	m_speed = 0;

	initHitbox({ 120, 120 });
	m_hitbox.setOrigin(m_hitbox.getSize() / 2.f);
	initSprite();
	m_sprite.setOrigin(m_hitbox.getOrigin());

	m_sprite.setColor(sf::Color(255, 0, 255));

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
	m_hitbox.setOrigin(m_hitbox.getSize() / 2.f);
	initSprite();
	m_sprite.setOrigin({ (m_hitbox.getSize().x / 2.f) * m_sprite.getScale().x , (m_hitbox.getSize().y / 2.f) * m_sprite.getScale().y });

	m_sprite.setColor(keyColors[ID]);

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

void Door::initSprite()
{
	if (!m_texture.loadFromFile("assets/textures/Door.png"))
	{
		LOG("COULDN'T LOAD DOOR TEXTURE")
	}
	m_sprite.setTexture(m_texture);
	updatePosition(m_position);
}