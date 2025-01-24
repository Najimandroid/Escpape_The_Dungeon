#pragma once

#include "Interactable.h"
#include "EntityManager.h"

class Crystal : public Interactable
{
public:
	Crystal(sf::Vector2f spawnPosition);

	virtual void interact(Player& player, const std::vector<std::unique_ptr<Wall>>& walls);
private:
	void initSprite() override;
};