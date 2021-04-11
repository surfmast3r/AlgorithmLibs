
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"
#include "zmytest/menu.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2020" << std::endl;
  //


  BaseMenu* aCurrentMenu = new FirstMenu;
  bool isQuitOptionSelected = false;
  while (!isQuitOptionSelected)
  {
	  aCurrentMenu->printText();

	  int choice = 0;
	  //std::cin >> choice;
	  if(!(std::cin >> choice))
		{
			std::cout << "Please enter numbers only: ";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}

	  BaseMenu* aNewMenuPointer = aCurrentMenu->getMenuSelection(choice, isQuitOptionSelected);

	  if (aNewMenuPointer)
	  {
		  delete aCurrentMenu;
		  aCurrentMenu = aNewMenuPointer;
	  }
  }
  std::cout << "Goodbye!" << std::endl;
  return true;
}
