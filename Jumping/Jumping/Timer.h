#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Timer
{
public:
	Timer() {};

	void Start()
	{
		sf::Time micro = sf::microseconds(1000);
		sf::Time milli = sf::milliseconds(10);
		sf::Time second = sf::seconds(0.01f);
		std::cout << "Seconds per milliseconds: " << micro.asSeconds() << std::endl;
		std::cout << "Milliseconds per millisecond: " << micro.asMilliseconds() << std::endl;
		std::cout << "Microseconds per millisecond: " << micro.asMicroseconds() << std::endl;
		std::cout << (micro + micro).asSeconds() << std::endl;
	};

	~Timer()
	{
	};

};