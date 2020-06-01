#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) : State(window)
{

}

GameState::~GameState()
{
}

void GameState::playerMovement(Entity player, float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player.move(time, 0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player.move(time, 0.f, 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player.move(time, -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player.move(time, 1.f, 0.f);
}

void GameState::handleEnd()
{
	
}

void GameState::updateKeyboard(float time)
{
	this->end();
	this->playerMovement(player, time);
}

void GameState::show(sf::RenderTarget* target)
{
	this->player.show(this->window);
}

void GameState::update(float time)
{
	this->updateKeyboard(time);
	this->player.update(time);
}
