#pragma once

#include "Entity.h"
#include "Player.h"

class Interactable : public Entity
{
public:

	Interactable();
	Interactable(sf::Vector2f spawnPosition);

	virtual void interact(Player& player) = 0;

	virtual void update(sf::RenderWindow& window, float deltaTime) override;
	void draw(sf::RenderWindow& window) override;

protected:
	bool m_interacted;
};