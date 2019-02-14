
#include "Music.h"
#include <iostream>
#include <SFML/Audio.hpp>


using namespace std;


 Music::Music() {
	
	
	//music.setVolume(50);
	//music.setLoop(true);
	
}

 void Music::PlayMusic(string file) {
	 //sf::Music music;
	 if (!music.openFromFile(file)) {
		 cout << "Music Error";
	 }
	 music.play();
 }
Music::~Music()
{
}

