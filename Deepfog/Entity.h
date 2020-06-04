#pragma once

#include <iostream>
#include <stack>

#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "CollisionEngine.h"
#include "MovementEngine.h"
#include "AnimationEngine.h"

class Entity
{
protected:
	sf::Texture* texture;
	sf::Sprite sprite;
	CollisionEngine* collisionEngine;
	MovementEngine* movementEngine;
	AnimationEngine* animationEngine;

public:
	Entity();
	~Entity();

	void CreateSprite(sf::Texture& texture);
	void createMovementEngine(float maxSpeed);
	void createAnimationEngine(sf::Texture& sheets);
	void createCollisionEngine(sf::Sprite& sprite, float x, float y, float width, float height);
	void setPosition(float x, float y);

	virtual void move(const float time, const float x, const float y);
	virtual void show(sf::RenderTarget& target);
	virtual void update(const float time);
};

