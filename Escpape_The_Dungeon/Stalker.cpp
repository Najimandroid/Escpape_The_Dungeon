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
	m_speed = 10;

	initHitbox(hitboxSize);
	initSprite();

	m_target = target;
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

	velocity = normalize({
			  (targetPosition.x - this->getPosition().x) / (sqrt((targetPosition.x - this->getPosition().x) * (targetPosition.x - this->getPosition().x) + (targetPosition.y - this->getPosition().y) * (targetPosition.y - this->getPosition().y)))
			, (targetPosition.y - this->getPosition().y) / (sqrt((targetPosition.x - this->getPosition().x) * (targetPosition.x - this->getPosition().x) + (targetPosition.y - this->getPosition().y) * (targetPosition.y - this->getPosition().y)))
		});

	velocity = velocity * sf::Vector2f{ m_speed * 20, m_speed * 20 };

	updatePosition(m_position + velocity * deltaTime);

}
