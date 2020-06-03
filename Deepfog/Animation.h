#pragma once

#include <map>
#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
class Animation
{
public:
	float speed;
	float timer;
	sf::Sprite& sprite;
	sf::Texture& sheets;
	sf::IntRect current;
	sf::IntRect start;
	sf::IntRect end;
	int width;
	int height;

	Animation(sf::Sprite& sprite, sf::Texture& sheets, int start_x, int start_y, int end_x, int end_y, int width, int height, float speed);


	void update(float time);
};

