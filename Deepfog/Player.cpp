#include "Player.h"

Player::Player(float x, float y, sf::Texture& texture)
{
	this->CreateSprite(texture);
	this->setPosition(x, y);
	this->initEngines();
}

Player::~Player()
{
	
}

void Player::initEngines()
{
	this->createMovementEngine(100.f);
}


