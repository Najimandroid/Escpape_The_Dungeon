#include "Interactable.h"

Interactable::Interactable()
{
	m_position = { 0, 0 };

	m_health = 1;
	m_damage = 0;
	m_speed = 0;

	m_interacted = false;

	initHitbox({ 25, 25 });
	initSprite();

	m_hitbox.setFillColor(sf::Color::Magenta);
}

Interactable::Interactable(sf::Vector2f spawnPosition)
{
	m_position = spawnPosition;

	m_health = 1;
	m_damage = 0;
	m_speed = 0;

	m_interacted = false;

	initHitbox({ 25, 25 });
	initSprite();

	m_hitbox.setFillColor(sf::Color::Magenta);
}

////////////////
//* UPDATING *\\
////////////////

void Interactable::update(sf::RenderWindow& window, float deltaTime)
{
	if (!m_interacted) draw(window);
}

////////////////
//* GRAPHICS *\\
////////////////

void Interactable::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
	drawHitbox(window);
}
