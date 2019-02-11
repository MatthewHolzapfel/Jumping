#include "Jumping.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Window.h"
#include "Music.h"
#include <SFML/Audio.hpp>


int main()
{
	if (Jumping::Instance()->Start())
		Jumping::Instance()->Open();

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML");

	//Music::Music();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}


	

	int a;
	std::cin >> a;
	return 0;
}