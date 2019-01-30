#pragma once
#include "Single.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Window : public Single<Window>
{
private:
	sf::RenderWindow* window;
	Window();

public:
	sf::RenderWindow* GetWindow() const;
	void Initialize(int width = 800, int height = 600);
};
