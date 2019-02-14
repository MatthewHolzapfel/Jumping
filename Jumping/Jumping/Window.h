#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Single.h"

class Window : public Single<Window>
{
private:
	sf::RenderWindow* window;
	friend Single;
	Window();

public:
	sf::RenderWindow* GetWindow() const;
	void Initialize(int width, int height);
	~Window();
};
