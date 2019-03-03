#include <SFML/Graphics.hpp>
#include "Jumping.h"
#include "HardwareCheck.h"
#include "Window.h"
#include "Timer.h"
#include <iostream>


Jumping::~Jumping()
{

}

void Jumping::Open()
{
	Timer timer;
	window = Window::Instance();
	window->Initialize(600, 600);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		std::cout << "Jump Player" << std::endl;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad6))
	{
		std::cout << "Move right Player" << std::endl;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad4))
	{
		std::cout << "Move left Player" << std::endl; 
	}

}

Jumping::Jumping()
{}

bool Jumping::Start()
{
	if (!CheckSystemRequirements())
		return false;

	Open();
	return true;
}

bool Jumping::CheckSystemRequirements()
{
	HardwareCheck hardwareCheck;
	hardwareCheck.DisplayCPUStats();
	hardwareCheck.Memory();
	if (!hardwareCheck.Storage())
		return false;

	return true;
}

