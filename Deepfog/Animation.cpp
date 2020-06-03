#include "Animation.h"

Animation::Animation(sf::Sprite& sprite, sf::Texture& sheets, int start_x, int start_y, int end_x, int end_y, int width, int height, float speed)
	: sprite(sprite), sheets(sheets), speed(speed), width(width), height(height)
{
	this->timer = 0.f;
	this->start = sf::IntRect(start_x * width, start_y * height, width, height);
	this->end = sf::IntRect(end_x * width, end_y * height, width, height);
	this->sprite.setTexture(this->sheets, true);
	this->sprite.setTextureRect(this->start);
	this->current = this->start;
}

void Animation::update(float time)
{
	this->timer += 500.f * time;
	if (this->timer >= this->speed)
	{
		this->timer = 0.f;

		if (this->current != this->end)
		{
			this->current.left += this->width;
		}
		else
		{
			this->current.left = this->start.left;
		}
	}
	this->sprite.setTextureRect(this->current);
}
