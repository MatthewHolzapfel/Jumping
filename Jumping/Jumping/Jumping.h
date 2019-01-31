#pragma once

#include "Single.h"

class Window;

class Jumping : public Single<Jumping>
{
public:
	Window* window;
	~Jumping();
	bool Start();
	void Open();
private:
	friend Single<Jumping>;
	Jumping();
	bool CheckSystemRequirements();
};