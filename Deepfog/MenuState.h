#pragma once
#include "State.h"
#include "Button.h"
#include "GameState.h"

class MenuState : public State
{
protected:
	sf::Font font;
	std::vector<Button*> buttons;
	sf::RectangleShape background;
	sf::Texture backgroundTexture;

public:
	MenuState(sf::RenderWindow* window, std::stack<State*>* States);
	~MenuState();

	void handleEnd();
	void initMenu();
	void initBackground();
	void showButtons(sf::RenderTarget* target);
	void updateButtons();
	void updateKeyboard(float time);
	void show(sf::RenderTarget* target);
	void update(float time);
};

