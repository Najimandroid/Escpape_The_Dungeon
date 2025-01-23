#pragma once
#include <SFML/Graphics.hpp>
#include "EntityManager.h"

#include <fstream>


//MAP 9X15 TILES

class Map
{
public:

	//void loadMap();
	void createMap(EntityManager* manager, sf::Vector2i indexVector);

private:
	//15*9 = 135

	const int TILE_SIZE_PX = 120;
	const char* m_filePath = "assets/rooms/Room"; //..1,2,3..etc
};