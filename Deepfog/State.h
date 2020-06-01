#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "Entity.h"

#include <iostream>
#include <vector>
#include <stack>

class State
{
protected:
	sf::RenderWindow* window;
	sf::Vector2i mouseScreen;
	sf::Vector2i mouseWindow;
	sf::Vector2f mouseMap;
	std::stack<State*>* States;
	bool quit;

public:


	State(sf::RenderWindow* window, std::stack<State*>* states);
	~State();

	const bool& getEnd() const;
	virtual void mousePosition();

	virtual void handleEnd() = 0;
	virtual void updateKeyboard(float time) = 0;
	virtual void show(sf::RenderTarget* target = NULL) = 0;
	virtual void update(float time) = 0;

};

