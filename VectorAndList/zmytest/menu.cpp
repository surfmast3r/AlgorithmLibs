/*
 * menu.cpp
 *
 *  Created on: 29 mar 2021
 *      Author: Paolo Gallo
 */
#include "menu.hpp"

FirstMenu::FirstMenu()
{
	m_MenuText = std::string("Main Menu\n")
				+"Please make your selection\n"
				+ "1 - Start game\n"
				+ "2 - Options\n"
				+ "3 - Quit\n"
				+ "Selection: ";
}
BaseMenu *FirstMenu::getMenuSelection(int choice, bool& iIsQuitOptionSelected) // This is us actually defining the pure virtual method above
{
	BaseMenu *aNewMenu = 0; // We're setting up the pointer here, but makin sure it's null (0)

	switch (choice) // Notice - I have only done "options". You would obviously need to do this for all of your menus
	{
		case 2:
		{
			aNewMenu = new SecondMenu;
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

	return aNewMenu; // Sending it back to the main function
}

SecondMenu::SecondMenu()
{
	m_MenuText = std::string("OptionsMenu\n")
				+ "Please make your selection\n"
				+ "1 - ????"
				+ "2 - dafuq?";
}

BaseMenu *SecondMenu::getMenuSelection(int choice, bool& iIsQuitOptionSelected) // This is us actually defining the pure virtual method above
{
	BaseMenu *aNewMenu = 0; // We're setting up the pointer here, but makin sure it's null (0)

	switch (choice) // Notice - I have only done options. You would obviously need to do this for all of your menus
	{
		case 1:
		{
			aNewMenu = new FirstMenu; // We're creating our new menu object here, and will send it back to the main function below
		}
		break;
		case 2:
		{
			aNewMenu = new FirstMenu; // We're creating our new menu object here, and will send it back to the main function below
		}
		break;

		default:
		{
			// Do nothing - we won't change the menu
		}

	}

	return aNewMenu; // Sending it back to the main function
}





