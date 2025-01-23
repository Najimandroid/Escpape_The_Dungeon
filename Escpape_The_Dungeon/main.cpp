#include <SFML/Graphics.hpp>

#include <iostream>
#include <iostream>

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

	EntityManager* manager = EntityManager::getInstance();
	Map map;

	bool isRunning = true;

	sf::RenderWindow window(sf::VideoMode(1920 , 1080), "Escape the Dungeon", sf::Style::Fullscreen);
	window.setFramerateLimit(60);

	auto plr = std::make_unique<Player>(sf::Vector2f(1920 / 2, 1080 / 2), sf::Vector2f(50, 50));

	auto monster = std::make_unique<Stalker>(sf::Vector2f(500, 500), sf::Vector2f(50, 50), plr.get());

	sf::Vector2f pointsList[4] = { sf::Vector2f(50, 50), sf::Vector2f(50, 1000), sf::Vector2f(1000, 1000),  sf::Vector2f(1000, 50) };
	auto monster2 = std::make_unique<Wanderer>(sf::Vector2f(0, 0), sf::Vector2f(50, 50), pointsList, 4);

	auto potion = std::make_unique<Potion>(sf::Vector2f(100, 200), 1.5f);
	auto key = std::make_unique<Key>(sf::Vector2f(200, 600), 1);

	manager->addPlayer(std::move(plr));
	manager->addEnemy(std::move(monster));
	manager->addEnemy(std::move(monster2));

	manager->addInteractable(std::move(potion));
	manager->addInteractable(std::move(key));

	map.createMap(manager, 1);

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

		window.display();
	}

	return 0;
}