#include <iostream>

#include "../vector/vector.hpp"
#include <time.h>
#include <stdlib.h>
#include <random>
#include "test.hpp"
/* ************************************************************************** */

using namespace std;
void createRandomIntVector(unsigned long size){
	bool isQuitOptionSelected=false;
	std::cout<< "new vector\n";
	lasd::Vector<int> vec(size);

	default_random_engine genx(random_device{}());
	uniform_int_distribution<unsigned int> distx(7, 35);
	for(unsigned long i = 0; i<size; i++){

		vec[i]=distx(genx);
		cout << "vector "+to_string(i)+" "+to_string(vec[i]);
		cout << endl;
	}
	while (!isQuitOptionSelected)
	{
		cout<<std::string("Vector Menu\n")
						+ "Please make your selection\n"
						+ "1 - vector front element\n"
						+ "2 - vector back element\n"
						+ "3 - vector element at index\n"
						+ "4 - print vector\n"
						+ "5 - find element\n"
						+ "6 - sum less then n\n"
						+ "7 - back to main menu\n"
						+ "Selection: ";
		int choice = 0;
		std::cin >> choice;
		switch (choice){
			case 1:{
				cout<<"Vector front element: "+to_string(vec.Front())<<endl;
			}
			break;
			case 2:{
				cout<<"Vector back element: "+to_string(vec.Back())<<endl;
			}
			break;
			case 3:{
				int index;
				cout<<"insert index:"<<endl;
				cin>>index;
				try{
					cout<<vec[index];

				} catch (std::out_of_range&) {
					cout<<"invalid index\n";
				}


			}
			break;
			case 4:{
				vec.MapPreOrder(&mapPrint<int>, (void*)0);
			}
			break;
			case 5:{
				int value;
				unsigned long index=0;
				cout<<"insert element to find:"<<endl;
				cin>>value;
				vec.FoldPreOrder(&foldFind<int>, &value, &index);


			}
			break;
			case 6:{
				int value;
				unsigned long acc=0;
				cout<<"insert n size:"<<endl;
				cin>>value;
				vec.FoldPreOrder(&foldSumLessThan<int>, &value, &acc);
				cout<<"sum is: "<<acc<<endl;
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
};
