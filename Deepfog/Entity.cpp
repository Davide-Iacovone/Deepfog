#include "Entity.h"

Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->shape.setFillColor(sf::Color::Green);
	this->speed = 100.f;
}

Entity::~Entity()
{
}

void Entity::move(const float time, const float x, const float y)
{
	this->shape.move(x * this->speed * time, y * this->speed * time);
}

void Entity::show(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

void Entity::update(const float time)
{
}
