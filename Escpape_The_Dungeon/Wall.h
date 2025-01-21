#pragma once

#include "SFML/Graphics.hpp"

#include "Entity.h"
#include "Logger.h"

class Wall : public Entity
{
public:

	Wall();
	virtual ~Wall() = default;
	Wall(sf::Vector2f spawnPosition);

	virtual void update(sf::RenderWindow& window, float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
};