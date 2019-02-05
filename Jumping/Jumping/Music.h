#pragma once
#include "Single.h"
#include <SFML/Audio.hpp>

class Music : public Single<Music>
{
private:
	sf::Music* music;
	//friend Single;
	Music();

public:
	void PlayMusic();
	~Music();
};