#pragma once /*это директива препроцессора, 
	           которая указывает компилятору 
			   включить файл заголовка только 
			   один раз при компиляции файла 
			   исходного кода*/

//Подключаемые библиотеки проекта
#include "Enums.h"

//Объявление шаблона
template <typename T>

//Объявление функций для проверки корректности ввода пунктов меню
T GetInput(void);
int GetInt(void);
MainMenuItems GetMainMenuItem(void);
EnteringMenuItems GetEnteringMenuItem(void);
WriteDataMenuItems GetWriteDataMenuItem(void);
ExistFileItems GetExistFileItem(void);