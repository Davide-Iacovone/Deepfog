#include "GameState.h"

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* States) : State(window, States)
{
	this->initResources();
	this->initPlayer();
}

GameState::~GameState()
{
	delete player;
}

void GameState::initResources()
{
	sf::Texture t1;
	t1.loadFromFile("textures/player.png");
	this->resources["player_normal"] = t1;
}

void GameState::initPlayer()
{
	this->player = new Player(0, 0, this->resources["player_normal"]);
}

void GameState::playerMovement(Player *player, float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->player->move(time, 0.f, -1.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->player->move(time, 0.f, 1.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->player->move(time, -1.f, 0.f);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->player->move(time, 1.f, 0.f);
	else
		this->player->move(time, 0.f, 0.f);
}

void GameState::handleEnd()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->quit = true;
	}
}

void GameState::updateKeyboard(float time)
{
	this->playerMovement(player, time);
}

void GameState::show(sf::RenderTarget* target)
{
	this->map.show(*target);
	this->player->show(*target);
}

void GameState::update(float time)
{
	this->handleEnd();
	this->updateKeyboard(time);
	this->player->update(time);
}
