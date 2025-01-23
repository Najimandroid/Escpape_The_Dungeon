#pragma once

#include "Entity.h"

#include "Enemy.h"
#include "Player.h"
#include "Interactable.h"
#include "Wall.h"

#include <vector>
#include <memory>

class EntityManager
{
private:

	static EntityManager* instance;
	EntityManager() = default;

public:

	static EntityManager* getInstance()
	{
		if (instance == nullptr)
		{
			return new EntityManager;
		}
		return instance;
	}
	

	void addPlayer(std::unique_ptr<Player>&& newPlayer);
	void addEnemy(std::unique_ptr<Enemy>&& newEnemy);
	void addInteractable(std::unique_ptr<Interactable>&& newInteractable);
	void addWall(std::unique_ptr<Wall>&& newInteractable);

	void updateEntities(sf::RenderWindow& window, float deltaTime);
	bool isEnemyCollisionDetected();
	void checkInteractableCollision();

	void unloadEntities();

	std::vector<std::unique_ptr<Wall>>& getWalls() { return m_walls; }
	std::vector<std::unique_ptr<Player>>& getPlayers() { return m_players; }

private:

	std::vector<std::unique_ptr<Player>> m_players;
	std::vector<std::unique_ptr<Enemy>> m_enemies;
	std::vector<std::unique_ptr<Interactable>> m_interactables;
	std::vector<std::unique_ptr<Wall>> m_walls;
};