#pragma once

#include "SFML/Graphics.hpp"
#include "Entity.h"

#include "Wall.h"
#include <vector>

class Player : public Entity
{
public:

	Player(sf::Vector2f spawnPosition, sf::Vector2f hitboxSize);

	void update(sf::RenderWindow& window, float deltaTime,const std::vector<std::unique_ptr<Wall>>& walls);
	void draw(sf::RenderWindow& window);

	bool isWallCollided(sf::Vector2f futurePosition, const std::vector<std::unique_ptr<Wall>>& walls);

	int getXIndex() { return m_xIndex; }
	int getYIndex() { return m_yIndex; }
	std::vector<int> getOpenedIDs() { return m_openedIDs; }

	void setXIndex(int newIndex) { m_xIndex = newIndex; }
	void setYIndex(int newIndex) { m_yIndex = newIndex; }

	void addOpenedID(int openedID) { m_openedIDs.push_back(openedID); }

	void death();

private:
	void initSprite() override;

private:
	void handleInputs(float deltaTime, const std::vector<std::unique_ptr<Wall>>& walls);

	std::vector<int> m_openedIDs;

	int m_xIndex = 0;
	int m_yIndex = 0;
};