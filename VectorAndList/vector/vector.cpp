namespace lasd {

/* ************************************************************************** */

// A vector with a given initial dimension
template <typename DataType>
Vector<DataType>::Vector(const unsigned long& newsize){

	Elements= new DataType[size]{};
	size=newsize;
}

// A vector obtained from a LinearContainer
template <typename DataType>
Vector<DataType>::Vector(const LinearContainer<DataType>& linearContainer ){
	size=linearContainer.Size();
	Elements= new DataType[size];
	for(int i=0; i<size; i++){
		Elements[i]=linearContainer[i];
	}
}

// Copy constructor
template <typename DataType>
Vector<DataType>::Vector(const Vector<DataType>& vector ){
	size=vector.Size();
	Elements= new DataType[size];
	std::copy(vector.Elements, vector.Elements + size, Elements);
}

// Move constructor
template <typename DataType>
Vector<DataType>::Vector(Vector<DataType>&& vector ){
	std::swap(Elements,vector.Elements);
	std::swap(size, vector.size);
}

// Destructor
template <typename DataType>
Vector<DataType>::~Vector(){
	delete[] Elements;
}

template <typename DataType>
Vector<DataType>& Vector<DataType>::operator=(const Vector<DataType>& vector ){
	Vector<DataType>* temp = new Vector(vector);
	std::swap(*temp,*this);
	delete temp;
	return *this;
}

template <typename DataType>
Vector<DataType>& Vector<DataType>::operator=(Vector<DataType>&& vector ) noexcept{
	std::swap(Elements,vector.Elements);
	std::swap(size, vector.size);
	return *this;
}


template <typename DataType>
DataType& Vector<DataType>::operator[](const unsigned long& index) const{

	if(index < size )
		return Elements[index];
	else
		throw std::out_of_range("Out of range index:"+ std::to_string(index));


}



/* ************************************************************************** */

}
