#include "Player.h"
#include "VectorOperations.h"
#include "SFML/Graphics.hpp"

Player::Player(sf::Vector2f spawnPosition, sf::Vector2f hitboxSize)
{
	m_position = spawnPosition;

	m_health = 100;
	m_damage = 10;
	m_speed = 20;

	initHitbox(hitboxSize);
	initSprite();
}

void Player::update(float deltaTime)
{
	manageInputs(deltaTime);
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	drawHitbox(window);
}

void Player::manageInputs(float deltaTime)
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

void Player::initHitbox(sf::Vector2f hitboxSize)
{
	sf::RectangleShape box(hitboxSize);
	box.setPosition(m_position);
	box.setFillColor(sf::Color::Transparent);
	box.setOutlineColor(sf::Color::Red);
	box.setOutlineThickness(3);
	m_hitbox = box;
}

void Player::initSprite()
{
	sf::RectangleShape body(m_hitbox.getSize());
	body.setFillColor(sf::Color::Green);
	body.setPosition(m_position);
	m_sprite = body;
}

