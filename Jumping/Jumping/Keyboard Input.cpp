#include "SFML/Graphics.hpp"
#include "Keyboard Input.h"
#include "stdafx.h"
#include <iostream>
#include <string>
#include "SoundEffects.h"

using namespace std;

sf::Event event;
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
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (mySound.sound.getStatus() == sf::Sound::Status::Stopped) {


			mySound.SFX();
			
		}
		std::cout << "Move Left" << std::endl;
		s->move(sf::Vector2f(-2.5f, 0.0));
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (mySound.sound.getStatus() == sf::Sound::Status::Stopped) {


			mySound.SFX();

		}
		std::cout << "Move Right" << std::endl;
		s->move(sf::Vector2f(2.5f, 0.0));
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (mySound.sound.getStatus() == sf::Sound::Status::Stopped) {


			mySound.SFX();

		}
		std::cout << "Move Up" << std::endl;
		s->move(sf::Vector2f(0.0, -2.5));
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (mySound.sound.getStatus() == sf::Sound::Status::Stopped) {


			mySound.SFX();

		}
		std::cout << "Move Down" << std::endl;
		s->move(sf::Vector2f(0.0, 2.5f));
		
	}
}

Input::~Input() {

}
	
