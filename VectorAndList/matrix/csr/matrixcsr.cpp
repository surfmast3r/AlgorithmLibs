
namespace lasd {

/* ************************************************************************** */

  // Default constructor
	template <typename DataType>
	MatrixCSR<DataType>::MatrixCSR(){
		rowVector[0]=&head;

	}

  /* ************************************************************************ */

  // Specific constructors
	template <typename DataType>
	MatrixCSR<DataType>::MatrixCSR(unsigned long& row, unsigned long& col){

		rowNumber=row;
		columnNumber=col;
		rowVector.Resize(row+1);
		for(unsigned long i=0;i<=rowVector.Size(); i++){
			rowVector[i]=&head;
		}

	} // A matrix of some specified dimension

  /* ************************************************************************ */

  // Copy constructor
	template <typename DataType>
	MatrixCSR<DataType>::MatrixCSR(const MatrixCSR& matrix){
		rowNumber=matrix.rowNumber;
		columnNumber=matrix.columnNumber;
		rowVector.Resize(rowNumber+1);
		typename List<std::pair<DataType,unsigned long>>::Node** pointer;
		for(unsigned long i=0;i<matrix.rowVector.Size(); i++){
			pointer=matrix.rowVector[i];
			while(pointer!=matrix.rowVector[i+1]){
				typename List<std::pair<DataType,unsigned long>>::Node newNode=**matrix.rowVector[i];
				(*this)(i,newNode.value.second)= newNode.value.first;
				pointer=&((*pointer)->next);
			}
		}
	}

  // Move constructor
	template <typename DataType>
	MatrixCSR<DataType>::MatrixCSR(MatrixCSR&& matrix) noexcept : List<std::pair<DataType,unsigned long>>(std::move(matrix)){
		std::swap(rowNumber,matrix.rowNumber);
		std::swap(columnNumber,matrix.columnNumber);
		std::swap(rowVector,matrix.rowVector);

	}

  /* ************************************************************************ */

  // Copy assignment
	template <typename DataType>
	MatrixCSR<DataType>& MatrixCSR<DataType>::operator=(const MatrixCSR<DataType>& matrix) noexcept{
		MatrixCSR<DataType> temp= new Matrix<DataType>(matrix);
		std::swap(*this,*temp);
		delete temp;
		return *this;

	}

  // Move assignment
	template <typename DataType>
	MatrixCSR<DataType>& MatrixCSR<DataType>::operator=(MatrixCSR<DataType>&& matrix) noexcept{
		MatrixCSR<DataType> temp= new Matrix<DataType>(std::move(matrix));
		std::swap(*this,*temp);
		delete temp;
		return *this;

	}

  /* ************************************************************************ */

  // Comparison operators
	template <typename DataType>
	bool MatrixCSR<DataType>::operator==(const MatrixCSR<DataType>&matrix) const noexcept{
		return true;
	}

	template <typename DataType>
	bool MatrixCSR<DataType>::operator!=(const MatrixCSR<DataType>&matrix) const noexcept{
		return !(*this==matrix);
	}

  /* ************************************************************************ */

  // Specific member functions (inherited from Matrix)

	template <typename DataType>
	void MatrixCSR<DataType>::RowResize(unsigned long& newRowSize) {
		if(newRowSize>rowNumber){
			expandRowVector(newRowSize);
		}
		else if (newRowSize<rowNumber){
			reduceRowVector(newRowSize);
		}
	} // Override Matrix member

	template <typename DataType>
	void MatrixCSR<DataType>::expandRowVector(unsigned long newRowSize){
		rowVector.Resize(newRowSize+1);
		for(unsigned long i=rowNumber+1; i<=newRowSize+1;i++)
			rowVector[i]=nullptr;
		rowNumber=newRowSize;
	}
	template <typename DataType>
	void MatrixCSR<DataType>::reduceRowVector(unsigned long newRowSize){
		typename List<std::pair<DataType,unsigned long>>::Node* newTail=*rowVector[newRowSize];
		rowVector.Resize(newRowSize+1);
		tail=newTail;
		deleteListFrom(newTail);
		rowNumber=newRowSize;

	}

	template <typename DataType>
	void MatrixCSR<DataType>::deleteListFrom(typename List<std::pair<DataType,unsigned long>>::Node* ptr) {

		typename List<std::pair<DataType,unsigned long>>::Node* temp;
		unsigned long deletedItems=0;
		while(ptr != nullptr) {
			temp = ptr;
			ptr = ptr->next;
			delete(temp);
			deletedItems++;
		}
		size=size-deletedItems;


	}

	template <typename DataType>
	void MatrixCSR<DataType>::ColumnResize(unsigned long& newColumnSize) {
		if(newColumnSize==0)
			List<std::pair<DataType,unsigned long>>::Clear();
		else if(newColumnSize<columnNumber)
		{

			typename List<std::pair<DataType,unsigned long>>::Node** ptr = &head;
			typename List<std::pair<DataType,unsigned long>>::Node* node = *ptr;

			for(unsigned long nextRowIndex=1; nextRowIndex<=rowNumber;nextRowIndex++){

				typename List<std::pair<DataType,unsigned long>>::Node** nextRowPtr = rowVector[nextRowIndex];
				//search for columns in the list of data
				while(ptr!=nextRowPtr && (*ptr)->value.second<newColumnSize ){
					node=*ptr;
					ptr=&(*ptr)->next;

				}
				if(ptr!=nextRowPtr)
				{
					if(nextRowPtr==rowVector[rowNumber])
						tail=node;

					typename List<std::pair<DataType,unsigned long>>::Node* temp = *ptr;
					typename List<std::pair<DataType,unsigned long>>::Node** tempPtr = ptr;

					while(tempPtr!=rowVector[nextRowIndex])
					{
						temp=*tempPtr;
						tempPtr=&(*tempPtr)->next;

					}
					temp->next=nullptr; //stacco il nodo dalla lista
					deleteListFrom(*ptr);//cancello gli elementi
					*nextRowPtr=*ptr;//unisco colonna a riga successiva

					//NON FUNZIONA, DA COMPLETARE





				}
			}

		}

	} // Override Matrix member

	template <typename DataType>
	bool MatrixCSR<DataType>::ExistsCell(const unsigned long&,const unsigned long&) const noexcept {} // Override Matrix member (should not throw exceptions)

	template <typename DataType>
	DataType& MatrixCSR<DataType>::operator()(const unsigned long&,const unsigned long&) {} // Override Matrix member (mutable access to the element; throw out_of_range when out of range)

	template <typename DataType>
	DataType const& MatrixCSR<DataType>::operator()(const unsigned long&,const unsigned long&) const {} // Override Matrix member (immutable access to the element; throw out_of_range when out of range and length_error when not present)


/* ************************************************************************** */
	// Specific member functions (inherited from Container)

	template <typename DataType>
	void MatrixCSR<DataType>::Clear() {} // Override Container member

	/* ************************************************************************ */

	// Specific member functions (inherited from MappableContainer)

	template <typename DataType>
	void MatrixCSR<DataType>::MapPreOrder(const MapFunctor, void*) {} // Override MappableContainer member

	template <typename DataType>
	void MatrixCSR<DataType>::MapPostOrder(const MapFunctor, void*) {} // Override MappableContainer member

	/* ************************************************************************ */

	// Specific member functions (inherited from FoldableContainer)
	template <typename DataType>
	void MatrixCSR<DataType>::FoldPreOrder(const FoldFunctor,const void*,void*) const {} // Override FoldableContainer member

	template <typename DataType>
	void MatrixCSR<DataType>::FoldPostOrder(const FoldFunctor,const void*,void*) const {} // Override FoldableContainer member


}
