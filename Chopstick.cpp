#include "Chopstick.h"


bool Chopstick::Take()
{
	/*
	* Если уже взята возвращаем Ложь(Нельзя взять)
	* Если свободна меняем статус на Взята и возвращаем Истинна
	*/
	return Taken?false:Taken=!Taken;
}


void Chopstick::Drop()
{
	Taken = false;
}
