
namespace lasd {

/* ************************************************************************** */

	// Default constructor
	template<typename DataType>
	StackLst<DataType>::StackLst() {
		list= new List<DataType>;
   }

  /* ************************************************************************ */

  // Specific constructor
	template<typename DataType>
	StackLst<DataType>::StackLst(const LinearContainer<DataType>& container){// A stack obtained from a LinearContainer
		list= new List<DataType>(container);
	}

  /* ************************************************************************ */
   // Copy constructor
	template<typename DataType>
	StackLst<DataType>::StackLst(const StackLst& stackList){
		list= new List<DataType>(*stackList.list);
	}

   // Move constructor
	template<typename DataType>
	StackLst<DataType>::StackLst(StackLst&& stackList) noexcept{
		std::swap(list,stackList.list);
	}

  /* ************************************************************************ */

  // Destructor
	template<typename DataType>
	StackLst<DataType>::~StackLst(){
		delete list;
	}

  /* ************************************************************************ */
   // Copy assignment
	template<typename DataType>
	StackLst<DataType>& StackLst<DataType>::operator=(const StackLst& stackList){
		StackLst<DataType>* temp = new StackLst<DataType>(stackList);
		std::swap(*temp,*this);
		delete temp;
		return *this;
	}

   // Move assignment
	template<typename DataType>
	StackLst<DataType>& StackLst<DataType>::operator=(StackLst&& stackList) noexcept{
		std::swap(list,stackList.list);
		return *this;
	}

  /* ************************************************************************ */

  // Comparison operators
	template<typename DataType>
	bool StackLst<DataType>::operator==(const StackLst& stackList) const noexcept{
		return list==stackList.list;
	}
	template<typename DataType>
	bool StackLst<DataType>::operator!=(const StackLst& stackList) const noexcept{
		return list!=stackList.list;
	}

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)
	template<typename DataType>
	void StackLst<DataType>::Push(const DataType& data) {// Override Stack member (copy of the value)
		list->InsertAtFront(data);
	}

	template<typename DataType>
	void StackLst<DataType>::Push(DataType&& data) noexcept{// Override Stack member (move of the value)
		list->InsertAtFront(std::move(data));
	}

	template<typename DataType>
	DataType& StackLst<DataType>::Top() const {// Override Stack member (must throw std::length_error when empty)
		return list->Front();
	}

	template<typename DataType>
	void StackLst<DataType>::Pop() {// Override Stack member (must throw std::length_error when empty)
		list->RemoveFromFront();
	}

	template<typename DataType>
	DataType StackLst<DataType>::TopNPop() {// Override Stack member (must throw std::length_error when empty)
		return list->FrontNRemove();
	}

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)
	template<typename DataType>
	void StackLst<DataType>::Clear() {
		list->Clear();
	} // Override Container member

/* ************************************************************************** */

}
