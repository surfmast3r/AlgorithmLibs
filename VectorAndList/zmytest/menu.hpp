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
    virtual BaseMenu *getMenuSelection(int iChoice, bool& iIsQuitOptionSelected) = 0;
    virtual void printText()
    {
        std::cout << menuText << std::endl;
    }

protected:
    std::string menuText;
};

class FirstMenu : public BaseMenu
{
public:
    FirstMenu();
    ~FirstMenu()= default;
    BaseMenu *getMenuSelection(int choice, bool& iIsQuitOptionSelected);
};

class MatrixVectorMenu : public BaseMenu
{
public:
	MatrixVectorMenu();
    ~MatrixVectorMenu()= default;
    BaseMenu *getMenuSelection(int choice, bool& iIsQuitOptionSelected);

};

class MatrixYaleMenu : public BaseMenu
{
public:
	MatrixYaleMenu();
    ~MatrixYaleMenu()= default;
    BaseMenu *getMenuSelection(int choice, bool& iIsQuitOptionSelected);

};



/* ************************************************************************** */

#endif
