#pragma once

#include "Entity.h"

#include "Enemy.h"
#include "Player.h"
#include "Interactable.h"

#include <vector>
#include <memory>

class EntityManager
{
public:

	EntityManager();

	void addPlayer(std::unique_ptr<Player>&& newPlayer);
	void addEnemy(std::unique_ptr<Enemy>&& newEnemy);
	void addInteractable(std::unique_ptr<Interactable>&& newInteractable);

	void updateEntities(sf::RenderWindow& window, float deltaTime);
	bool isEnemyCollisionDetected();
	void checkInteractableCollision();

private:

	std::vector<std::unique_ptr<Player>> m_players;
	std::vector<std::unique_ptr<Enemy>> m_enemies;
	std::vector<std::unique_ptr<Interactable>> m_interactables;
};