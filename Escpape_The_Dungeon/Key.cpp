#include "Key.h"
#include "Logger.h"
#include "Door.h"

Key::Key(sf::Vector2f spawnPosition, int doorID)
{
	m_position = spawnPosition;
	m_doorID = doorID;

	initSprite();
	m_sprite.setScale({ .4f, .4f });
	m_sprite.setOrigin({ 48.f, 48.f });
	m_sprite.setColor(keyColors[doorID]);
	m_hitbox.setOrigin(m_hitbox.getSize() / 2.f);

	updatePosition(m_position);
}

void Key::interact(Player& player, const std::vector<std::unique_ptr<Wall>>& walls)
{
	if (m_interacted) return;

	for (auto& wall : walls)
	{
		Door* door = dynamic_cast<Door*>(wall.get());

		if (door)
		{
			LOG("Door found");
			door->unlock(m_doorID);
			player.addOpenedID(m_doorID);
		}
	}

	m_interacted = true;
}

void Key::initSprite()
{
	if (!m_texture.loadFromFile("assets/textures/Key.png"))
	{
		LOG("COULDN'T LOAD KEY TEXTURE")
	}
	m_sprite.setTexture(m_texture);
	updatePosition(m_position);
}