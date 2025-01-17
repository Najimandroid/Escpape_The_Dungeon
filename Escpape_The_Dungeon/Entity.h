#pragma once

#include "SFML/Graphics.hpp"


class Entity
{
public:

	virtual void update(float deltaTime) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;


	void drawHitbox(sf::RenderWindow& window); //only in debug mode


	void updatePosition(sf::Vector2f newPosition);

protected:
	
	sf::Vector2f m_position;

	int	m_health;
	int	m_damage;
	float m_speed;

	sf::RectangleShape m_hitbox;
	sf::RectangleShape m_sprite;

};