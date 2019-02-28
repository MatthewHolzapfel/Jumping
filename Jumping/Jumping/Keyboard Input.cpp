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

}

Input::~Input() {

}
	
