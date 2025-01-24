#include "Stalker.h"
#include "SFML/Graphics.hpp"

#include "VectorOperations.h"
#include "Logger.h"

#include <cmath>

//////////////////////
//* INITIALIZATION *\\
//////////////////////

Stalker::Stalker(sf::Vector2f spawnPosition, sf::Vector2f hitboxSize, Entity* target)
{
	m_position = spawnPosition;

	m_health = 100;
	m_damage = 10;
	m_speed = 8;

	initHitbox(hitboxSize);
	initSprite();
	m_sprite.setColor(sf::Color::Red);

	m_hitbox.setFillColor(sf::Color::Red);
	m_sprite.setScale({ .5f, .5f });
	m_sprite.setOrigin({ (m_hitbox.getSize().x / 2.f) * m_sprite.getScale().x , (m_hitbox.getSize().y / 2.f) * m_sprite.getScale().y });

	m_target = target;
	updatePosition(m_position);
}

////////////////
//* UPDATING *\\
////////////////

void Stalker::update(sf::RenderWindow& window, float deltaTime)
{
	draw(window);
	followEntity(m_target, deltaTime);
}

void Stalker::followEntity(Entity* followedEntity, float deltaTime)
{
	sf::Vector2f velocity;

	sf::Vector2f targetPosition = followedEntity->getPosition();

	//LOG("Stalker target position: " + std::to_string(targetPosition.x) + ", " + std::to_string(targetPosition.y));

	sf::Vector2f direction = targetPosition - m_position;
	float distance = sqrt(direction.x * direction.x + direction.y * direction.y);

	if (distance > 0) velocity = direction / distance;
	else velocity = { 0, 0 };

	velocity = velocity * sf::Vector2f{ m_speed * 20, m_speed * 20 };

	updatePosition(m_position + velocity * deltaTime);

}

void Stalker::initSprite()
{
	if (!m_texture.loadFromFile("assets/textures/Ghost.png"))
	{
		LOG("COULDN'T LOAD STALKER TEXTURE")
	}
	m_sprite.setTexture(m_texture);
}
