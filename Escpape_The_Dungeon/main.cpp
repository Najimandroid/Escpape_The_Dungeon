#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{

	sf::RenderWindow window(sf::VideoMode(1600, 1080), "Escape the Dungeon");

	sf::RectangleShape rect({ 50, 50 });
	rect.setFillColor(sf::Color::Green);
	
	while (window.isOpen())
	{
		window.clear();

		sf::Event event;
		while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.draw(rect);
		window.display();
	}

	return 0;
}