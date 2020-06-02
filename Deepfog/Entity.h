#pragma once

#include <iostream>
#include <stack>

#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "MovementEngine.h"

class Entity
{
protected:
	sf::Texture* texture;
	sf::Sprite sprite;
	MovementEngine* movementEngine;

public:
	Entity();
	~Entity();

	void CreateSprite(sf::Texture& texture);
	void createMovementEngine(float maxSpeed);
	void setPosition(float x, float y);

	virtual void move(const float time, const float x, const float y);
	virtual void show(sf::RenderTarget* target);
	virtual void update(const float time);
};

