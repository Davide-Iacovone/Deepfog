#include "MenuState.h"

MenuState::MenuState(sf::RenderWindow* window, std::stack<State*>* States) : State(window, States)
{
	this->initBackground();
	this->initMenu();
	this->font.loadFromFile("TenaliRamakrishna-Regular.ttf");
}

MenuState::~MenuState()
{
	for (auto i : buttons)
	{
		delete i;
	}
}

void MenuState::handleEnd()
{
	for (auto i : buttons)
	{
		i->setPressed();
	}
}

void MenuState::initMenu()
{
	this->buttons.emplace_back(new Button(100, 100, 150, 50, &this->font, "New Game", sf::Color::White, sf::Color(194, 214, 214)));
	this->buttons.emplace_back(new Button(100, 300, 150, 50, &this->font, "Exit", sf::Color::White, sf::Color(194, 214, 214)));
}

void MenuState::initBackground()
{
	this->background.setSize(sf::Vector2f(this->window->getSize().x, this->window->getSize().y));
	this->backgroundTexture.loadFromFile("textures/background.jpg");
	this->background.setTexture(&backgroundTexture);
}

void MenuState::showButtons(sf::RenderTarget* target)
{
	for (auto &i : buttons)
	{
		i->show(*target);
	}
}

void MenuState::updateButtons()
{
	for (auto i : buttons)
	{
		i->update(mouseMap);
	}

	if (this->buttons[0]->isPressed())
	{
		this->handleEnd();
		this->States->push(new GameState(this->window, this->States));
	}

	if (this->buttons[1]->isPressed())
	{
		this->quit = true;
	}
}

void MenuState::updateKeyboard(float time)
{
	this->mousePosition();
}

void MenuState::show(sf::RenderTarget* target)
{
	target->draw(this->background);
	this->showButtons(target);
}

void MenuState::update(float time)
{
	this->updateKeyboard(time);
	this->updateButtons();
}
