#include "MovementEngine.h"

MovementEngine::MovementEngine(sf::Sprite& sprite, float maxSpeed) : sprite(sprite), maxSpeed(maxSpeed)
{
}

MovementEngine::~MovementEngine()
{
}

sf::Vector2f MovementEngine::getSpeed()
{
	return this->speed;
}

bool MovementEngine::isMoving()
{
	if (speed.x == 0.f && speed.y == 0.f)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void MovementEngine::move(float x, float y, float time)
{
	this->speed.x = this->maxSpeed * x;
	this->speed.y = this->maxSpeed * y;
	this->sprite.move(this->speed * time);
}

void MovementEngine::update(float time)
{

}

	

	

