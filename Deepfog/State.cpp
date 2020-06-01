#include "State.h"

State::State(sf::RenderWindow* window, std::stack<State*>* States)
{
	this->window = window;
	this->quit = false;
	this->States = States;
}

State::~State()
{

}

const bool& State::getEnd() const
{
	return this->quit;
}

void State::mousePosition()
{
	this->mouseScreen = sf::Mouse::getPosition();
	this->mouseWindow = sf::Mouse::getPosition(*this->window);
	this->mouseMap = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));
}
