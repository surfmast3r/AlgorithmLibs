
namespace lasd {

/* ************************************************************************** */

	// Default constructor
	template <typename DataType>
	QueueVec<DataType>::QueueVec() : Vector<DataType>::Vector(2){
		queueSize=0;
		head=0;
		tail=0;
	}

   /* ************************************************************************ */
	// Specific constructor
	template <typename DataType>
	QueueVec<DataType>::QueueVec(const LinearContainer<DataType>& linearContainer) : Vector<DataType>::Vector(linearContainer){
		queueSize=linearContainer.Size();
		head=0;
		tail=queueSize;
	} // A stack obtained from a LinearContainer


   /* ************************************************************************** */
	// Copy constructor
	template <typename DataType>
	QueueVec<DataType>::QueueVec(const QueueVec<DataType>& queueVector) {
		size=queueVector.size;
		Elements= new DataType[size];
		std::copy(queueVector.Elements, queueVector.Elements + size, Elements);
		queueSize=queueVector.queueSize;
		head=queueVector.head;
		tail=queueVector.tail;
	}

	// Move constructor
	template <typename DataType>
	QueueVec<DataType>::QueueVec(QueueVec<DataType>&& queueVector) noexcept {
		std::swap(Elements,queueVector.Elements);
		std::swap(size, queueVector.size);
		std::swap(queueSize, queueVector.queueSize);
		std::swap(head, queueVector.head);
		std::swap(tail, queueVector.tail);

	}

  /* ************************************************************************ */

	// Destructor
	template <typename DataType>
	QueueVec<DataType>::~QueueVec() = default;

	/* ************************************************************************ */

	// Copy assignment
	template <typename DataType>
	QueueVec<DataType>& QueueVec<DataType>::operator=(const QueueVec<DataType>& queueVector){
		QueueVec<DataType>* temp = new QueueVec<DataType>(queueVector);
		std::swap(*temp,*this);
		delete temp;

		return *this;
	}

	// Move assignment
	template <typename DataType>
	QueueVec<DataType>& QueueVec<DataType>::operator=(QueueVec<DataType>&& queueVector) noexcept{
		std::swap(Elements,queueVector.Elements);
		std::swap(size, queueVector.size);
		std::swap(queueSize, queueVector.queueSize);
		std::swap(head, queueVector.head);
		std::swap(tail, queueVector.tail);
		return *this;
	}

	/* ************************************************************************ */
	// Comparison operators
	template <typename DataType>
	bool QueueVec<DataType>::operator==(const QueueVec<DataType>& queueVector) const noexcept{

		if(queueSize == queueVector.queueSize){
			unsigned long h=head,t=tail;
			unsigned long queueVecH=queueVector.head;
			while(h!=t){
				if(Elements[h] != queueVector.Elements[queueVecH])
					return false;
				h = (h+1)%(size);
				queueVecH = (queueVecH+1)%(size);
			}
			return true;
		}
		else
			return false;
	}
	template <typename DataType>
	bool QueueVec<DataType>::operator!=(const QueueVec<DataType>& stackVector) const noexcept{
		return !(*this == stackVector);
	}


	/* ************************************************************************ */


	// Specific member functions (inherited from Queue)

	template <typename DataType>
	void QueueVec<DataType>::Enqueue(const DataType& value) {
		if(fullQueue()){ Expand(2*size);}
		Elements[tail]=value;
		tail = (tail+1)%(size);
		queueSize++;
	}// Override Queue member (copy of the value)

	template <typename DataType>
	void QueueVec<DataType>::Enqueue(DataType&& value) noexcept {
		if(fullQueue()){ Expand(2*size);}
		Elements[tail]=std::move(value);
		tail = (tail+1)%(size);
		queueSize++;
	}  // Override Queue member (move of the value)

	template <typename DataType>
	DataType& QueueVec<DataType>::Head() const {
		if ( emptyQueue() )
		{
			throw std::length_error("queue is empty");
		}
		return Elements[head];
	} // Override Queue member (must throw std::length_error when empty)

	template <typename DataType>
	void QueueVec<DataType>::Dequeue() {
		if ( !emptyQueue() )
		{
			head = (head+1)%(size);
			queueSize--;
		}
		else
			throw std::length_error("Queue is empty");
	} // Override Queue member (must throw std::length_error when empty)

	template <typename DataType>
	DataType QueueVec<DataType>::HeadNDequeue() {
		if ( !emptyQueue() )
		{
			DataType returnValue = Elements[head];
			head = (head+1)%(size);
			queueSize--;
			return returnValue;
		}
		else
			throw new std::length_error("Queue is empty");


	} // Override Queue member (must throw std::length_error when empty)

	/* ************************************************************************ */
	 // Specific member functions (inherited from Container)
	template <typename DataType>
	bool QueueVec<DataType>::Empty() const noexcept {
		return QueueVec<DataType>::emptyQueue();
	} // Override Container member

	template <typename DataType>
	unsigned long QueueVec<DataType>::Size() const noexcept {
		return queueSize;
	} // Override Container member

	template <typename DataType>
	void QueueVec<DataType>::Clear() {
		Vector<DataType>::Clear();
		size=2;
		Elements= new DataType[size]{};
		queueSize=0;
		head=0;
		tail=0;

	} // Override Container member.
  /* ************************************************************************ */
	template <typename DataType>
	void QueueVec<DataType>::Expand(const unsigned long newSize){
		if(newSize==0)
			Clear();
		else if(size!=newSize){
			unsigned long limit= (size < newSize) ? size:newSize;
			DataType* temp= new DataType[newSize]{};
			unsigned long i=0;
			while(head!=tail){
				std::swap(Elements[head],temp[i]);
				i++;
				head = (head+1)%(size);
			}
			std::swap(Elements,temp);
			head=0;
			tail=queueSize;
			size= newSize;
			delete[] temp;
		}
	}

	template <typename DataType>
	bool QueueVec<DataType>::fullQueue() const{
		return (tail+1)%size==head;
	}
	template <typename DataType>
	bool QueueVec<DataType>::emptyQueue() const{
		return tail==head;
	}
}
