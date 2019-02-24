#include "SFML/Graphics.hpp"

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int jump() {

	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORK!");

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

				break;
			}
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			std::cout << "Jump Player" << std::endl;
		}

		window.clear();
	}


	return 0;
	
} 