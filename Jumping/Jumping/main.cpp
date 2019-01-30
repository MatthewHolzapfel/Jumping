#include "Jumping.h"
#include <iostream>


int main()
{
	if (Jumping::Instance()->Start())
		Jumping::Instance()->Open();
}