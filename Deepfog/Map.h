#pragma once

#include "Tile.h"

class Map
{
private:
	float gridSize;
	int layers;
	sf::Vector2f size;
	std::vector<std::vector<std::vector<Tile>>> map;
	sf::Texture texture;

public:
	Map();
	~Map();

	void update();
	void show(sf::RenderTarget& target);
};

