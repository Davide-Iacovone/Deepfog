#include "Entity.h"

Entity::Entity()
{
	this->texture = NULL;
	this->animationEngine = NULL;
	this->movementEngine = NULL;
	this->collisionEngine = NULL;
}

Entity::~Entity()
{
	delete this->collisionEngine;
	delete this->movementEngine;
	delete this->animationEngine;
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

void Entity::createAnimationEngine(sf::Texture& sheets)
{
	this->animationEngine = new AnimationEngine(this->sprite, sheets);
}

void Entity::createCollisionEngine(sf::Sprite& sprite, float x, float y, float width, float height)
{
	this->collisionEngine = new CollisionEngine(sprite, 0, 0, width, height);
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

void Entity::show(sf::RenderTarget& target)
{
		target.draw(this->sprite);
		if (this->animationEngine)
		{
			this->collisionEngine->show(target);
		}
}

void Entity::update(const float time)
{
}
