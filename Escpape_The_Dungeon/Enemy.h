#pragma once

#include "SFML/Graphics.hpp"

#include "Entity.h"

class Enemy : public Entity
{
public:

	Enemy();
	Enemy(sf::Vector2f spawnPosition, sf::Vector2f hitboxSize);

	virtual void update(sf::RenderWindow& window, float deltaTime) override;
	void draw(sf::RenderWindow& window) override;

protected:

	void initHitbox(sf::Vector2f hitboxSize);
	void initSprite();
};

class Stalker : public Enemy
{
public:
	Stalker();
	Stalker(sf::Vector2f spawnPosition, sf::Vector2f hitboxSize, Entity* target);

	void update(sf::RenderWindow& window, float deltaTime) override;

	void followEntity(Entity* followedEntity, float deltaTime);

private:
	Entity* m_target;
};