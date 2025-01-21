#include "SFML/Graphics.hpp"

#include "Player.h"


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

void Player::update(sf::RenderWindow& window, float deltaTime, const std::vector<std::unique_ptr<Wall>>& walls)
{
	handleInputs(deltaTime, walls);
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

void Player::handleInputs(float deltaTime, const std::vector<std::unique_ptr<Wall>>& walls)
{
	sf::Vector2f velocity;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		velocity = { 0, -m_speed*20 };
		if (!isWallCollided(m_position + velocity * deltaTime, walls))
		{
			updatePosition(m_position + velocity * deltaTime);
		}
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		velocity = { 0, m_speed*20 };
		if (!isWallCollided(m_position + velocity * deltaTime, walls))
		{
			updatePosition(m_position + velocity * deltaTime);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		velocity = { -m_speed*20, 0 };
		if (!isWallCollided(m_position + velocity * deltaTime, walls))
		{
			updatePosition(m_position + velocity * deltaTime);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity = { m_speed*20, 0 };
		if (!isWallCollided(m_position + velocity * deltaTime, walls))
		{
			updatePosition(m_position + velocity * deltaTime);
		}
	}
}

bool Player::isWallCollided(sf::Vector2f futurePosition, const std::vector<std::unique_ptr<Wall>>& walls)
{
	sf::RectangleShape hitboxDummy(m_hitbox.getSize());
	hitboxDummy.setPosition(futurePosition);

	sf::FloatRect boundingBox = hitboxDummy.getGlobalBounds();

	for (auto& wall : walls)
	{
		sf::FloatRect otherBoundingBox = wall->getHitbox().getGlobalBounds();

		if (boundingBox.intersects(otherBoundingBox))
		{
			return true;
		}
	}

	return false;
}