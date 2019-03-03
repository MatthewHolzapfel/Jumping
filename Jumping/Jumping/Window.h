#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Single.h"
#include "Music.h"
#include "Platform.h"
#include "Keyboard Input.h"
#include <SFML/Audio.hpp>
#include "SoundEffects.h"

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
