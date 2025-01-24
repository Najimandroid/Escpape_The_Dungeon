#pragma once

#include "Wall.h"
#include "KeyColorConfig.h"

class Door : public Wall
{
public:

	Door();
	Door(sf::Vector2f spawnPosition, int ID);

	void unlock(int ID);
	void update(sf::RenderWindow& window, float deltaTime) override;
private:
	void initSprite() override;

private:
	int m_ID;
	bool m_unlocked;
};