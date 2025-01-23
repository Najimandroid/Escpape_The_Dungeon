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

	int getXIndex() { return m_xIndex; }
	int getYIndex() { return m_yIndex; }

	void setXIndex(int newIndex) { m_xIndex = newIndex; }
	void setYIndex(int newIndex) { m_yIndex = newIndex; }

private:
	void handleInputs(float deltaTime, const std::vector<std::unique_ptr<Wall>>& walls);

	int m_xIndex = 0;
	int m_yIndex = 0;
};