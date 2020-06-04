#include "Tile.h"

Tile::Tile()
{
}

Tile::Tile(float x, float y, float gridSize, const sf::Texture& texture)
{
	this->shape.setSize(sf::Vector2f(gridSize, gridSize));
	this->shape.setPosition(x, y);
	this->shape.setTexture(&texture);
}

Tile::~Tile()
{

}

void Tile::show(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
