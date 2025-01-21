#pragma once

#include "SFML/Graphics.hpp"
#include "Entity.h"

#include "Wall.h"

class Player : public Entity
{
public:

	Player(sf::Vector2f spawnPosition, sf::Vector2f hitboxSize);

	void update(sf::RenderWindow& window, float deltaTime,const std::vector<std::unique_ptr<Wall>>& walls);
	void draw(sf::RenderWindow& window);

	bool isWallCollided(sf::Vector2f futurePosition, const std::vector<std::unique_ptr<Wall>>& walls);

private:
	void handleInputs(float deltaTime, const std::vector<std::unique_ptr<Wall>>& walls);
};