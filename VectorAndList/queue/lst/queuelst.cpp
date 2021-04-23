
namespace lasd {

/* ************************************************************************** */

// Default constructor

	template<typename DataType>
	QueueLst<DataType>::QueueLst(): List<DataType>::List(){}

  /* ************************************************************************ */

  // Specific constructor
	template<typename DataType>
	QueueLst<DataType>::QueueLst(const LinearContainer<DataType>& container): List<DataType>::List(container){

	} // A queue obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
	template<typename DataType>
	QueueLst<DataType>::QueueLst(const QueueLst<DataType>& queueList): List<DataType>::List(queueList){

	}

  // Move constructor
	template<typename DataType>
	QueueLst<DataType>::QueueLst(QueueLst<DataType>&& queueList) noexcept{
		std::swap(head,queueList.head);
		std::swap(tail,queueList.tail);
		std::swap(size, queueList.size);

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

		std::swap(head,queueList.head);
		std::swap(tail,queueList.tail);
		std::swap(size, queueList.size);
		return *this;
	}

  /* ************************************************************************ */

  // Comparison operators
	template<typename DataType>
    bool QueueLst<DataType>::operator==(const QueueLst& queueList) const noexcept{

		return List<DataType>::operator==(queueList);
	}
	template<typename DataType>
	bool QueueLst<DataType>::operator!=(const QueueLst& queueList) const noexcept{

		return List<DataType>::operator!=(queueList);
	}

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)
	template<typename DataType>
    void QueueLst<DataType>::Enqueue(const DataType& data) {// Override Queue member (copy of the value)

		List<DataType>::InsertAtBack(data);
	}

	template<typename DataType>
	void QueueLst<DataType>::Enqueue( DataType&& data) noexcept { // Override Queue member (move of the value)

		List<DataType>::InsertAtBack(std::move(data));
	}

	template<typename DataType>
	DataType& QueueLst<DataType>::Head() const {// Override Queue member (must throw std::length_error when empty)

		return List<DataType>::Front();
	}

	template<typename DataType>
	void QueueLst<DataType>::Dequeue() {// Override Queue member (must throw std::length_error when empty)

		List<DataType>::RemoveFromFront();
	}

	template<typename DataType>
	DataType QueueLst<DataType>::HeadNDequeue() {// Override Queue member (must throw std::length_error when empty)

		return List<DataType>::FrontNRemove();
	}

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)
	template<typename DataType>
	void QueueLst<DataType>::Clear() {// Override Container member

		List<DataType>::Clear();
	}

/* ************************************************************************** */

}
