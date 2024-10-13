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

//Функция на выбор перезаписи или нового файла
string IsFileExist(void) {
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

//Функция для записи данных в файл
void WritingTheDataToFile(int *FileArray, int SizeOfArray) {
	WriteDataMenuItems UserChoice = static_cast<WriteDataMenuItems>(0);
	cout << "Записать данные в файл?" << endl;
	cout << "[1] - Записать данные в файл" << endl;
	cout << "[2] - Продолжить без записи" << endl;
	cout << "Выберите пункт меню: ";
	do {
		UserChoice = GetWriteDataMenuItem();
		if (UserChoice == Writing) {
			cout << "Сохранение в файл" << endl;
			string PathName = IsFileExist();
			ofstream File;
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
		}
		else if (UserChoice == Cancelling) {
			continue;
		}
		else {
			cout << "Введённый пункт отсутствует. Повторите ввод: ";
		}
	} while ((UserChoice != Writing) && (UserChoice != Cancelling));
}

//Функция вывода отсортированного массива
void ShowSortedArray(int* SortedArray, int SizeOfArray) {
	cout << "Отсортированный массив: [ ";
	for (int i = 0; i < SizeOfArray; i++) cout << SortedArray[i] << " ";
	cout << "]" << endl;
}

//Функция сортировки массива
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

//Функция заполнения массива случайными значениями
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

//Функция заполнения массива вручную
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

//Функция выбора способа заполнения массива
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

