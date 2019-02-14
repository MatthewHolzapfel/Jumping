#include "stdafx.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
//#include <SFML/Timer.hpp>
#include <SFML/System/Time.hpp>

using namespace std;
/*
int main(int _width, int _height) {
	//SFML Render Window
	sf::RenderWindow window(sf::VideoMode(_width, _height), "Jump!");

	sf::Time t1 = sf::microseconds(10000);
	sf::Time t2 = sf::milliseconds(10);
	sf::Time t3 = sf::seconds(0.01f);


	sf::Time t1 = t1;
	sf::Time t2 = t1 * 2;
	sf::Time t3 = t1 + t2;
	sf::Time t4 = -t3;

	bool b1 = (t1 == t2);
	bool b2 = (t3 > t4);

	sf::Clock clock; // starts the clock

	sf::Time elapsed1 = clock.getElapsedTime();
	std::cout << elapsed1.asSeconds() << std::endl;
	clock.restart();

	sf::Time elapsed2 = clock.getElapsedTime();
	std::cout << elapsed2.asSeconds() << std::endl;

	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		window(elapsed);

	}

	window.clear();
	window.display();
} 


int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Game");

	sf::Time micro = sf::microseconds(1000);
	sf::Time milli = sf::milliseconds(10);
	sf::Time second = sf::seconds(0.01f);

	std::cout << micro.asSeconds() << std::endl;
	std::cout << micro.asMilliseconds() << std::endl;
	std::cout << micro.asMicroseconds() << std::endl;

	std::cout << (micro + micro).asSeconds << std::endl; 

	sf::Clock clock;


	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch(event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyReleased:
				clock.restart();
				break; 
			}
		}

		//update the game
		sf::Time elapsed = clock.getElapsedTime();
		std::cout << elapsed.asSeconds() << std::endl; 

		window.clear();
		window.display(); 
	}
} */