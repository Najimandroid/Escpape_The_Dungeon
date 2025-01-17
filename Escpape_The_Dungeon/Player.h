#pragma once

#include "SFML/Graphics.hpp"

#include "Entity.h"

class Player : Entity
{
public:

	Player(sf::Vector2f spawnPosition, sf::Vector2f hitboxSize);

	void update(float deltaTime) override;
	void draw(sf::RenderWindow& window) override;

private:
	void manageInputs(float deltaTime);

	void initHitbox(sf::Vector2f hitboxSize);
	void initSprite();
};