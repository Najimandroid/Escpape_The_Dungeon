#pragma once

#include "SFML/Graphics.hpp"

#include "Entity.h"

class Enemy : public Entity
{
public:

	Enemy();
	Enemy(sf::Vector2f spawnPosition, sf::Vector2f hitboxSize);

	virtual void update(sf::RenderWindow& window, float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
};