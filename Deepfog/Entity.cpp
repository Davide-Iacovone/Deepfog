#include "Entity.h"

Entity::Entity()
{
	this->sprite = NULL;
	this->texture = NULL;
	this->speed = 100.f;
}

Entity::~Entity()
{
}

void Entity::CreateSprite(sf::Texture* texture)
{
	this->texture = texture;
	this->sprite->setTexture(*this->texture);
}

void Entity::move(const float time, const float x, const float y)
{
	if (this->sprite)
	{
		this->sprite->move(x * this->speed * time, y * this->speed * time);
	}
	
}

void Entity::show(sf::RenderTarget* target)
{
	if (this->sprite)
	{
		target->draw(*this->sprite);
	}
}

void Entity::update(const float time)
{
}
