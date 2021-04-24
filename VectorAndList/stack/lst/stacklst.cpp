
namespace lasd {

/* ************************************************************************** */

	// Default constructor
	template<typename DataType>
	StackLst<DataType>::StackLst() : List<DataType>::List(){}

  /* ************************************************************************ */

  // Specific constructor
	template<typename DataType>
	StackLst<DataType>::StackLst(const LinearContainer<DataType>& container): List<DataType>::List(container){}// A stack obtained from a LinearContainer

  /* ************************************************************************ */
   // Copy constructor
	template<typename DataType>
	StackLst<DataType>::StackLst(const StackLst& stackList): List<DataType>::List(stackList){}

   // Move constructor
	template<typename DataType>
	StackLst<DataType>::StackLst(StackLst<DataType>&& stackList) noexcept{
		std::swap(head,stackList.head);
		std::swap(tail,stackList.tail);
		std::swap(size, stackList.size);
	}

  /* ************************************************************************ */

   // Copy assignment
	template<typename DataType>
	StackLst<DataType>& StackLst<DataType>::operator=(const StackLst<DataType>& stackList){
		StackLst<DataType>* temp = new StackLst<DataType>(stackList);
		std::swap(*temp,*this);
		delete temp;

		return *this;
	}

   // Move assignment
	template<typename DataType>
	StackLst<DataType>& StackLst<DataType>::operator=(StackLst<DataType>&& stackList) noexcept{
		std::swap(head,stackList.head);
		std::swap(tail,stackList.tail);
		std::swap(size, stackList.size);
		return *this;
	}

  /* ************************************************************************ */

  // Comparison operators
	template<typename DataType>
	bool StackLst<DataType>::operator==(const StackLst<DataType>& stackList) const noexcept{
		return List<DataType>::operator==(stackList);
	}
	template<typename DataType>
	bool StackLst<DataType>::operator!=(const StackLst<DataType>& stackList) const noexcept{

		return List<DataType>::operator!=(stackList);
	}

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)
	template<typename DataType>
	void StackLst<DataType>::Push(const DataType& data) {// Override Stack member (copy of the value)

		List<DataType>::InsertAtFront(data);
	}

	template<typename DataType>
	void StackLst<DataType>::Push(DataType&& data) noexcept{// Override Stack member (move of the value)

		List<DataType>::InsertAtFront(std::move(data));
	}

	template<typename DataType>
	DataType& StackLst<DataType>::Top() const {// Override Stack member (must throw std::length_error when empty)

		return List<DataType>::Front();

	}

	template<typename DataType>
	void StackLst<DataType>::Pop() {// Override Stack member (must throw std::length_error when empty)

		List<DataType>::RemoveFromFront();
	}

	template<typename DataType>
	DataType StackLst<DataType>::TopNPop() {// Override Stack member (must throw std::length_error when empty)

		return List<DataType>::FrontNRemove();

	}

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)
	template<typename DataType>
	void StackLst<DataType>::Clear() {

		List<DataType>::Clear();
	} // Override Container member

/* ************************************************************************** */

}
