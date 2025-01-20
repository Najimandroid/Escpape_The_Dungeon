#pragma once

#include "Interactable.h"
#include "Door.h"

class Key : public Interactable
{
public:
	Key(sf::Vector2f spawnPosition, Door* target);

	virtual void interact(Player& player);
private:
	Door* m_target;
};