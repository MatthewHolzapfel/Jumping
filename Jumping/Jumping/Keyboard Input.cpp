#include "SFML/Graphics.hpp"
#include "Keyboard Input.h"
#include "stdafx.h"
#include <iostream>
#include <string>
#include "SoundEffects.h"

using namespace std;


Input::Input() {

}

void Input::jump() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		std::cout << "Jump Player" << std::endl;
	}

}

void Input::move(sf::RectangleShape *s) {

	SoundEffects mySound;
	mySound.SetSoundBuffer("Walking.wav");
	


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		
		mySound.SFX();
		std::cout << "Move Left" << std::endl;
		s->move(sf::Vector2f(-2.5f, 0.0));
		

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		
		mySound.SFX();
		std::cout << "Move Right" << std::endl;
		s->move(sf::Vector2f(2.5f, 0.0));
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		
		mySound.SFX();
		std::cout << "Move Up" << std::endl;
		s->move(sf::Vector2f(0.0, -2.5));
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		
		mySound.SFX();
		std::cout << "Move Down" << std::endl;
		s->move(sf::Vector2f(0.0, 2.5f));
		
	}
}

Input::~Input() {

}
	
