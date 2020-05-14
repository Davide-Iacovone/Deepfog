#include "Game.h"

Game::Game()
{
	this->setupWindow();
}

Game::~Game()
{
	delete this->window;
}

void Game::setupWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1000, 800), "Deepfog");
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
}

void Game::show()
{
	this->window->clear(sf::Color::Black);
	this->window->display();
}


void Game::running()
{
	while (this->window->isOpen())
	{
		this->checkForEvents();
		this->show();
	}
}
