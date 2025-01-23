#include "Key.h"
#include "Logger.h"
#include "Door.h"

Key::Key(sf::Vector2f spawnPosition, int doorID)
{
	m_position = spawnPosition;
	m_doorID = doorID;

	m_hitbox.setFillColor(keyColors[doorID]);

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