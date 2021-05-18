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
				+ "1 - BinarySearchTree\n"
				+ "2 - start zlasd tests\n"
				+ "3 - Quit\n"
				+ "Selection: ";
}
BaseMenu *FirstMenu::getMenuSelection(int choice, bool& iIsQuitOptionSelected)
{
	BaseMenu *mainMenu = 0;
	switch (choice)
	{
		case 1:
		{
			mainMenu = new BinarySearchTreeMenu;
			break;
		}
//		case 2:
//		{
//			mainMenu = new BinaryTreeLnkMenu;
//			break;
//		}
		case 2:
		{
			lasdtest();
			break;
		}

		case 3:
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

BinarySearchTreeMenu::BinarySearchTreeMenu()
{
	menuText = std::string("\n--BinaryTreeVec Menu--\n")
				+ "Please make your selection\n"
				+ "1 - create random int BinarySearchTree \n"
				+ "2 - create random string BinarySearchTree \n"
				+ "3 - create random float BinarySearchTree \n"
				+ "4 - back to main menu\n"
				+ "Selection: ";
}

BaseMenu *BinarySearchTreeMenu::getMenuSelection(int choice, bool& iIsQuitOptionSelected)
{
	BaseMenu *mainMenu = 0;

	switch (choice)
	{
		case 1:
		{

			createIntBST();
		}
		break;
		case 2:
		{

			createStringBST();
		}
		break;
		case 3:
		{

			createFloatBST();
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

BinaryTreeLnkMenu::BinaryTreeLnkMenu()
{
	menuText = std::string("\n--BinaryTreeLnk Menu--\n")
				+ "Please make your selection\n"
				+ "1 - create random int BinaryTreeLnk\n"
				+ "2 - create random string BinaryTreeLnk\n"
				+ "3 - create random float BinaryTreeLnk\n"
				+ "4 - back to main menu\n"
				+ "Selection: ";
}

BaseMenu *BinaryTreeLnkMenu::getMenuSelection(int choice, bool& iIsQuitOptionSelected)
{
	BaseMenu *mainMenu = 0;

	switch (choice)
	{
		case 1:
		{
			createIntBinaryTreeLnk();
		}
		break;
		case 2:
		{
			createStringBinaryTreeLnk();
		}
		break;
		case 3:
		{
			createFloatBinaryTreeLnk();
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





