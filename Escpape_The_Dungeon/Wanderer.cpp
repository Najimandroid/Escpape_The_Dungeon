#include "Wanderer.h"
#include "VectorOperations.h"
#include "Logger.h"

Wanderer::Wanderer(sf::Vector2f position, sf::Vector2f hitboxSize, std::vector<sf::Vector2f> positionPoints)
{
	m_health = 100;
	m_damage = 10;
	m_speed = 20;

	initHitbox(hitboxSize);
	initSprite();
	m_sprite.setScale({ .5f, .5f });
	m_sprite.setOrigin({ (m_hitbox.getSize().x / 2.f) * m_sprite.getScale().x , (m_hitbox.getSize().y / 2.f) * m_sprite.getScale().y });

	m_sprite.setColor(sf::Color::Cyan);

	for (int i = 0; i < positionPoints.size(); i++)
	{
		m_positionPoints.push_back(positionPoints[i]);
	}

	m_position = m_positionPoints.at(0);
	m_currentPosition = 0;

	updatePosition(m_position);
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
		if (m_currentPosition > m_positionPoints.size() - 1) m_currentPosition = 0;
		targetPosition = m_positionPoints.at(m_currentPosition);
	}

	//LOG("POSITION: " + std::to_string(m_position.x) + ", " + std::to_string(m_position.y) + " | TARGET:" + std::to_string(targetPosition.x) + ", " + std::to_string(targetPosition.y));

	sf::Vector2f direction = targetPosition - m_position;
	float distance = sqrt(direction.x * direction.x + direction.y * direction.y);

	
	if (distance > 0 && distance < 5) { velocity = { 0, 0 }; m_position = targetPosition; }
	else if (distance > 0) velocity = direction / distance;
	else velocity = { 0, 0 };

	velocity = velocity * sf::Vector2f{ m_speed * 20, m_speed * 20 };

	updatePosition(m_position + velocity * deltaTime);
}

void Wanderer::initSprite()
{
	if (!m_texture.loadFromFile("assets/textures/Ghost.png"))
	{
		LOG("COULDN'T LOAD WANDERER TEXTURE")
	}
	m_sprite.setTexture(m_texture);
}