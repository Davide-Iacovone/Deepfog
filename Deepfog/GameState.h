#pragma once
#include "State.h"

#include <iostream>

class GameState : public State
{
public:
	GameState(sf::RenderWindow* window);
	~GameState();

	void handleEnd();
	void updateKeyboard(sf::Time time);
	void show(sf::RenderTarget* target);
	void update(sf::Time time);
};

