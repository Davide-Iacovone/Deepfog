#pragma once
#include "State.h"

#include <iostream>

class GameState : public State
{
protected:
	Entity player;
public:
	GameState(sf::RenderWindow* window, std::stack<State*>* States);
	~GameState();

	void playerMovement(Entity player, float time);
	void handleEnd();
	void updateKeyboard(float time);
	void show(sf::RenderTarget* target);
	void update(float time);
};

