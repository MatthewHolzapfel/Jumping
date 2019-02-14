#pragma once
#include <SFML/Audio.hpp>
#include <string>
//#define MAX_NUMBER_OF_ITEMS 3

class Music
{
public:
	Music();
	~Music();
	void PlayMusic(std::string file);
	sf::Music music;
};