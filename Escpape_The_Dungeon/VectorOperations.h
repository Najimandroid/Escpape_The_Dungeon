#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

sf::Vector2f operator*(sf::Vector2f aVec, sf::Vector2f bVec)
{
	sf::Vector2f newVector = { aVec.x * bVec.x, aVec.y * bVec.y };
	return newVector;
}

sf::Vector2f normalize(const sf::Vector2f& vec)
{
    float magnitude = std::sqrt(vec.x * vec.x + vec.y * vec.y); 
    if (magnitude == 0)
    {
        return sf::Vector2f(0, 0); 
    }
    return sf::Vector2f(vec.x / magnitude, vec.y / magnitude);
}