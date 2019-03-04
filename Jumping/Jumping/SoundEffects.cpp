#include "SoundEffects.h"
#include <iostream>
#include <SFML/Audio.hpp>

using namespace std;


SoundEffects::SoundEffects()
{
}

void SoundEffects::SetSoundBuffer(string file) {
	

	if (!buffer.loadFromFile(file)) {
		cout << "SFX Error";
	}
	sound.setBuffer(buffer);
	sound.setVolume(100);
	//sound.setLoop(true);
	
}
void SoundEffects::SFX() {

	sound.play();
}




SoundEffects::~SoundEffects()
{
}
