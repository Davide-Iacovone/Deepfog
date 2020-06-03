#include "Player.h"

Player::Player(float x, float y, sf::Texture& texture)
{
	this->setPosition(x, y);

	this->createMovementEngine(100.f);
	this->createAnimationEngine(texture);

	this->animationEngine->addAnimation("player_normal", 0, 0, 3, 0, 48, 48, 100.f);
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
	this->animationEngine->play("player_normal", time);
}


