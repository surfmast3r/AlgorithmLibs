
#ifndef MYTEST_HPP
#define MYTEST_HPP
/* ************************************************************************** */
#include <iostream>
#include <cmath>
#include <limits>
#include <iomanip>
#include <type_traits>
#include <algorithm>
#include "../vector/vector.hpp"
#include "../list/list.hpp"
#include "../queue/lst/queuelst.hpp"
#include "../queue/vec/queuevec.hpp"
#include "../stack/lst/stacklst.hpp"
#include "../stack/vec/stackvec.hpp"
#include "../binarytree/binarytree.hpp"
#include "../binarytree/vec/binarytreevec.hpp"
#include "../binarytree/lnk/binarytreelnk.hpp"
#include "../bst/bst.hpp"
#include <string>



typedef std::function<void(void*,std::string)> readInputFunctor;

void readSizeInput(unsigned long &size,std::string msg);
void readInput(const readInputFunctor&);
void readIntValue(void*, std::string);
void readFloatValue(void*,std::string);
void readStringValue(void*,std::string);

void populateRandomIntVector(lasd::Vector<int>&);
void populateRandomFloatVector(lasd::Vector<float>&);
void populateRandomStringVector(lasd::Vector<std::string>&);

void populateRandomIntList(lasd::List<int>& container,unsigned long&);
void populateRandomFloatList(lasd::List<float>& container,unsigned long& );
void populateRandomStringList(lasd::List<std::string>& container,unsigned long& );
std::string createRandomString(int stringSize);

/* ************************************************************************** */
/* BinarySearchTreeMenu */

void createIntBST();
void createFloatBST();
void createStringBST();

template <typename DataType>
void editBST(lasd::BST<DataType>& bt, const readInputFunctor& readFunction);

void intBSTTest(lasd::BST<int>& );
void floatBSTTest(lasd::BST<float>& );
void stringBSTTest(lasd::BST<std::string>& );
/* ************************************************************************** */
/* BinaryTreeVecMenu */

void createIntBinaryTreeVec();
void createFloatBinaryTreeVec();
void createStringBinaryTreeVec();

/* BinaryTreeLnkMenu */
void createIntBinaryTreeLnk();
void createFloatBinaryTreeLnk();
void createStringBinaryTreeLnk();

void intBinaryTreeTest(lasd::BinaryTree<int>& bt);
void floatBinaryTreeTest(lasd::BinaryTree<float>& bt);
void stringBinaryTreeTest(lasd::BinaryTree<std::string>& bt);

template<typename DataType>
void navigateBinaryTree(lasd::BinaryTree<DataType>& bt,const readInputFunctor&);

template<typename DataType>
void startIteratorNavigation(lasd::BinaryTree<DataType>& bt);

template<typename DataType>
void iteratorNavigation(lasd::ForwardIterator<DataType>& iterator);

/* ************************************************************************** */
// MappableContainer functions

template <typename DataType>
void mapPrint(const DataType& data, void* _) {
  std::cout << data << " ";
}

template <typename DataType>
void printMappableContainer(lasd::MappableContainer<DataType>& container){
	container.MapPreOrder(&mapPrint<DataType>, 0);
}

template <typename DataType>
void mapDoubleElementValue(DataType& data,void* _) {
	data=2*data;
}

template <typename DataType>
void mapTripleElementValue(DataType& data,void* _) {
	data=3*data;
}

template <typename DataType>
void mapPowerElementValue(DataType& data,void* power) {
	data=pow(data, *static_cast<DataType*>(power));
}
template <typename DataType>
void mapSquareElementValue(DataType& data,void* _) {
	data*=data;
}

void capitalizeString(std::string& s);
void mapUppercase(std::string& data,void* _);
void mapConcatInHead(std::string& data,void*);

// FoldableContainer functions
template <typename DataType>
void foldFind(const DataType& data,const void* target,void* index) {
	if(data==*((DataType*)target)){
		std::cout<<"found element at index:"<<*((unsigned long*) index)<<std::endl;
	}
	*((unsigned long*) index) += 1;
}

template<class T>
typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type
almost_equal(T x, T y, int ulp)
{
    // the machine epsilon has to be scaled to the magnitude of the values used
    // and multiplied by the desired precision in ULPs (units in the last place)
    return std::fabs(x-y) <= std::numeric_limits<T>::epsilon() * std::fabs(x+y) * ulp
        // unless the result is subnormal
        || std::fabs(x-y) < std::numeric_limits<T>::min();
}


template <typename DataType>
void foldFloatFind(const DataType& data,const void* target,void* index) {
	if(almost_equal<DataType>(data, *((DataType*)target),10)){
		std::cout<<"found element at index:"<<*((unsigned long*) index)<<std::endl;
	}
	*((unsigned long*) index) += 1;
}

template <typename DataType>
void foldSumLessThan(const DataType& data,const void* n,void* acc) {
	if(data<*((DataType*)n)){
		*((DataType*) acc)+=data;
	}

}
template <typename DataType>
void foldSumBiggerThan(const DataType& data,const void* n,void* acc) {
	if(data>*((DataType*)n)){
		*((DataType*) acc)+=data;
	}

}

template <typename DataType>
void foldMultiplyLessThan(const DataType& data,const void* n,void* acc) {
	if(data<*((DataType*)n)){
		*((DataType*) acc)*=data;
	}

}

template <typename DataType>
void foldMultiplyGreaterThan(const DataType& data,const void* n,void* acc) {
	if(data>*((DataType*)n)){
		*((DataType*) acc)*=data;
	}

}

void foldStringLessEqThan(const std::string& data,const void* n,void* acc);

/* ************************************************************************** */

#endif
