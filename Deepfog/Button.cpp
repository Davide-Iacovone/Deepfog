#include "Button.h"

Button::Button(float x, float y, float width, float height, sf::Font* font, std::string text, sf::Color normal, sf::Color hover)
{
	this->body.setPosition(sf::Vector2f(x, y));
	this->body.setSize(sf::Vector2f(width, height));
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::Black);
	this->text.setCharacterSize(15);
	this->normal = normal;
	this->hover = hover;
	this->body.setFillColor(this->normal);
	this->text.setPosition(sf::Vector2f(this->body.getPosition().x + (this->body.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f, this->body.getPosition().y + (this->body.getGlobalBounds().height / 2.f) - this->text.getGlobalBounds().height / 2.f));
	this->pressed = false;
	this->hovered = false;
}

Button::~Button()
{
}

bool Button::isPressed()
{
	return pressed;
}

void Button::setPressed()
{
	this->pressed = false;
}

void Button::state(sf::Vector2f mouse)
{
	if (this->body.getGlobalBounds().contains(mouse))
	{
		this->hovered = true;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->pressed = true;
		}
	}
	else
	{
		this->hovered = false;
	}
	switch (this->hovered)
	{
	case true:
		this->body.setFillColor(this->hover);
		break;
	case false:
		this->body.setFillColor(this->normal);
		break;
	default:
		break;
	}
}

void Button::show(sf::RenderTarget& target)
{
	target.draw(this->body);
	target.draw(this->text);
}

void Button::update(sf::Vector2f mouse)
{
	this->state(mouse);
}
