#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

#include <iostream>
#include <vector>
#include <map>

class Tile
{
protected:
	sf::RectangleShape shape;

public:
	Tile();
	Tile(float x, float y, float gridSize, const sf::Texture& texture);
	~Tile();

	void show(sf::RenderTarget& target);
};

