
#ifndef MYTEST_HPP
#define MYTEST_HPP
/* ************************************************************************** */
#include <iostream>

void createRandomIntVector(unsigned long size);

template <typename DataType>
void mapPrint(const DataType& data, void* _) {
  std::cout << data << " ";
}

template <typename DataType>
void foldFind(const DataType& data,const void* target,void* index) {
	if(data==*((DataType*)target)){
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

/* ************************************************************************** */

#endif
