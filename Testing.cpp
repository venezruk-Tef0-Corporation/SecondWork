//Директивы препроцессора
#include <iostream>

//Подключаемые библиотеки проекта
#include "ProgramFunctions.h"

using namespace std; /*позволяет использовать все идентификаторы
		       из пространства имён std без указания
		       префикса std::*/

/// <summary>CompletionArrayOfArrays - Функция для заполнения массива указателями на массив</summary>
/// <param name="ArrayOfArrays"> - Массив указателей на массив</param>
/// <param name="firstarray"> - Первый указатель на массив</param>
/// <param name="secondarray"> - Второй указатель на массив</param>
/// <param name="thirdarray"> - Третий указатель на массив</param>
/// <param name="fourtharray"> - Четвертый указатель на массив</param>
void CompletionArrayOfArrays(int** ArrayOfArrays, int* firstarray, int* secondarray, int* thirdarray, int* fourtharray) {
	ArrayOfArrays[0] = firstarray;
	ArrayOfArrays[1] = secondarray;
	ArrayOfArrays[2] = thirdarray;
	ArrayOfArrays[3] = fourtharray;
}

/// <summary>SetTesting - Функция тестирования сортировки</summary>
/// <param name="ArrayOfArrays"> - Массив указателей на массив</param>
/// <param name="firstarray"> - Первый указатель на массив</param>
/// <param name="secondarray"> - Второй указатель на массив</param>
/// <param name="thirdarray"> - Третий указатель на массив</param>
/// <param name="fourtharray"> - Четвертый указатель на массив</param>
/// <param name="ArrayOfTrueArrays"> - Массив указателей на массив</param>
/// <param name="truefirstarray"> - Первый указатель на массив с заведомо истинными значениями</param>
/// <param name="truesecondarray"> - Второй указатель на массив с заведомо истинными значениями</param>
/// <param name="truethirdarray"> - Третий указатель на массив с заведомо истинными значениями</param>
/// <param name="truefourtharray"> - Четвертый указатель на массив с заведомо истинными значениями</param>
/// <param name="size"> - Размеры массивов</param>
/// <param name="IsTestFine"> - Принимет значение true, когда тесты завершены без ошибок</param>
void SetTesting(void) {

	bool IsTestFine = true;

	int size = 4;

	int* firstarray = new int[size] { 1, 3, 2, 5 };
	int* secondarray = new int[size] { 6, 5, 2, 5 };
	int* thirdarray = new int[size] { -10, 7, 3, 6 };
	int* fourtharray = new int[size] { 0, 1, 45, -9 };

	int** ArrayOfArrays = new int* [size];
	CompletionArrayOfArrays(ArrayOfArrays, firstarray, secondarray, thirdarray, fourtharray);

	for (int i = 0; i < size; i++) ShakerSorting(ArrayOfArrays[i], size);


	int* truefirstarray = new int[size] { 1, 2, 3, 5 };
	int* truesecondarray = new int[size] { 2, 5, 5, 6 };
	int* truethirdarray = new int[size] { -10, 3, 6, 7 };
	int* truefourtharray = new int[size] { -9, 0, 1, 45  };

	int** ArrayOfTrueArrays = new int* [size];
	CompletionArrayOfArrays(ArrayOfTrueArrays, truefirstarray, truesecondarray, truethirdarray, truefourtharray);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (ArrayOfArrays[i][j] != ArrayOfTrueArrays[i][j]) {
				cout << "Ошибка при тестировании в массиве " << i + 1 << "." << endl
					<< "Ожидалось: " << ArrayOfTrueArrays[i][j] << endl
					<< "Получено: " << ArrayOfArrays[i][j] << endl;
				IsTestFine = false;
			}
		}
	}

	if (IsTestFine) cout << "Тесты завершены успешно." << endl;
}
