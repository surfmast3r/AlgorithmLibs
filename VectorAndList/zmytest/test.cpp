#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <random>
#include <list>
#include "test.hpp"
using namespace std;

/* ************************************************************************** */
/* Stack */
void createIntStack(){
	bool isQuitOptionSelected=false;

	unsigned long size;

	std::cout<<"insert Stack size\n";
	while(!(std::cin >> size)){
		std::cout << "Please enter numbers only: "<<endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout<<"insert Stack size\n";
	}

	while (!isQuitOptionSelected)
		{
			cout<<std::string("\n--Int Stack Menu--\n");
			std::cout<<"insert Stack type"<<endl;
			std::cout<<"1: Stack Vector"<<endl;
			std::cout<<"2: Stack List"<<endl;
			std::cout<<"3: Back"<<endl;
			std::cout<<"Selection: ";
			int choice = 0;

			if(!(std::cin >> choice)){
				std::cout << "Please enter numbers only: ";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			switch (choice){
				case 1:{
					cout<<"Stack Vector "<<endl;
					lasd::Vector<int> vec(size);
					populateRandomIntVector(vec);
					lasd::StackVec<int> stackVec(vec);
					intStackTest(stackVec);
				}
				break;
				case 2:{
					cout<<"Stack List "<<endl;
					lasd::List<int> list;
					populateRandomIntList(list,size);
					lasd::StackLst<int> stackLst(list);
					intStackTest(stackLst);
				}
				break;
				case 3:{
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
void createFloatStack(){
	bool isQuitOptionSelected=false;

	unsigned long size;

	std::cout<<"insert Stack size\n";
	while(!(std::cin >> size)){
		std::cout << "Please enter numbers only"<<endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout<<"insert vector size\n";
	}

	while (!isQuitOptionSelected)
		{
			cout<<std::string("\n--Float Stack Menu--\n");
			std::cout<<"insert Stack type"<<endl;
			std::cout<<"1: Stack Vector"<<endl;
			std::cout<<"2: Stack List"<<endl;
			std::cout<<"3: Back"<<endl;
			std::cout<<"Selection: ";
			int choice = 0;

			if(!(std::cin >> choice)){
				std::cout << "Please enter numbers only";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			switch (choice){
				case 1:{
					cout<<"Stack Vector "<<endl;
					lasd::Vector<float> vec(size);
					populateRandomFloatVector(vec);
					lasd::StackVec<float> stackVec(vec);
					floatStackTest(stackVec);
				}
				break;
				case 2:{
					cout<<"Stack List "<<endl;
					lasd::List<float> list;
					populateRandomFloatList(list,size);
					lasd::StackLst<float> stackLst(list);
					floatStackTest(stackLst);
				}
				break;
				case 3:{
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
void createStringStack(){
	bool isQuitOptionSelected=false;

	unsigned long size;

	std::cout<<"insert Stack size\n";
	while(!(std::cin >> size)){
		std::cout << "Please enter numbers only"<<endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout<<"insert vector size\n";
	}

	while (!isQuitOptionSelected)
		{
			cout<<std::string("\n--String Stack Menu--\n");
			std::cout<<"insert Stack type"<<endl;
			std::cout<<"1: Stack Vector"<<endl;
			std::cout<<"2: Stack List"<<endl;
			std::cout<<"3: Back"<<endl;
			std::cout<<"Selection: ";
			int choice = 0;

			if(!(std::cin >> choice)){
				std::cout << "Please enter numbers only";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			switch (choice){
				case 1:{
					cout<<"Stack Vector "<<endl;
					lasd::Vector<string> vec(size);
					populateRandomStringVector(vec);
					lasd::StackVec<string> stackVec(vec);
					stringStackTest(stackVec);
				}
				break;
				case 2:{
					cout<<"Stack List "<<endl;
					lasd::List<string> list;
					populateRandomStringList(list,size);
					lasd::StackLst<string> stackLst(list);
					stringStackTest(stackLst);
				}
				break;
				case 3:{
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

void intStackTest(lasd::Stack<int>& stack){
	bool isQuitOptionSelected=false;

	while (!isQuitOptionSelected)
		{
			cout<<std::string("\n--Int Stack Test Menu--\n")
								+ "Please make your selection\n"
								+ "1 - push element\n"
								+ "2 - pop element\n"
								+ "3 - top&pop element\n"
								+ "4 - top element\n"
								+ "5 - check if stack is empty\n"
								+ "6 - stack size\n"
								+ "7 - clear stack\n"
								+ "8 - back to main menu\n"
								+ "Selection: ";
			int choice = 0;

			if(!(std::cin >> choice)){
				std::cout << "Please enter numbers only";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			switch (choice){
				case 1:{
					int value;
					cout<<"insert int value:"<<endl;
					while(!(std::cin >> value)){
						std::cout << "Please enter numbers only";
						std::cin.clear();
						std::cin.ignore(10000, '\n');
					}
					stack.Push(value);

				}
				break;
				case 2:{
					try{
						int topValue=stack.Top();
						stack.Pop();

						cout<<"Removed element: "<<topValue<<endl;

					} catch (std::length_error&) {
						cout<<"Stack is empty"<<endl;
					}
				}
				break;
				case 3:{
					try{
						int popValue=stack.TopNPop();
						cout<<"Top&pop element: "<<popValue<<endl;

					} catch (std::length_error&) {
						cout<<"Stack is empty"<<endl;
					}
				}
				break;
				case 4:{
					try{
						int topValue=stack.Top();
						cout<<"Top element: "<<topValue<<endl;

					} catch (std::length_error&) {
						cout<<"Stack is empty"<<endl;
					}
				}
				break;
				case 5:{

					if(stack.Empty()){
						cout<<"Stack is empty"<<endl;
					}else{
						cout<<"Stack is not empty"<<endl;
					}

				}
				break;
				case 6:{

					cout<<"Stack size: "<<stack.Size();
					cout<<endl;

				}
				break;
				case 7:{
					cout<<"Clearing Stack .. "<<endl;
					stack.Clear();
					cout<<"Stack size: "<<stack.Size();
					cout<<endl;

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


}
void floatStackTest(lasd::Stack<float>& stack){
	bool isQuitOptionSelected=false;

	while (!isQuitOptionSelected)
		{
			cout<<std::string("\n--Float Stack Test Menu--\n")
								+ "Please make your selection\n"
								+ "1 - push element\n"
								+ "2 - pop element\n"
								+ "3 - top&pop element\n"
								+ "4 - top element\n"
								+ "5 - check if stack is empty\n"
								+ "6 - stack size\n"
								+ "7 - clear stack\n"
								+ "8 - back to main menu\n"
								+ "Selection: ";
			int choice = 0;

			if(!(std::cin >> choice)){
				std::cout << "Please enter numbers only";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			switch (choice){
				case 1:{
					float value;
					cout<<"insert value:"<<endl;
					while(!(std::cin >> value)){
						std::cout << "Please enter numbers only";
						std::cin.clear();
						std::cin.ignore(10000, '\n');
					}
					stack.Push(value);

				}
				break;
				case 2:{
					try{
						float topValue=stack.Top();
						stack.Pop();

						cout<<"Removed element: "<<topValue<<endl;

					} catch (std::length_error&) {
						cout<<"Stack is empty"<<endl;
					}
				}
				break;
				case 3:{
					try{
						float popValue=stack.TopNPop();
						cout<<"Top&pop element: "<<popValue<<endl;

					} catch (std::length_error&) {
						cout<<"Stack is empty"<<endl;
					}
				}
				break;
				case 4:{
					try{
						float topValue=stack.Top();
						cout<<"Top element: "<<topValue<<endl;

					} catch (std::length_error&) {
						cout<<"Stack is empty"<<endl;
					}
				}
				break;
				case 5:{

					if(stack.Empty()){
						cout<<"Stack is empty"<<endl;
					}else{
						cout<<"Stack is not empty"<<endl;
					}

				}
				break;
				case 6:{

					cout<<"Stack size: "<<stack.Size()<<endl;

				}
				break;
				case 7:{
					cout<<"Clearing Stack .. "<<endl;
					stack.Clear();
					cout<<"Stack size: "<<stack.Size()<<endl;

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


}
void stringStackTest(lasd::Stack<string>& stack){
	bool isQuitOptionSelected=false;

	while (!isQuitOptionSelected)
		{
			cout<<std::string("\n--String Stack Test Menu--\n")
								+ "Please make your selection\n"
								+ "1 - push element\n"
								+ "2 - pop element\n"
								+ "3 - top&pop element\n"
								+ "4 - top element\n"
								+ "5 - check if stack is empty\n"
								+ "6 - stack size\n"
								+ "7 - clear stack\n"
								+ "8 - back to main menu\n"
								+ "Selection: ";
			int choice = 0;

			if(!(std::cin >> choice)){
				std::cout << "Please enter numbers only";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			switch (choice){
				case 1:{
					string value="";
					cout<<"insert string:"<<endl;
					cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
					getline(cin,value);
					stack.Push(value);

				}
				break;
				case 2:{
					try{
						string topValue=stack.Top();
						stack.Pop();

						cout<<"Removed element: "<<topValue<<endl;

					} catch (std::length_error&) {
						cout<<"Stack is empty"<<endl;
					}
				}
				break;
				case 3:{
					try{
						string popValue=stack.TopNPop();
						cout<<"Top&pop element: "<<popValue<<endl;

					} catch (std::length_error&) {
						cout<<"Stack is empty"<<endl;
					}
				}
				break;
				case 4:{
					try{
						string topValue=stack.Top();
						cout<<"Top element: "<<topValue<<endl;

					} catch (std::length_error&) {
						cout<<"Stack is empty"<<endl;
					}
				}
				break;
				case 5:{

					if(stack.Empty()){
						cout<<"Stack is empty"<<endl;
					}else{
						cout<<"Stack is not empty"<<endl;
					}

				}
				break;
				case 6:{

					cout<<"Stack size: "<<stack.Size()<<endl;

				}
				break;
				case 7:{
					cout<<"Clearing Stack .. "<<endl;
					stack.Clear();
					cout<<"Stack size: "<<stack.Size()<<endl;

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


}
/* ************************************************************************** */
/* Queue */
void myQueueTest(){

	lasd::Vector<int>vec1(6);
	lasd::Vector<int>vec2(8);
	populateRandomIntVector(vec1);
	lasd::QueueVec<int>queue1(vec1);
	lasd::QueueVec<int>queue2(vec2);
	queue2.Dequeue();
	queue2.Enqueue(10);
	queue2.Dequeue();
	queue2.Enqueue(26);
	queue2.Dequeue();
	queue2.Enqueue(21);
	queue2.Dequeue();
	queue2.Enqueue(20);
	queue2.Dequeue();
	queue2.Enqueue(25);
	queue2.Dequeue();
		queue2.Enqueue(17);
		queue2.Dequeue();
		queue2.Dequeue();
	if(queue1==queue2){
		cout<<"uguali";
	}

}
void createIntQueue(){
	bool isQuitOptionSelected=false;

	unsigned long size;

	std::cout<<"insert Queue size\n";
	while(!(std::cin >> size)){
		std::cout << "Please enter numbers only: "<<endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout<<"insert Queue size\n";
	}

	while (!isQuitOptionSelected)
		{
			cout<<std::string("\n--Int Queue Menu--\n");
			std::cout<<"insert Queue type"<<endl;
			std::cout<<"1: Queue Vector"<<endl;
			std::cout<<"2: Queue List"<<endl;
			std::cout<<"3: Back"<<endl;
			std::cout<<"Selection: ";
			int choice = 0;

			if(!(std::cin >> choice)){
				std::cout << "Please enter numbers only: ";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			switch (choice){
				case 1:{
					cout<<"Queue Vector "<<endl;
					lasd::Vector<int> vec(size);
					populateRandomIntVector(vec);

					lasd::QueueVec<int> queueVec(vec);
					intQueueTest(queueVec);
				}
				break;
				case 2:{
					cout<<"Queue List "<<endl;
					lasd::List<int> list;
					populateRandomIntList(list,size);

					lasd::QueueLst<int> queueLst(list);
					intQueueTest(queueLst);
				}
				break;
				case 3:{
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
void createFloatQueue(){
	bool isQuitOptionSelected=false;

	unsigned long size;

	std::cout<<"insert Queue size\n";
	while(!(std::cin >> size)){
		std::cout << "Please enter numbers only: "<<endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout<<"insert Queue size\n";
	}

	while (!isQuitOptionSelected)
		{
			cout<<std::string("\n--Int Queue Menu--\n");
			std::cout<<"insert Queue type"<<endl;
			std::cout<<"1: Queue Vector"<<endl;
			std::cout<<"2: Queue List"<<endl;
			std::cout<<"3: Back"<<endl;
			std::cout<<"Selection: ";
			int choice = 0;

			if(!(std::cin >> choice)){
				std::cout << "Please enter numbers only: ";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			switch (choice){
				case 1:{
					cout<<"Queue Vector "<<endl;
					lasd::Vector<float> vec(size);
					populateRandomFloatVector(vec);
					lasd::QueueVec<float> queueVec(vec);
					floatQueueTest(queueVec);
				}
				break;
				case 2:{
					cout<<"Queue List "<<endl;
					lasd::List<float> list;
					populateRandomFloatList(list,size);
					lasd::QueueLst<float> queueLst(list);
					floatQueueTest(queueLst);
				}
				break;
				case 3:{
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
void createStringQueue(){
	bool isQuitOptionSelected=false;

	unsigned long size;

	std::cout<<"insert Queue size\n";
	while(!(std::cin >> size)){
		std::cout << "Please enter numbers only: "<<endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout<<"insert Queue size\n";
	}

	while (!isQuitOptionSelected)
		{
			cout<<std::string("\n--String Queue Menu--\n");
			std::cout<<"insert Queue type"<<endl;
			std::cout<<"1: Queue Vector"<<endl;
			std::cout<<"2: Queue List"<<endl;
			std::cout<<"3: Back"<<endl;
			std::cout<<"Selection: ";
			int choice = 0;

			if(!(std::cin >> choice)){
				std::cout << "Please enter numbers only: ";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			switch (choice){
				case 1:{
					cout<<"Queue Vector "<<endl;
					lasd::Vector<string> vec(size);
					populateRandomStringVector(vec);
					lasd::QueueVec<string> queueVec(vec);
					stringQueueTest(queueVec);
				}
				break;
				case 2:{
					cout<<"Queue List "<<endl;
					lasd::List<string> list;
					populateRandomStringList(list,size);
					lasd::QueueLst<string> queueLst(list);
					stringQueueTest(queueLst);
				}
				break;
				case 3:{
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

void intQueueTest(lasd::Queue<int>& queue){
	bool isQuitOptionSelected=false;

	while (!isQuitOptionSelected)
		{
			cout<<std::string("\n--Int Queue Test Menu--\n")
								+ "Please make your selection\n"
								+ "1 - Enqueue element\n"
								+ "2 - Dequeue element\n"
								+ "3 - Head&Dequeue element\n"
								+ "4 - Head element\n"
								+ "5 - check if Queue is empty\n"
								+ "6 - Queue size\n"
								+ "7 - clear Queue\n"
								+ "8 - back to main menu\n"
								+ "Selection: ";
			int choice = 0;

			if(!(std::cin >> choice)){
				std::cout << "Please enter numbers only";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			switch (choice){
				case 1:{
					int value;
					cout<<"insert int value:"<<endl;
					while(!(std::cin >> value)){
						std::cout << "Please enter numbers only";
						std::cin.clear();
						std::cin.ignore(10000, '\n');
					}
					queue.Enqueue(value);

				}
				break;
				case 2:{
					try{
						int headValue=queue.Head();//add try-catch
						queue.Dequeue();

						cout<<"Removed element: "<<headValue<<endl;

					} catch (std::length_error&) {
						cout<<"Queue is empty"<<endl;
					}
				}
				break;
				case 3:{
					try{
						int headValue=queue.HeadNDequeue();
						cout<<"Head&Dequeue element: "<<headValue<<endl;

					} catch (std::length_error&) {
						cout<<"Queue is empty"<<endl;
					}
				}
				break;
				case 4:{
					try{
						int headValue=queue.Head();
						cout<<"Head element: "<<headValue<<endl;

					} catch (std::length_error&) {
						cout<<"Queue is empty"<<endl;
					}
				}
				break;
				case 5:{

					if(queue.Empty()){
						cout<<"Queue is empty"<<endl;
					}else{
						cout<<"Queue is not empty"<<endl;
					}

				}
				break;
				case 6:{

					cout<<"Queue size: "<<queue.Size();
					cout<<endl;

				}
				break;
				case 7:{
					cout<<"Clearing Queue .. "<<endl;
					queue.Clear();
					cout<<"Queue size: "<<queue.Size();
					cout<<endl;

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
}
void floatQueueTest(lasd::Queue<float>& queue){
	bool isQuitOptionSelected=false;

	while (!isQuitOptionSelected)
		{
			cout<<std::string("\n--Float Queue Test Menu--\n")
								+ "Please make your selection\n"
								+ "1 - Enqueue element\n"
								+ "2 - Dequeue element\n"
								+ "3 - Head&Dequeue element\n"
								+ "4 - Head element\n"
								+ "5 - check if Queue is empty\n"
								+ "6 - Queue size\n"
								+ "7 - clear Queue\n"
								+ "8 - back to main menu\n"
								+ "Selection: ";
			int choice = 0;

			if(!(std::cin >> choice)){
				std::cout << "Please enter numbers only";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			switch (choice){
				case 1:{
					float value;
					cout<<"insert value:"<<endl;
					while(!(std::cin >> value)){
						std::cout << "Please enter numbers only";
						std::cin.clear();
						std::cin.ignore(10000, '\n');
					}
					queue.Enqueue(value);

				}
				break;
				case 2:{
					try{
						float headValue=queue.Head();//add try-catch
						queue.Dequeue();

						cout<<"Removed element: "<<headValue<<endl;

					} catch (std::length_error&) {
						cout<<"Queue is empty"<<endl;
					}
				}
				break;
				case 3:{
					try{
						float headValue=queue.HeadNDequeue();
						cout<<"Head&Dequeue element: "<<headValue<<endl;

					} catch (std::length_error&) {
						cout<<"Queue is empty"<<endl;
					}
				}
				break;
				case 4:{
					try{
						float headValue=queue.Head();
						cout<<"Head element: "<<headValue<<endl;

					} catch (std::length_error&) {
						cout<<"Queue is empty"<<endl;
					}
				}
				break;
				case 5:{

					if(queue.Empty()){
						cout<<"Queue is empty"<<endl;
					}else{
						cout<<"Queue is not empty"<<endl;
					}

				}
				break;
				case 6:{

					cout<<"Queue size: "<<queue.Size();
					cout<<endl;

				}
				break;
				case 7:{
					cout<<"Clearing Queue .. "<<endl;
					queue.Clear();
					cout<<"Queue size: "<<queue.Size();
					cout<<endl;

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
}
void stringQueueTest(lasd::Queue<string>& queue){
	bool isQuitOptionSelected=false;

	while (!isQuitOptionSelected)
		{
			cout<<std::string("\n--String Queue Test Menu--\n")
								+ "Please make your selection\n"
								+ "1 - Enqueue element\n"
								+ "2 - Dequeue element\n"
								+ "3 - Head&Dequeue element\n"
								+ "4 - Head element\n"
								+ "5 - check if Queue is empty\n"
								+ "6 - Queue size\n"
								+ "7 - clear Queue\n"
								+ "8 - back to main menu\n"
								+ "Selection: ";
			int choice = 0;

			if(!(std::cin >> choice)){
				std::cout << "Please enter numbers only";
				std::cin.clear();
				std::cin.ignore(10000, '\n');
			}
			switch (choice){
				case 1:{
					string value="";
					cout<<"insert string:"<<endl;
					cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
					getline(cin,value);
					queue.Enqueue(value);

				}
				break;
				case 2:{
					try{
						string headValue=queue.Head();//add try-catch
						queue.Dequeue();

						cout<<"Removed element: "<<headValue<<endl;

					} catch (std::length_error&) {
						cout<<"Queue is empty"<<endl;
					}
				}
				break;
				case 3:{
					try{
						string headValue=queue.HeadNDequeue();
						cout<<"Head&Dequeue element: "<<headValue<<endl;

					} catch (std::length_error&) {
						cout<<"Queue is empty"<<endl;
					}
				}
				break;
				case 4:{
					try{
						string headValue=queue.Head();
						cout<<"Head element: "<<headValue<<endl;

					} catch (std::length_error&) {
						cout<<"Queue is empty"<<endl;
					}
				}
				break;
				case 5:{

					if(queue.Empty()){
						cout<<"Queue is empty"<<endl;
					}else{
						cout<<"Queue is not empty"<<endl;
					}

				}
				break;
				case 6:{

					cout<<"Queue size: "<<queue.Size();
					cout<<endl;

				}
				break;
				case 7:{
					cout<<"Clearing Queue .. "<<endl;
					queue.Clear();
					cout<<"Queue size: "<<queue.Size();
					cout<<endl;

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
}

/* ************************************************************************** */
/* Vector */
//void testIntVector(){
//
//	bool isQuitOptionSelected=false;
//	unsigned long size;
//
//	std::cout<<"insert vector size\n";
//	//std::cin>>size;
//	while(!(std::cin >> size)){
//		std::cout << "Please enter numbers only: "<<endl;
//		std::cin.clear();
//		std::cin.ignore(10000, '\n');
//		std::cout<<"insert vector size\n";
//	}
//	std::cout<< "new vector\n";
//	lasd::Vector<int> vec(size);
//	populateRandomIntVector(vec);
//
//	while (!isQuitOptionSelected)
//	{
//		cout<<std::string("\nVector Menu\n")
//						+ "Please make your selection\n"
//						+ "1 - vector front element\n"
//						+ "2 - vector back element\n"
//						+ "3 - vector element at index\n"
//						+ "4 - print vector\n"
//						+ "5 - find element\n"
//						+ "6 - sum less then n\n"
//						+ "7 - apply 2n function n\n"
//						+ "8 - back to main menu\n"
//						+ "Selection: ";
//		int choice = 0;
//		//std::cin >> choice;
//		if(!(std::cin >> choice)){
//			std::cout << "Please enter numbers only: ";
//			std::cin.clear();
//			std::cin.ignore(10000, '\n');
//		}
//		switch (choice){
//			case 1:{
//				cout<<"Vector front element: "+to_string(vec.Front())<<endl;
//			}
//			break;
//			case 2:{
//				cout<<"Vector back element: "+to_string(vec.Back())<<endl;
//			}
//			break;
//			case 3:{
//				int index;
//				cout<<"insert index:"<<endl;
//				while(!(std::cin >> index)){
//					std::cout << "Please enter numbers only: insert index";
//					std::cin.clear();
//					std::cin.ignore(10000, '\n');
//				}
//				try{
//					cout<<vec[index];
//
//				} catch (std::out_of_range&) {
//					cout<<"invalid index\n";
//				}
//
//
//			}
//			break;
//			case 4:{
//				vec.MapPreOrder(&mapPrint<int>, (void*)0);
//				cout<<endl;
//			}
//			break;
//			case 5:{
//				int value;
//				unsigned long index=0;
//				cout<<"insert element to find:"<<endl;
//				if(!(std::cin >> value)){
//					std::cout << "Please enter numbers only: ";
//					std::cin.clear();
//					std::cin.ignore(10000, '\n');
//				}
//				vec.FoldPreOrder(&foldFind<int>, &value, &index);
//
//
//			}
//			break;
//			case 6:{
//				int value;
//				unsigned long acc=0;
//				cout<<"insert n size:"<<endl;
//				while(!(std::cin >> value)){
//					std::cout << "Please enter numbers only: ";
//					std::cin.clear();
//					std::cin.ignore(10000, '\n');
//				}
//				vec.FoldPreOrder(&foldSumLessThan<int>, &value, &acc);
//				cout<<"sum is: "<<acc<<endl;
//			}
//			break;
//			case 7:{
//
//				vec.MapPreOrder(&mapDoubleElementValue<int>, (void*)0);
//				vec.MapPreOrder(&mapPrint<int>, 0);
//				cout<<endl;
//			}
//			break;
//			case 8:{
//				isQuitOptionSelected=true;
//			}
//			break;
//			default:
//			{
//				// Do nothing
//			}
//		}
//
//
//	}
//};
//void testStringVector(){
//	bool isQuitOptionSelected=false;
//	unsigned long size;
//
//	std::cout<<"insert vector size\n";
//	while(!(std::cin >> size)){
//		std::cout << "Please enter numbers only: "<<endl;
//		std::cin.clear();
//		std::cin.ignore(10000, '\n');
//		std::cout<<"insert vector size\n";
//	}
//	std::cout<< "new vector\n";
//	lasd::Vector<string> vec(size);
//	populateRandomStringVector(vec);
//
//	while (!isQuitOptionSelected)
//	{
//		cout<<std::string("\nVector Menu\n")
//						+ "Please make your selection\n"
//						+ "1 - vector front element\n"
//						+ "2 - vector back element\n"
//						+ "3 - vector element at index\n"
//						+ "4 - print vector\n"
//						+ "5 - find element\n"
//						+ "6 - concat less then n\n"
//						+ "7 - apply uppercase function\n"
//						+ "8 - back to main menu\n"
//						+ "Selection: ";
//		int choice = 0;
//		//std::cin >> choice;
//		if(!(std::cin >> choice)){
//			std::cout << "Please enter numbers only: ";
//			std::cin.clear();
//			std::cin.ignore(10000, '\n');
//		}
//		switch (choice){
//			case 1:{
//				cout<<"Vector front element: "+vec.Front()<<endl;
//			}
//			break;
//			case 2:{
//				cout<<"Vector back element: "+vec.Back()<<endl;
//			}
//			break;
//			case 3:{
//				int index;
//				cout<<"insert index:"<<endl;
//				while(!(std::cin >> index)){
//					std::cout << "Please enter numbers only: ";
//					std::cin.clear();
//					std::cin.ignore(10000, '\n');
//				}
//				try{
//					cout<<vec[index];
//
//				} catch (std::out_of_range&) {
//					cout<<"invalid index\n";
//				}
//
//
//			}
//			break;
//			case 4:{
//				vec.MapPreOrder(&mapPrint<string>, (void*)0);
//				cout<<endl;
//			}
//			break;
//			case 5:{
//				string value="";
//				unsigned long index=0;
//				cout<<"insert element to find:"<<endl;
//				cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
//				getline(cin,value);
//				vec.FoldPreOrder(&foldFind<string>, &value, &index);
//
//
//			}
//			break;
//			case 6:{
//				unsigned int value;
//				string acc="";
//				cout<<"insert n size:"<<endl;
//				if(!(std::cin >> value)){
//					std::cout << "Please enter numbers only: ";
//					std::cin.clear();
//					std::cin.ignore(10000, '\n');
//				}else{
//					vec.FoldPreOrder(&foldStringLessEqThan, &value, &acc);
//					cout<<"concat string: "<<acc<<endl;
//				}
//
//			}
//			break;
//			case 7:{
//				vec.MapPreOrder(&mapUppercase,0);
//				vec.MapPreOrder(&mapPrint<string>, (void*)0);
//			}
//			break;
//			case 8:{
//				isQuitOptionSelected=true;
//			}
//			break;
//			default:
//			{
//				// Do nothing
//			}
//		}
//
//
//	}
//};
//void testFloatVector(){
//
//	bool isQuitOptionSelected=false;
//	unsigned long size;
//
//	std::cout<<"insert vector size\n";
//	while(!(std::cin >> size)){
//		std::cout << "Please enter numbers only: "<<endl;
//		std::cin.clear();
//		std::cin.ignore(10000, '\n');
//		std::cout<<"insert vector size\n";
//	}
//	std::cout<< "new vector\n";
//	lasd::Vector<float> vec(size);
//	populateRandomFloatVector(vec);
//
//	while (!isQuitOptionSelected)
//	{
//		cout<<std::string("\nFloat Vector Menu\n")
//						+ "Please make your selection\n"
//						+ "1 - vector front element\n"
//						+ "2 - vector back element\n"
//						+ "3 - vector element at index\n"
//						+ "4 - print vector\n"
//						+ "5 - find element\n"
//						+ "6 - multiply greater then n\n"
//						+ "7 - apply n^2 function n\n"
//						+ "8 - back to main menu\n"
//						+ "Selection: ";
//		int choice = 0;
//		//std::cin >> choice;
//		if(!(std::cin >> choice)){
//			std::cout << "Please enter numbers only: ";
//			std::cin.clear();
//			std::cin.ignore(10000, '\n');
//		}
//		switch (choice){
//			case 1:{
//				cout<<"Vector front element: "+to_string(vec.Front())<<endl;
//			}
//			break;
//			case 2:{
//				cout<<"Vector back element: "+to_string(vec.Back())<<endl;
//			}
//			break;
//			case 3:{
//				int index;
//				cout<<"insert index:"<<endl;
//				while(!(std::cin >> index)){
//					std::cout << "Please enter numbers only: ";
//					std::cin.clear();
//					std::cin.ignore(10000, '\n');
//				}
//				try{
//					cout<<vec[index];
//
//				} catch (std::out_of_range&) {
//					cout<<"invalid index\n";
//				}
//
//
//			}
//			break;
//			case 4:{
//				vec.MapPreOrder(&mapPrint<float>, (void*)0);
//				cout<<endl;
//			}
//			break;
//			case 5:{
//				float value;
//				unsigned long index=0;
//				cout<<"insert element to find:"<<endl;
//				if(!(std::cin >> value)){
//					std::cout << "Please enter numbers only: ";
//					std::cin.clear();
//					std::cin.ignore(10000, '\n');
//				}else{
//					cout<<"value to find: "<<value<<endl;
//					vec.FoldPreOrder(&foldFloatFind<float>, &value, &index);
//				}
//
//
//			}
//			break;
//			case 6:{
//				float value;
//				float acc=1;
//				cout<<"insert n size:"<<endl;
//				if(!(std::cin >> value)){
//					std::cout << "Please enter numbers only: ";
//					std::cin.clear();
//					std::cin.ignore(10000, '\n');
//				}
//				else{
//					vec.FoldPreOrder(&foldMultiplyGreaterThan<float>, &value, &acc);
//					cout<<"product is: "<<acc<<endl;
//				}
//
//			}
//			break;
//			case 7:{
//
//				vec.MapPreOrder(&mapSquareElementValue<float>, (void*)0);
//				vec.MapPreOrder(&mapPrint<float>, 0);
//				cout<<endl;
//			}
//			break;
//			case 8:{
//				isQuitOptionSelected=true;
//			}
//			break;
//			default:
//			{
//				// Do nothing
//			}
//		}
//
//
//	}
//};

void populateRandomIntVector(lasd::Vector<int>& vec){
	std::cout<< "populating int vector\n";
	unsigned int size=vec.Size();
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
	unsigned int size=vec.Size();
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
	unsigned int size=vec.Size();
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
/*List*/
//void testIntList(){
//
//	bool isQuitOptionSelected=false;
//	unsigned long size;
//
//	std::cout<<"insert List size\n";
//	while(!(std::cin >> size)){
//		std::cout << "Please enter numbers only: "<<endl;
//		std::cin.clear();
//		std::cin.ignore(10000, '\n');
//		std::cout<<"insert list size\n";
//	}
//	std::cout<< "new list\n";
//	lasd::List<int> list;
//	populateRandomIntList(list,size);
//
//	while (!isQuitOptionSelected)
//	{
//		cout<<std::string("\nList int Menu\n")
//						+ "Please make your selection\n"
//						+ "1 - list front element\n"
//						+ "2 - list back element\n"
//						+ "3 - list element at index\n"
//						+ "4 - print list\n"
//						+ "5 - find element\n"
//						+ "6 - sum less then n\n"
//						+ "7 - apply 2n function n\n"
//						+ "8 - back to main menu\n"
//						+ "Selection: ";
//		int choice = 0;
//		if(!(std::cin >> choice)){
//				std::cout << "Please enter numbers only: "<<endl;
//				std::cin.clear();
//				std::cin.ignore(10000, '\n');
//		}
//		switch (choice){
//			case 1:{
//				cout<<"List front element: "+to_string(list.Front())<<endl;
//			}
//			break;
//			case 2:{
//				cout<<"List back element: "+to_string(list.Back())<<endl;
//			}
//			break;
//			case 3:{
//				int index;
//				cout<<"insert index:"<<endl;
//				if(!(std::cin >> index)){
//						std::cout << "Please enter numbers only: "<<endl;
//						std::cin.clear();
//						std::cin.ignore(10000, '\n');
//
//				}else{
//					try{
//						cout<<list[index];
//
//					} catch (std::out_of_range&) {
//						cout<<"invalid index\n";
//					}
//				}
//
//
//
//			}
//			break;
//			case 4:{
//				list.MapPreOrder(&mapPrint<int>, (void*)0);
//			}
//			break;
//			case 5:{
//				int value;
//				unsigned long index=0;
//				cout<<"insert element to find:"<<endl;
//				while(!(std::cin >> value)){
//						std::cout << "Please enter numbers only: "<<endl;
//						std::cin.clear();
//						std::cin.ignore(10000, '\n');
//						cout<<"insert element to find:"<<endl;
//				}
//				list.FoldPreOrder(&foldFind<int>, &value, &index);
//
//
//			}
//			break;
//			case 6:{
//				int value;
//				unsigned long acc=0;
//				cout<<"insert n size:"<<endl;
//				while(!(std::cin >> value)){
//						std::cout << "Please enter numbers only: "<<endl;
//						std::cin.clear();
//						std::cin.ignore(10000, '\n');
//						cout<<"insert n size:"<<endl;
//				}
//				list.FoldPreOrder(&foldSumLessThan<int>, &value, &acc);
//				cout<<"sum is: "<<acc<<endl;
//			}
//			break;
//			case 7:{
//
//				list.MapPreOrder(&mapDoubleElementValue<int>, (void*)0);
//				list.MapPreOrder(&mapPrint<int>, 0);
//				cout<<endl;
//			}
//			break;
//			case 8:{
//				isQuitOptionSelected=true;
//			}
//			break;
//			default:
//			{
//				// Do nothing
//			}
//		}
//
//
//	}
//};
//void testStringList(){
//
//	bool isQuitOptionSelected=false;
//	unsigned long size;
//
//	std::cout<<"insert List size\n";
//	while(!(std::cin >> size)){
//		std::cout << "Please enter numbers only: "<<endl;
//		std::cin.clear();
//		std::cin.ignore(10000, '\n');
//		std::cout<<"insert list size\n";
//	}
//	std::cout<< "new list\n";
//	lasd::List<std::string> list;
//	populateRandomStringList(list,size);
//
//	while (!isQuitOptionSelected)
//	{
//		cout<<std::string("\nList Menu\n")
//						+ "Please make your selection\n"
//						+ "1 - list front element\n"
//						+ "2 - list back element\n"
//						+ "3 - list element at index\n"
//						+ "4 - print list\n"
//						+ "5 - find element\n"
//						+ "6 - concat less then n\n"
//						+ "7 - apply uppercase function\n"
//						+ "8 - back to main menu\n"
//						+ "Selection: ";
//		int choice = 0;
//		if(!(std::cin >> choice)){
//				std::cout << "Please enter numbers only "<<endl;
//				std::cin.clear();
//				std::cin.ignore(10000, '\n');
//
//			}
//		switch (choice){
//			case 1:{
//				cout<<"Vector front element: "+list.Front()<<endl;
//			}
//			break;
//			case 2:{
//				cout<<"Vector back element: "+list.Back()<<endl;
//			}
//			break;
//			case 3:{
//				int index;
//				cout<<"insert index:"<<endl;
//				if(!(std::cin >> index)){
//						std::cout << "Please enter numbers only "<<endl;
//						std::cin.clear();
//						std::cin.ignore(10000, '\n');
//
//				}else{
//					try{
//						cout<<list[index];
//
//					} catch (std::out_of_range&) {
//						cout<<"invalid index\n";
//					}
//				}
//
//
//			}
//			break;
//			case 4:{
//				printMappableContainer(list);
//
//			}
//			break;
//			case 5:{
//				string value="";
//				unsigned long index=0;
//				cout<<"insert element to find:"<<endl;
//				cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
//				getline(cin,value);
//				list.FoldPreOrder(&foldFind<string>, &value, &index);
//
//
//			}
//			break;
//			case 6:{
//				unsigned int value;
//				string acc="";
//				cout<<"insert n size:"<<endl;
//				while(!(std::cin >> value)){
//						std::cout << "Please enter numbers only: "<<endl;
//						std::cin.clear();
//						std::cin.ignore(10000, '\n');
//						std::cout<<"insert n size:\n";
//				}
//				list.FoldPreOrder(&foldStringLessEqThan, &value, &acc);
//				cout<<"concat string: "<<acc<<endl;
//
//			}
//			break;
//			case 7:{
//				list.MapPreOrder(&mapUppercase,0);
//				printMappableContainer(list);
//			}
//			break;
//			case 8:{
//				isQuitOptionSelected=true;
//			}
//			break;
//			default:
//			{
//				// Do nothing
//			}
//		}
//
//
//	}
//};
//void testFloatList(){
//	bool isQuitOptionSelected=false;
//	unsigned long size;
//
//	std::cout<<"insert list size\n";
//	while(!(std::cin >> size)){
//		std::cout << "Please enter numbers only: "<<endl;
//		std::cin.clear();
//		std::cin.ignore(10000, '\n');
//		std::cout<<"insert list size\n";
//	}
//	std::cout<< "new list\n";
//	lasd::List<float> list;
//	populateRandomFloatList(list,size);
//
//	while (!isQuitOptionSelected)
//	{
//		cout<<std::string("\nFloat List Menu\n")
//						+ "Please make your selection\n"
//						+ "1 - list front element\n"
//						+ "2 - list back element\n"
//						+ "3 - list element at index\n"
//						+ "4 - print list\n"
//						+ "5 - find element\n"
//						+ "6 - multiply greater then n\n"
//						+ "7 - apply n^2 function n\n"
//						+ "8 - back to main menu\n"
//						+ "Selection: ";
//		int choice = 0;
//		if(!(std::cin >> choice)){
//				std::cout << "Please enter numbers only "<<endl;
//				std::cin.clear();
//				std::cin.ignore(10000, '\n');
//
//			}
//		switch (choice){
//			case 1:{
//				cout<<"List front element: "+to_string(list.Front())<<endl;
//			}
//			break;
//			case 2:{
//				cout<<"List back element: "+to_string(list.Back())<<endl;
//			}
//			break;
//			case 3:{
//				int index;
//				cout<<"insert index:"<<endl;
//				if(!(std::cin >> index)){
//						std::cout << "Please enter numbers only ";
//						std::cin.clear();
//						std::cin.ignore(10000, '\n');
//
//				}else{
//					try{
//						cout<<list[index];
//
//					} catch (std::out_of_range&) {
//						cout<<"invalid index\n";
//					}
//				}
//
//
//			}
//			break;
//			case 4:{
//				printMappableContainer(list);
//			}
//			break;
//			case 5:{
//				float value;
//				unsigned long index=0;
//				cout<<"insert element to find:"<<endl;
//				while(!(std::cin >> value)){
//						std::cout << "Please enter numbers only: ";
//						std::cin.clear();
//						std::cin.ignore(10000, '\n');
//						std::cout<<"insert element to find\n";
//				}
//				cout<<"value to find: "<<value<<endl;
//				list.FoldPreOrder(&foldFloatFind<float>, &value, &index);
//
//
//			}
//			break;
//			case 6:{
//				float value;
//				float acc=1;
//				cout<<"insert n size:"<<endl;
//				while(!(std::cin >> value)){
//						std::cout << "Please enter numbers only: ";
//						std::cin.clear();
//						std::cin.ignore(10000, '\n');
//						std::cout<<"insert n size\n";
//				}
//				list.FoldPreOrder(&foldMultiplyGreaterThan<float>, &value, &acc);
//				cout<<"product is: "<<acc<<endl;
//			}
//			break;
//			case 7:{
//
//				list.MapPreOrder(&mapSquareElementValue<float>, (void*)0);
//				printMappableContainer(list);
//				cout<<endl;
//			}
//			break;
//			case 8:{
//				isQuitOptionSelected=true;
//			}
//
//			break;
//			default:
//			{
//				// Do nothing
//			}
//		}
//
//
//	}
//
//};

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
void mapUppercase(string& data,void* _){
	capitalizeString(data);
}
void capitalizeString(string& s)
{
    transform(s.begin(), s.end(), s.begin(),
                   [](unsigned char c){ return toupper(c); });
}




