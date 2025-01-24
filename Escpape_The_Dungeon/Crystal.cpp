#include "Crystal.h"
#include "Logger.h"

Crystal::Crystal(sf::Vector2f spawnPosition)
{
	m_position = spawnPosition;

	initSprite();
	m_sprite.setScale({ .4f, .4f });
	m_sprite.setOrigin({ 48.f, 48.f });
	m_hitbox.setOrigin(m_hitbox.getSize() / 2.f);

	updatePosition(m_position);
}

void Crystal::interact(Player& player, const std::vector<std::unique_ptr<Wall>>& walls)
{
	if (m_interacted) return;

	player.makeWin();

	m_interacted = true;
}

void Crystal::initSprite()
{
	if (!m_texture.loadFromFile("assets/textures/Crystal.png"))
	{
		LOG("COULDN'T LOAD KEY TEXTURE")
	}
	m_sprite.setTexture(m_texture);
	updatePosition(m_position);
}