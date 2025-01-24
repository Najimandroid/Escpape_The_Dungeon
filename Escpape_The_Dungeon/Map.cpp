#include <SFML/Graphics.hpp>


#include "Map.h"
#include "Door.h"
#include "Stalker.h"
#include "Wanderer.h"
#include "Key.h"
#include "Potion.h"

#include <memory>
#include <sstream>
#include <string>
#include <vector>

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

void Map::createMap(EntityManager* manager, sf::Vector2i indexVector)
{
	std::string mapCoord = '(' + std::to_string(indexVector.x) + ',' + std::to_string(indexVector.y) + ')';
	std::string pathToLoad = m_filePath + mapCoord + ".txt";
	LOG(mapCoord)
	std::ifstream file(pathToLoad);
	//file.open(pathToLoad);

	if (!file.is_open())
	{
		LOG("COULDN'T LOAD FILE MAP");
		return;
	}
	else
	{
		LOG("LOADED FILE MAP");

		std::vector<std::string> mapContent;
		std::string str;
		char ch;

		while (file.get(ch))
		{
			if (ch == ' ' || ch == '\n')
			{
				if (!str.empty())
				{
					mapContent.push_back(str);
					str.clear();
				}
			}
			else
			{
				str += ch;
			}
		}

		if (!str.empty()) {
			mapContent.push_back(str);
		}

		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 15; x++)
			{
				sf::Vector2f spawnPos = sf::Vector2f(TILE_SIZE_PX * (float)x + TILE_SIZE_PX, TILE_SIZE_PX * (float)y + TILE_SIZE_PX/2.f);
				//LOG(mapContent[x + 15 * y])
				if (mapContent[x + 15 * y] == "#") //WALL
				{
					auto newWall = std::make_unique<Wall>(spawnPos);
					manager->addWall(std::move(newWall));
				}				
				else if (mapContent[x + 15 * y] == "s") //STALKER
				{
					auto stalker = std::make_unique<Stalker>(spawnPos, sf::Vector2f(50, 50), manager->getPlayers()[0].get());
					manager->addEnemy(std::move(stalker));
				}
				/*else if (mapContent[x + 15 * y].find("w") == 0) //WANDERER
				{
					if (mapContent[x + 15 * y].length() > 2)
					{
						std::string door_id_str = mapContent[x + 15 * y].substr(2);
					}
				}*/
				else if (mapContent[x + 15 * y].find("[]") == 0) //DOOR
				{
					bool doorOpened = false;

					if (mapContent[x + 15 * y].length() > 2)
					{
						std::string door_id_str = mapContent[x + 15 * y].substr(2);
						int key_id = std::stoi(door_id_str);

						std::vector<int> plrOpenedIds = manager->getPlayers()[0]->getOpenedIDs();
						for (int id : plrOpenedIds)
						{
							//LOG(id);
							if (id == key_id) { doorOpened = true; break; }
						}


						if (!doorOpened)
						{
							auto newDoor = std::make_unique<Door>(spawnPos, key_id);
							manager->addWall(std::move(newDoor));
						}
					}
				}
				else if (mapContent[x + 15 * y].find("k") == 0) //KEY
				{
					bool keyColected = false;

					if (mapContent[x + 15 * y].length() > 1)
					{
						std::string id_str = mapContent[x + 15 * y].substr(1);
						int key_id = std::stoi(id_str);

						std::vector<int> plrOpenedIds = manager->getPlayers()[0]->getOpenedIDs();
						for (int id : plrOpenedIds)
						{
							//LOG(id);
							if (id == key_id) { keyColected = true; break; }
						}


						if (!keyColected)
						{
							auto newKey = std::make_unique<Key>(spawnPos, key_id);
							manager->addInteractable(std::move(newKey));
						}
					}
				}
			}
		}
	}
}
