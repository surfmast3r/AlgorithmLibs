
namespace lasd {

/* ************************************************************************** */

// Default constructor
	template <typename DataType>
	StackVec<DataType>::StackVec() : Vector<DataType>::Vector(2){
		stackSize=0;
		top=0;
	}

  /* ************************************************************************ */

  // Specific constructor
	template <typename DataType>
	StackVec<DataType>::StackVec(const LinearContainer<DataType>& linearContainer) : Vector<DataType>::Vector(linearContainer){
		stackSize=linearContainer.Size();
		top=0;
	} // A stack obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
	template <typename DataType>
	StackVec<DataType>::StackVec(const StackVec<DataType>& stackVector) :  Vector<DataType>::Vector(stackVector){
		stackSize=stackVector.stackSize;
		top=stackVector.top;
	}

  // Move constructor
	template <typename DataType>
	StackVec<DataType>::StackVec(StackVec<DataType>&& stackVector) noexcept :  Vector<DataType>::Vector(stackVector){
		std::swap(stackSize, stackVector.stackSize);
		std::swap(top, stackVector.top);

	}

  /* ************************************************************************ */

  // Destructor
	template <typename DataType>
	StackVec<DataType>::~StackVec() = default;

  /* ************************************************************************ */

  // Copy assignment
	template <typename DataType>
	StackVec<DataType>& StackVec<DataType>::operator=(const StackVec<DataType>& stackVector){
		StackVec<DataType>* temp = new StackVec<DataType>(stackVector);
		std::swap(*temp,*this);
		delete temp;

		return *this;
	}

  // Move assignment
	template <typename DataType>
	StackVec<DataType>& StackVec<DataType>::operator=(StackVec<DataType>&& stackVector){
		std::swap(Elements,stackVector.Elements);
		std::swap(size, stackVector.size);
		std::swap(stackSize, stackVector.stackSize);
		std::swap(top, stackVector.top);
		return *this;
	}

  /* ************************************************************************ */

  // Comparison operators
	template <typename DataType>
	bool StackVec<DataType>::operator==(const StackVec<DataType>& stackVector) const noexcept{

		if(stackSize == stackVector.stackSize){
			for(unsigned long i=0;i<stackSize;i++){
				if(Elements[i] != stackVector.Elements[i])
					return false;
			}
			return true;
		}
		else
			return false;
	}
	template <typename DataType>
	bool StackVec<DataType>::operator!=(const StackVec<DataType>& stackVector) const noexcept{
		return !(*this == stackVector);
	}

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

	template <typename DataType>
	void StackVec<DataType>::Push(const DataType& value) {// Override Stack member (copy of the value)
		if(fullStack()){ Expand();}
		top++;
		Elements[top]=value;

		stackSize++;

	}

	template <typename DataType>
	void StackVec<DataType>::Push(DataType&& value) noexcept {
		if(fullStack()){ Expand();}
		top++;
		Elements[top]=std::move(value);
		stackSize++;
	} // Override Stack member (move of the value)

	template <typename DataType>
	DataType& StackVec<DataType>::Top() const{
		if(!emptyStack())
			return Elements[top];
		else
			throw std::length_error("Stack is Empty size:"+ std::to_string(stackSize));
	} // Override Stack member (must throw std::length_error when empty)

	template <typename DataType>
	void StackVec<DataType>::Pop() {

		if( !emptyStack() ){
			top--;
			stackSize--;
		}
		else
			throw std::length_error("Stack is Empty size:"+ std::to_string(stackSize));

	} // Override Stack member (must throw std:: when empty)

	template <typename DataType>
	DataType StackVec<DataType>::TopNPop() {
		if( !emptyStack() ){
			DataType returnValue=Elements[top];
			top--;
			stackSize--;

			return returnValue;
		}
		else
			throw std::length_error("Stack is Empty size:"+ std::to_string(stackSize));
	} // Override Stack member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)
	template <typename DataType>
	bool StackVec<DataType>::Empty() const noexcept {
		return StackVec<DataType>::emptyStack();
	} // Override Container member

	template <typename DataType>
	unsigned long StackVec<DataType>::Size() const noexcept {
		return StackVec<DataType>::stackSize;
	} // Override Container member

	template <typename DataType>
	void StackVec<DataType>::Clear() {
		Vector<DataType>::Clear();
		StackVec<DataType>* temp = new StackVec<DataType>();
		std::swap(*temp,*this);

	} // Override Container member.

/* ************************************************************************** */
	template <typename DataType>
	bool StackVec<DataType>::fullStack() const{
		return stackSize==size-1;
	}
	template <typename DataType>
	bool StackVec<DataType>::emptyStack() const{
		return stackSize==0;
	}

	template <typename DataType>
	void StackVec<DataType>::Expand(){
		Vector<DataType>::Resize(2*size);
	}

}
