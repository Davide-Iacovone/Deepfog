#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "Player.h"

class Game
{
protected:
	sf::RenderWindow* window;
	sf::Event event;

	void setupWindow();
	void checkForEvents();
	void show();

public:
	Game();
	~Game();
	void running();

};

