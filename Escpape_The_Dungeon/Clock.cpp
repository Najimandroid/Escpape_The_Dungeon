#include "Clock.h"
#include "Logger.h"

#include <chrono>

Clock::Clock()
{
	m_time = 10;
	m_text.setPosition({ 0, 0 });

	loadFont();
}

Clock::Clock(float timeInSeconds)
{
	m_time = timeInSeconds;
	m_text.setPosition({ 0, 0 });

	loadFont();
}

void Clock::updateClock(sf::RenderWindow& window, float deltaTime)
{
	m_time -= deltaTime;

	if (m_time < 0) m_time = 0;

	m_text.setString("Temps restant: " + std::to_string((int)m_time) + "s");
	window.draw(m_text);

}

void Clock::loadFont()
{
	//not working on debug
	if (!m_font.loadFromFile("assets/fonts/Pixel.ttf"))
	{
		LOG("COULDN'T LOAD CLOCK FONT")
	}
	m_text.setCharacterSize(50);
	m_text.setFillColor(sf::Color::Red);
	m_text.setFont(m_font);
}
