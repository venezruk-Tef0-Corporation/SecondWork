//Директивы препроцессора
#include <iostream>

//Подключаемые библиотеки проекта
#include "ProgramFunctions.h"

using namespace std; /*позволяет использовать все идентификаторы
					   из пространства имён std без указания
					   префикса std::*/

//Функция тестирования сортировки
void SetTesting(void) {

	bool IsTestFine = true;

	int size = 4;

	int* firstarray = new int[size] { 1, 3, 2, 5 };
	int* secondarray = new int[size] { 6, 5, 2, 5 };
	int* thirdarray = new int[size] { -10, 7, 3, 6 };
	int* fourtharray = new int[size] { 0, 1, 45, -9 };
	int* fiftharray = new int[size] { -100, 50, 0, 100 };

	ShakerSorting(firstarray, size);
	ShakerSorting(secondarray, size);
	ShakerSorting(thirdarray, size);
	ShakerSorting(fourtharray, size);
	ShakerSorting(fiftharray, size);


	int* truefirstarray = new int[size] { 1, 2, 3, 5 };
	int* truesecondarray = new int[size] { 2, 5, 5, 6 };
	int* truethirdarray = new int[size] { -10, 3, 6, 7 };
	int* truefourtharray = new int[size] { -9, 0, 1, 45  };
	int* truefiftharray = new int[size] { -100, 0, 50, 100 };

	for (int i = 0; i < size; i++) {

		if (firstarray[i] != truefirstarray[i]) {
			cout << "Ошибка при тестировании в массиве 1." << endl
				 << "Ожидалось: " << truefirstarray[i] << endl
				 << "Получено: " << firstarray[i] << endl;
			IsTestFine = false;
		}

		if (secondarray[i] != truesecondarray[i]) {
			cout << "Ошибка при тестировании в массиве 2." << endl
				<< "Ожидалось: " << truesecondarray[i] << endl
				<< "Получено: " << secondarray[i] << endl;
			IsTestFine = false;
		}

		if (thirdarray[i] != truethirdarray[i]) {
			cout << "Ошибка при тестировании в массиве 3." << endl
				<< "Ожидалось: " << truethirdarray[i] << endl
				<< "Получено: " << thirdarray[i] << endl;
			IsTestFine = false;
		}

		if (fourtharray[i] != truefourtharray[i]) {
			cout << "Ошибка при тестировании в массиве 4." << endl
				<< "Ожидалось: " << truefourtharray[i] << endl
				<< "Получено: " << fourtharray[i] << endl;
			IsTestFine = false;
		}

		if (fiftharray[i] != truefiftharray[i]) {
			cout << "Ошибка при тестировании в массиве 5." << endl
				<< "Ожидалось: " << truefiftharray[i] << endl
				<< "Получено: " << fiftharray[i] << endl;
			IsTestFine = false;
		}
	}

	if (IsTestFine) cout << "Тесты завершены успешно." << endl;
}