
//#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
  std::cout << "Lasd Libraries 2020" << std::endl;
  //lasdtest(); // To call in the menu of your library test!


  BaseMenu* aCurrentMenu = new FirstMenu; // We have a pointer to our menu. We're using a pointer so we can change the menu seamlessly.
  bool isQuitOptionSelected = false;
  while (!isQuitOptionSelected) // We're saying that, as long as the quit option wasn't selected, we keep running
  {
	  aCurrentMenu->printText(); // This will call the method of whichever MenuObject we're using, and print the text we want to display

	  int choice = 0; // Always initialise variables, unless you're 100% sure you don't want to.
	  std::cin >> choice;

	  BaseMenu* aNewMenuPointer = aCurrentMenu->getMenuSelection(choice, isQuitOptionSelected); // This will return a new object, of the type of the new menu we want. Also checks if quit was selected

	  if (aNewMenuPointer) // This is why we set the pointer to 0 when we were creating the new menu - if it's 0, we didn't create a new menu, so we will stick with the old one
	  {
		  delete aCurrentMenu; // We're doing this to clean up the old menu, and not leak memory.
		  aCurrentMenu = aNewMenuPointer; // We're updating the 'current menu' with the new menu we just created
	  }
  }

  return true;
}
