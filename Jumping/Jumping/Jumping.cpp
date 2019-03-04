#include <SFML/Graphics.hpp>
#include "Jumping.h"
#include "HardwareCheck.h"
#include "Window.h"
#include <iostream>
#include "Timer.h"


Jumping::~Jumping()
{

}

void Jumping::Open()
{
	window = Window::Instance();
	Timer timer;
	window->Initialize(1000, 600);

}

Jumping::Jumping()
{
	//Starting up engine
}

/**
	Checks if an instance of the engine is already running,
	performs various spec checks and
	initializes various components of the Engine.

	@return Returns the success value of initialization.
 */
bool Jumping::Start()
{
	if (!CheckSystemRequirements())
		return false;

	Open();
	return true;
}


/**
	Creates an instance of the system checker and uses it to
	checks if the user's system has the required hardware/software capabilities
	to run the program.

	@return Returns true if system check passes.
 */
bool Jumping::CheckSystemRequirements()
{
	HardwareCheck hardwareCheck;
	hardwareCheck.DisplayCPUStats();
	hardwareCheck.Memory();
	if (!hardwareCheck.Storage())
		return false;

	return true;
}

