#pragma once
#include <SFML/Graphics.hpp>

sf::Vector2f operator*(sf::Vector2f right, float left)
{
	sf::Vector2f newVector = { right.x * left, right.y * left };
	return newVector;
}