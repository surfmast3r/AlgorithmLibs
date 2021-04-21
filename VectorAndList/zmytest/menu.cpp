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
	menuText = std::string("\n--Main Menu--\n")
				+"Please make your selection\n"
				+ "1 - Stack\n"
				+ "2 - Queue\n"
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
			mainMenu = new StackMenu;
			break;
		}
		case 2:
		{
			mainMenu = new QueueMenu;
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

StackMenu::StackMenu()
{
	menuText = std::string("\n--Stack Menu--\n")
				+ "Please make your selection\n"
				+ "1 - create random int Stack \n"
				+ "2 - create random string Stack \n"
				+ "3 - create random float Stack \n"
				+ "4 - back to main menu\n"
				+ "Selection: ";
}

BaseMenu *StackMenu::getMenuSelection(int choice, bool& iIsQuitOptionSelected)
{
	BaseMenu *mainMenu = 0;

	switch (choice)
	{
		case 1:
		{
			//testIntVector();
			createIntStack();
		}
		break;
		case 2:
		{
			//testStringVector();
			createStringStack();
		}
		break;
		case 3:
		{
			//testFloatVector();
			createFloatStack();
		}
		break;
		case 4:
		{
			mainMenu = new FirstMenu;
		}
		break;

		default:
		{
			// Do nothing
		}

	}

	return mainMenu;
}

QueueMenu::QueueMenu()
{
	menuText = std::string("\n--Queue Menu--\n")
				+ "Please make your selection\n"
				+ "1 - create random int Queue\n"
				+ "2 - create random string Queue\n"
				+ "3 - create random float Queue\n"
				+ "4 - back to main menu\n"
				+ "Selection: ";
}

BaseMenu *QueueMenu::getMenuSelection(int choice, bool& iIsQuitOptionSelected)
{
	BaseMenu *mainMenu = 0;

	switch (choice)
	{
		case 1:
		{
			createIntQueue();
		}
		break;
		case 2:
		{
			createStringQueue();
		}
		break;
		case 3:
		{
			createFloatQueue();
		}
		break;
		case 4:
		{
			mainMenu = new FirstMenu;
		}
		break;

		default:
		{
			// Do nothing
		}

	}

	return mainMenu;
}





