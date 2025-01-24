#pragma once
#include <SFML/Graphics.hpp>

class Clock
{
public:
	Clock();
	Clock(float timeInSeconds);

	void updateClock(sf::RenderWindow& window, float deltaTime);

	float getTime() { return m_time; }

private:

	void loadFont();

private:

	float m_time;
	sf::Font m_font;
	sf::Text m_text;
};