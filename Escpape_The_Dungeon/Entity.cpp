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

Entity::Entity()
{
	m_position = { 0, 0 };

	m_health = 1;
	m_damage = 1;
	m_speed = 1;

	initHitbox({ 5, 5 });
	initSprite();
}

Entity::Entity(Entity&& other) noexcept
{
	m_position = std::move(other.m_position);
	m_health = std::move(other.m_health);
	m_damage = std::move(other.m_damage);
	m_speed = std::move(other.m_speed);
	m_hitbox = std::move(other.m_hitbox);
	m_sprite = std::move(other.m_sprite);
}

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



