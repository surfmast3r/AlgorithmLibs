
namespace lasd {

/* ************************************************************************** */

// Specific constructors
	template <typename DataType>
	MatrixVec<DataType>::MatrixVec(unsigned long& row, unsigned long& column) : Vector<DataType>(row*column){// A matrix of some specified dimension
		rowNumber=row;
		columnNumber=column;
	}

  /* ************************************************************************ */

  // Copy constructor
	template <typename DataType>
	MatrixVec<DataType>::MatrixVec( const MatrixVec<DataType>& matrix) : Vector<DataType>(matrix){
		rowNumber=matrix.rowNumber;
		columnNumber=matrix.columnNumber;
	}

  // Move constructor
	template <typename DataType>
	MatrixVec<DataType>::MatrixVec(MatrixVec<DataType>&& matrix) : Vector<DataType>(std::move(matrix)){
		std::swap(rowNumber,matrix.rowNumber);
		std::swap(columnNumber,matrix.columnNumber);
	}

  /* ************************************************************************ */

  // Copy assignment
	template <typename DataType>
	MatrixVec<DataType>& MatrixVec<DataType>::operator=(const MatrixVec<DataType>&matrix) noexcept{
		MatrixVec<DataType>* temp = new MatrixVec<DataType>(matrix);
		std::swap(*temp,*this);
		delete temp;
		return *this;
	}

  // Move assignment

	template <typename DataType>
	MatrixVec<DataType>& MatrixVec<DataType>::operator=(MatrixVec<DataType>&&matrix) noexcept{
		std::swap(Elements,matrix.Elements);
		std::swap(size, matrix.size);
		std::swap(rowNumber,matrix.rowNumber);
		std::swap(columnNumber,matrix.columnNumber);
		return *this;
	}

  /* ************************************************************************ */

  // Comparison operators
	template <typename DataType>
	bool MatrixVec<DataType>::operator==(const MatrixVec<DataType>& matrix) const noexcept {
		return Vector<DataType>::operator==(matrix);
	}

	template <typename DataType>
	bool MatrixVec<DataType>::operator!=(const MatrixVec<DataType>& matrix) const noexcept{
		return !(*this==matrix);
	}

  /* ************************************************************************ */

  // Specific member functions (inherited from Matrix)
	template <typename DataType>
	void MatrixVec<DataType>::RowResize(unsigned long& newRowSize) {
		Vector<DataType>::Resize(newRowSize*columnNumber);
		rowNumber=newRowSize;
	} // Override Matrix member

	template <typename DataType>
	void MatrixVec<DataType>::ColumnResize(unsigned long& newColumnSize) {
		if(newColumnSize==0)
			Vector<DataType>::Clear();
		else if(columnNumber!=newColumnSize){
			unsigned long limit = (columnNumber < newColumnSize) ? (size):(rowNumber*newColumnSize);
			unsigned long diff = (columnNumber < newColumnSize) ? (newColumnSize-columnNumber):(columnNumber-newColumnSize);
			unsigned long endRow = (columnNumber < newColumnSize) ? (columnNumber):(newColumnSize);
			bool expand = (columnNumber < newColumnSize);

			DataType* temp= new DataType[rowNumber*newColumnSize]{};
			unsigned long j=0;
			for (unsigned long i=0;i<limit;i++){

				if(i>0&&i%endRow==0)
					j=j+diff;

				if(expand)
					std::swap(Elements[i],temp[j]);
				else
					std::swap(Elements[j],temp[i]);
				j++;
			}

			std::swap(Elements,temp);

			size=rowNumber*newColumnSize;
			delete[] temp;
		}
		columnNumber=newColumnSize;
	} // Override Matrix member

	template <typename DataType>
	bool MatrixVec<DataType>::ExistsCell(const unsigned long& rowIndex, const unsigned long& columnIndex) const noexcept {
		if(rowIndex<rowNumber&&columnIndex<columnNumber)
			return true;
		else
			return false;
	} // Override Matrix member (should not throw exceptions)

	template <typename DataType>
	DataType& MatrixVec<DataType>::operator()(const unsigned long& rowIndex, const unsigned long& columnIndex) {
		return const_cast<DataType&>(static_cast<const MatrixVec<DataType>*>(this)->operator()(rowIndex,columnIndex));
	} // Override Matrix member (mutable access to the element; throw out_of_range when out of range)

	template <typename DataType>
	DataType const& MatrixVec<DataType>::operator()(const unsigned long& rowIndex, const unsigned long& columnIndex) const{
		if(ExistsCell(rowIndex, columnIndex)){
			return Vector<DataType>::operator[](rowIndex*columnNumber+columnIndex);
		}
		else
			throw std::out_of_range("Out of range index: ["+ std::to_string(rowIndex)+"] ["+ std::to_string(columnIndex)+"]");
	} // Override Matrix member (immutable access to the element; throw out_of_range when out of range and length_error when not present)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)
	template <typename DataType>
	void MatrixVec<DataType>::Clear(){
		Vector<DataType>::Clear();
		rowNumber=0;
		columnNumber=0;
	} // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)
	template <typename DataType>
	void MatrixVec<DataType>::MapPreOrder(const MapFunctor fun, void* param){
		Vector<DataType>::MapPreOrder(fun, param);
	} // Override MappableContainer member

	template <typename DataType>
	void MatrixVec<DataType>::MapPostOrder(const MapFunctor fun, void*param ){
		Vector<DataType>::MapPostOrder(fun, param);
	} // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

	template <typename DataType>
	void MatrixVec<DataType>::FoldPreOrder(const FoldFunctor fun, const void* param ,void* acc) const {
		Vector<DataType>::FoldPreOrder(fun, param,acc);
	} // Override FoldableContainer member

	template <typename DataType>
	void MatrixVec<DataType>::FoldPostOrder(const FoldFunctor fun, const void* param,void*acc) const {
		Vector<DataType>::FoldPostOrder(fun, param,acc);
	} // Override FoldableContainer member
/* ************************************************************************** */

}
