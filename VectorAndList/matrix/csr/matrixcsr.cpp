
namespace lasd {

/* ************************************************************************** */

  // Default constructor
	template <typename DataType>
	MatrixCSR<DataType>::MatrixCSR() {
		rowVector[0]=&head;

	}

  /* ************************************************************************ */

  // Specific constructors
	template <typename DataType>
	MatrixCSR<DataType>::MatrixCSR(unsigned long row, unsigned long col) {

		rowNumber=row;
		columnNumber=col;
		rowVector.Resize(row+1);
		for(unsigned long i=0;i<rowVector.Size(); i++){
			rowVector[i]=&head;
		}

	} // A matrix of some specified dimension

  /* ************************************************************************ */

  // Copy constructor
	template <typename DataType>
	MatrixCSR<DataType>::MatrixCSR(const MatrixCSR& matrix) : MatrixCSR<DataType>::MatrixCSR( matrix.rowNumber, matrix.columnNumber) {

		typename List<std::pair<DataType,unsigned long>>::Node** pointer;
		for(unsigned long i=0;i<matrix.rowNumber; i++){
			pointer=matrix.rowVector[i];
			while(pointer!=matrix.rowVector[i+1]){
				typename List<std::pair<DataType,unsigned long>>::Node newNode=**pointer;
				(*this)(i,newNode.value.second)= newNode.value.first;
				pointer=&((*pointer)->next);
			}
		}
	}

  // Move constructor
	template <typename DataType>
	MatrixCSR<DataType>::MatrixCSR(MatrixCSR&& matrix) noexcept : List<std::pair<DataType,unsigned long>>(std::move(matrix)){ //controllare puntatore head
		typename List<std::pair<DataType,unsigned long>>::Node** mHead = &(matrix.head);
		std::swap(rowNumber,matrix.rowNumber);
		std::swap(columnNumber,matrix.columnNumber);
		std::swap(rowVector,matrix.rowVector);
//		rowVector[0]=&head;
		unsigned long index=0;
		while(index<rowNumber&&rowVector[index]==mHead){

			rowVector[index]=&head;
		}

	}

  /* ************************************************************************ */

  // Copy assignment
	template <typename DataType>
	MatrixCSR<DataType>& MatrixCSR<DataType>::operator=(const MatrixCSR<DataType>& matrix) noexcept{
		MatrixCSR<DataType>* temp= new MatrixCSR<DataType>(matrix);
		std::swap(*temp,*this);
		delete temp;
		return *this;

	}

  // Move assignment
	template <typename DataType>
	MatrixCSR<DataType>& MatrixCSR<DataType>::operator=(MatrixCSR<DataType>&& matrix) noexcept{ //test head

		typename List<std::pair<DataType,unsigned long>>::Node** mHead = &(matrix.head);
		std::swap(head,matrix.head);
		std::swap(tail,matrix.tail);
		std::swap(size, matrix.size);
		std::swap(rowNumber,matrix.rowNumber);
		std::swap(columnNumber,matrix.columnNumber);
		std::swap(rowVector,matrix.rowVector);

		unsigned long index=0;
		while(index<rowNumber&&rowVector[index]==mHead){

			rowVector[index]=&head;
		}
		return *this;

	}

  /* ************************************************************************ */

  // Comparison operators

	template <typename DataType>
	bool MatrixCSR<DataType>::operator==(const MatrixCSR<DataType>&matrix) const noexcept{

		if(rowNumber==matrix.rowNumber && columnNumber==matrix.columnNumber ){

			for(unsigned long row=0;row<rowNumber;row++){
				typename List<std::pair<DataType,unsigned long>>::Node** mPtr = matrix.rowVector[row];
				typename List<std::pair<DataType,unsigned long>>::Node** ptr = rowVector[row];
				for(;ptr!=rowVector[row+1] || mPtr!=matrix.rowVector[row+1];ptr=&((*ptr)->next), mPtr=&((*mPtr)->next)){

					if((*ptr)->value.first!=(*mPtr)->value.first){
							return false;
					}

				}
			}


			return true;
		}else
			return false;

	}

	template <typename DataType>
	bool MatrixCSR<DataType>::operator!=(const MatrixCSR<DataType>&matrix) const noexcept{
		return !(*this==matrix);
	}

//	template <typename DataType>
//	bool MatrixCSR<DataType>::operator==(const MatrixCSR<DataType>&matrix) const noexcept{ //modificare
//
//		if(rowNumber==matrix.rowNumber && columnNumber==matrix.columnNumber ){
//
//			for(unsigned long row=0;row<rowNumber;row++)
//				for(unsigned long col=0;col<columnNumber;col++){
//					bool exist=ExistsCell(row,col);
//					if(exist==matrix.ExistsCell(row,col)){
//						if(exist==true){
//							if((*this)(row,col)!=matrix(row,col))
//								return false;
//						}
//					}else
//						return false;
//
//				}
//
//
//			return true;
//		}else
//			return false;
//
//	}
//
//	template <typename DataType>
//	bool MatrixCSR<DataType>::operator!=(const MatrixCSR<DataType>&matrix) const noexcept{
//		return !(*this==matrix);
//	}

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
		for(unsigned long i=rowNumber+1; i<=newRowSize;i++)
			rowVector[i]=rowVector[i-1];
		rowNumber=newRowSize;
	}
	template <typename DataType>
	void MatrixCSR<DataType>::reduceRowVector(unsigned long newRowSize){

		typename List<std::pair<DataType,unsigned long>>::Node* nodeToDelete=*rowVector[newRowSize];
		rowVector.Resize(newRowSize+1);

		deleteListFrom(nodeToDelete);
		*rowVector[newRowSize]=nullptr;

		//ripristino tail
		typename List<std::pair<DataType,unsigned long>>::Node* ptr=head;
		while(ptr!=nullptr)
			ptr=ptr->next;
		tail=ptr;
		rowNumber=newRowSize;

	}

	template <typename DataType>
	void MatrixCSR<DataType>::deleteListFrom(typename List<std::pair<DataType,unsigned long>>::Node* ptr) {

		typename List<std::pair<DataType,unsigned long>>::Node* temp;

		while(ptr != nullptr) {
			temp = ptr;
			ptr = ptr->next;
			delete(temp);
			size--;
		}



	}

	template <typename DataType>
	void MatrixCSR<DataType>::ColumnResize(unsigned long& newColumnSize) {
		if(newColumnSize==0)
			List<std::pair<DataType,unsigned long>>::Clear();
		else if(newColumnSize<columnNumber)
		{

			typename List<std::pair<DataType,unsigned long>>::Node** ptr = &head;
			typename List<std::pair<DataType,unsigned long>>::Node* node = *ptr;

			unsigned long nextRowIndex=1;
			while( nextRowIndex<=rowNumber){

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
					*ptr=*nextRowPtr;//unisco colonna a riga successiva
					*nextRowPtr=nullptr; //stacco il nodo dalla lista
					deleteListFrom(temp);//cancello gli elementi

				}
				while(nextRowIndex<=rowNumber&&rowVector[nextRowIndex]==nextRowPtr)
				{
					rowVector[nextRowIndex]=ptr;
					nextRowIndex++;
				}

			}

		}

		columnNumber=newColumnSize;

	} // Override Matrix member

	template <typename DataType>
	bool MatrixCSR<DataType>::ExistsCell(const unsigned long& rowIndex,const unsigned long&columnIndex) const noexcept {
		if(rowIndex<rowNumber&&columnIndex<columnNumber)
		{
			typename List<std::pair<DataType,unsigned long>>::Node** ptr=rowVector[rowIndex];
			typename List<std::pair<DataType,unsigned long>>::Node* node=*ptr;
			while(ptr!=rowVector[rowIndex+1]&&node->value.second<=columnIndex){
				if(node->value.second==columnIndex)
					return true;
				ptr=&(node->next);
				node=node->next;
			}
			return false;
		}
		else
			return false;
	} // Override Matrix member (should not throw exceptions)


	template <typename DataType>
	DataType& MatrixCSR<DataType>::operator()(const unsigned long& rowIndex,const unsigned long&columnIndex) {
		if(rowIndex<rowNumber&&columnIndex<columnNumber)
		{
			typename List<std::pair<DataType,unsigned long>>::Node** ptr=rowVector[rowIndex];
			typename List<std::pair<DataType,unsigned long>>::Node* node=*ptr;;
			while(ptr!=rowVector[rowIndex+1]&&(*ptr)->value.second<=columnIndex){

				if(node->value.second==columnIndex)
					return node->value.first;
				ptr=&(node->next);
				node=node->next;
			}
			//node punta al successivo del nodo da creare
			//ptr punta al puntatore a node (precedente nella lista)
			DataType newData;
			typename List<std::pair<DataType,unsigned long>>::Node* newNode= new typename List<std::pair<DataType,unsigned long>>::Node(std::pair<DataType,unsigned long>(newData,columnIndex));
			newNode->next=node;
			unsigned long nextRowIndex=rowIndex+1;
			while(nextRowIndex<=rowNumber&&rowVector[nextRowIndex]==ptr)
			{
				rowVector[nextRowIndex]=&newNode->next;
				nextRowIndex++;
			}

			if(*ptr==head)
				head=newNode;
			*ptr=newNode;
			size++;
			return (newNode->value.first);

		}
		else
			throw std::out_of_range("Out of range index: ["+ std::to_string(rowIndex)+"] ["+ std::to_string(columnIndex)+"]");
	} // Override Matrix member (mutable access to the element; throw out_of_range when out of range)

	template <typename DataType>
	DataType const& MatrixCSR<DataType>::operator()(const unsigned long& rowIndex,const unsigned long&columnIndex) const {
		if(rowIndex<rowNumber&&columnIndex<columnNumber)
		{
			typename List<std::pair<DataType,unsigned long>>::Node** ptr=rowVector[rowIndex];
			typename List<std::pair<DataType,unsigned long>>::Node* node=nullptr;
			while(ptr!=rowVector[rowIndex+1]&&(*ptr)->value.second<=columnIndex){
				node=*ptr;
				if(node->value.second==columnIndex)
					return node->value.first;
				ptr=&(node->next);
				node=node->next;
			}
			throw std::length_error("Element with index: ["+ std::to_string(rowIndex)+"] ["+ std::to_string(columnIndex)+"] not present");

		}
		else
			throw std::out_of_range("Out of range index: ["+ std::to_string(rowIndex)+"] ["+ std::to_string(columnIndex)+"]");
	} // Override Matrix member (immutable access to the element; throw out_of_range when out of range and length_error when not present)


/* ************************************************************************** */
	// Specific member functions (inherited from Container)

	template <typename DataType>
	void MatrixCSR<DataType>::Clear() {

		List<std::pair<DataType,unsigned long>>::Clear();
		rowVector.Resize(1);
		rowVector[0]=&head;
		rowNumber=0;
		columnNumber=0;
	} // Override Container member

	/* ************************************************************************ */

	// Specific member functions (inherited from MappableContainer)

	template <typename DataType>
	void MatrixCSR<DataType>::MapPreOrder(const MapFunctor fun, void* param) {
		List<std::pair<DataType,unsigned long>>::MapPreOrder(
				[&fun](std::pair<DataType,unsigned long>& data, void*param){fun(data.first,param);}
				,param);
	} // Override MappableContainer member

	template <typename DataType>
	void MatrixCSR<DataType>::MapPostOrder(const MapFunctor fun, void* param) {
		List<std::pair<DataType,unsigned long>>::MapPostOrder(
				[&fun](std::pair<DataType,unsigned long>& data, void*param){fun(data.first,param);}
				,param);
	} // Override MappableContainer member

	/* ************************************************************************ */

	// Specific member functions (inherited from FoldableContainer)
	template <typename DataType>
	void MatrixCSR<DataType>::FoldPreOrder(const FoldFunctor fun,const void* data,void*acc) const {
		List<std::pair<DataType,unsigned long>>::FoldPreOrder(
				[&fun](const std::pair<DataType,unsigned long>& data, const void*param,void*acc){fun(data.first,param,acc);}
				,data,acc);

	} // Override FoldableContainer member

	template <typename DataType>
	void MatrixCSR<DataType>::FoldPostOrder(const FoldFunctor fun,const void* data,void*acc) const {
		List<std::pair<DataType,unsigned long>>::FoldPostOrder(
				[&fun](const std::pair<DataType,unsigned long>& data, const void*param,void*acc){fun(data.first,param,acc);}
				,data,acc);
	} // Override FoldableContainer member


}
