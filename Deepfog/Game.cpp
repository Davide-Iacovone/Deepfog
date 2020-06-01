#include "Game.h"

Game::Game()
{
	this->setupWindow();
	this->setupStates();
}

Game::~Game()
{
	delete this->window;
	while (!this->States.empty())
	{
		delete this->States.top();
		this->States.pop();
	}
}

void Game::setupWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1000, 800), "Deepfog");
}

void Game::setupStates()
{
	this->States.push(new GameState(this->window));
}

void Game::checkForEvents()
{
	while (this->window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window->close();
		}
	}

	if (!this->States.empty())
	{
		this->States.top()->update(this->time);
		if (this->States.top()->getEnd())
		{
			this->States.top()->handleEnd();
			delete this->States.top();
			this->States.pop();
		}
	}
	else
	{
		this->window->close();
	}
}

void Game::show()
{
	this->window->clear(sf::Color::Black);
	if (!this->States.empty())
	{
		this->States.top()->show(this->window);
	}
	this->window->display();
}


void Game::running()
{
	while (this->window->isOpen())
	{
		this->timeMeasurment();
		this->checkForEvents();
		this->show();
	}
}

float Game::getTime()
{
	return time;
}


void Game::timeMeasurment()
{
	time = clock.restart().asSeconds();
}
