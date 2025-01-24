#pragma once

#include "Entity.h"
#include "Player.h"

class Interactable : public Entity
{
public:

	Interactable();
	Interactable(sf::Vector2f spawnPosition);
	Interactable(Interactable&& other);

	virtual void interact(Player& player, const std::vector<std::unique_ptr<Wall>>& walls);

	virtual void update(sf::RenderWindow& window, float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
protected:
	virtual void initSprite();

protected:
	bool m_interacted;
};