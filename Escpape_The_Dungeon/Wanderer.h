#pragma once

#include "SFML/Graphics.hpp"
#include <vector>

#include "Enemy.h"

class Wanderer : public Enemy
{
public:
	Wanderer(sf::Vector2f spawnPosition, sf::Vector2f hitboxSize, const sf::Vector2f* positionPoints, int numberOfPositions);

	void update(sf::RenderWindow& window, float deltaTime) override;

	void followPath(float deltaTime);

private:
	std::vector<sf::Vector2f> m_positionPoints;
	int m_currentPosition;
};