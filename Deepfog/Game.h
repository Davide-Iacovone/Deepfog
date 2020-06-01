#pragma once

#include <iostream>
#include <stack>

#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "State.h"
#include "GameState.h"
#include "MenuState.h"

class Game
{
protected:
	sf::RenderWindow* window;
	sf::Event event;
	sf::Clock clock;
	float time;
	std::stack<State* > States;

	void setupWindow();
	void setupStates();
	void checkForEvents();
	void show();

public:

	Game();
	~Game();
	void running();
	float getTime();
	void timeMeasurment();

};

