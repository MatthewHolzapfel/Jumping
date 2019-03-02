#include "SFML/Graphics.hpp"
#include "Keyboard Input.h"
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

Input::Input() {

}

void Input::jump() {


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		std::cout << "Jump Player" << std::endl;
	}




	/*sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORK!");

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
	*/

	return;
	
} 

Input::~Input() {

}