#pragma once

#include "SFML/Graphics.hpp"

#include "Entity.h"

class Enemy : public Entity
{
public:

	Enemy(sf::Vector2f spawnPosition, sf::Vector2f hitboxSize);

	void update(sf::RenderWindow& window, float deltaTime) override;
	void draw(sf::RenderWindow& window) override;

private:

	void initHitbox(sf::Vector2f hitboxSize);
	void initSprite();
};