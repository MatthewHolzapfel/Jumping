/*

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::Transform t1 = sf::Transform::Identity;

	// a rotation transform
	sf::Transform t2;
	t2.rotate(45);

	// a custom matrix
	sf::Transform t3(2, 0, 20,
		0, 1, 50,
		0, 0, 1);

	// a combined transform
	sf::Transform t4 = t1 * t2 * t3;

	sf::Transform t;
	t.translate(10, 100);
	t.rotate(90);
	t.translate(-10, 50);
	t.scale(0.5f, 0.75f);

	window.draw(entity, transform);
}  */