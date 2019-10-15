#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <Windows.h>


using namespace std;

class MenuChepterItem
{
	friend class MenuChepter;
private:
	string title;

	void (*proc)() = 0;

	MenuChepterItem(string aTitle, void (*procLink)()) : title(aTitle), proc(procLink) {}

	MenuChepterItem() { title = ""; }

};
 
class MenuChepter : protected MenuChepterItem
{
	friend class Menu;
	friend class Init;
private :
	void GetMenuView();

	vector<MenuChepterItem> menuChepterItem;
	string title_Chepter;

	void ShowMenu();
	void AddMenuItem(string itemTitle, void (*procLink)());
public:
	
	MenuChepter(string title, vector<MenuChepterItem> menuChepterItem)
	{
		this->title_Chepter = title;
		this->menuChepterItem = menuChepterItem;
	}

	MenuChepter() { title_Chepter = "Lol"; }

	
};

class Menu : protected  MenuChepter
{
	friend class Init;
private:
	string menuTitle;
	vector<MenuChepter> menuChepter;

	void GetMenuView();

	// Interface method
	void AddMenuItem(string itemTitle, MenuChepter linkMenuChepter);
	void ShowMenu();
public:

	// Constructors
	Menu()
	{
		menuTitle = "Main menu";
	}
	Menu(string menuTitle)
	{
		this->menuTitle = menuTitle;
	}

	
};

