#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include "SoundEffects.h"
//#define MAX_NUMBER_OF_ITEMS 3

class Input
{
public:
	Input();
	~Input();
	void jump();
	void move(sf::RectangleShape *s);
	bool isPlaying = false;
	SoundEffects mySound;
	
};