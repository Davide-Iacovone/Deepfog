#pragma once
#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class MovementEngine
{
private:
	float maxSpeed;
	sf::Vector2f speed;
	sf::Vector2f acceleration;
	sf::Sprite& sprite;
	
public:
	MovementEngine(sf::Sprite& sprite, float maxSpeed);
	~MovementEngine();

	sf::Vector2f getSpeed();

	void move(float x, float y, float time);
	void update(float time);
};

