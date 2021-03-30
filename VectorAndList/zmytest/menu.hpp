/*
 * menu.hpp
 *
 *  Created on: 29 mar 2021
 *      Author: Paolo Gallo
 */
#ifndef MYMENU_HPP
#define MYMENU_HPP

/* ************************************************************************** */

#include <iostream>
#include <string>

class BaseMenu
{
public:
    BaseMenu()=default;
    virtual ~BaseMenu()= default;
    virtual BaseMenu *getMenuSelection(int iChoice, bool& iIsQuitOptionSelected) = 0; // This is a 'pure virtual method', as shown by the "= 0". It means it doesn't do anything. It's used to set up the framework
    virtual void printText()
    {
        std::cout << menuText << std::endl;
    }

protected:
    std::string menuText; // This string will be shared by all children (i.e. derived) classes
};

class FirstMenu : public BaseMenu
{
public:
    FirstMenu();
    BaseMenu *getMenuSelection(int choice, bool& iIsQuitOptionSelected);
};

class SecondMenu : public BaseMenu
{
public:
    SecondMenu();
    BaseMenu *getMenuSelection(int choice, bool& iIsQuitOptionSelected);
};



/* ************************************************************************** */

#endif
