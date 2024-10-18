//Директивы препроцессора
#include <iostream>

//Подключаемые библиотеки проекта
#include "ProgramFunctions.h"

using namespace std; /*позволяет использовать все идентификаторы
					   из пространства имён std без указания
					   префикса std::*/

/// <summary>CompletionArrayOfArrays - Функция для заполнения массива указателями на массив</summary>
/// <param name="ArrayOfArrays"> - Массив указателей на массив</param>
/// <param name="FirstArray"> - Первый указатель на массив</param>
/// <param name="SecondArray"> - Второй указатель на массив</param>
/// <param name="ThirdArray"> - Третий указатель на массив</param>
/// <param name="FourthArray"> - Четвертый указатель на массив</param>
void CompletionArrayOfArrays(int** ArrayOfArrays, int* FirstArray, int* SecondArray, int* ThirdArray, int* FourthArray) {
	ArrayOfArrays[0] = FirstArray;
	ArrayOfArrays[1] = SecondArray;
	ArrayOfArrays[2] = ThirdArray;
	ArrayOfArrays[3] = FourthArray;
}

/// <summary>SetTesting - Функция тестирования сортировки</summary>
/// <param name="ArrayOfArrays"> - Массив указателей на массив</param>
/// <param name="FirstArray"> - Первый указатель на массив</param>
/// <param name="SecondArray"> - Второй указатель на массив</param>
/// <param name="ThirdArray"> - Третий указатель на массив</param>
/// <param name="FourthArray"> - Четвертый указатель на массив</param>
/// <param name="ArrayOfTrueArrays"> - Массив указателей на массив</param>
/// <param name="TrueFirstArray"> - Первый указатель на массив с заведомо истинными значениями</param>
/// <param name="TrueSecondArray"> - Второй указатель на массив с заведомо истинными значениями</param>
/// <param name="TrueThirdArray"> - Третий указатель на массив с заведомо истинными значениями</param>
/// <param name="TrueFourthArray"> - Четвертый указатель на массив с заведомо истинными значениями</param>
/// <param name="size"> - Размеры массивов</param>
/// <param name="IsTestFine"> - Принимет значение true, когда тесты завершены без ошибок</param>
void SetTesting(void) {

	bool IsTestFine = true;

	int size = 4;

	int* FirstArray = new int[size] { 1, 3, 2, 5 };
	int* SecondArray = new int[size] { 6, 5, 2, 5 };
	int* ThirdArray = new int[size] { -10, 7, 3, 6 };
	int* FourthArray = new int[size] { 0, 1, 45, -9 };

	int** ArrayOfArrays = new int* [size];
	CompletionArrayOfArrays(ArrayOfArrays, FirstArray, SecondArray, ThirdArray, FourthArray);

	for (int i = 0; i < size; i++) ShakerSorting(ArrayOfArrays[i], size);

	int* TrueFirstArray = new int[size] { 1, 2, 3, 5 };
	int* TrueSecondArray = new int[size] { 2, 5, 5, 6 };
	int* TrueThirdArray = new int[size] { -10, 3, 6, 7 };
	int* TrueFourthArray = new int[size] { -9, 0, 1, 45  };

	int** ArrayOfTrueArrays = new int* [size];
	CompletionArrayOfArrays(ArrayOfTrueArrays, TrueFirstArray, TrueSecondArray, TrueThirdArray, TrueFourthArray);

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
