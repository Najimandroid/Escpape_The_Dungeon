#include "Enemy.h"
#include "SFML/Graphics.hpp"

//////////////////////
//* INITIALIZATION *\\
//////////////////////

Enemy::Enemy(sf::Vector2f spawnPosition, sf::Vector2f hitboxSize)
{
	m_position = spawnPosition;

	m_health = 100;
	m_damage = 10;
	m_speed = 20;

	initHitbox(hitboxSize);
	initSprite();
}

void Enemy::initHitbox(sf::Vector2f hitboxSize)
{
	sf::RectangleShape box(hitboxSize);
	box.setPosition(m_position);

	box.setFillColor(sf::Color::Transparent);
	box.setOutlineColor(sf::Color::Magenta); 

	box.setOutlineThickness(3);

	m_hitbox = box;
}

void Enemy::initSprite()
{
	sf::RectangleShape body(m_hitbox.getSize());
	body.setPosition(m_position);

	body.setFillColor(sf::Color::Red);
	
	m_sprite = body;
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

