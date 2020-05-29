#include "State.h"

State::State(sf::RenderWindow* window)
{
	this->window = window;
	this->quit = false;
}

State::~State()
{

}

const bool& State::getEnd() const
{
	return this->quit;
}

void State::end()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->quit = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		std::cout << "A" << std::endl;
	}
}
