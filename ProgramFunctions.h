#pragma once /*это директива препроцессора, 
	       которая указывает компилятору 
	       включить файл заголовка только 
	       один раз при компиляции файла 
	       исходного кода*/

//Объявление функций, описанных в файле ProgramFunctions.cpp
void WritingTheDataToFile(int* array, int size);
void ShowSortedArray(int* array, int size);
void ShakerSorting(int* array, int size);
void AutoEntering(void);
void ManualEntering(void);
void ProgramEntering(void);
