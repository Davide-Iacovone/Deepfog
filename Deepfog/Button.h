#pragma once

#include <iostream>

#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

class Button
{
protected:
	sf::RectangleShape body;
	sf::Font* font;
	sf::Text text;
	sf::Color normal;
	sf::Color hover;
	sf::Vector2f mouse;
	bool pressed;
	bool hovered;
public:
	Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color normal, sf::Color hover);
	~Button();

	bool isPressed();
	void setPressed();
	void state(sf::Vector2f mouse);
	void show(sf::RenderTarget& target);
	void update(sf::Vector2f mouse);
};

