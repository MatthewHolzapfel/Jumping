#include "SFML/Graphics.hpp"

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int jump() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		std::cout << "Jump Player" << std::endl;
	}

	return 0;
} 