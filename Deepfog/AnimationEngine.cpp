#include "AnimationEngine.h"

AnimationEngine::AnimationEngine(sf::Sprite& sprite, sf::Texture& sheets) : sprite(sprite), sheets(sheets)
{

}

AnimationEngine::~AnimationEngine()
{
	for (auto& i : this->animations)
	{
		delete i.second;
	}
}

void AnimationEngine::addAnimation(std::string key, int start_x, int start_y, int end_x, int end_y, int width, int height, float speed)
{
	this->animations[key] = new Animation(this->sprite, this->sheets, start_x, start_y, end_x, end_y, width, height, speed);
}

void AnimationEngine::play(std::string key, float time)
{
	this->animations[key]->update(time);
}
