
namespace lasd {

/* ************************************************************************** */

// A vector with a given initial dimension
template <typename DataType>
Vector<DataType>::Vector(const unsigned long newsize){

	Elements= new DataType[newsize]{};
	size=newsize;
	std::cout<<"New vector constructed\n";
}

// A vector obtained from a LinearContainer
template <typename DataType>
Vector<DataType>::Vector(const LinearContainer<DataType>& linearContainer ){
	size=linearContainer.Size();
	Elements= new DataType[size];
	for(unsigned long i=0; i<size; i++){
		Elements[i]=linearContainer[i];
	}
	std::cout<<"New vector constructed\n";
}

// Copy constructor
template <typename DataType>
Vector<DataType>::Vector(const Vector<DataType>& vector ){
	size=vector.Size();
	Elements= new DataType[size];
	std::copy(vector.Elements, vector.Elements + size, Elements);
	std::cout<<"New vector constructed\n";
}

// Move constructor
template <typename DataType>
Vector<DataType>::Vector(Vector<DataType>&& vector ) noexcept{
	std::swap(Elements,vector.Elements);
	std::swap(size, vector.size);
	std::cout<<"New vector constructed\n";
}

// Destructor
template <typename DataType>
Vector<DataType>::~Vector(){
	delete[] Elements;
	std::cout<<"Vector destructed\n";
}

//copy assignment
template <typename DataType>
Vector<DataType>& Vector<DataType>::operator=(const Vector<DataType>& vector ){
	Vector<DataType>* temp = new Vector<DataType>(vector);
	std::swap(*temp,*this);
	delete temp;
	return *this;
}

//move assignment
template <typename DataType>
Vector<DataType>& Vector<DataType>::operator=(Vector<DataType>&& vector ) noexcept{
	std::swap(Elements,vector.Elements);
	std::swap(size, vector.size);
	return *this;
}

//comparison operators

template <typename DataType>
bool Vector<DataType>::operator ==(const Vector<DataType>& vector) const noexcept{
	if(size == vector.size){
		for(unsigned long i=0;i<size;i++){
			if(Elements[i] != vector.Elements[i])
				return false;
		}
		return true;
	}
	else
		return false;
}

template <typename DataType>
bool Vector<DataType>::operator !=(const Vector<DataType>& vector) const noexcept{
	return !(*this == vector);
}

//resize
template <typename DataType>
void Vector<DataType>::Resize(const unsigned long newSize){
	if(newSize==0)
		Clear();
	else if(size!=newSize){
		unsigned long limit= (size < newSize) ? size:newSize;
		DataType* temp= new DataType[newSize]{};
		for (unsigned long i=0;i<limit;i++)
			std::swap(Elements[i],temp[i]);
		std::swap(Elements,temp);
		size= newSize;
		delete[] temp;
	}
}

//operator[]
template <typename DataType>
DataType& Vector<DataType>::operator[](const unsigned long index) const {

	if(index < size )
		return Elements[index];
	else
		throw std::out_of_range("Out of range index:"+ std::to_string(index));


}


template <typename DataType>
void Vector<DataType>::Clear() {
	delete[] Elements;
	Elements=nullptr;
	size=0;
}

template <typename DataType>
DataType& Vector<DataType>::Front() const{
	if(size!=0)
		return Elements[0];
	else
		throw std::length_error("Vector is empty");
}

template <typename DataType>
DataType& Vector<DataType>::Back() const{
	if(size!=0)
		return Elements[size-1];
	else
		throw std::length_error("Vector is empty");
}


/* ************************************************************************** */

//mappable container functions
template <typename DataType>
void Vector<DataType>::MapPreOrder(const MapFunctor function,void* param){
	for(unsigned long i=0;i<size;i++){
		function(Elements[i],param);
	}
}

template <typename DataType>
void Vector<DataType>::MapPostOrder(const MapFunctor function,void* param){
	long index;
	if(size>0){
		index=size-1;
		while(index>=0)
		{
			function(Elements[index],param);
			index--;
		}
	}
}

//foldable container functions
template <typename DataType>
void Vector<DataType>::FoldPreOrder(const FoldFunctor function,const void* param, void* acc) const{
	for(unsigned long i=0;i<size;i++){
		function(Elements[i],param,acc);
	}
}
template <typename DataType>
void Vector<DataType>::FoldPostOrder(const FoldFunctor function,const void* param, void* acc)const{
	long index;
	if(size>0){
		index=size-1;
		while(index>=0)
		{
			function(Elements[index],param,acc);
			index--;
		}
	}
}

}
