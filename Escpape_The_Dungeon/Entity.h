#pragma once

#include "SFML/Graphics.hpp"


class Entity
{
public:

	virtual void update(sf::RenderWindow& window, float deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;


	void drawHitbox(sf::RenderWindow& window); //only in debug mode

	void updatePosition(const sf::Vector2f newPosition);

	[[nodiscard]] bool collide(Entity* otherEntity);

	sf::RectangleShape& getHitbox() { return m_hitbox; }

protected:
	
	sf::Vector2f m_position;

	int	m_health;
	int	m_damage;
	float m_speed;

	sf::RectangleShape m_hitbox;
	sf::RectangleShape m_sprite;

};