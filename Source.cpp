//Директивы препроцессора
#include <windows.h>

//Подключаемые библиотеки проекта
#include "GreetingFunction.h"
#include "StartingFunction.h"

using namespace std; /*позволяет использовать все идентификаторы 
		       из пространства имён std без указания 
		       префикса std::*/

//Точка входа в программу
int main(void) {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ShowGreeting();
	ProgramStarting();

	system("PAUSE");

	return EXIT_SUCCESS;
}
