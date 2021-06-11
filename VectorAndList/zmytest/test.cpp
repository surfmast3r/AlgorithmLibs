#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <random>
#include <list>
#include "test.hpp"
using namespace std;


/* ************************************************************************** */
/* Matrix */
template <typename DataType>
void editMatrix(lasd::Matrix<DataType>& mat, const readInputFunctor& readFunction){
	bool isQuitOptionSelected=false;

	if(!mat.Empty()){

		while (!isQuitOptionSelected)
			{
				cout<<std::string("\n--Edit Matrix Menu--\n");
				std::cout<<"Please make your selection"<<endl;
				std::cout<<"1: Exists cell"<<endl;
				std::cout<<"2: Read cell"<<endl;
				std::cout<<"3: Insert element"<<endl;
				std::cout<<"4: Resize row"<<endl;
				std::cout<<"5: Resize column"<<endl;
				std::cout<<"6: Back"<<endl;
				std::cout<<"Selection: ";
				int choice = 0;

				if(!(std::cin >> choice)){
					std::cout << "Please enter numbers only: ";
					std::cin.clear();
					std::cin.ignore(10000, '\n');
				}
				switch (choice){
					case 1:{
						unsigned long column;
						unsigned long row;
						readSizeInput(row, "insert row index");
						readSizeInput(column, "insert column index");
						if(mat.ExistsCell(row,column))
							cout<<"Cell exists"<<endl;
						else
							cout<<"Cell not exists"<<endl;


					}
					break;
					case 2:{
						unsigned long column;
						unsigned long row;
						readSizeInput(row, "insert row index");
						readSizeInput(column, "insert column index");
						try{
							cout<<"cell value is "<<static_cast<const lasd::Matrix<DataType>*>(&mat)->operator()(row,column)<<endl;

						}catch(out_of_range& exc){
							std::cout << exc.what() << std::endl;

						}catch(std::length_error& exc){
							std::cout << exc.what() << std::endl;
						}
					}
					break;
					case 3:{

						unsigned long column;
						unsigned long row;
						readSizeInput(row, "insert row index");
						readSizeInput(column, "insert column index");
						DataType value;
						readFunction((void*)&value, "Insert element");
						try{
							mat(row,column)=value;
							cout<<"cell value is "<<static_cast<const lasd::Matrix<DataType>*>(&mat)->operator()(row,column)<<endl;
						}catch(out_of_range& exc){
							std::cout << exc.what() << std::endl;
						}

					}
					break;
					case 4:{
						unsigned long row;
						readSizeInput(row, "insert new row number");
						try{
							mat.RowResize(row);
							cout<<"Matrix after resize: "<<endl;
							mat.MapPreOrder(&mapPrint<DataType>, (void*)0);
							cout << endl;
						} catch(std::exception& exc) {
						    cout << "\"" << exc.what() << "\": " << "Error!" <<endl;
						}


					}
					break;
					case 5:{
						unsigned long col;
						readSizeInput(col, "insert new column number");
						try{
							mat.ColumnResize(col);
							cout<<"Matrix after resize: "<<endl;
							mat.MapPreOrder(&mapPrint<DataType>, (void*)0);
							cout << endl;
						} catch(std::exception& exc) {
							cout << "\"" << exc.what() << "\": " << "Error!" <<endl;
						}

					}
					break;

					case 6:{
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

void intMatrixTest(lasd::Matrix<int>& matrix){

	bool isQuitOptionSelected=false;

	while (!isQuitOptionSelected)
	{
		cout<<std::string("\n--Int Matrix Test Menu--\n")
							+ "Please make your selection\n"
							+ "1 - PreOrder visit\n"
							+ "2 - PostOrder visit\n"
							+ "3 - Find Element\n"
							+ "4 - Multiply less then Function\n"
							+ "5 - Apply 2n function\n"
							+ "6 - Edit Matrix\n"
							+ "7 - back to main menu\n"
							+ "Selection: ";
		int choice = 0;

		if(!(std::cin >> choice)){
			std::cout << "Please enter numbers only";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		switch (choice){
			case 1:{
				matrix.MapPreOrder(&mapPrint<int>, (void*)0);
				std::cout << endl;
			}
			break;
			case 2:{
				matrix.MapPostOrder(&mapPrint<int>, (void*)0);
				std::cout << endl;
			}
			break;
			case 3:{
				int value;
				unsigned long index=0;
				cout<<"insert element to find:"<<endl;
				while(!(std::cin >> value)){
						std::cout << "Please enter numbers only: "<<endl;
						std::cin.clear();
						std::cin.ignore(10000, '\n');
						cout<<"insert element to find:"<<endl;
				}
				matrix.FoldPreOrder(&foldFind<int>, &value, &index);
			}
			break;
			case 4:{
				int value;
				long acc=1;
				readIntValue(static_cast<void*>(&value), "insert n:");
				matrix.FoldPreOrder(&foldMultiplyLessThan<int>, &value, &acc);
				cout<<"product is: "<<acc<<endl;

			}
			break;
			case 5:{
				matrix.MapPreOrder(&mapDoubleElementValue<int>, (void*)0);
				matrix.MapPreOrder(&mapPrint<int>, 0);
				cout<<endl;


			}
			break;

			case 6:{

				editMatrix(matrix,&readIntValue);
			}
			break;
			case 7:{
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
void floatMatrixTest(lasd::Matrix<float>& matrix){

	bool isQuitOptionSelected=false;

	while (!isQuitOptionSelected)
	{
		cout<<std::string("\n--Int Matrix Test Menu--\n")
							+ "Please make your selection\n"
							+ "1 - PreOrder visit\n"
							+ "2 - PostOrder visit\n"
							+ "3 - Find Element\n"
							+ "4 - Sum greater then Function\n"
							+ "5 - Apply -n^3 function\n"
							+ "6 - Edit Matrix\n"
							+ "7 - back to main menu\n"
							+ "Selection: ";
		int choice = 0;

		if(!(std::cin >> choice)){
			std::cout << "Please enter numbers only";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		switch (choice){
			case 1:{
				matrix.MapPreOrder(&mapPrint<float>, (void*)0);
				std::cout << endl;
			}
			break;
			case 2:{
				matrix.MapPostOrder(&mapPrint<float>, (void*)0);
				std::cout << endl;
			}
			break;
			case 3:{
				float value;
				unsigned long index=0;
				cout<<"insert element to find:"<<endl;
				while(!(std::cin >> value)){
						std::cout << "Please enter numbers only: "<<endl;
						std::cin.clear();
						std::cin.ignore(10000, '\n');
						cout<<"insert element to find:"<<endl;
				}
				matrix.FoldPreOrder(&foldFloatFind, &value, &index);
			}
			break;
			case 4:{
				float value;
				float acc=0;
				readFloatValue(static_cast<void*>(&value), "insert n size:");
				cout<<"value is: "<<value<<endl;
				matrix.FoldPreOrder(&foldSumBiggerThan<float>, &value, &acc);
				cout<<"sum is: "<<acc<<endl;

			}
			break;
			case 5:{
				int power=3;
				matrix.MapPreOrder(&mapPowerNegativeElementValue<float>, (void*)&power);
				matrix.MapPreOrder(&mapPrint<float>, 0);
				cout<<endl;


			}
			break;

			case 6:{

				editMatrix(matrix,&readFloatValue);
			}
			break;
			case 7:{
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
void stringMatrixTest(lasd::Matrix<std::string>& matrix ){

	bool isQuitOptionSelected=false;

	while (!isQuitOptionSelected)
	{
		cout<<std::string("\n--String Matrix Test Menu--\n")
							+ "Please make your selection\n"
							+ "1 - PreOrder visit\n"
							+ "2 - PostOrder visit\n"
							+ "3 - Find Element\n"
							+ "4 - Concatenate less then n Function\n"
							+ "5 - Concatenate head\n"
							+ "6 - Edit Matrix\n"
							+ "7 - back to main menu\n"
							+ "Selection: ";
		int choice = 0;

		if(!(std::cin >> choice)){
			std::cout << "Please enter numbers only";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
		switch (choice){
			case 1:{
				matrix.MapPreOrder(&mapPrint<string>, (void*)0);
				std::cout << endl;
			}
			break;
			case 2:{
				matrix.MapPostOrder(&mapPrint<string>, (void*)0);
				std::cout << endl;
			}
			break;

			case 3:{

				string value;
				unsigned long index=0;
				readStringValue(static_cast<void*>(&value), "insert element to find:");

				matrix.FoldPreOrder(&foldFind<string>, &value, &index);

			}
			break;
			case 4:{

				int value;
				string acc="";
				readIntValue(static_cast<void*>(&value), "insert n:");
				matrix.FoldPreOrder(&foldStringLessEqThan, &value, &acc);
				cout<<"Concatenated String: "<<acc<<endl;

			}
			break;
			case 5:{
				string value;
				readStringValue(static_cast<void*>(&value), "insert string to concatenate:");
				matrix.MapPreOrder(&mapConcatInHead, (void*)&value);
				matrix.MapPreOrder(&mapPrint<string>, (void*)0);
			}
			break;
			case 6:{
				editMatrix(matrix,&readStringValue);
			}
			break;
			case 7:{
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

void foldFloatFind(const float& data,const void* target,void* index) {
	if(almost_equal<float>(data, *((float*)target),10)){
		std::cout<<"found element at index:"<<*((unsigned long*) index)<<std::endl;
	}
	*((unsigned long*) index) += 1;
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




