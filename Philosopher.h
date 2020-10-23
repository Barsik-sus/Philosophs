#pragma once
#include <Windows.h>
#include "Chopstick.h"
class Philosopher
{
public:
	Philosopher() {};
	bool Status = false;
	bool Left—hopstick = false;
	bool Right—hopstick = false;
	Chopstick* Left;
	Chopstick* Right;
	
	// True - Eating
	// False - Thinking
	bool GetStatus();

	void SetChopsticks(Chopstick* _Left, Chopstick* _Right);

	bool TryToEat();
	void Think();

	bool TakeLeftChopstick();
	bool TakeRightChopstick();

	void DropLeftChopstick();
	void DropRightChopstick();
	
};
