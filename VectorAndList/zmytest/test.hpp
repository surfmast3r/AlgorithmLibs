
#ifndef MYTEST_HPP
#define MYTEST_HPP
/* ************************************************************************** */
#include <iostream>
#include <cmath>
#include <limits>

#include <random>
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
#include "../matrix/matrix.hpp"
#include "../matrix/vec/matrixvec.hpp"
#include "../matrix/csr/matrixcsr.hpp"
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
void mapPowerNegativeElementValue(DataType& data,void* power) {
	data=pow(-1*data, *static_cast<int*>(power));
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


void foldFloatFind(const float& data,const void* target,void* index);

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
/* MatrixMenu */

template <typename DataType>
void editMatrix(lasd::Matrix<DataType>& bt, const readInputFunctor& readFunction);

template <typename DataType>
void populateRandomMatrix(lasd::Matrix<DataType>& mat,lasd::Vector<DataType>& vec){
	std::cout<< "populating random matrix from vector (some element could be missing due to collision)\n";
	unsigned long size=vec.Size();
	srand(time(NULL));

	std::default_random_engine genx(std::random_device{}());
	std::uniform_int_distribution<unsigned int> row(0,mat.RowNumber()-1);
	std::uniform_int_distribution<unsigned int> col(0,mat.ColumnNumber()-1);
	for(unsigned long i = 0; i<size; i++){

		mat(row(genx),col(genx))=vec[i];

	}
	printMappableContainer(mat);
	std::cout<<std::endl;

};


void intMatrixTest(lasd::Matrix<int>& );
void floatMatrixTest(lasd::Matrix<float>& );
void stringMatrixTest(lasd::Matrix<std::string>& );


template <template<typename> typename Mat>
void createIntMatrix(Mat<int>& mat){
	unsigned long column;
	unsigned long row;
	readSizeInput(row, "insert row number");
	readSizeInput(column, "insert column number");

	unsigned long size;
	do{
		unsigned long max=row*column;

		readSizeInput(size, "insert number of elements, max: "+std::to_string(max));
	}while(size>row*column);

	std::cout<<"Random Vector "<<std::endl;
	lasd::Vector<int> vec(size);
	mat.RowResize(row);
	mat.ColumnResize(column);
	populateRandomIntVector(vec);
	populateRandomMatrix(mat,vec);

	intMatrixTest(mat);
}
template <template<typename> typename Mat>
void createFloatMatrix(Mat<float>& mat){
	unsigned long column;
	unsigned long row;
	readSizeInput(row, "insert row number");
	readSizeInput(column, "insert column number");

	unsigned long size;
	do{
		unsigned long max=row*column;

		readSizeInput(size, "insert number of elements, max: "+std::to_string(max));
	}while(size>row*column);

	std::cout<<"Random Vector "<<std::endl;
	lasd::Vector<float> vec(size);
	mat.RowResize(row);
	mat.ColumnResize(column);
	populateRandomFloatVector(vec);
	populateRandomMatrix(mat,vec);

	floatMatrixTest(mat);
}
template <template<typename> typename Mat>
void createStringMatrix(Mat<std::string>& mat){
	unsigned long column;
	unsigned long row;
	readSizeInput(row, "insert row number");
	readSizeInput(column, "insert column number");

	unsigned long size;
	do{
		unsigned long max=row*column;

		readSizeInput(size, "insert number of elements, max: "+std::to_string(max));
	}while(size>row*column);

	std::cout<<"Random Vector "<<std::endl;
	lasd::Vector<std::string> vec(size);
	mat.RowResize(row);
	mat.ColumnResize(column);
	populateRandomStringVector(vec);
	populateRandomMatrix(mat,vec);

	stringMatrixTest(mat);
}

/* ************************************************************************** */


#endif
