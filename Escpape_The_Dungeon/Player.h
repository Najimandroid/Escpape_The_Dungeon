#pragma once

#include "SFML/Graphics.hpp"

#include "Entity.h"

class Player : public Entity
{
public:

	Player(sf::Vector2f spawnPosition, sf::Vector2f hitboxSize);

	void update(sf::RenderWindow& window, float deltaTime) override;
	void draw(sf::RenderWindow& window) override;

	///////////////
	//* GETTERS *\\
	///////////////
	float getSpeed() const { return m_speed; }

	///////////////
	//* SETTERS *\\
	///////////////
	void setSpeed(const float newSpeed) { m_speed = newSpeed; }

private:
	void handleInputs(float deltaTime);
};