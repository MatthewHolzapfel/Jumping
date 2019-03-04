
#include "Music.h"
#include <iostream>
#include <SFML/Audio.hpp>


using namespace std;


 Music::Music() {
	
	
	
	
}

 void Music::PlayMusic(string file) {

	 if (!music.openFromFile(file)) {
		 cout << "Music Error";
	 }
	 music.play();
	 music.setVolume(25);
	 music.setLoop(true);
 }
Music::~Music()
{
}

