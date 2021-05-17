
namespace lasd {

/* ************************************************************************** */
	//NodeLnk

	template<typename DataType>
	BinaryTreeLnk<DataType>::NodeLnk::NodeLnk(const DataType& value){
		data=value;
	}

	// Copy assignment
	template<typename DataType>
	typename BinaryTreeLnk<DataType>::NodeLnk& BinaryTreeLnk<DataType>::NodeLnk::operator=(const NodeLnk& node) noexcept{

		data=node.data;
		leftChild=node.leftChild;
		rightChild=node.rightChild;
		return *this;
	}

    // Move assignment
	template<typename DataType>
	typename BinaryTreeLnk<DataType>::NodeLnk& BinaryTreeLnk<DataType>::NodeLnk::operator=(NodeLnk&& node) noexcept{
		std::swap(data,node.data);
		std::swap(leftChild,node.leftChild);
		std::swap(rightChild,node.rightChild);
		return *this;
	}

	// Specific member functions
	template<typename DataType>
	DataType& BinaryTreeLnk<DataType>::NodeLnk::Element() noexcept {
		return data;
	} // Mutable access to the element (concrete function should not throw exceptions)

	template<typename DataType>
	const DataType& BinaryTreeLnk<DataType>::NodeLnk::Element() const noexcept {
		return data;
	} // Immutable access to the element (concrete function should not throw exceptions)

	template<typename DataType>
	bool BinaryTreeLnk<DataType>::NodeLnk::IsLeaf() const noexcept{
		return (!HasLeftChild()&&!HasRightChild());
	} // (concrete function should not throw exceptions)

	template<typename DataType>
	bool BinaryTreeLnk<DataType>::NodeLnk::HasLeftChild()const noexcept{
		return (leftChild!=nullptr);
	} // (concrete function should not throw exceptions)

	template<typename DataType>
	bool BinaryTreeLnk<DataType>::NodeLnk::HasRightChild()const noexcept{
		return (rightChild!=nullptr);
	} // (concrete function should not throw exceptions)

	template<typename DataType>
	typename BinaryTreeLnk<DataType>::NodeLnk& BinaryTreeLnk<DataType>::NodeLnk::LeftChild() const{
		if(HasLeftChild())
			return *leftChild;
		else
			throw std::out_of_range("left child not existent");
	} // (concrete function must throw std::out_of_range when not existent)

	template<typename DataType>
	typename BinaryTreeLnk<DataType>::NodeLnk& BinaryTreeLnk<DataType>::NodeLnk::RightChild() const{
		if(HasRightChild())
			return *rightChild;
		else
			throw std::out_of_range("right child not existent");
	} // (concrete function must throw std::out_of_range when not existent)

	template <typename DataType>
	bool BinaryTreeLnk<DataType>::NodeLnk::operator==(const NodeLnk& node) const noexcept{

		return BinaryTree<DataType>::operator==(node);
	}

	template <typename DataType>
	bool BinaryTreeLnk<DataType>::NodeLnk::operator!=(const NodeLnk& node) const noexcept{
		return BinaryTree<DataType>::operator!=(node);
	}


/* ************************************************************************** */
	//BinaryTreeLnk
	// Specific constructors
	template<typename DataType>
	BinaryTreeLnk<DataType>::BinaryTreeLnk(const LinearContainer<DataType>& linearContainer){
		size=linearContainer.Size();

		if(size>0){
			root=buildTreeFromLinearContainer(linearContainer,0,size);

		}
	}


	template<typename DataType>
	typename BinaryTreeLnk<DataType>::NodeLnk* BinaryTreeLnk<DataType>::buildTreeFromLinearContainer(const LinearContainer<DataType>& container, int i, int n)
	{
		// Base case for recursion
		if (i < n)
		{
			NodeLnk* temp= new NodeLnk();

			temp->data=container[i];
			// insert left child
			temp->leftChild = buildTreeFromLinearContainer(container, 2 * i + 1, n);
			// insert right child
			temp->rightChild = buildTreeFromLinearContainer(container, 2 * i + 2, n);
			return temp;
		}
		return nullptr;
	}

	/* ************************************************************************ */

	// Copy constructor
	template<typename DataType>
	BinaryTreeLnk<DataType>::BinaryTreeLnk(const BinaryTreeLnk& binaryTree) {

		size=binaryTree.size;
		if(size>0){

			root= binaryTreeCopy(binaryTree.root);

		}
	}
	template<typename DataType>
	typename BinaryTreeLnk<DataType>::NodeLnk* BinaryTreeLnk<DataType>::binaryTreeCopy( NodeLnk* node)
		{
				NodeLnk* copyNode = new NodeLnk(node->Element());

				if(node->HasLeftChild())
					copyNode->leftChild=binaryTreeCopy(&node->LeftChild());
				if(node->HasRightChild())
					copyNode->rightChild=binaryTreeCopy(&node->RightChild());
		    	return copyNode;
		}

	// Move constructor
	template<typename DataType>
	BinaryTreeLnk<DataType>::BinaryTreeLnk(BinaryTreeLnk&& binaryTree) noexcept{
		std::swap(root, binaryTree.root);
		std::swap(size, binaryTree.size);

	}

	// Copy assignment
	template<typename DataType>
	BinaryTreeLnk<DataType>& BinaryTreeLnk<DataType>::operator=(const BinaryTreeLnk& bt) noexcept{
		BinaryTreeLnk<DataType>* temp = new BinaryTreeLnk<DataType>(bt);
		std::swap(*temp,*this);
		delete temp;
		return *this;
	}

	// Move assignment
	template<typename DataType>
	BinaryTreeLnk<DataType>& BinaryTreeLnk<DataType>::operator=(BinaryTreeLnk&& binaryTree) noexcept{
		std::swap(root, binaryTree.root);
		std::swap(size, binaryTree.size);
		return *this;
	}

	/* ************************************************************************ */
	//comparison operators
	template<typename DataType>
	bool BinaryTreeLnk<DataType>::operator==(const BinaryTreeLnk& bt) const noexcept{
		return BinaryTree<DataType>::operator==(bt);
	}

	template<typename DataType>
	bool BinaryTreeLnk<DataType>::operator!=(const BinaryTreeLnk& bt) const noexcept{
		return BinaryTree<DataType>::operator!=(bt);
	}

	/* ************************************************************************ */

	// Destructor
	template<typename DataType>
	BinaryTreeLnk<DataType>::~BinaryTreeLnk(){
		deleteBinaryTree(root);
	}
	// Recursive function to delete a given binary tree
	template<typename DataType>
	void BinaryTreeLnk<DataType>::deleteBinaryTree(NodeLnk* root)
	{
	    if (root == nullptr) {
	        return;
	    }

	    if(root->HasLeftChild())
	    	deleteBinaryTree(&root->LeftChild());
	    if(root->HasRightChild())
	    	deleteBinaryTree(&root->RightChild());

	    delete root;
	    root = nullptr;
	}

	 /* ************************************************************************ */

	template<typename DataType>
	void BinaryTreeLnk<DataType>::Clear(){
		deleteBinaryTree(root);
		root = nullptr;
		size=0;
	} // Override Container member
/* ************************************************************************** */
	template<typename DataType>
    typename BinaryTree<DataType>::Node& BinaryTreeLnk<DataType>::Root() const{
		if(size>0)
			return *root;
		else
			throw std::length_error("tree is empty");
	}

}
