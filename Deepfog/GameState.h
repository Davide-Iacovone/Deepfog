#pragma once
#include "State.h"
#include "Player.h"
#include "Map.h"

#include <iostream>

class GameState : public State
{
protected:
	Player *player;
	Map map;
public:
	GameState(sf::RenderWindow* window, std::stack<State*>* States);
	~GameState();

	void initResources();
	void initPlayer();
	void playerMovement(Player* player, float time);
	void handleEnd();
	void updateKeyboard(float time);
	void show(sf::RenderTarget* target);
	void update(float time);
};

