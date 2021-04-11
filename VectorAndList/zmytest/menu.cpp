/*
 * menu.cpp
 *
 *  Created on: 29 mar 2021
 *      Author: Paolo Gallo
 */
#include "../zlasdtest/test.hpp"
#include "menu.hpp"
#include "test.hpp"
FirstMenu::FirstMenu()
{
	menuText = std::string("\nMain Menu\n")
				+"Please make your selection\n"
				+ "1 - Vector\n"
				+ "2 - List\n"
				+ "3 - start zlasd tests\n"
				+ "4 - Quit\n"
				+ "Selection: ";
}
BaseMenu *FirstMenu::getMenuSelection(int choice, bool& iIsQuitOptionSelected)
{
	BaseMenu *mainMenu = 0;
	switch (choice)
	{
		case 1:
		{
			mainMenu = new VectorMenu;
			break;
		}
		case 2:
		{
			mainMenu = new ListMenu;
			break;
		}
		case 3:
		{
			lasdtest();
			break;
		}

		case 4:
		{

			iIsQuitOptionSelected = true;
			break;
		}

		default:
		{
			// Do nothing
		}

	}

	return mainMenu;
}

VectorMenu::VectorMenu()
{
	menuText = std::string("\nVector Menu\n")
				+ "Please make your selection\n"
				+ "1 - create random int vector\n"
				+ "2 - create random string vector\n"
				+ "3 - create random float vector\n"
				+ "4 - back to main menu\n"
				+ "Selection: ";
}

BaseMenu *VectorMenu::getMenuSelection(int choice, bool& iIsQuitOptionSelected)
{
	BaseMenu *mainMenu = 0;

	switch (choice)
	{
		case 1:
		{
			testIntVector();
		}
		break;
		case 2:
		{
			testStringVector();
		}
		break;
		case 3:
		{
			testFloatVector();
		}
		break;
		case 4:
		{
			mainMenu = new FirstMenu;
		}
		break;
		case 5:
		{

		}
		break;

		default:
		{
			// Do nothing
		}

	}

	return mainMenu;
}

ListMenu::ListMenu()
{
	menuText = std::string("\nList Menu\n")
				+ "Please make your selection\n"
				+ "1 - create random int list\n"
				+ "2 - create random string list\n"
				+ "3 - create random float list\n"
				+ "4 - back to main menu\n"
				+ "Selection: ";
}

BaseMenu *ListMenu::getMenuSelection(int choice, bool& iIsQuitOptionSelected)
{
	BaseMenu *mainMenu = 0;

	switch (choice)
	{
		case 1:
		{
			testIntList();
		}
		break;
		case 2:
		{
			testStringList();
		}
		break;
		case 3:
		{
			testFloatList();
		}
		break;
		case 4:
		{
			mainMenu = new FirstMenu;
		}
		break;
		case 5:
		{

		}
		break;

		default:
		{
			// Do nothing
		}

	}

	return mainMenu;
}





