//Директивы препроцессора
#include <iostream>
#include <string>

//Подключаемые библиотеки проекта
#include "Enums.h"

//Пространства имен
using namespace std;

//Объявление шаблона
template <typename T>

//Функция на проверку ввода с использованием шаблона
T GetInput(void) {
	T UserInput{};
	cin >> UserInput;
	if (cin.fail()) {
		cout << "Ошибка обработки ввода. Введите корректные данные: ";
		while (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cin >> UserInput;
		}
	}
	cin.ignore(INT_MAX, '\n');
	return UserInput;
}

/// <summary>GetInt - Функция на проверку целочисленного ввода с использованием шаблонной функции</summary>
int GetInt(void) {
	return GetInput<int>();
}

/// <summary>GetMainMenuItem - Функция на проверку ввода пункта главного меню с использованием функции на проверку ввода целого числа</summary>
MainMenuItems GetMainMenuItem(void) {
	return static_cast<MainMenuItems>(GetInt());
}

/// <summary>GetMainMenuItem - Функция на проверку ввода пункта следующего за главным меню с использованием функции на проверку ввода целого числа</summary>
EnteringMenuItems GetEnteringMenuItem(void) {
	return static_cast<EnteringMenuItems>(GetInt());
}

/// <summary>GetMainMenuItem - Функция на проверку ввода пункта меню для выбора записи с использованием функции на проверку ввода целого числа</summary>
WriteDataMenuItems GetWriteDataMenuItem(void) {
	return static_cast<WriteDataMenuItems>(GetInt());
}

/// <summary>GetMainMenuItem - Функция на проверку ввода пункта меню для выбора места для записи с использованием функции на проверку ввода целого числа </summary>
ExistFileItems GetExistFileItem(void) {
	return static_cast<ExistFileItems>(GetInt());
}
