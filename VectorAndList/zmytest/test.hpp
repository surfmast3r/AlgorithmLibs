
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
#include <string>

void populateRandomIntVector(lasd::Vector<int>&);
void populateRandomFloatVector(lasd::Vector<float>&);
void populateRandomStringVector(lasd::Vector<std::string>&);
std::string createRandomString(int stringSize);

void testFloatVector();
void testStringVector();
void testIntVector();

// MappableContainer functions
template <typename DataType>
void mapPrint(const DataType& data, void* _) {
  std::cout << data << " ";
}

template <typename DataType>
void mapDoubleElementValue(DataType& data,void* _) {
	data=2*data;
}

template <typename DataType>
void mapSquareElementValue(DataType& data,void* _) {
	data*=data;
}

void capitalizeString(std::string& s);
void mapUppercase(std::string& data,void* _);

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
	if(data<=*((DataType*)n)){
		*((DataType*) acc)+=data;
	}

}

template <typename DataType>
void foldMultiplyGreaterThan(const DataType& data,const void* n,void* acc) {
	if(data>*((DataType*)n)){
		*((DataType*) acc)*=data;
	}

}

void foldStringLessThan(const std::string& data,const void* n,void* acc);


/* ************************************************************************** */

#endif
