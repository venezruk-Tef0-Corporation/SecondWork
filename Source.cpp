//Директивы препроцессора
#include <windows.h>

//Подключаемые библиотеки проекта
#include "GreetingFunction.h"
#include "StartingFunction.h"

using namespace std; /*позволяет использовать все идентификаторы 
		       из пространства имён std без указания 
		       префикса std::*/

/// <summary>main - Главная функция, точка входа в программу</summary>
int main(void) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ShowGreeting();
	ProgramStarting();

	system("PAUSE");

	return EXIT_SUCCESS;
}
