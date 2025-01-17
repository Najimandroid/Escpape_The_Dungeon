#include <SFML/Graphics.hpp>
#include <iostream>

#include "Entity.h"
#include "Player.h"




int main()
{
#ifdef _DEBUG 
	std::cout << "---[DEBUG MODE]---\n";
#endif

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Escape the Dungeon");
	window.setFramerateLimit(60);

	Player plr({ 1920 / 2, 1080 / 2 }, { 50, 50 });
	
	sf::Clock clock;
	float deltaTime = 0.f;

	while (window.isOpen())
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

		plr.update(deltaTime);
		plr.draw(window);

		window.display();
	}

	return 0;
}