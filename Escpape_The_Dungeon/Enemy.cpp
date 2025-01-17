#include "Enemy.h"
#include "SFML/Graphics.hpp"

#include "VectorOperations.h"
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



//* STALKER *\\

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

	velocity = velocity * sf::Vector2f{m_speed*20, m_speed*20};

	updatePosition(m_position + velocity * deltaTime);

}
