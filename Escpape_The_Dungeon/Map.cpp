#include <SFML/Graphics.hpp>


#include "Map.h"
#include "Wall.h"

#include <memory>

/*
void Map::loadMap()
{
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			if (m_map[x + 15 * y] == 1)
			{
				sf::RectangleShape tile({ 50.0f, 50.0f });
				tile.setPosition({ x * 50.0f, y * 50.0f });
				tile.setFillColor(sf::Color::White);
			}
		}
	}
}*/

void Map::createMap(EntityManager* manager)
{
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			if (m_map[x + 15 * y] == 1)
			{
				auto newWall = std::make_unique<Wall>(sf::Vector2f(100.f * (float)x, 100.f * (float)y));
				manager->addWall(std::move(newWall));
			}
		}
	}
}
