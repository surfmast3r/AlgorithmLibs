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
	menuText = std::string("Main Menu\n")
				+"Please make your selection\n"
				+ "1 - Vector\n"
				+ "2 - List\n"
				+ "3 - Quit\n"
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

		case 3:
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
	menuText = std::string("Vector Menu\n")
				+ "Please make your selection\n"
				+ "1 - create random int vector\n"
				+ "2 - create random string vector\n"
				+ "3 - create random float vector\n"
				+ "4 - start vector tests\n"
				+ "5 - back to main menu\n"
				+ "Selection: ";
}

BaseMenu *VectorMenu::getMenuSelection(int choice, bool& iIsQuitOptionSelected) // This is us actually defining the pure virtual method above
{
	BaseMenu *mainMenu = 0; // We're setting up the pointer here, but makin sure it's null (0)

	switch (choice) // Notice - I have only done options. You would obviously need to do this for all of your menus
	{
		case 1:
		{
			unsigned long size;
			std::cout<<"insert vector size\n";
			std::cin>>size;
			createRandomIntVector(size);
		}
		break;
		case 4:
		{
			lasdtest(); // To call in the menu of your library test!
		}
		break;
		case 5:
		{
			mainMenu = new FirstMenu; // We're creating our new menu object here, and will send it back to the main function below
		}
		break;

		default:
		{
			// Do nothing - we won't change the menu
		}

	}

	return mainMenu; // Sending it back to the main function
}





