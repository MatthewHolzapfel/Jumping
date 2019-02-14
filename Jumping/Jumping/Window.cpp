#include "Window.h"
#include <SFML/Graphics/Texture.hpp>	
#include <iostream>
Window::Window()
{}

void Window::Initialize(int _width, int _height)
{
	//window = new sf::RenderWindow (sf::VideoMode(_width, _height), "Jump!");
	/*sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);*/

	//sf::Texture test;
	//if (!test.loadFromFile("splashscreen.png"))
	//	std::cout << "ERROR";
	//sf::Sprite sprite;
	//sprite.setTexture(test);
	//// Draw the textured sprite
	//window->draw(sprite);
}

sf::RenderWindow* Window::GetWindow() const
{
	return window;
}

