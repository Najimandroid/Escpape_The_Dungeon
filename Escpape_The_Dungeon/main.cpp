#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entity.h"
#include "Player.h"
#include "Enemy.h"




int main()
{
#ifdef _DEBUG 
	std::cout << "---[DEBUG MODE]---\n";
#endif

	bool isRunning = true;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Escape the Dungeon");
	window.setFramerateLimit(60);

	Player plr({ 1920 / 2, 1080 / 2 }, { 50, 50 });
	Enemy monster({ 500, 500 }, { 50, 50 });
	
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
		}

		plr.update(window, deltaTime);
		monster.update(window, deltaTime);

		if (plr.collide(&monster)) 
		{
			std::cout << "GAME OVER!\n";
			isRunning = false;
		}

		window.display();
	}

	return 0;
}