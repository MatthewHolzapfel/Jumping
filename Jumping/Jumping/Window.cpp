#include "Window.h"

Window::Window()
{
}

void Window::Initialize(int _width, int _height)
{
	sf::RenderWindow window(sf::VideoMode(_width, _height), "Jump!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

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


}

Window::~Window()
{
}

sf::RenderWindow* Window::GetWindow() const
{
	return window;
}
