#pragma once

#include "Interactable.h"
#include "EntityManager.h"
#include "KeyColorConfig.h"

class Key : public Interactable
{
public:
	Key(sf::Vector2f spawnPosition, int doorID);

	virtual void interact(Player& player, const std::vector<std::unique_ptr<Wall>>& walls);
private:
	int m_doorID;
};