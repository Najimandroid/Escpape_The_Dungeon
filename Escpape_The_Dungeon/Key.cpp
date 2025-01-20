#include "Key.h"
#include "Logger.h"

Key::Key(sf::Vector2f spawnPosition, Door* target)
{
	m_position = spawnPosition;
	m_target = target;

	m_hitbox.setFillColor(sf::Color::Yellow);

	updatePosition(m_position);
}

void Key::interact(Player& player)
{
	if (m_interacted) return;

	LOG("OPEN DOOR");

	m_interacted = true;
}