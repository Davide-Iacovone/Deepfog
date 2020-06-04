#include "Map.h"

Map::Map()
{
	this->texture.loadFromFile("textures/576.jpg");
	this->gridSize = 50.f;
	this->size.x = 20;
	this->size.y = 20;
	this->layers = 1;
	this->map.resize(this->size.x);

	for (size_t x = 0; x < this->size.x; x++)
	{
		this->map.emplace_back(std::vector<std::vector<Tile>>());
		for (size_t y = 0; y < this->size.y; y++)
		{
			this->map[x].resize(this->size.y);
			this->map[x].emplace_back(std::vector<Tile>());
			for (size_t z = 0; z < this->layers; z++)
			{
				this->map[x][y].resize(this->layers);
				this->map[x][y].emplace_back(Tile(x * this->gridSize, y * this->gridSize, this->gridSize, this->texture));
			}
		}
	}
}

Map::~Map()
{
}


void Map::update()
{
}

void Map::show(sf::RenderTarget& target)
{
	for (auto& x : this->map)
	{
		for (auto& y : x)
		{
			for (auto& z : y)
			{
				z.show(target);
			}
		}
	}
}
