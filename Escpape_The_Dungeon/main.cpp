#include <SFML/Graphics.hpp>

#include <iostream>
#include <thread>

#include "EntityManager.h"
#include "Map.h"

#include "Stalker.h"
#include "Wanderer.h"

#include "Potion.h"
#include "Key.h"

#include "Logger.h"

EntityManager* EntityManager::instance = nullptr;

int main()
{
#ifdef _DEBUG 
	std::cout << "---[DEBUG MODE]---\n";
#endif

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Escape the Dungeon", sf::Style::Fullscreen);
	window.setFramerateLimit(60);

	EntityManager* manager = EntityManager::getInstance();


	bool isRunning = true;

	auto plr = std::make_unique<Player>(sf::Vector2f(1920 / 2, 1080 / 2), sf::Vector2f(50, 50));

	sf::Vector2f pointsList[4] = { sf::Vector2f(50, 50), sf::Vector2f(50, 1000), sf::Vector2f(1000, 1000),  sf::Vector2f(1000, 50) };
	auto monster2 = std::make_unique<Wanderer>(sf::Vector2f(0, 0), sf::Vector2f(50, 50), pointsList, 4);

	auto potion = std::make_unique<Potion>(sf::Vector2f(100, 200), 1.5f);

	manager->addPlayer(std::move(plr));
	manager->addEnemy(std::move(monster2));

	manager->addInteractable(std::move(potion));

	Map map;
	map.createMap(manager, { 0, 0 });

	sf::Clock clock;
	float deltaTime = 0.f;

	while (window.isOpen() && isRunning)
	{
		deltaTime = clock.restart().asSeconds();
		window.clear();

		sf::Event event;
		while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
			}
		}

		manager->updateEntities(window, deltaTime);

		if(manager->isEnemyCollisionDetected())
		{
			LOG("GAME OVER!");
			isRunning = false;
		}

		manager->checkInteractableCollision();

		//check if player goes to another room
		//Y:
		auto player = manager->getPlayers()[0].get();
		if (manager->getPlayers()[0].get()->getPosition().y > 1080.f + 25.f)
		{
			manager->unloadEntities();
			player->setPosition({ player->getPosition().x, player->getPosition().y -1080.f});

			player->setYIndex(player->getYIndex() + 1);
			map.createMap(manager, { player->getXIndex(), player->getYIndex() });

		}
		else if (manager->getPlayers()[0].get()->getPosition().y < -25.f)
		{
			manager->unloadEntities();
			player->setPosition({ player->getPosition().x, player->getPosition().y + 1080.f });

			player->setYIndex(player->getYIndex() - 1);
			map.createMap(manager, { player->getXIndex(), player->getYIndex() });

		}

		//X:
		if (manager->getPlayers()[0].get()->getPosition().x > 1920.f - 60.f + 25.f)
		{
			manager->unloadEntities();
			player->setPosition({ player->getPosition().x - 1920.f + 61.f, player->getPosition().y });

			player->setXIndex(player->getXIndex() + 1);
			map.createMap(manager, { player->getXIndex(), player->getYIndex() });
		}
		else if (manager->getPlayers()[0].get()->getPosition().x < 60.f - 25.f)
		{
			manager->unloadEntities();
			player->setPosition({ player->getPosition().x + 1920.f - 59.f, player->getPosition().y });

			player->setXIndex(player->getXIndex() - 1);
			map.createMap(manager, { player->getXIndex(), player->getYIndex() });
		}

		window.display();
	}

	return 0;
}