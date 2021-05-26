#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <random>
#include <list>
#include "test.hpp"
using namespace std;


/* ************************************************************************** */
/* Binary Search Tree */

template <typename DataType>
void editBST(lasd::BST<DataType>& bt, const readInputFunctor& readFunction){
	bool isQuitOptionSelected=false;

	if(!bt.Empty()){

		while (!isQuitOptionSelected)
			{
				cout<<std::string("\n--Edit Binary Search Tree Menu--\n");
				std::cout<<"Please make your selection"<<endl;
				std::cout<<"1: Insert Element"<<endl;
				std::cout<<"2: Remove Element"<<endl;
				std::cout<<"3: Read Min"<<endl;
				std::cout<<"4: ReadNRemove Min"<<endl;
				std::cout<<"5: Remove Min"<<endl;
				std::cout<<"6: Read Max"<<endl;
				std::cout<<"7: ReadNRemove Max"<<endl;
				std::cout<<"8: Remove Max"<<endl;
				std::cout<<"9: Successor of Element"<<endl;
				std::cout<<"10: Predecessor of Element"<<endl;
				std::cout<<"11: Back"<<endl;
				std::cout<<"Selection: ";
				int choice = 0;

				if(!(std::cin >> choice)){
					std::cout << "Please enter numbers only: ";
					std::cin.clear();
					std::cin.ignore(10000, '\n');
				}
				switch (choice){
					case 1:{
						DataType value;
						readFunction((void*)&value, "Insert new element");
						bt.Insert(std::move(value));

					}
					break;
					case 2:{
						DataType value;
						readFunction((void*)&value, "Insert element to remove");
						bt.Remove(value);
					}
					break;
					case 3:{

						try{
							cout<<"BST min: "<<bt.Min()<<endl;
						}catch(std::length_error& exc){
							std::cout << exc.what() << std::endl;
						}

					}
					break;
					case 4:{

						try{
							cout<<"BST MinNRemove: "<<bt.MinNRemove()<<endl;
							cout<<"BST new min: "<<bt.Min()<<endl;
						}catch(std::length_error& exc){
							std::cout << exc.what() << std::endl;
						}


					}
					break;
					case 5:{
						try{
							bt.RemoveMin();
							cout<<"BST new min: "<<bt.Min()<<endl;
						}catch(std::length_error& exc){
							std::cout << exc.what() << std::endl;
						}
					}
					break;
					case 6:{
						try{
							cout<<"BST max: "<<bt.Max()<<endl;
						}catch(std::length_error& exc){
							std::cout << exc.what() << std::endl;
						}
					}
					break;
					case 7:{
						try{
							cout<<"BST MaxNRemove: "<<bt.MaxNRemove()<<endl;
							cout<<"BST new max: "<<bt.Max()<<endl;
						}catch(std::length_error& exc){
							std::cout << exc.what() << std::endl;
						}
					}
					break;
					case 8:{
						try{
							bt.MaxNRemove();
							cout<<"BST new max: "<<bt.Max()<<endl;
						}catch(std::length_error& exc){
							std::cout << exc.what() << std::endl;
						}
					}
					break;
					case 9:{
						DataType value;
						readFunction((void*)&value, "Insert element");
						try{

							cout<<"Successor of "<<value<< ": "<<bt.Successor(value)<<endl;

						}catch(std::length_error& exc){
							std::cout << exc.what() << std::endl;
						}
					}
					break;
					case 10:{
						DataType value;
						readFunction((void*)&value, "Insert element");
						try{

							cout<<"Predecessor of "<<value<< ": "<<bt.Predecessor(value)<<endl;
						}catch(std::length_error& exc){
							std::cout << exc.what() << std::endl;
						}
					}
					break;
					case 11:{
						isQuitOptionSelected=true;
					}
					break;
					default:
					{
						// Do nothing
					}
				}
			}
	}else
		cout<<"Binary Tree is empty"<<endl;

}

void createIntBST(){
	unsigned long size;

	readSizeInput(size, "insert Tree size");
	cout<<"Tree Vector "<<endl;
	lasd::Vector<int> vec(size);
	populateRandomIntVector(vec);
	lasd::BST<int> bst(vec);
	intBSTTest(bst);
}
void createFloatBST(){
	unsigned long size;
	readSizeInput(size, "insert Tree size");
	cout<<"Tree Vector "<<endl;
	lasd::Vector<float> vec(size);
	populateRandomFloatVector(vec);
	lasd::BST<float> bst(vec);
	floatBSTTest(bst);
}

void createStringBST(){
	unsigned long size;
	readSizeInput(size, "insert Tree size");
	cout<<"Tree Link "<<endl;
	lasd::Vector<std::string> vec(size);
	populateRandomStringVector(vec);
	lasd::BST<std::string> bst(vec);
	stringBSTTest(bst);
}

void intBSTTest(lasd::BST<int>& bt){

	bool isQuitOptionSelected=false;

	while (!isQuitOptionSelected)
	{
		cout<<std::string("\n--Int BinaryTree Test Menu--\n")
							+ "Please make your selection\n"
							+ "1 - PreOrder visit\n"
							+ "2 - PostOrder visit\n"
							+ "3 - Breadth Visit\n"
							+ "4 - InOrder Visit\n"
							+ "5 - Find Element\n"
							+ "6 - Multiply less then Function\n"
							+ "7 - Edit BST\n"
							+ "8 - Navigate tree\n"
							+ "9 - back to main menu\n"
							+ "Selection: ";
		int choice = 0;

		if(!(std::cin >> choice)){
			std::cout << "Please enter numbers only";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		switch (choice){
			case 1:{
				bt.MapPreOrder(&mapPrint<int>, (void*)0);
				std::cout << endl;
			}
			break;
			case 2:{
				bt.MapPostOrder(&mapPrint<int>, (void*)0);
				std::cout << endl;
			}
			break;
			case 3:{

				bt.MapBreadth(&mapPrint<int>, (void*)0);
				std::cout << endl;
			}
			break;
			case 4:{
				bt.MapInOrder(&mapPrint<int>, (void*)0);
				std::cout << endl;
			}
			break;
			case 5:{

				int value;
				unsigned long index=0;
				cout<<"insert element to find:"<<endl;
				while(!(std::cin >> value)){
						std::cout << "Please enter numbers only: "<<endl;
						std::cin.clear();
						std::cin.ignore(10000, '\n');
						cout<<"insert element to find:"<<endl;
				}
				bt.FoldBreadth(&foldFind<int>, &value, &index);

			}
			break;
			case 6:{

				int value;
				long acc=1;
				readIntValue(static_cast<void*>(&value), "insert n:");
				bt.FoldPreOrder(&foldMultiplyLessThan<int>, &value, &acc);
				cout<<"product is: "<<acc<<endl;

			}
			break;
			case 7:{

				editBST(bt,&readIntValue);
			}
			break;
			case 8:{
				navigateBinaryTree<int>(bt,&readIntValue);
			}
			break;
			case 9:{
				isQuitOptionSelected=true;
			}
			break;
			default:
			{
				// Do nothing
			}
		}
	}

}

void floatBSTTest(lasd::BST<float>& bt){

	bool isQuitOptionSelected=false;

	while (!isQuitOptionSelected)
	{
		cout<<std::string("\n--Int BinaryTree Test Menu--\n")
							+ "Please make your selection\n"
							+ "1 - PreOrder visit\n"
							+ "2 - PostOrder visit\n"
							+ "3 - Breadth Visit\n"
							+ "4 - InOrder Visit\n"
							+ "5 - Find Element\n"
							+ "6 - Sum bigger then n Function\n"
							+ "7 - Edit BST\n"
							+ "8 - Navigate tree\n"
							+ "9 - back to main menu\n"
							+ "Selection: ";
		int choice = 0;

		if(!(std::cin >> choice)){
			std::cout << "Please enter numbers only";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		switch (choice){
			case 1:{
				bt.MapPreOrder(&mapPrint<float>, (void*)0);
				std::cout << endl;
			}
			break;
			case 2:{
				bt.MapPostOrder(&mapPrint<float>, (void*)0);
				std::cout << endl;
			}
			break;
			case 3:{

				bt.MapBreadth(&mapPrint<float>, (void*)0);
				std::cout << endl;
			}
			break;
			case 4:{
				bt.MapInOrder(&mapPrint<float>, (void*)0);
				std::cout << endl;
			}
			break;
			case 5:{

				float value;
				unsigned long index=0;
				readFloatValue(static_cast<void*>(&value), "insert element to find:");
				bt.FoldBreadth(&foldFind<int>, &value, &index);

			}
			break;
			case 6:{

				float value;
				float acc=0;
				readFloatValue(static_cast<void*>(&value), "insert n:");
				bt.FoldPreOrder(&foldSumBiggerThan<float>, &value, &acc);
				cout<<"sum is: "<<acc<<endl;

			}
			break;
			case 7:{

				editBST(bt,&readFloatValue);
			}
			break;
			case 8:{
				navigateBinaryTree<float>(bt,&readFloatValue);
			}
			break;
			case 9:{
				isQuitOptionSelected=true;
			}
			break;
			default:
			{
				// Do nothing
			}
		}
	}

}

void stringBSTTest(lasd::BST<string>& bt){

	bool isQuitOptionSelected=false;

	while (!isQuitOptionSelected)
	{
		cout<<std::string("\n--Int BinaryTree Test Menu--\n")
							+ "Please make your selection\n"
							+ "1 - PreOrder visit\n"
							+ "2 - PostOrder visit\n"
							+ "3 - Breadth Visit\n"
							+ "4 - InOrder Visit\n"
							+ "5 - Find Element\n"
							+ "6 - Concatenate less then n Function\n"
							+ "7 - Edit BST\n"
							+ "8 - Navigate tree\n"
							+ "9 - back to main menu\n"
							+ "Selection: ";
		int choice = 0;

		if(!(std::cin >> choice)){
			std::cout << "Please enter numbers only";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		switch (choice){
			case 1:{
				bt.MapPreOrder(&mapPrint<string>, (void*)0);
				std::cout << endl;
			}
			break;
			case 2:{
				bt.MapPostOrder(&mapPrint<string>, (void*)0);
				std::cout << endl;
			}
			break;
			case 3:{

				bt.MapBreadth(&mapPrint<string>, (void*)0);
				std::cout << endl;
			}
			break;
			case 4:{
				bt.MapInOrder(&mapPrint<string>, (void*)0);
				std::cout << endl;
			}
			break;
			case 5:{

				string value;
				unsigned long index=0;
				readStringValue(static_cast<void*>(&value), "insert element to find:");

				bt.FoldBreadth(&foldFind<string>, &value, &index);

			}
			break;
			case 6:{

				int value;
				string acc="";
				readIntValue(static_cast<void*>(&value), "insert n:");
				bt.FoldPreOrder(&foldStringLessEqThan, &value, &acc);
				cout<<"Concatenated String: "<<acc<<endl;

			}
			break;
			case 7:{

				editBST(bt,&readStringValue);
			}
			break;
			case 8:{
				navigateBinaryTree<string>(bt,&readStringValue);
			}
			break;
			case 9:{
				isQuitOptionSelected=true;
			}
			break;
			default:
			{
				// Do nothing
			}
		}
	}

}

/* ************************************************************************** */
/* Binary Tree int*/
template <typename DataType>
void navigateBinaryTree(lasd::BinaryTree<DataType>& bt, const readInputFunctor& readFunction){
	bool isQuitOptionSelected=false;

	if(!bt.Empty()){
		typename lasd::BinaryTree<DataType>::Node * curr = &bt.Root();
		while (!isQuitOptionSelected)
			{
				cout<<std::string("\n--Navigate Tree Menu--\n");
				std::cout<<"Please make your selection"<<endl;
				std::cout<<"1: Read current Element"<<endl;
				std::cout<<"2: Write current Element"<<endl;
				std::cout<<"3: Check HasLeftChild"<<endl;
				std::cout<<"4: Check HasRightChild"<<endl;
				std::cout<<"5: Go Left"<<endl;
				std::cout<<"6: Go Right"<<endl;
				std::cout<<"7: Navigate with Iterator"<<endl;
				std::cout<<"8: Back"<<endl;
				std::cout<<"Selection: ";
				int choice = 0;

				if(!(std::cin >> choice)){
					std::cout << "Please enter numbers only: ";
					std::cin.clear();
					std::cin.ignore(10000, '\n');
				}
				switch (choice){
					case 1:{
						cout<<"Current Element: "<<curr->Element()<<endl;

					}
					break;
					case 2:{
						DataType value;
						readFunction((void*)&value, "Insert new value");
						curr->Element()=value;
					}
					break;
					case 3:{
						if(curr->HasLeftChild())
							cout<<"Has Left Child"<<endl;
						else
							cout<<"No Left Child"<<endl;
					}
					break;
					case 4:{
						if(curr->HasRightChild())
							cout<<"Has Right Child"<<endl;
						else
							cout<<"No Right Child"<<endl;
					}
					break;
					case 5:{
						if(curr->HasLeftChild()){
							curr=&curr->LeftChild();
							cout<<"Current Element: "<<curr->Element()<<endl;
						}
						else
							cout<<"No Left Child"<<endl;
					}
					break;
					case 6:{
						if(curr->HasRightChild()){
							curr=&curr->RightChild();
							cout<<"Current Element: "<<curr->Element()<<endl;
						}

						else
							cout<<"No Right Child"<<endl;
					}
					break;
					case 7:{
						startIteratorNavigation(bt);
					}
					break;
					case 8:{
						isQuitOptionSelected=true;
					}
					break;
					default:
					{
						// Do nothing
					}
				}
			}
	}else
		cout<<"Binary Tree is empty"<<endl;

}

template<typename DataType>
void startIteratorNavigation(lasd::BinaryTree<DataType>& bt){
	bool isQuitOptionSelected=false;

	while (!isQuitOptionSelected)
		{
			cout<<std::string("\n--Iterator selection Menu--\n");
			std::cout<<"Please make your selection"<<endl;
			std::cout<<"1: PreOrder Iterator"<<endl;
			std::cout<<"2: PostOrder Iterator"<<endl;
			std::cout<<"3: InOrder Iterator"<<endl;
			std::cout<<"4: Breadth Iterator"<<endl;
			std::cout<<"5: Back"<<endl;
			std::cout<<"Selection: ";
			int choice = 0;

			if(!(std::cin >> choice)){
				std::cout << "Please enter numbers only: ";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			switch (choice){
				case 1:{
					lasd::BTPreOrderIterator<DataType> iterator(bt);
					iteratorNavigation<DataType>(iterator);

				}
				break;
				case 2:{
					lasd::BTPostOrderIterator<DataType> iterator(bt);
					iteratorNavigation<DataType>(iterator);
				}
				break;
				case 3:{
					lasd::BTInOrderIterator<DataType> iterator(bt);
					iteratorNavigation<DataType>(iterator);
				}
				break;
				case 4:{
					lasd::BTBreadthIterator<DataType> iterator(bt);
					iteratorNavigation<DataType>(iterator);
				}
				break;

				case 5:{
					isQuitOptionSelected=true;
				}
				break;
				default:
				{
					// Do nothing
				}
			}
		}
}

template<typename DataType>
void iteratorNavigation(lasd::ForwardIterator<DataType>& iterator){
	bool isQuitOptionSelected=false;
	cout<<"Current Element: "<<*iterator<<endl;
	while (!isQuitOptionSelected)
		{
			cout<<std::string("\n--Iterator Menu--\n");
			std::cout<<"Please make your selection"<<endl;
			std::cout<<"1: Iterator++"<<endl;
			std::cout<<"2: Back"<<endl;
			std::cout<<"Selection: ";
			int choice = 0;

			if(!(std::cin >> choice)){
				std::cout << "Please enter numbers only: ";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			switch (choice){
				case 1:{
					try{
						cout<<"Current Element: "<<*++iterator<<endl;
					}catch (std::out_of_range&) {
						cout<<"Iterator Terminated"<<endl;
					}
				}
				break;
				case 2:{
					isQuitOptionSelected=true;
				}
				break;
				default:
				{
					// Do nothing
				}
			}
		}
}

void createIntBinaryTreeLnk(){
	unsigned long size;

	readSizeInput(size, "insert Tree size");
	cout<<"Tree Vector "<<endl;
	lasd::Vector<int> vec(size);
	populateRandomIntVector(vec);
	lasd::BinaryTreeLnk<int> btVec(vec);
	intBinaryTreeTest(btVec);
}
void createIntBinaryTreeVec(){
	unsigned long size;

	readSizeInput(size, "insert Tree size");
	cout<<"Tree Vector "<<endl;
	lasd::Vector<int> vec(size);
	populateRandomIntVector(vec);
	lasd::BinaryTreeVec<int> btVec(vec);
	intBinaryTreeTest(btVec);

}
void intBinaryTreeTest(lasd::BinaryTree<int>& bt){

	bool isQuitOptionSelected=false;

	while (!isQuitOptionSelected)
		{
			cout<<std::string("\n--Int BinaryTree Test Menu--\n")
								+ "Please make your selection\n"
								+ "1 - PreOrder visit\n"
								+ "2 - PostOrder visit\n"
								+ "3 - Breadth Visit\n"
								+ "4 - InOrder Visit\n"
								+ "5 - Find Element\n"
								+ "6 - 3n Function\n"
								+ "7 - Multiply less then Function\n"
								+ "8 - Navigate tree\n"
								+ "9 - back to main menu\n"
								+ "Selection: ";
			int choice = 0;

			if(!(std::cin >> choice)){
				std::cout << "Please enter numbers only";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			switch (choice){
				case 1:{
					bt.MapPreOrder(&mapPrint<int>, (void*)0);
					std::cout << endl;
				}
				break;
				case 2:{
					bt.MapPostOrder(&mapPrint<int>, (void*)0);
					std::cout << endl;
				}
				break;
				case 3:{

					bt.MapBreadth(&mapPrint<int>, (void*)0);
					std::cout << endl;
				}
				break;
				case 4:{
					bt.MapInOrder(&mapPrint<int>, (void*)0);
					std::cout << endl;
				}
				break;
				case 5:{

					int value;
					unsigned long index=0;
					cout<<"insert element to find:"<<endl;
					while(!(std::cin >> value)){
							std::cout << "Please enter numbers only: "<<endl;
							std::cin.clear();
							std::cin.ignore(10000, '\n');
							cout<<"insert element to find:"<<endl;
					}
					bt.FoldBreadth(&foldFind<int>, &value, &index);

				}
				break;
				case 6:{

					bt.MapPreOrder(&mapTripleElementValue<int>, (void*)0);
					cout<<"Breadth visit:"<<endl;
					bt.MapBreadth(&mapPrint<int>, 0);
					cout<<endl;

				}
				break;
				case 7:{
					int value;
					unsigned long acc=1;
					cout<<"insert n size:"<<endl;
					while(!(std::cin >> value)){
							std::cout << "Please enter numbers only: "<<endl;
							std::cin.clear();
							std::cin.ignore(10000, '\n');
							cout<<"insert n size:"<<endl;
					}
					bt.FoldPreOrder(&foldMultiplyLessThan<int>, &value, &acc);
					cout<<"product is: "<<acc<<endl;

				}
				break;
				case 8:{
					navigateBinaryTree<int>(bt,&readIntValue);
				}
				break;
				case 9:{
					isQuitOptionSelected=true;
				}
				break;
				default:
				{
					// Do nothing
				}
			}
		}

}

/* ************************************************************************** */
/* Binary Tree float*/

void createFloatBinaryTreeLnk(){
	unsigned long size;
	readSizeInput(size, "insert Tree size");
	cout<<"Tree Vector "<<endl;
	lasd::Vector<float> vec(size);
	populateRandomFloatVector(vec);
	lasd::BinaryTreeLnk<float> btVec(vec);
	floatBinaryTreeTest(btVec);
}
void createFloatBinaryTreeVec(){
	unsigned long size;

	readSizeInput(size, "insert Tree size");
	cout<<"Tree Vector "<<endl;
	lasd::Vector<float> vec(size);
	populateRandomFloatVector(vec);
	lasd::BinaryTreeVec<float> btVec(vec);
	floatBinaryTreeTest(btVec);

}
void floatBinaryTreeTest(lasd::BinaryTree<float>& bt){

	bool isQuitOptionSelected=false;

	while (!isQuitOptionSelected)
		{
			cout<<std::string("\n--Int BinaryTree Test Menu--\n")
								+ "Please make your selection\n"
								+ "1 - PreOrder visit\n"
								+ "2 - PostOrder visit\n"
								+ "3 - Breadth Visit\n"
								+ "4 - InOrder Visit\n"
								+ "5 - Find Element\n"
								+ "6 - n^3 Function\n"
								+ "7 - sum bigger then Function\n"
								+ "8 - Navigate tree\n"
								+ "9 - back to main menu\n"
								+ "Selection: ";
			int choice = 0;

			if(!(std::cin >> choice)){
				std::cout << "Please enter numbers only";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			switch (choice){
				case 1:{
					bt.MapPreOrder(&mapPrint<float>, (void*)0);
					std::cout << endl;
				}
				break;
				case 2:{
					bt.MapPostOrder(&mapPrint<float>, (void*)0);
					std::cout << endl;
				}
				break;
				case 3:{
					bt.MapBreadth(&mapPrint<float>, (void*)0);
					std::cout << endl;
				}
				break;
				case 4:{
					bt.MapInOrder(&mapPrint<float>, (void*)0);
					std::cout << endl;
				}
				break;
				case 5:{

					float value;
					unsigned long index=0;
					readFloatValue(static_cast<void*>(&value), "insert element to find:");

					bt.FoldBreadth(&foldFloatFind<float>, &value, &index);

				}
				break;
				case 6:{

					float power=3.0;
					bt.MapPreOrder(&mapPowerElementValue<float>, static_cast<void*>(&power));
					bt.MapBreadth(&mapPrint<float>, 0);
					cout<<endl;

				}
				break;
				case 7:{
					float value;
					float acc=0;
					readFloatValue(static_cast<void*>(&value), "insert n size:");
					cout<<"value is: "<<value<<endl;
					bt.FoldPreOrder(&foldSumBiggerThan<float>, &value, &acc);
					cout<<"sum is: "<<acc<<endl;

				}
				break;
				case 8:{
					navigateBinaryTree<float>(bt,&readFloatValue);
				}
				break;
				case 9:{
					isQuitOptionSelected=true;
				}
				break;
				default:
				{
					// Do nothing
				}
			}
		}

}

/* ************************************************************************** */
/* Binary Tree string*/
void createStringBinaryTreeLnk(){
	unsigned long size;
	readSizeInput(size, "insert Tree size");
	cout<<"Tree Link "<<endl;
	lasd::Vector<std::string> vec(size);
	populateRandomStringVector(vec);
	lasd::BinaryTreeLnk<std::string> btLnk(vec);
	stringBinaryTreeTest(btLnk);
}
void createStringBinaryTreeVec(){
	unsigned long size;

	readSizeInput(size, "insert Tree size");
	cout<<"Tree Vector "<<endl;
	lasd::Vector<std::string> vec(size);
	populateRandomStringVector(vec);
	lasd::BinaryTreeVec<std::string> btVec(vec);
	stringBinaryTreeTest(btVec);

}
void stringBinaryTreeTest(lasd::BinaryTree<std::string>& bt){

	bool isQuitOptionSelected=false;

	while (!isQuitOptionSelected)
		{
			cout<<std::string("\n--Int BinaryTree Test Menu--\n")
								+ "Please make your selection\n"
								+ "1 - PreOrder visit\n"
								+ "2 - PostOrder visit\n"
								+ "3 - Breadth Visit\n"
								+ "4 - InOrder Visit\n"
								+ "5 - Find Element\n"
								+ "6 - Concatenate in head\n"
								+ "7 - Concatenate string less then n\n"
								+ "8 - Navigate tree\n"
								+ "9 - back to main menu\n"
								+ "Selection: ";
			int choice = 0;

			if(!(std::cin >> choice)){
				std::cout << "Please enter numbers only";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			switch (choice){
				case 1:{
					bt.MapPreOrder(&mapPrint<std::string>, (void*)0);
					std::cout << endl;
				}
				break;
				case 2:{
					bt.MapPostOrder(&mapPrint<std::string>, (void*)0);
					std::cout << endl;
				}
				break;
				case 3:{
					bt.MapBreadth(&mapPrint<std::string>, (void*)0);
					std::cout << endl;
				}
				break;
				case 4:{
					bt.MapInOrder(&mapPrint<std::string>, (void*)0);
					std::cout << endl;
				}
				break;
				case 5:{

					std::string value;
					unsigned long index=0;
					readStringValue(static_cast<void*>(&value), "insert element to find:");

					bt.FoldBreadth(&foldFind<std::string>, &value, &index);

				}
				break;
				case 6:{

					std::string value;
					readStringValue(static_cast<void*>(&value), "insert string to concatenate:");
					bt.MapPreOrder(&mapConcatInHead, static_cast<void*>(&value));
					bt.MapBreadth(&mapPrint<std::string>, 0);
					cout<<endl;

				}
				break;
				case 7:{
					std::string acc="";
					int value;
					readIntValue(static_cast<void*>(&value), "insert n:");
					bt.FoldBreadth(&foldStringLessEqThan, &value, &acc);
					cout<<"Concatenated string: "<<acc<<endl;



				}
				break;
				case 8:{
					navigateBinaryTree<std::string>(bt,&readStringValue);
				}
				break;
				case 9:{
					isQuitOptionSelected=true;
				}
				break;
				default:
				{
					// Do nothing
				}
			}
		}

}
/* ************************************************************************** */

void populateRandomIntVector(lasd::Vector<int>& vec){
	std::cout<< "populating int vector\n";
	unsigned long size=vec.Size();
	srand(time(NULL));

	default_random_engine genx(random_device{}());
	uniform_int_distribution<unsigned int> distx(7, 35);
	for(unsigned long i = 0; i<size; i++){

		vec[i]=distx(genx);

	}
	printMappableContainer(vec);
	cout<<endl;

};
void populateRandomFloatVector(lasd::Vector<float>& vec){
	std::cout<< "populating float vector\n";
	unsigned long size=vec.Size();
	srand(time(NULL));
	default_random_engine genx(random_device{}());
	uniform_real_distribution<float> distx(0.0, 10.0);

	for(unsigned long i = 0; i<size; i++){

		vec[i]=distx(genx);

	}
	printMappableContainer(vec);
	cout<<endl;

};
void populateRandomStringVector(lasd::Vector<string>& vec){
	std::cout<< "populating string vector\n";
	unsigned long size=vec.Size();
	unsigned int stringSize=0;
	srand(time(NULL));
	for(unsigned long i = 0; i<size; i++){

		stringSize=rand()%10;
		vec[i]=createRandomString(stringSize);

	}
	printMappableContainer(vec);
	cout<<endl;

};

/* ************************************************************************** */


void populateRandomIntList(lasd::List<int>& container,unsigned long& size){
	std::cout<< "populating int list\n";
	srand(time(NULL));
	default_random_engine genx(random_device{}());
	uniform_int_distribution<unsigned int> distx(5, 50);
	for(unsigned long i = 0; i<size; i++){
		container.InsertAtFront(distx(genx));
	}
	printMappableContainer(container);
	cout<<endl;
};
void populateRandomFloatList(lasd::List<float>& container,unsigned long& size){
	std::cout<< "populating float list\n";
	srand(time(NULL));
	default_random_engine genx(random_device{}());
	uniform_real_distribution<float> distx(0.0, 10.0);
	for(unsigned long i = 0; i<size; i++){
		container.InsertAtFront(distx(genx));
	}
	printMappableContainer(container);
	cout<<endl;

};
void populateRandomStringList(lasd::List<string>& container,unsigned long& size){
	std::cout<< "populating string list\n";
	unsigned int stringSize=0;
	srand(time(NULL));
	for(unsigned long i = 0; i<size; i++){
		stringSize=rand()%10;
		container.InsertAtFront(createRandomString(stringSize));
	}
	printMappableContainer(container);
	cout<<endl;
};

/* ************************************************************************** */

string createRandomString(int stringSize)
{
	char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q',
	'r','s','t','u','v','w','x',
	'y','z'};
	string ran = "";
	for (int i=0;i<stringSize;i++)
		ran=ran + letters[rand() % 26];
	return ran;
}

void foldStringLessEqThan(const std::string& data,const void* n,void* acc) {
	if(data.size()<=*(unsigned int*)n){
		((std::string*) acc)->append(data);
	}

}

void mapConcatInHead(string& data,void* str){

	data=*(static_cast<std::string*>(str))+data;
}
void mapUppercase(string& data,void* _){
	capitalizeString(data);
}
void capitalizeString(string& s)
{
    transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return toupper(c); });
}

void readSizeInput(unsigned long &size,string msg){
	std::cout<<msg<<endl;
	while(!(std::cin >> size)){

		std::cout << "Please enter numbers only: "<<endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout<<msg<<endl;
	}
}
void readIntValue(void *input,string msg){
	std::cout<<msg<<endl;
	while(!(std::cin >> *static_cast<int*>(input))){

		std::cout << "Please enter numbers only: "<<endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout<<msg<<endl;
	}
}
void readFloatValue(void *input,string msg){
	std::cout<<msg<<endl;
	while(!(std::cin >>  *static_cast<float*>(input))){

			std::cout << "Please enter numbers only: "<<endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout<<msg<<endl;
		}
}
void readStringValue(void *input,string msg){
	std::cout<<msg<<endl;
	cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
	getline(cin, *static_cast<std::string*>(input));
}




