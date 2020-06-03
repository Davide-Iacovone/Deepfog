#pragma once

#include "Animation.h"

class AnimationEngine
{
private:
	sf::Texture& sheets;
	sf::Sprite& sprite;
	std::map<std::string, Animation*> animations;
public:
	AnimationEngine(sf::Sprite& sprite, sf::Texture& sheets);
	~AnimationEngine();

	void addAnimation(std::string key, int start_x, int start_y, int end_x, int end_y, int width, int height, float speed);
	void play(std::string key, float time);
};

