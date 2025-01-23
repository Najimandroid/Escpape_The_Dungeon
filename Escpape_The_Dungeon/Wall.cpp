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
	initSprite();

	m_sprite.setFillColor(sf::Color::White);
}


Wall::Wall(sf::Vector2f spawnPosition)
{
	//LOG("WALL CREATED");
	m_position = spawnPosition;

	m_health = 999;
	m_damage = 0;
	m_speed = 0;

	initHitbox({ 120, 120 });
	initSprite();

	m_sprite.setFillColor(sf::Color::White);
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
