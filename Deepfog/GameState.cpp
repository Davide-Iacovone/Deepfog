#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) : State(window)
{

}

GameState::~GameState()
{
}

void GameState::handleEnd()
{
	
}

void GameState::updateKeyboard(sf::Time time)
{
	this->end();
}

void GameState::show(sf::RenderTarget* target)
{
	
}

void GameState::update(sf::Time time)
{
	this->updateKeyboard(time);
}
