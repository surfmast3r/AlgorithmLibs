
namespace lasd {

/* ************************************************************************** */

	// Default constructor
	/*template<typename DataType>
	StackLst<DataType>::StackLst() {
		list= new List<DataType>;
		size=list->Size();
   }*/

  /* ************************************************************************ */

  // Specific constructor
	/*template<typename DataType>
	StackLst<DataType>::StackLst(const LinearContainer<DataType>& container){// A stack obtained from a LinearContainer
		list= new List<DataType>(container);
		size=list->Size();
	}*/

  /* ************************************************************************ */
   // Copy constructor
	/*template<typename DataType>
	StackLst<DataType>::StackLst(const StackLst& stackList){
		list= new List<DataType>(*stackList.list);
		size=list->Size();
	}
*/
   // Move constructor
	template<typename DataType>
	StackLst<DataType>::StackLst(StackLst<DataType>&& stackList) noexcept{
		/*list=new List<DataType>();
		std::swap(list,stackList.list);
		std::swap(size,stackList.size);
		*/
		std::swap(head,stackList.head);
		std::swap(tail,stackList.tail);
		std::swap(size, stackList.size);
	}

  /* ************************************************************************ */

  // Destructor
/*	template<typename DataType>
	StackLst<DataType>::~StackLst(){
		delete list;

	}
*/
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
		//std::swap(list,stackList.list);
		std::swap(head,stackList.head);
		std::swap(tail,stackList.tail);
		std::swap(size, stackList.size);
		return *this;
	}

  /* ************************************************************************ */

  // Comparison operators
	template<typename DataType>
	bool StackLst<DataType>::operator==(const StackLst<DataType>& stackList) const noexcept{
		//return *list==*stackList.list;
		return List<DataType>::operator==(stackList);
	}
	template<typename DataType>
	bool StackLst<DataType>::operator!=(const StackLst<DataType>& stackList) const noexcept{
		//return *list!=*stackList.list;
		return List<DataType>::operator!=(stackList);
	}

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)
	template<typename DataType>
	void StackLst<DataType>::Push(const DataType& data) {// Override Stack member (copy of the value)
		//list->InsertAtFront(data);
		//size=list->Size();
		List<DataType>::InsertAtFront(data);
	}

	template<typename DataType>
	void StackLst<DataType>::Push(DataType&& data) noexcept{// Override Stack member (move of the value)
		//list->InsertAtFront(std::move(data));
		//size=list->Size();
		List<DataType>::InsertAtFront(data);
	}

	template<typename DataType>
	DataType& StackLst<DataType>::Top() const {// Override Stack member (must throw std::length_error when empty)
		//return list->Front();
		return List<DataType>::Front();

	}

	template<typename DataType>
	void StackLst<DataType>::Pop() {// Override Stack member (must throw std::length_error when empty)
		//list->RemoveFromFront();
		//size=list->Size();
		List<DataType>::RemoveFromFront();
	}

	template<typename DataType>
	DataType StackLst<DataType>::TopNPop() {// Override Stack member (must throw std::length_error when empty)
		//size--;
		return List<DataType>::FrontNRemove();

	}

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)
	template<typename DataType>
	void StackLst<DataType>::Clear() {
		//list->Clear();
		//size=0;
		List<DataType>::Clear();
	} // Override Container member

/* ************************************************************************** */

}
