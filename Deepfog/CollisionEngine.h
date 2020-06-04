#pragma once

#include <iostream>
#include <stack>

#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class CollisionEngine
{
private:
	sf::Sprite& sprite;
	sf::RectangleShape boundry;
	float x;
	float y;

public:
	CollisionEngine(sf::Sprite& sprite, float x, float y, float width, float height);
	~CollisionEngine();

	bool checkCollision(sf::FloatRect& f);

	void update();
	void show(sf::RenderTarget& target);
};

