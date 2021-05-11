
namespace lasd {

/* ************************************************************************** */

	//NodeVec
	template<typename DataType>
	BinaryTreeVec<DataType>::NodeVec::NodeVec(const DataType& value, unsigned int& i, Vector<NodeVec>& vec) {
		data=value;
		index=i;
		btVec=&vec;
	}

	// Copy assignment
	template<typename DataType>
	typename BinaryTreeVec<DataType>::NodeVec& BinaryTreeVec<DataType>::NodeVec::operator=(const NodeVec& node) noexcept{
		btVec=node.btVec;
		data=node.data;
		index=node.index;
		return *this;
	}

    // Move assignment
	template<typename DataType>
	typename BinaryTreeVec<DataType>::NodeVec& BinaryTreeVec<DataType>::NodeVec::operator=(NodeVec&& node) noexcept{
		std::swap(data,node.data);
		std::swap(index,node.index);
		std::swap(btVec,node.btVec);
		return *this;
	}

	// Specific member functions
	template<typename DataType>
	DataType& BinaryTreeVec<DataType>::NodeVec::Element() noexcept {
		return data;
	} // Mutable access to the element (concrete function should not throw exceptions)

	template<typename DataType>
	const DataType& BinaryTreeVec<DataType>::NodeVec::Element() const noexcept {
		return data;
	} // Immutable access to the element (concrete function should not throw exceptions)

	template<typename DataType>
	bool BinaryTreeVec<DataType>::NodeVec::IsLeaf() const noexcept{
		return (!HasLeftChild()&&!HasRightChild());
	} // (concrete function should not throw exceptions)

	template<typename DataType>
	bool BinaryTreeVec<DataType>::NodeVec::HasLeftChild()const noexcept{
		try{
			(*btVec)[(index*2+1)];
		}
		catch (std::out_of_range&) {
			return false;
		}
		return true;
	} // (concrete function should not throw exceptions)

	template<typename DataType>
	bool BinaryTreeVec<DataType>::NodeVec::HasRightChild()const noexcept{
		try{
			(*btVec)[(index*2+2)];
		}
		catch (std::out_of_range&) {
			return false;
		}
		return true;
	} // (concrete function should not throw exceptions)

	template<typename DataType>
	typename BinaryTreeVec<DataType>::NodeVec& BinaryTreeVec<DataType>::NodeVec::LeftChild() const{
		if(HasLeftChild()){
			return (*btVec)[(index*2+1)];
		}

		else
			throw std::out_of_range("left child not existent");
	} // (concrete function must throw std::out_of_range when not existent)

	template<typename DataType>
	typename BinaryTreeVec<DataType>::NodeVec& BinaryTreeVec<DataType>::NodeVec::RightChild() const{
		if(HasRightChild()){
			return (*btVec)[(index*2+2)];
		}
		else
			throw std::out_of_range("right child not existent");
	} // (concrete function must throw std::out_of_range when not existent)

	template <typename DataType>
	bool BinaryTreeVec<DataType>::NodeVec::operator==(const NodeVec& node) const noexcept{

		return BinaryTree<DataType>::Node::operator==(node);
	}

	template <typename DataType>
	bool BinaryTreeVec<DataType>::NodeVec::operator!=(const NodeVec& node) const noexcept{
		return BinaryTree<DataType>::Node::operator!=(node);
	}

/* ************************************************************************** */
	//BinaryTreeVec

	// Specific constructors
	template<typename DataType>
    BinaryTreeVec<DataType>::BinaryTreeVec(const LinearContainer<DataType>& container){
		size=container.Size();
		binaryTreeVector=Vector<NodeVec>(size);
		for(unsigned int i=0;i<size;i++){
			BinaryTreeVec<DataType>::NodeVec newNode(container[i],i,binaryTreeVector);
			binaryTreeVector[i]=newNode;
		}

	} // A binary tree obtained from a LinearContainer

	/* ************************************************************************ */

	// Copy constructor
	template<typename DataType>
	BinaryTreeVec<DataType>::BinaryTreeVec(const BinaryTreeVec& btVec) noexcept{
		binaryTreeVector= Vector<NodeVec>(btVec.binaryTreeVector);
		size= btVec.size;
	}

	// Move constructor
	template<typename DataType>
	BinaryTreeVec<DataType>::BinaryTreeVec(BinaryTreeVec&& btVec) noexcept{
		std::swap(binaryTreeVector,btVec.binaryTreeVector);
		std::swap(size,btVec.size);
	}

	/* ************************************************************************ */

	// Destructor
	template<typename DataType>
	BinaryTreeVec<DataType>::~BinaryTreeVec(){}

	/* ************************************************************************ */

	// Copy assignment
	template<typename DataType>
	BinaryTreeVec<DataType>& BinaryTreeVec<DataType>::operator=(const BinaryTreeVec& btVec) noexcept{
		size=btVec.size;
		binaryTreeVector=btVec.binaryTreeVector;
		return *this;

	}

	// Move assignment
	template<typename DataType>
	BinaryTreeVec<DataType>& BinaryTreeVec<DataType>::operator=(BinaryTreeVec&& btVec) noexcept{
		std::swap(binaryTreeVector,btVec.binaryTreeVector);
		std::swap(size,btVec.size);
		return *this;
	}

	/* ************************************************************************ */

	// Comparison operators
	template<typename DataType>
	bool BinaryTreeVec<DataType>::operator==(const BinaryTreeVec& btVec) const noexcept{
		return binaryTreeVector==btVec.binaryTreeVector;
	}

	template<typename DataType>
	bool BinaryTreeVec<DataType>::operator!=(const BinaryTreeVec& btVec) const noexcept{
		return binaryTreeVector!=btVec.binaryTreeVector;
	}

	/* ************************************************************************ */

	// Specific member functions (inherited from BinaryTree)

	template<typename DataType>
	typename BinaryTree<DataType>::Node& BinaryTreeVec<DataType>::Root() const{
		if(size>0)
			return binaryTreeVector[0];
		else throw std::length_error("tree is empty");
	} // Override BinaryTree member (throw std::length_error when empty)

	/* ************************************************************************ */

	// Specific member functions (inherited from Container)

	template<typename DataType>
	void BinaryTreeVec<DataType>::Clear() {
		//delete binaryTreeVector;
		size=0;
	} // Override Container member

	template <typename DataType>
	void BinaryTreeVec<DataType>::MapBreadth(const typename BinaryTree<DataType>::MapFunctor function, void* param) {// Override BreadthMappableContainer member

		for(unsigned int i = 0; i<size;i++){
			function(binaryTreeVector[i].Element(),param);
		}
	}
	template <typename DataType>
	void BinaryTreeVec<DataType>::FoldBreadth(const typename BinaryTree<DataType>::FoldFunctor function,const  void* param, void* acc) const{// Override BreadthMappableContainer member

		for(unsigned int i = 0; i<size;i++){
			function(binaryTreeVector[i].Element(),param,acc);
		}
	}


}
