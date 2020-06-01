#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "Entity.h"

#include <iostream>

class State
{
protected:
	sf::RenderWindow* window;
	bool quit;

public:


	State(sf::RenderWindow* window);
	~State();

	const bool& getEnd() const;

	virtual void end();
	virtual void handleEnd() = 0;
	virtual void updateKeyboard(float time) = 0;
	virtual void show(sf::RenderTarget* target = NULL) = 0;
	virtual void update(float time) = 0;

};

