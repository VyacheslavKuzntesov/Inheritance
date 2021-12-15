#include<iostream>
#include<thread>
#include<Windows.h>
using namespace std;

bool finish = false;

void Hello()
{
	while (!finish)
	{
		//cout << "Hello";
		cout << "+ ";
		Sleep(100);
	}
}

void World()
{
	while (!finish)
	{
		//cout << "World";
		cout << "- ";
		Sleep(100);
	}
}

void main()
{
	setlocale(LC_ALL, "");
	//������� ������ ������� ������� ����������� � ���� �����:
	/*Hello();
	World();*/

	//�������� ������� � ��������� �������:
	std::thread hello_thread(Hello);
	std::thread world_thread(World);
	cin.get();		//������� ������� Enter
	finish = true;
	hello_thread.join();
	world_thread.join();
}