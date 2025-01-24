#include <SFML/Graphics.hpp>

#include <iostream>
#include <thread>

#include "EntityManager.h"
#include "Map.h"
#include "Clock.h"

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

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Escape The Dungeon", sf::Style::Fullscreen);
	window.setFramerateLimit(60);

	EntityManager* manager = EntityManager::getInstance();

	bool isOnMenu = true;
	bool isRunning = false;

	//MENU
	sf::Font menuFont;
	sf::Text gameTitle, playTitle, gameOverTitle;
	if (!menuFont.loadFromFile("assets/fonts/Pixel.ttf"))
	{
		LOG("COULDN'T LOAD MENU FONT")
	}

	sf::Clock clock;
	float deltaTime = 0.f;

	Clock timer(120);
	Map map;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		window.clear();

		sf::Event event;
		while (window.pollEvent(event))
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

		if (isOnMenu)
		{
			gameTitle.setCharacterSize(100);
			gameTitle.setFillColor(sf::Color::White);
			gameTitle.setFont(menuFont);
			gameTitle.setString("Escape The Dungeon");
			gameTitle.setOrigin(gameTitle.getLocalBounds().width / 2, gameTitle.getLocalBounds().height / 2);
			gameTitle.setPosition({ 1920 / 2.f, 300 });

			playTitle.setCharacterSize(80);
			playTitle.setFillColor(sf::Color::Green);
			playTitle.setFont(menuFont);
			playTitle.setString("-PLAY-");
			playTitle.setOrigin(playTitle.getLocalBounds().width / 2, playTitle.getLocalBounds().height / 2);
			playTitle.setPosition({ 1920 / 2.f, 500 });


			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			if (playTitle.getGlobalBounds().contains(mousePos.x, mousePos.y))
			{
				
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					isRunning = true;
					isOnMenu = false;
					
					auto plr = std::make_unique<Player>(sf::Vector2f(1920 / 2, 1080 / 2), sf::Vector2f(50, 50));
					manager->addPlayer(std::move(plr));

					map.createMap(manager, { 0, 0 });
				}
				else
				{
					playTitle.setFillColor(sf::Color::Yellow);
				}
			}
			else
			{
				playTitle.setFillColor(sf::Color::Green);
			}


			window.draw(gameTitle);
			window.draw(playTitle);
		}

		if (isRunning)
		{
			manager->updateEntities(window, deltaTime);
			timer.updateClock(window, deltaTime);

			if (manager->isEnemyCollisionDetected() || timer.getTime() <= 0)
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
				player->setPosition({ player->getPosition().x, player->getPosition().y - 1080.f });

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
		}

		window.display();
		if (!isRunning && !isOnMenu) {
			manager->getPlayers()[0].get()->death(); manager->getPlayers()[0].get()->draw(window); std::this_thread::sleep_for(std::chrono::milliseconds(500));

		gameOverTitle.setCharacterSize(150);
		gameOverTitle.setFillColor(sf::Color::Red);
		gameOverTitle.setFont(menuFont);
		gameOverTitle.setString("GAME OVER");
		gameOverTitle.setOrigin(gameOverTitle.getLocalBounds().width / 2, gameOverTitle.getLocalBounds().height / 2);
		gameOverTitle.setPosition({ 1920 / 2.f, 500 });

		window.clear();
		window.draw(gameOverTitle);
		window.display();

		std::this_thread::sleep_for(std::chrono::seconds(2));
		window.clear();

		break; }
	}
	return 0;
}