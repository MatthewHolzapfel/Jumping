#pragma once
#include "Single.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Window : public Single<Window>
{
private:
	sf::RenderWindow* window;
	friend Single;
	Window();

public:
	sf::RenderWindow* GetWindow() const;
	void Initialize(int width = 200, int height = 200);
	~Window();
};
