#pragma once

#include <iostream>
#include <stack>

#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class Entity
{
protected:
	sf::RectangleShape shape;
	float speed;

public:
	Entity();
	~Entity();

	virtual void move(const float time, const float x, const float y);

	virtual void show(sf::RenderTarget* target);
	virtual void update(const float time);
};

