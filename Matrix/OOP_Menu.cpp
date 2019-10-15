#include "OOP_Menu.h"

void MenuChepter::GetMenuView()
{
	system("cls");

	for (unsigned int i = 0; i < title_Chepter.size() + 20; i++) cout << "=";

	cout << endl << "\t" << title_Chepter << endl;

	for (unsigned int i = 0; i < title_Chepter.size() + 20; i++) cout << "=";

	cout << endl;

	int ItemNumber = 1;

	for (vector<MenuChepterItem>::iterator it = menuChepterItem.begin(); it != menuChepterItem.end(); it++, ItemNumber++)
	{
		cout << ItemNumber << " -> " << it->title << endl;
	}

	cout << endl << "Ведiть 0 для Виходу!" << endl << endl << "Введiть номер елемента: " << endl;

}

void MenuChepter::ShowMenu()
{
	int itemN = 0;

		while (1)
		{
			GetMenuView();

			itemN = 0;
			string temp = "";
			while (temp == "") getline(cin, temp);

			for (int i = 0; i < temp.size(); i++) itemN += ((temp[i] - 48) * pow(10, i));

			if (itemN == 0) return;

			if (itemN > 0 and itemN <= (int)menuChepterItem.size())
			{
				system("cls");
				menuChepterItem[itemN - 1].proc();
				system("pause");
			}
			else
			{
				cout << "Невiрне значення!" << endl;
				system("pause");
			}
		}


	system("cls");
}

void MenuChepter::AddMenuItem(string itemTitle, void(*procLink)())
{
	menuChepterItem.push_back(*(new MenuChepterItem(itemTitle, procLink)));
}

void Menu::ShowMenu()
{
	int itemN = 0;

	
		while (1)
		{
			GetMenuView();

			itemN = 0;
			string temp = "";
			while (temp == "") getline(cin, temp);

			for (int i = 0; i < temp.size(); i++) itemN += ((temp[i] - 48) * pow(10, i));

			if (itemN == 0) return;

			if (itemN > 0 and itemN <= (int)menuChepter.size())
			{
				system("cls");
				menuChepter[itemN - 1].ShowMenu();
			}
			else
			{
				cout << "Невiрне значення!" << endl;
				system("pause");
			}
		
		}
	
	system("cls");
}

void Menu::GetMenuView()
{
	system("cls");

	for (unsigned int i = 0; i < menuTitle.size() + 20; i++) cout << "=";

	cout << endl << "\t" << menuTitle << endl;

	for (unsigned int i = 0; i < menuTitle.size() + 20; i++) cout << "=";

	cout << endl;

	int ItemNumber = 1;

	for (vector<MenuChepter>::iterator it2 = menuChepter.begin(); it2 != menuChepter.end(); it2++, ItemNumber++)
	{
		cout << ItemNumber << " -> " << it2->title_Chepter << endl;
	}

	cout << endl << "Ведiть 0 для Виходу!" << endl << endl << "Введiть номер елемента: " << endl;
}

void Menu::AddMenuItem(string itemTitle, MenuChepter linkMenuChepter)
{
	menuChepter.push_back(MenuChepter(itemTitle, linkMenuChepter.menuChepterItem));
}