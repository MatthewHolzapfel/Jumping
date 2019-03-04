#pragma once
#include <SFML/Audio.hpp>
#include <string>


class SoundEffects
{
public:
	SoundEffects();
	~SoundEffects();
	void SFX();
	void SetSoundBuffer(std::string file);
	sf::SoundBuffer* soundBufPtr;
	sf::SoundBuffer buffer;
	sf::Sound sound;
	
};

