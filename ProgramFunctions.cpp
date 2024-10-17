//Директивы препроцессора
#include <iostream>                 
#include <random>                   
#include <string>                   
#include <filesystem>
#include <fstream>

#define RangeForSize 10
#define MinimumForSize 6

#define RangeForElements 100
#define MinimumForElements 50

//Подключаемые библиотеки проекта
#include "Enums.h"
#include "InputValidation.h"


//Пространства имен
using namespace std;
using namespace filesystem;

/// <param name="UserChoice"> - Используется для считывания выбранного пункта меню</param>
/// <param name="FilePath"> - Используется для считывания введенного адреса файла</param>
/// <param name="TryAnotherFile"> - Принимет значение true, если пользователь выбрал запись в другой файл</param>
/// <param name="IsDataSaved"> - Принимет значение true, когда данные записаны в файл</param>
/// <summary>FileRecord - Функция выбора адреса для записи данных</summary>
string AddressTaking(void) {
	ExistFileItems UserChoice = static_cast<ExistFileItems>(0);
	string FilePath;
	bool TryAnotherFile = false;
	bool IsDataSaved = false;
	do {
		cout << "Введите относительный или абсолютный путь файла: ";
		getline(cin, FilePath);

		if (fstream(FilePath)) {

			cout << "Файл уже существует" << endl;

			do {
				cout << "[1] - Перезаписать существующий файл" << endl;
				cout << "[2] - Выбрать другой файл" << endl;
				cout << "Выберите пункт меню: ";

				UserChoice = GetExistFileItem();
				if ((UserChoice != NewFileChoice) && (UserChoice != Rewriting)) {
					cout << "Выбранный пункт не найден. Повторите ввод: " << endl;
				}

			} while ((UserChoice != NewFileChoice) && (UserChoice != Rewriting));

			if (UserChoice == NewFileChoice) {
				TryAnotherFile = true;
				continue;
			}
		}
		ofstream MyFile(FilePath.c_str());
		error_code ec{};

		if (!is_regular_file(FilePath, ec)) {
			cout << "Адрес содержит недопустимые значения" << endl;
			continue;
		}

		if (!MyFile) {
			cout << "Запись в этот файл недоступна" << endl;
			MyFile.close();
			continue;
		}
		IsDataSaved = true;
	} while (!IsDataSaved);

	return FilePath;
}

/// <summary>WritingTheDataToFile - Функция записи данных в файл</summary>
/// <param name="UserChoice"> - Используется для считывания выбранного пункта меню</param>
/// <param name="FileArray"> - Записываемый в файл массив</param>
/// <param name="SizeOfArray"> - Записываемый в файл размер массива</param>
/// <param name="SizeOfArray"> - Записываемый в файл размер массива</param>
void WritingTheDataToFile(int *FileArray, int SizeOfArray) {
	WriteDataMenuItems UserChoice = static_cast<WriteDataMenuItems>(0);
	cout << "Записать данные в файл?" << endl;
	cout << "[1] - Записать данные в файл" << endl;
	cout << "[2] - Продолжить без записи" << endl;
	cout << "Выберите пункт меню: ";
	do {
		UserChoice = GetWriteDataMenuItem();
		switch (UserChoice) {
			case Writing:
				cout << "Сохранение в файл" << endl;
				PathName = AddressTaking();
				File.open(PathName.c_str(), ios_base::trunc | ios_base::out);
				if (File.is_open()) {
					File << SizeOfArray << endl;
					File << "[ ";
					for (int i = 0; i < SizeOfArray; i++) File << FileArray[i] << " ";
					File << "]";
					cout << "Данные сохранены" << endl;
					File.close();
				}
				else {
					cout << "Файл недоступен для записи" << endl;
					File.close();
				}
				break;
			case Cancelling:
				continue;
				break;

			default:
				cout << "Введённый пункт отсутствует. Повторите ввод: ";
				break;
		}

	} while ((UserChoice != Writing) && (UserChoice != Cancelling));
}

/// <summary>ShowSortedArray - Функция вывода отсортированного массива</summary>
/// <param name="SortedArray"> - Отсортированный массив</param>
/// <param name="SizeOfArray"> - Размер массива</param>
void ShowSortedArray(int* SortedArray, int SizeOfArray) {
	cout << "Отсортированный массив: [ ";
	for (int i = 0; i < SizeOfArray; i++) cout << SortedArray[i] << " ";
	cout << "]" << endl;
}

/// <summary>ShowSortedArray - Функция сортировки массива</summary>
/// <param name="ArrayForSorting"> - Исходный массив</param>
/// <param name="SizeOfArray"> - Размер массива</param>
/// <param name="IsSwapped"> - Принимет значение true, когда произошла перестановка элементов</param>
/// <param name="Start"> - Начальный элемент сортировки</param>
/// <param name="End"> - Конечный элемент сортировки</param>
void ShakerSorting(int* ArrayForSorting, int SizeOfArray) {

	bool IsSwapped = true;
	int Start = 0;
	int End = SizeOfArray - 1;

	while (IsSwapped) {
		IsSwapped = false;

		// Проходим снизу вверх
		for (int i = Start; i < End; ++i) {
			if (ArrayForSorting[i] > ArrayForSorting[i + 1]) {
				swap(ArrayForSorting[i], ArrayForSorting[i + 1]);
				IsSwapped = true;
			}
		}

		// Если не было перестановок, то сортировка уже выполнена
		if (!IsSwapped)
			break;

		IsSwapped = false;

		// Уменьшаем окончание на 1, так как самый большой элемент уже находится на правильной позиции
		--End;

		// Проходим сверху вниз
		for (int i = End - 1; i >= Start; --i) {
			if (ArrayForSorting[i] > ArrayForSorting[i + 1]) {
				swap(ArrayForSorting[i], ArrayForSorting[i + 1]);
				IsSwapped = true;
			}
		}

		// Увеличиваем начало на 1, так как самый маленький элемент уже находится на правильной позиции
		++Start;
	}

}

/// <summary>AutoEntering - Функция заполнения массива случайными значениями</summary>
/// <param name="ArraySize"> - Размер массива, определямый случайным образом</param>
/// <param name="RangeForSize"> - Длина выборки для случайного значения размера</param>
/// <param name="MinimumForSize"> - Младший элемент выборки для случайного значения размера</param>
/// <param name="Array"> - Массив, заполняемый случайными значениями</param>
/// <param name="RangeForElements"> - Длина выборки для случайного значения элемента</param>
/// <param name="MinimumForElements"> - Младший элемент выборки для случайного значения элемента</param>
void AutoEntering(void) {

	int ArraySize = rand() % RangeForSize + rand() % MinimumForSize;
	cout << "Рандомайзер выбрал размер массива = " << ArraySize << endl;

	int* Array = new int[ArraySize];

	for (int i = 0; i < ArraySize; i++) {
		Array[i] = rand() % RangeForElements - MinimumForElements;
	}

	cout << "Рандомайзер заполнил массив: [ ";
	for (int i = 0; i < ArraySize; i++) {
		cout << Array[i] << " ";
	}
	cout << "]" << endl;

	ShakerSorting(Array, ArraySize);
	ShowSortedArray(Array, ArraySize);
	WritingTheDataToFile(Array, ArraySize);
}

/// <summary>ManualEntering - Функция заполнения массива с клавиатуры</summary>
/// <param name="ArraySize"> - Размер массива, вводимый с клавиатуры</param>
/// <param name="Array"> - Массив, элементы которого вводятся с клавиатуры</param>
void ManualEntering(void) {

	int ArraySize = 0;
	cout << "Введите размер массива: ";
	do {
		ArraySize = GetInt();
		if (ArraySize <= 0) cout << "Ошибка ввода. Повторите ввод: ";
	} while (ArraySize <= 0);

	int* Array = new int[ArraySize];

	for (int i = 0; i < ArraySize; i++) {
		cout << "Введите " << i + 1 << " элемент: ";
		Array[i] = GetInt();
	}

	cout << "Введенный массив: " << endl;
	cout << "[ ";
	for (int i = 0; i < ArraySize; i++) cout << Array[i] << " ";
	cout << "]" << endl;

	ShakerSorting(Array, ArraySize);
	ShowSortedArray(Array, ArraySize);
	WritingTheDataToFile(Array, ArraySize);
}

/// <summary>AutoEntering - Функция выбора способа заполнения массива</summary>
/// <param name="UserChoice"> - Используется для считывания выбранного пункта меню</param>
void ProgramEntering(void) {

	EnteringMenuItems UserChoice = static_cast<EnteringMenuItems>(0);

	do {

		cout << "[1] - Заполнить массив вручную" << endl;
		cout << "[2] - Заполнить массив случайными значениями" << endl;
		cout << "Выберите пункт меню: ";

		UserChoice = GetEnteringMenuItem();

		switch (UserChoice) {
			case ManualEnter:
				ManualEntering();
				break;
			case AutoEnter:
				AutoEntering();
				break;
			default:
				cout << "Введённый пункт не найден. Повторите ввод." << endl;
				break;
		}
	} while ((UserChoice != ManualEnter) && (UserChoice != AutoEnter));

}

