#pragma once /*это директива препроцессора, 
	           которая указывает компилятору 
			   включить файл заголовка только 
			   один раз при компиляции файла 
			   исходного кода*/

//Объявление переменных перечислимого типа - вспомогательных переменных для пунктов меню
enum MainMenuItems { StartProgram = 1, StartTesting, Quit };
enum EnteringMenuItems { ManualEnter = 1, AutoEnter };
enum ExistFileItems { Rewriting = 1, NewFileChoice };
enum WriteDataMenuItems { Writing = 1, Cancelling };