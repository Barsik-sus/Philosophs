#include "Philosopher.h"

bool Philosopher::GetStatus()
{
	return Status;
}

void Philosopher::SetChopsticks(Chopstick* _Left, Chopstick* _Right)
{
	Left = _Left;
	Right = _Right;
}

bool Philosopher::TryToEat()
{
	if (!Left�hopstick || !Right�hopstick)
		return false;
	Status = true;
	Sleep(3000);
	DropLeftChopstick();
	DropRightChopstick();
	Status = false;
	return true;
}

void Philosopher::Think()
{
	Sleep(2000);
}

bool Philosopher::TakeLeftChopstick()
{
	// ������� �����, ���� ����������, ���������� ��� �� � �����
	if (Left->Take())
	{
		Left�hopstick = true;
		return true;
	}
	return false;
}

bool Philosopher::TakeRightChopstick()
{
	if (Right->Take())
	{
		Right�hopstick = true;
		return true;
	}
	return false;
}

void Philosopher::DropLeftChopstick()
{
	// ����� ������� � ���������� ��� ��� �� � ���
	Left->Drop();
	Left�hopstick = false;

}

void Philosopher::DropRightChopstick()
{
	Right->Drop();
	Right�hopstick = false;
}
	

