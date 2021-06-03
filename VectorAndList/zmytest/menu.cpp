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
				+ "1 - Matrix Vector\n"
				+ "2 - Matrix Yale\n"
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
			mainMenu = new MatrixVectorMenu;
			break;
		}
		case 2:
		{
			mainMenu = new MatrixYaleMenu;
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

MatrixVectorMenu::MatrixVectorMenu()
{
	menuText = std::string("\n--MatrixVector Menu--\n")
				+ "Please make your selection\n"
				+ "1 - create random int MatrixVector \n"
				+ "2 - create random float MatrixVector \n"
				+ "3 - create random string MatrixVector \n"
				+ "4 - back to main menu\n"
				+ "Selection: ";
}

BaseMenu* MatrixVectorMenu::getMenuSelection(int choice, bool& iIsQuitOptionSelected)
{
	BaseMenu *mainMenu = 0;

	switch (choice)
	{
		case 1:
		{
			lasd::MatrixVec<int> matVec;
			createIntMatrix(matVec);
		}
		break;
		case 2:
		{
			lasd::MatrixVec<float> matVec;
			createFloatMatrix(matVec);
		}
		break;
		case 3:
		{
			lasd::MatrixVec<std::string> matVec;
			createStringMatrix(matVec);
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

MatrixYaleMenu::MatrixYaleMenu()
{
	menuText = std::string("\n--MatrixYale Menu--\n")
				+ "Please make your selection\n"
				+ "1 - create random int MatrixYale\n"
				+ "2 - create random float MatrixYale\n"
				+ "3 - create random string MatrixYale\n"
				+ "4 - back to main menu\n"
				+ "Selection: ";
}

BaseMenu* MatrixYaleMenu::getMenuSelection(int choice, bool& iIsQuitOptionSelected)
{
	BaseMenu *mainMenu = 0;

	switch (choice)
	{
		case 1:
		{
			lasd::MatrixCSR<int> matYale;
			createIntMatrix(matYale);
		}
		break;
		case 2:
		{
			lasd::MatrixCSR<float> matYale;
			createFloatMatrix(matYale);
		}
		break;
		case 3:
		{
			lasd::MatrixCSR<std::string> matYale;
			createStringMatrix(matYale);
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





