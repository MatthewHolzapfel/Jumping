#include "SFML/Graphics.hpp"
#include "Player.h"
#include "stdafx.h"
#include <iostream>
#include <string>
#include "SoundEffects.h"

using namespace std;

//sf::Event event;
Player::Player(float speed)
{
	this->speed = speed;
	body.setSize(sf::Vector2f(25.0f, 25.0f));
	body.setFillColor(sf::Color::Green);
	body.setPosition(50.0f, 550.0f);
	body.setOrigin(body.getSize() / 2.0f);

}

void Player::Jump() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		std::cout << "Jump Player" << std::endl;
	}

}

void Player::Move(float deltaTime) {
	this->bottom = false;
	SoundEffects mySound;
	mySound.SetSoundBuffer("Walking.wav");
	sf::Vector2f movement(0.0f, 0.0f);
	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (mySound.sound.getStatus() == sf::Sound::Status::Stopped) {


			mySound.SFX();
			
		}
		std::cout << "Move Left" << std::endl;
		movement.x -= speed + deltaTime;
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (mySound.sound.getStatus() == sf::Sound::Status::Stopped) {


			mySound.SFX();

		}
		std::cout << "Move Right" << std::endl;
		movement.x += speed + deltaTime; 
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)|| sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (mySound.sound.getStatus() == sf::Sound::Status::Stopped) {

			mySound.SFX();
		}
		std::cout << "Move Up" << std::endl;
		movement.y -= speed + deltaTime;
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)|| sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (mySound.sound.getStatus() == sf::Sound::Status::Stopped) {


			mySound.SFX();

		}
		std::cout << "Move Down" << std::endl;
		movement.y += speed + deltaTime;
		
	}

	body.move(movement);
}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

Player::~Player() {

}
	
