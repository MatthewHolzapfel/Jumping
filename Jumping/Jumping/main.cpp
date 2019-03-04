#include "Jumping.h"
#include <iostream>
#include "SFML/Graphics.hpp"


using namespace std;

int main()
{
	if (!Jumping::Instance()->Start())
	{
		cout << "Failed to meet system requirements. Press enter to close." << endl;
		cin.get();
		return 0;
	}
	
	system("CLS");
	cout << "Press 'Enter' to close." << endl;
	cin.get();

	return 0;
}