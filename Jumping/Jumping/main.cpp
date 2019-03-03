#include "Jumping.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Window.h"
#include <SFML/Audio.hpp>

int main()
{
	if (!Jumping::Instance()->Start())
		std::cout << "Failed to meet system requirements. Press enter to close." << std::endl;
	std::cin.get();
	return 0;
}