#include "Player.h"

Player::Player(float x, float y, sf::Texture& texture)
{
	this->setPosition(x, y);

	this->createCollisionEngine(this->sprite, 0.f, 0.f, 48.f, 48.f);
	this->createMovementEngine(100.f);
	this->createAnimationEngine(texture);

	this->animationEngine->addAnimation("player_normal", 0, 0, 3, 0, 48, 48, 100.f);
	this->animationEngine->addAnimation("player_walk", 0, 1, 5, 1, 48, 48, 100.f);
}

Player::~Player()
{
	
}

void Player::initEngines()
{
}

void Player::update(const float time)
{
	this->movementEngine->update(time);
	if (this->movementEngine->isMoving())
	{
		this->animationEngine->play("player_walk", time);
	}
	else
	{
		this->animationEngine->play("player_normal", time);
	}
	this->collisionEngine->update();
}


