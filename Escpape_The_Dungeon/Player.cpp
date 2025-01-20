#include "Player.h"
#include "SFML/Graphics.hpp"

//////////////////////
//* INITIALIZATION *\\
//////////////////////

Player::Player(sf::Vector2f spawnPosition, sf::Vector2f hitboxSize)
{
	m_position = spawnPosition;

	m_health = 100;
	m_damage = 10;
	m_speed = 20;

	initHitbox(hitboxSize);
	initSprite();

	m_hitbox.setFillColor(sf::Color::Green);
}


////////////////
//* UPDATING *\\
////////////////

void Player::update(sf::RenderWindow& window, float deltaTime)
{
	handleInputs(deltaTime);
	draw(window);
}

////////////////
//* GRAPHICS *\\
////////////////

void Player::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	drawHitbox(window);
}

//////////////
//* INPUTS *\\
//////////////

void Player::handleInputs(float deltaTime)
{
	sf::Vector2f velocity;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		velocity = { 0, -m_speed*20 };
		updatePosition(m_position + velocity * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		velocity = { 0, m_speed*20 };
		updatePosition(m_position + velocity * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		velocity = { -m_speed*20, 0 };
		updatePosition(m_position + velocity * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity = { m_speed*20, 0 };
		updatePosition(m_position + velocity * deltaTime);
	}
}
