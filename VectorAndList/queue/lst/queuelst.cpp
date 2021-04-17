
namespace lasd {

/* ************************************************************************** */

// Default constructor

	template<typename DataType>
	QueueLst<DataType>::QueueLst(){
		list= new List<DataType>;
		size=list->Size();
	}

  /* ************************************************************************ */

  // Specific constructor
	template<typename DataType>
	QueueLst<DataType>::QueueLst(const LinearContainer<DataType>& container){
		list= new List<DataType>(container);
		size=list->Size();
	} // A queue obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
	template<typename DataType>
	QueueLst<DataType>::QueueLst(const QueueLst<DataType>& queueList){
		list= new List<DataType>(*queueList.list);
		size=list->Size();
	}

  // Move constructor
	template<typename DataType>
	QueueLst<DataType>::QueueLst(QueueLst<DataType>&& queueList){
		list=new List<DataType>();
		std::swap(list,queueList.list);
		std::swap(size,queueList.size);
	}

  /* ************************************************************************ */

  // Destructor
	template<typename DataType>
	QueueLst<DataType>::~QueueLst(){
		delete list;
	}

  /* ************************************************************************ */

    // Copy assignment
	template<typename DataType>
	QueueLst<DataType>& QueueLst<DataType>::operator=(const QueueLst& queueList){
		QueueLst<DataType>* temp = new QueueLst<DataType>(queueList);
		std::swap(*temp,*this);
		delete temp;
		return *this;
	}

	// Move assignment
	template<typename DataType>
	QueueLst<DataType>& QueueLst<DataType>::operator=(QueueLst&& queueList) noexcept{
		std::swap(list,queueList.list);
		return *this;
	}

  /* ************************************************************************ */

  // Comparison operators
	template<typename DataType>
    bool QueueLst<DataType>::operator==(const QueueLst& queueList) const noexcept{
		return *list==*queueList.list;
	}
	template<typename DataType>
	bool QueueLst<DataType>::operator!=(const QueueLst& queueList) const noexcept{
		return *list!=*queueList.list;
	}

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)
	template<typename DataType>
    void QueueLst<DataType>::Enqueue(const DataType& data) {// Override Queue member (copy of the value)
		list->InsertAtBack(data);
		size=list->Size();
	}

	template<typename DataType>
	void QueueLst<DataType>::Enqueue( DataType&& data) noexcept { // Override Queue member (move of the value)
		list->InsertAtBack(std::move(data));
		size=list->Size();
	}

	template<typename DataType>
	DataType& QueueLst<DataType>::Head() const {// Override Queue member (must throw std::length_error when empty)
		return list->Front();
	}

	template<typename DataType>
	void QueueLst<DataType>::Dequeue() {// Override Queue member (must throw std::length_error when empty)
		list->RemoveFromFront();
		size=list->Size();
	}

	template<typename DataType>
	DataType QueueLst<DataType>::HeadNDequeue() {// Override Queue member (must throw std::length_error when empty)
		size--;
		return list->FrontNRemove();
	}

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)
	template<typename DataType>
	void QueueLst<DataType>::Clear() {// Override Container member
		list->Clear();
		size=0;
	}

/* ************************************************************************** */

}
