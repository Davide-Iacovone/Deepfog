#include "Entity.h"

Entity::Entity()
{
	this->texture = NULL;
	this->movementEngine = NULL;
}

Entity::~Entity()
{
}

void Entity::CreateSprite(sf::Texture& texture)
{
		this->texture = &texture;
		this->sprite.setTexture(texture);
}

void Entity::createMovementEngine(float maxSpeed)
{
	this->movementEngine = new MovementEngine(this->sprite, maxSpeed);
}

void Entity::setPosition(float x, float y)
{
		this->sprite.setPosition(x, y);
}

void Entity::move(const float time, const float x, const float y)
{
	if (this->movementEngine)
	{
		this->movementEngine->move(x, y, time);
	}
}

void Entity::show(sf::RenderTarget* target)
{
		target->draw(this->sprite);
}

void Entity::update(const float time)
{
}
