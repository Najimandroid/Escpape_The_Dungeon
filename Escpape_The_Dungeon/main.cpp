#include <SFML/Graphics.hpp>

#include <iostream>

#include "Entity.h"
#include "Player.h"
#include "Stalker.h"
#include "Wanderer.h"

#include "Potion.h"
#include "Key.h"

#include "Logger.h"




int main()
{
#ifdef _DEBUG 
	std::cout << "---[DEBUG MODE]---\n";
#endif

	bool isRunning = true;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Escape the Dungeon");
	window.setFramerateLimit(60);

	Player plr({ 1920 / 2, 1080 / 2 }, { 50, 50 });
	Stalker monster({ 500, 500 }, { 50, 50 }, &plr);

	sf::Vector2f pointsList[4] = {sf::Vector2f(50, 50), sf::Vector2f(50, 1000), sf::Vector2f(1000, 1000),  sf::Vector2f(1000, 50)};
	Wanderer monster2({ 0, 0 }, { 50, 50 }, pointsList, 4);
	
	Potion potion({ 200, 200 }, 1.5f);
	Key key({ 200, 500 }, nullptr);

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

		plr.update(window, deltaTime);
		monster.update(window, deltaTime);
		monster2.update(window, deltaTime);
		potion.update(window, deltaTime);
		key.update(window, deltaTime);

		if (plr.collide(&monster2) || plr.collide(&monster))
		{
			LOG("GAME OVER!");
			isRunning = false;
		}

		if (plr.collide(&potion))
		{
			potion.interact(plr);
		}

		if (plr.collide(&key))
		{
			key.interact(plr);
		}

		window.display();
	}

	return 0;
}