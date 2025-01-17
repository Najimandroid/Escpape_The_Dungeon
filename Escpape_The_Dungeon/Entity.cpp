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


