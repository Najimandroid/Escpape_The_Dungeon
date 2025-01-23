#pragma once

#include "SFML/Graphics.hpp"

#include "Logger.h"

class Entity
{
public:
	Entity();
	Entity(Entity&& other) noexcept;

	virtual void update(sf::RenderWindow& window, float deltaTime) { LOG("update"); };
	virtual void draw(sf::RenderWindow& window) { LOG("draw"); };


	void drawHitbox(sf::RenderWindow& window); //only in debug mode

	void updatePosition(const sf::Vector2f newPosition);

	[[nodiscard]] bool collide(Entity* otherEntity);

	///////////////
	//* GETTERS *\\
	///////////////
	float getSpeed() const { return m_speed; }
	sf::RectangleShape& getHitbox() { return m_hitbox; }
	sf::Vector2f getPosition() { return m_position; }

	///////////////
	//* SETTERS *\\
	///////////////
	void setSpeed(const float newSpeed) { m_speed = newSpeed; }
	void setPosition(const sf::Vector2f newPos) { m_position = newPos; updatePosition(m_position); }

protected:

	void initHitbox(sf::Vector2f hitboxSize);
	void initSprite();

protected:
	
	sf::Vector2f m_position;

	int	m_health;
	int	m_damage;
	float m_speed;

	sf::RectangleShape m_hitbox;
	sf::RectangleShape m_sprite;

};