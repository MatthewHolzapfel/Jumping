
#include "Music.h"
#include <iostream>
#include <SFML/Audio.hpp>

using namespace std;


 Music::Music() {
	sf::Music music;
	if (!music.openFromFile("MarioBGM.wav")) {
		cout << "Music Error";
	}
	music.setVolume(50);
	music.setLoop(true);
	music.play();
}

Music::~Music()
{
}

