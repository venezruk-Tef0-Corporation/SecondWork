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

//Функция на проверку ввода целого числа с использованием шаблонной функции 
int GetInt(void) {
	return GetInput<int>();
}

//Функция на проверку ввода пункта главного меню с использованием функции на проверку ввода целого числа 
MainMenuItems GetMainMenuItem(void) {
	return static_cast<MainMenuItems>(GetInt());
}

//Функция на проверку ввода пункта следующего за главным меню с использованием функции на проверку ввода целого числа 
EnteringMenuItems GetEnteringMenuItem(void) {
	return static_cast<EnteringMenuItems>(GetInt());
}

//Функция на проверку ввода пункта меню для выбора записи с использованием функции на проверку ввода целого числа
WriteDataMenuItems GetWriteDataMenuItem(void) {
	return static_cast<WriteDataMenuItems>(GetInt());
}

//Функция на проверку ввода пункта меню для выбора места для записи с использованием функции на проверку ввода целого числа 
ExistFileItems GetExistFileItem(void) {
	return static_cast<ExistFileItems>(GetInt());
}