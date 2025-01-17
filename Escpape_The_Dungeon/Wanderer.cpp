#include "Wanderer.h"
#include "VectorOperations.h"
#include "Logger.h"

Wanderer::Wanderer(sf::Vector2f position, sf::Vector2f hitboxSize, const sf::Vector2f* positionPoints, int numberOfPositions)
{
	m_health = 100;
	m_damage = 10;
	m_speed = 15;

	initHitbox(hitboxSize);
	initSprite();

	for (int i = 0; i < numberOfPositions; i++)
	{
		m_positionPoints.push_back(positionPoints[i]);
	}

	m_position = m_positionPoints.at(0);
	m_currentPosition = 0;
}

void Wanderer::update(sf::RenderWindow& window, float deltaTime)
{
	draw(window);
	followPath(deltaTime);
}

void Wanderer::followPath(float deltaTime)
{
	sf::Vector2f velocity;
	sf::Vector2f targetPosition;

	targetPosition = m_positionPoints.at(m_currentPosition);

	if (m_position == targetPosition)
	{
		m_currentPosition++;
		if (m_currentPosition > m_positionPoints.size()) m_currentPosition = 0;
	}

	velocity = normalize({
		 (targetPosition.x - this->getPosition().x) / (sqrt((targetPosition.x - this->getPosition().x) * (targetPosition.x - this->getPosition().x) + (targetPosition.y - this->getPosition().y) * (targetPosition.y - this->getPosition().y)))
		,(targetPosition.y - this->getPosition().y) / (sqrt((targetPosition.x - this->getPosition().x) * (targetPosition.x - this->getPosition().x) + (targetPosition.y - this->getPosition().y) * (targetPosition.y - this->getPosition().y)))
	});

	updatePosition(m_position + velocity * deltaTime);
}
