#include "EntityManager.h"
#include "Logger.h"

/*EntityManager::EntityManager()
{
	m_enemies.reserve(5);
	m_interactables.reserve(5);
}*/

void EntityManager::addPlayer(std::unique_ptr<Player>&& newPlayer)
{
	m_players.push_back(std::move(newPlayer));
}

void EntityManager::addEnemy(std::unique_ptr<Enemy>&& newEnemy)
{
	m_enemies.push_back(std::move(newEnemy));
}

void EntityManager::addInteractable(std::unique_ptr<Interactable>&& newInteractable)
{
	m_interactables.push_back(std::move(newInteractable));
}

void EntityManager::addWall(std::unique_ptr<Wall>&& wall)
{
	m_walls.push_back(std::move(wall));
}

void EntityManager::updateEntities(sf::RenderWindow& window, float deltaTime)
{
	for (auto& wall : m_walls)
	{
		wall->update(window, deltaTime);
	}

	for (auto& plr : m_players)
	{
		plr->update(window, deltaTime, m_walls);
	}

	for (auto& enemy : m_enemies)
	{
		enemy->update(window, deltaTime);
	}

	for (auto& interactable : m_interactables)
	{
		interactable->update(window, deltaTime);
	}
}

bool EntityManager::isEnemyCollisionDetected()
{
	for (auto& enemy : m_enemies)
	{
		if (m_players[0]->collide(enemy.get()))
		{
			return true;
		}
	}
	return false;
}

void EntityManager::checkInteractableCollision()
{
	for (auto& interactable : m_interactables)
	{
		if (m_players[0]->collide(interactable.get()))
		{
			interactable->interact(*m_players.at(0).get(), m_walls);
		}
	}
}
