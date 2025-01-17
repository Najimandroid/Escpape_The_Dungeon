#include "Entity.h"
#include <iostream> 

#ifdef _DEBUG 
void Entity::drawHitbox(sf::RenderWindow& window)
{
	window.draw(m_hitbox);
}
#else
void Entity::drawHitbox(sf::RenderWindow& window) {}
#endif // DEBUG


void Entity::updatePosition(sf::Vector2f newPosition)
{
	m_position = newPosition;

	m_hitbox.setPosition(m_position);
	m_sprite.setPosition(m_position);
}


