#pragma once
#include "OOP_Menu.h"
#include "Matrix.h"

class Init : protected MenuChepter
{
private:
	MenuChepter MatrixFirst;
	MenuChepter MatrixSecond;
	MenuChepter MatrixThird;
	MenuChepter MatrixFourth;
	Menu MainMenu;
public:

	Init()
	{
		MatrixFirst.AddMenuItem("Task 8 of 100", Matrix8);
		MatrixFirst.AddMenuItem("Task 16 of 100", Matrix16);
		MatrixSecond.AddMenuItem("Task 24 of 100", Matrix24);
		MatrixSecond.AddMenuItem("Task 34 of 100", Matrix34);
		MatrixThird.AddMenuItem("Task 51 of 100", Matrix51);
		MatrixThird.AddMenuItem("Task 76 of 100", Matrix76);
		MatrixFourth.AddMenuItem("Task 88 of 100", Matrix88);
		MatrixFourth.AddMenuItem("Task 98 of 100", Matrix98);
		MainMenu.AddMenuItem("First Chepter", MatrixFirst);
		MainMenu.AddMenuItem("Second Chepter", MatrixSecond);
		MainMenu.AddMenuItem("Third Chepter", MatrixThird);
		MainMenu.AddMenuItem("Fourth Chepter", MatrixFourth);
	}

	void Show_Main()
	{
		MainMenu.ShowMenu();
	}
};