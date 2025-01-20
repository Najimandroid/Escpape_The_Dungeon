#include "Entity.h"
#include <iostream> 

#ifdef _DEBUG 
void Entity::drawHitbox(sf::RenderWindow& window)
{
	window.draw(m_hitbox);
}
#else
void Entity::drawHitbox(sf::RenderWindow& window) {}
#endif

void Entity::initHitbox(sf::Vector2f hitboxSize)
{
	sf::RectangleShape box(hitboxSize);
	box.setPosition(m_position);

	box.setFillColor(sf::Color::Transparent);
	box.setOutlineColor(sf::Color::Blue);

	box.setOutlineThickness(3);

	m_hitbox = box;
}

void Entity::initSprite()
{
	sf::RectangleShape body(m_hitbox.getSize());
	body.setPosition(m_position);

	body.setFillColor(sf::Color::Red);

	m_sprite = body;
}

void Entity::updatePosition(const sf::Vector2f newPosition)
{
	m_position = newPosition;

	m_hitbox.setPosition(m_position);
	m_sprite.setPosition(m_position);
}

bool Entity::collide(Entity* otherEntity)
{
	sf::FloatRect boundingBox = m_hitbox.getGlobalBounds();
	sf::FloatRect otherBoundingBox = otherEntity->getHitbox().getGlobalBounds();

	if (boundingBox.intersects(otherBoundingBox))
	{
		return true;
	}
	return false;
}



