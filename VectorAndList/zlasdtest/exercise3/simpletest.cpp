
#include <iostream>

/* ************************************************************************** */

#include "../container/container.hpp"

#include "../iterator/iterator.hpp"

#include "../vector/vector.hpp"

#include "../list/list.hpp"

#include "../binarytree/binarytree.hpp"
#include "../../binarytree/lnk/binarytreelnk.hpp"
#include "../../binarytree/vec/binarytreevec.hpp"

/* ************************************************************************** */

using namespace std;

/* ************************************************************************** */

void stestBinaryTreeInt(lasd::BinaryTree<int>& bt, uint& testnum, uint& testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    MapPreOrder(loctestnum, loctesterr, bt, true, &MapPrint<int>, 0);
    FoldPreOrder(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 0, 6);
    FoldPostOrder(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 0, 6);
    FoldInOrder(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 0, 6);
    FoldBreadth(loctestnum, loctesterr, bt, true, &FoldAdd<int>, 0, 0, 6);
    MapBreadth(loctestnum, loctesterr, bt, true, &MapPrint<int>, 0);
    lasd::BinaryTreeVec<int> btvec;
    cout << endl << "Start map and fold with empty vec " << endl;
    MapBreadth(loctestnum, loctesterr, btvec, true, &MapPrint<int>, 0);
    MapInOrder(loctestnum, loctesterr, btvec, true, &MapPrint<int>, 0);
    MapPreOrder(loctestnum, loctesterr, btvec, true, &MapPrint<int>, 0);
    MapPostOrder(loctestnum, loctesterr, btvec, true, &MapPrint<int>, 0);
	FoldPreOrder(loctestnum, loctesterr, btvec, true, &FoldAdd<int>, 0, 0, 0);
	FoldPostOrder(loctestnum, loctesterr, btvec, true, &FoldAdd<int>, 0, 0, 0);
	FoldInOrder(loctestnum, loctesterr, btvec, true, &FoldAdd<int>, 0, 0, 0);
	FoldBreadth(loctestnum, loctesterr, btvec, true, &FoldAdd<int>, 0, 0, 0);

  } catch(...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of BinaryTreeVec<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}
//
void stestBinaryTreeInt(uint& testnum, uint& testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of BinaryTreeVec<int> Test" << endl;
  try {

    lasd::BinaryTreeLnk<int> btvec3;
	lasd::BinaryTreeLnk<int> btvec4=btvec3;
	Empty(loctestnum, loctesterr, btvec4, true);

	cout << endl << "Test empty BinaryTreeVec<int> equals" << endl;
	if(btvec3==btvec4)
		cout << endl << "equals" << endl;
    lasd::Vector<int> vec(4);
    btvec4=lasd::BinaryTreeLnk<int>(vec);
    Empty(loctestnum, loctesterr, btvec4, false);
    btvec4.Clear();
    Empty(loctestnum, loctesterr, btvec4, true);
    SetAt(loctestnum, loctesterr, vec, true, 0, 0);
    SetAt(loctestnum, loctesterr, vec, true, 1, 1);
    SetAt(loctestnum, loctesterr, vec, true, 2, 2);
    SetAt(loctestnum, loctesterr, vec, true, 3, 3);

    lasd::BinaryTreeVec<int> btvec(vec);
    lasd::BinaryTreeVec<int> btvec2=btvec;
    cout << endl << "Begin of BinaryTreeVec<int> Test:" << endl;
    stestBinaryTreeInt(btvec2, loctestnum, loctesterr);
    lasd::BinaryTreeLnk<int> btlnk(vec);
    cout << endl << "Begin of BinaryTreeLnk<int> Test:" << endl;
    stestBinaryTreeInt(btlnk, loctestnum, loctesterr);
    cout << "\n";

    lasd::BinaryTreeVec<int> copbtvec(btvec);
    EqualTrees(loctestnum, loctesterr, copbtvec, btvec, true);
    btvec.Clear();
    btvec = move(copbtvec);
    EqualTrees(loctestnum, loctesterr, copbtvec, btvec, false);
    Empty(loctestnum, loctesterr, copbtvec, true);

    lasd::BinaryTreeLnk<int> copbtlnk(btlnk);
    EqualTrees(loctestnum, loctesterr, copbtlnk, btlnk, true);
    btlnk.Clear();
    btlnk = move(copbtlnk);
    EqualTrees(loctestnum, loctesterr, copbtlnk, btlnk, false);
    Empty(loctestnum, loctesterr, copbtlnk, true);
  } catch(...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestBinaryTreeFloat(lasd::BinaryTree<double>& bt, uint& testnum, uint& testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    lasd::BTPreOrderIterator<double> itr1(bt);
    GetItrValue(loctestnum, loctesterr, itr1, true, 1.2);
    lasd::BTPreOrderIterator<double> itr6=++itr1;
    if(itr6==itr1)
		cout<<"itr6 and 1 are equals"<<endl;
	else if(itr6!=itr1)
		cout<<"itr6 and 1 are different"<<endl;
    GetItrValue(loctestnum, loctesterr, itr6, true, 0.3);
    GetItrValue(loctestnum, loctesterr, itr1, true, 0.3);
    ++itr1;
    GetItrValue(loctestnum, loctesterr, itr1, true, 2.1);
    ++itr1;
    GetItrValue(loctestnum, loctesterr, itr1, true, 3.0);
    ++itr1;
    Terminated(loctestnum, loctesterr, itr1, true);

    lasd::BTBreadthIterator<double> itr2(bt);
    GetItrValue(loctestnum, loctesterr, itr2, true, 1.2);

    lasd::BTBreadthIterator<double> itr7(++itr2);
    if(itr7==itr2)
        cout<<"itr7 and 2 are equals"<<endl;
    else if(itr7!=itr2)
    	cout<<"itr7 and 2 are different"<<endl;
    GetItrValue(loctestnum, loctesterr, itr7, true, 0.3);

    GetItrValue(loctestnum, loctesterr, itr2, true, 0.3);
    ++itr2;
    GetItrValue(loctestnum, loctesterr, itr2, true, 3.0);
    ++itr2;
    GetItrValue(loctestnum, loctesterr, itr2, true, 2.1);
    ++itr2;
    Terminated(loctestnum, loctesterr, itr2, true);

    lasd::BTInOrderIterator<double> itr3(bt);
    GetItrValue(loctestnum, loctesterr, itr3, true, 2.1);
    ++itr3;
    lasd::BTInOrderIterator<double> itr8(itr3);
    ++itr8;
    if(itr8==itr3)
		cout<<"itr8 and 3 are equals"<<endl;
	else if(itr8!=itr3)
		cout<<"itr8 and 3 are different"<<endl;
    GetItrValue(loctestnum, loctesterr, itr3, true, 0.3);
    ++itr3;
    GetItrValue(loctestnum, loctesterr, itr3, true, 1.2);
    ++itr3;
    GetItrValue(loctestnum, loctesterr, itr3, true, 3.0);
    ++itr3;
    Terminated(loctestnum, loctesterr, itr3, true);

    lasd::BTPostOrderIterator<double> itr4(bt);
    lasd::BTPostOrderIterator<double> itr9(itr4);
    //itr9=itr4;
    if(itr9==itr4)
    	cout<<"itr9 and 4 are equals"<<endl;
    GetItrValue(loctestnum, loctesterr, itr9, true, 2.1);
        ++itr9;
        GetItrValue(loctestnum, loctesterr, itr9, true, 0.3);
        ++itr9;
        GetItrValue(loctestnum, loctesterr, itr9, true, 3.0);
        ++itr9;
        GetItrValue(loctestnum, loctesterr, itr9, true, 1.2);
        ++itr9;
        Terminated(loctestnum, loctesterr, itr9, true);
    GetItrValue(loctestnum, loctesterr, itr4, true, 2.1);
    ++itr4;
    GetItrValue(loctestnum, loctesterr, itr4, true, 0.3);
    ++itr4;
    GetItrValue(loctestnum, loctesterr, itr4, true, 3.0);
    ++itr4;
    GetItrValue(loctestnum, loctesterr, itr4, true, 1.2);
    ++itr4;
    Terminated(loctestnum, loctesterr, itr4, true);
    itr9=move(itr4);
    Terminated(loctestnum, loctesterr, itr9, true);

    lasd::BinaryTreeVec<double> btvec;
    lasd::BTPostOrderIterator<double> itr10(btvec);
    Terminated(loctestnum, loctesterr, itr10, true);

  } catch(...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of BinaryTreeVec<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestBinaryTreeFloat(uint& testnum, uint& testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of BinaryTreeVec<double> Test" << endl;
  try {
    lasd::List<double> lst;
    InsertAtFront(loctestnum, loctesterr, lst, true, 0.3);
    InsertAtBack(loctestnum, loctesterr, lst, true, 3.0);
    InsertAtFront(loctestnum, loctesterr, lst, true, 1.2);
    InsertAtBack(loctestnum, loctesterr, lst, true, 2.1);

    lasd::BinaryTreeVec<double> btvec(lst);
    cout << endl << "Begin of BinaryTreeVec<double> Test:" << endl;
    stestBinaryTreeFloat(btvec, loctestnum, loctesterr);
    lasd::BinaryTreeLnk<double> btlnk(lst);
    cout << endl << "Begin of BinaryTreeLnk<double> Test:" << endl;
    stestBinaryTreeFloat(btlnk, loctestnum, loctesterr);
    cout << "\n";

    lasd::BinaryTreeVec<double> copbtvec(move(btvec));
    Empty(loctestnum, loctesterr, btvec, true);
    EqualTrees(loctestnum, loctesterr, copbtvec, btvec, false);
    btvec = copbtvec;
    EqualTrees(loctestnum, loctesterr, copbtvec, btvec, true);

    lasd::BinaryTreeLnk<double> copbtlnk(move(btlnk));
    Empty(loctestnum, loctesterr, btlnk, true);
    EqualTrees(loctestnum, loctesterr, copbtlnk, btlnk, false);
    btlnk = copbtlnk;
    EqualTrees(loctestnum, loctesterr, copbtlnk, btlnk, true);
  } catch(...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestBinaryTreeString(lasd::BinaryTree<string>& bt, uint& testnum, uint& testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    MapPreOrder(loctestnum, loctesterr, bt, true, &MapPrint<string>, 0);
    FoldPreOrder(loctestnum, loctesterr, bt, true, &FoldStringConcatenate, string(""), string("?"), string("?ABDC"));
    FoldPostOrder(loctestnum, loctesterr, bt, true, &FoldStringConcatenate, string(""), string("?"), string("?DBCA"));
    FoldInOrder(loctestnum, loctesterr, bt, true, &FoldStringConcatenate, string(""), string("?"), string("?DBAC"));
    FoldBreadth(loctestnum, loctesterr, bt, true, &FoldStringConcatenate, string(""), string("?"), string("?ABCD"));
  } catch(...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of BinaryTreeVec<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void stestBinaryTreeString(uint& testnum, uint& testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of BinaryTreeVec<string> Test" << endl;
  try {
    lasd::Vector<string> vec(4);
    SetAt(loctestnum, loctesterr, vec, true, 0, string("A"));
    SetAt(loctestnum, loctesterr, vec, true, 1, string("B"));
    SetAt(loctestnum, loctesterr, vec, true, 2, string("C"));
    SetAt(loctestnum, loctesterr, vec, true, 3, string("D"));

    cout << endl << "Begin of BinaryTreeVec<string> Test:" << endl;
    lasd::BinaryTreeVec<string> btvec(vec);
    stestBinaryTreeString(btvec, loctestnum, loctesterr);
    cout << endl << "Begin of BinaryTreeLnk<string> Test:" << endl;
    lasd::BinaryTreeLnk<string> btlnk(vec);
    stestBinaryTreeString(btlnk, loctestnum, loctesterr);
    cout << "\n";

    EqualTrees(loctestnum, loctesterr, btvec, btlnk, true);
    btvec.Root().LeftChild().LeftChild().Element() = string("S");
    EqualTrees(loctestnum, loctesterr, btlnk, btvec, false);
    btlnk.Root().RightChild().Element() = string("X");
    EqualTrees(loctestnum, loctesterr, btvec, btlnk, false);
    btvec.Root().RightChild().Element() = string("X");
    btlnk.Root().LeftChild().LeftChild().Element() = string("S");
    EqualTrees(loctestnum, loctesterr, btlnk, btvec, true);
  } catch(...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  testnum += loctestnum;
  testerr += loctesterr;
}

/* ************************************************************************** */

void testSimpleExercise3() {
  uint testnum = 0, testerr = 0;
  stestBinaryTreeInt(testnum, testerr);
  stestBinaryTreeFloat(testnum, testerr);
  stestBinaryTreeString(testnum, testerr);
  cout << endl << "Exercise 3 (Simple Test) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}
