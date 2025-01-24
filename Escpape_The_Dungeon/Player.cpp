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

	m_xIndex = 0;
	m_yIndex = 0;

	initHitbox(hitboxSize);
	m_hitbox.setOrigin(m_hitbox.getSize() / 2.f);
	initSprite();
	m_sprite.setColor(sf::Color::Green);
	m_sprite.setScale({ .5f, .5f });
	m_sprite.setOrigin({ 60.f, 60.f });

	m_hitbox.setFillColor(sf::Color::Green);
	m_openedIDs.reserve(5);

	m_hasWon = false;
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

void Player::death()
{
	if (!m_deathTexture.loadFromFile("assets/textures/Death.png"))
	{
		LOG("COULDN'T LOAD DEATH TEXTURE")
		return;
	}
	m_sprite.setTexture(m_deathTexture);
	updatePosition(m_position);
}

void Player::initSprite()
{
	if (!m_texture.loadFromFile("assets/textures/Player.png"))
	{
		LOG("COULDN'T LOAD PLAYER TEXTURE")
	}
	m_sprite.setTexture(m_texture);
	updatePosition(m_position);
}

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
	hitboxDummy.setOrigin(m_hitbox.getOrigin());
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
