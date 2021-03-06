#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(float x, float y, sf::Texture& texture);
	~Player();

	void initEngines();
	void update(const float time);
};

