#pragma once
#include <SFML/Audio.hpp>
#include <string>


class Music
{
public:
	Music();
	~Music();
	void PlayMusic(std::string file);
	sf::Music music;
};