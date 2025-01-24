#include "Interactable.h"
#include "Logger.h"

Interactable::Interactable()
{
	m_position = { 0, 0 };

	m_health = 1;
	m_damage = 0;
	m_speed = 0;

	m_interacted = false;

	initHitbox({ 40, 40 });
	m_hitbox.setOrigin(m_hitbox.getSize() / 2.f);
	initSprite();
	m_sprite.setScale({ .4f, .4f });
	m_sprite.setOrigin({ (m_hitbox.getSize().x / 2.f) * m_sprite.getScale().x , (m_hitbox.getSize().y / 2.f) * m_sprite.getScale().y });

	m_hitbox.setFillColor(sf::Color::Magenta);
}

Interactable::Interactable(sf::Vector2f spawnPosition)
{
	m_position = spawnPosition;

	m_health = 1;
	m_damage = 0;
	m_speed = 0;

	m_interacted = false;

	initHitbox({ 40, 40 });
	m_hitbox.setOrigin(m_hitbox.getSize() / 2.f);
	initSprite();
	m_sprite.setScale({ .4f, .4f });
	m_sprite.setOrigin({ 48.f, 48.f });

	m_hitbox.setFillColor(sf::Color::Magenta);
}

Interactable::Interactable(Interactable&& other)
{
	m_position = std::move(other.m_position);
	m_health = std::move(other.m_health);
	m_damage = std::move(other.m_damage);
	m_speed = std::move(other.m_speed);
	m_hitbox = std::move(other.m_hitbox);
	m_sprite = std::move(other.m_sprite);
	m_interacted = std::move(other.m_interacted);
}

void Interactable::interact(Player& player, const std::vector<std::unique_ptr<Wall>>& walls)
{
	if (m_interacted) return;
	LOG("Interacted");
	m_interacted = true;
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

void Interactable::initSprite()
{
}
