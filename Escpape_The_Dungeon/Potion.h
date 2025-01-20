#pragma once

#include "Interactable.h"

class Potion : public Interactable
{
public:
	Potion(sf::Vector2f spawnPosition, float speedMultiplier);

	virtual void interact(Player& player);
private:
	float m_speedMultiplier;
};