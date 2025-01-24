#include "Wall.h"
#include "SFML/Graphics.hpp"

#include "Logger.h"

#include <cmath>

//////////////////////
//* INITIALIZATION *\\
//////////////////////

Wall::Wall()
{
	m_position = { 0, 0 };

	m_health = 999;
	m_damage = 0;
	m_speed = 0;

	initHitbox({ 120, 120 });
	m_hitbox.setOrigin(m_hitbox.getSize() / 2.f);
	initSprite();
	m_sprite.setOrigin(m_hitbox.getOrigin());

	m_sprite.setColor(sf::Color::White);
}


Wall::Wall(sf::Vector2f spawnPosition)
{
	//LOG("WALL CREATED");
	m_position = spawnPosition;

	m_health = 999;
	m_damage = 0;
	m_speed = 0;

	initHitbox({ 120, 120 });
	m_hitbox.setOrigin(m_hitbox.getSize() / 2.f);
	initSprite();
	m_sprite.setOrigin({ (m_hitbox.getSize().x / 2.f) * m_sprite.getScale().x , (m_hitbox.getSize().y / 2.f) * m_sprite.getScale().y });

	m_sprite.setColor(sf::Color::White);
}

////////////////
//* UPDATING *\\
////////////////

void Wall::update(sf::RenderWindow& window, float deltaTime)
{
	draw(window);
}

////////////////
//* GRAPHICS *\\
////////////////

void Wall::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	drawHitbox(window);
}

void Wall::initSprite()
{
	if (!m_texture.loadFromFile("assets/textures/Wall.png"))
	{
		LOG("COULDN'T LOAD WALL TEXTURE")
	}
	m_sprite.setTexture(m_texture);
	updatePosition(m_position);
}
