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
BaseMenu *FirstMenu::getMenuSelection(int choice, bool& iIsQuitOptionSelected) // This is us actually defining the pure virtual method above
{
	BaseMenu *mainMenu = 0; // We're setting up the pointer here, but makin sure it's null (0)
	switch (choice) // Notice - I have only done "options". You would obviously need to do this for all of your menus
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
			lasdtest(); // To call in the menu of your library test!
			break;
		}

		case 4:
		{
			// Ah, they selected quit! Update the bool we got as input
			iIsQuitOptionSelected = true;
			break;
		}

		default:
		{
			// Do nothing - we won't change the menu
		}

	}

	return mainMenu; // Sending it back to the main function
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

BaseMenu *VectorMenu::getMenuSelection(int choice, bool& iIsQuitOptionSelected) // This is us actually defining the pure virtual method above
{
	BaseMenu *mainMenu = 0; // We're setting up the pointer here, but makin sure it's null (0)

	switch (choice) // Notice - I have only done options. You would obviously need to do this for all of your menus
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
			mainMenu = new FirstMenu; // We're creating our new menu object here, and will send it back to the main function below
		}
		break;
		case 5:
		{

		}
		break;

		default:
		{
			// Do nothing - we won't change the menu
		}

	}

	return mainMenu; // Sending it back to the main function
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

BaseMenu *ListMenu::getMenuSelection(int choice, bool& iIsQuitOptionSelected) // This is us actually defining the pure virtual method above
{
	BaseMenu *mainMenu = 0; // We're setting up the pointer here, but makin sure it's null (0)

	switch (choice) // Notice - I have only done options. You would obviously need to do this for all of your menus
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
			mainMenu = new FirstMenu; // We're creating our new menu object here, and will send it back to the main function below
		}
		break;
		case 5:
		{

		}
		break;

		default:
		{
			// Do nothing - we won't change the menu
		}

	}

	return mainMenu; // Sending it back to the main function
}





