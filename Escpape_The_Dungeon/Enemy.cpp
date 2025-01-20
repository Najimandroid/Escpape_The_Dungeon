#include "Enemy.h"
#include "SFML/Graphics.hpp"

#include "Logger.h"

#include <cmath>

//////////////////////
//* INITIALIZATION *\\
//////////////////////

Enemy::Enemy()
{
	m_position = { 0, 0 };

	m_health = 1;
	m_damage = 1;
	m_speed = 1;

	initHitbox({ 5, 5 });
	initSprite();
}

Enemy::Enemy(sf::Vector2f spawnPosition, sf::Vector2f hitboxSize)
{
	m_position = spawnPosition;

	m_health = 100;
	m_damage = 10;
	m_speed = 10;

	initHitbox(hitboxSize);
	initSprite();
}

////////////////
//* UPDATING *\\
////////////////

void Enemy::update(sf::RenderWindow& window, float deltaTime)
{
	draw(window);
}

////////////////
//* GRAPHICS *\\
////////////////

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	drawHitbox(window);
}
