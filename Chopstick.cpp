#include "Chopstick.h"


bool Chopstick::Take()
{
	/*
	* ���� ��� ����� ���������� ����(������ �����)
	* ���� �������� ������ ������ �� ����� � ���������� �������
	*/
	return Taken?false:Taken=!Taken;
}


void Chopstick::Drop()
{
	Taken = false;
}
