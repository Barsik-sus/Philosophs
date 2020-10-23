#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include "Philosopher.h"
#include "Chopstick.h"

std::mutex _lock;

void Eating(Philosopher *ph)
{
	while (true)
	{
		_lock.lock();
		ph->TakeLeftChopstick();
		ph->TakeRightChopstick();
		_lock.unlock();

		if(ph->TryToEat())
		ph->Think();
	}
}
void PrintInfo(Philosopher* philosopher)
{
	while (true)
	{
		system("cls");
		for (int i = 0; i < 5; i++)
		{
			std::cout << "[" << i + 1 << "] "; philosopher[i].GetStatus() ? std::cout << "Eating" << std::endl : std::cout << "Thinking" << std::endl;
		}
	}
}

int main()
{
	Philosopher* philosopher = new Philosopher[5];
	Chopstick* chopstick = new Chopstick[5];

	for (int i = 0; i < 4; i++)
	{
		philosopher[i].SetChopsticks(&chopstick[i], &chopstick[i + 1]);
	}
	philosopher[4].SetChopsticks(&chopstick[4], &chopstick[0]);
	std::vector<std::thread> TH;
	
	for (int i = 0; i < 5; i++)
	{
		TH.push_back(std::thread(Eating, &philosopher[i]));
	}
	
	std::thread Monitor(PrintInfo, std::ref(philosopher));

	Monitor.detach();
	Sleep(30000);


	delete[] philosopher;
	delete[] chopstick;
	return 0;
}