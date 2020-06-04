#include "CollisionEngine.h"

CollisionEngine::CollisionEngine(sf::Sprite& sprite, float x, float y, float width, float height)
	: sprite(sprite), x(x), y(y)
{
	this->boundry.setPosition(this->sprite.getPosition().x + x, this->sprite.getPosition().y + y);
	this->boundry.setSize(sf::Vector2f(width, height));
	this->boundry.setFillColor(sf::Color::Transparent);
	this->boundry.setOutlineThickness(1.f);
	this->boundry.setOutlineColor(sf::Color::Green);
}

CollisionEngine::~CollisionEngine()
{
}

bool CollisionEngine::checkCollision(sf::FloatRect& f)
{
	return this->boundry.getGlobalBounds().intersects(f);
}

void CollisionEngine::update()
{
	this->boundry.setPosition(this->sprite.getPosition().x + this->x, this->sprite.getPosition().y + this->y);
}

void CollisionEngine::show(sf::RenderTarget& target)
{
	target.draw(this->boundry);
}
