#include "Window.h"

Window::Window()
{
}

void Window::Initialize(int _width, int _height)
{
	sf::RenderWindow window(sf::VideoMode(_width, _height), "Jump!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	


}

Window::~Window()
{
}

sf::RenderWindow* Window::GetWindow() const
{
	return window;
}
