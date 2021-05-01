
// #include "..."

namespace lasd {

/* ************************************************************************** */
template <typename DataType>
bool BinaryTree<DataType>::operator==(const BinaryTree<DataType>& binaryTree) const noexcept{

	Node& btRoot=binaryTree.Root();
	if(size==binaryTree.size)
	{
		return AuxiliaryEqualOperatorFunction( this->Root(),btRoot);
	}else return false;

}
template <typename DataType>
bool BinaryTree<DataType>::operator!=(const BinaryTree& binaryTree) const noexcept{
	return !(*this == binaryTree);
}

template <typename DataType>
bool AuxiliaryEqualOperatorFunction (typename BinaryTree<DataType>::Node& node1, typename BinaryTree<DataType>::Node& node2){
	if(node1.HasLeftChild()==node2.HasLeftChild()){
		if(node1.HasLeftChild()){
			AuxiliaryEqualOperator(node1.LeftChild(),node2.LeftChild());
		}
	}
	else return false;
	if(node1.HasRightChild()==node2.HasRightChild()){
		if(node1.HasRightChild())
			AuxiliaryEqualOperator(node1.RightChild(),node2.RightChild());
	}
	else return false;

	return node1.Element()==node2.Element();
}

/* ************************************************************************** */
	//mappable container functions
	template <typename DataType>
	void BinaryTree<DataType>::MapPreOrder(const MapFunctor function,void* param){
		Node* root=this->Root();
		MapPreOrder(function,param, root);
	}
	template <typename DataType>
	void BinaryTree<DataType>::MapPostOrder(const MapFunctor function,void* param){
		MapPostOrder(function,param, this->Root());
	}

	// Auxiliary member functions (for MappableContainer)
	template <typename DataType>
	void BinaryTree<DataType>::MapPreOrder(const MapFunctor function, void* param, Node& node){// Accessory function executing from one node of the tree
		if(node!=nullptr)
		{
			function(node.Element(),param);
			MapPreOrder(function,param,node.LeftChild());
			MapPreOrder(function,param,node.RightChild());
		}

	}
	template <typename DataType>
	void BinaryTree<DataType>::MapPostOrder(const MapFunctor function, void* param, Node& node){// Accessory function executing from one node of the tree
		if(node!=nullptr)
		{

			MapPreOrder(function,param,node.LeftChild());
			MapPreOrder(function,param,node.RightChild());
			function(node.Element(),param);
		}
	}
	/* ************************************************************************ */

	// Specific member functions (inherited from FoldableContainer)

	template <typename DataType>
	void BinaryTree<DataType>::FoldPreOrder(const FoldFunctor function, const void* param, void*acc) const {// Override FoldableContainer member
		FoldPreOrder(function,param,acc, this->Root());
	}
	template <typename DataType>
	void BinaryTree<DataType>::FoldPostOrder(const FoldFunctor function, const void* param, void*acc) const {// Override FoldableContainer member
		FoldPostOrder(function,param,acc, this->Root());
	};

	// Auxiliary member functions (for FoldableContainer)
	template <typename DataType>
	void BinaryTree<DataType>::FoldPreOrder(const FoldFunctor function,const void*param, void* acc, Node& node) const{// Accessory function executing from one node of the tree
		if(node!=nullptr)
		{
			function(node.Element(),param);
			FoldPreOrder(function,param,node.LeftChild());
			FoldPreOrder(function,param,node.RightChild());
		}
	}
	template <typename DataType>
	void BinaryTree<DataType>::FoldPostOrder(const FoldFunctor function,const void* param, void* acc, Node& node) const{// Accessory function executing from one node of the tree
		if(node!=nullptr)
		{
			FoldPostOrder(function,param,acc,node.LeftChild());
			FoldPostOrder(function,param,acc,node.RightChild());
			function(node.Element(),param);
		}
	}
	/* ************************************************************************ */
	// Specific member functions (inherited from InOrderMappableContainer)

	template <typename DataType>
	void BinaryTree<DataType>::MapInOrder(const MapFunctor function, void* param) {// Override InOrderMappableContainer member
		MapInOrder(function,param,this->Root());
	}

	// Auxiliary member functions (for InOrderMappableContainer)

	template <typename DataType>
	void BinaryTree<DataType>::MapInOrder(const MapFunctor function, void* param, Node& node){// Accessory function executing from one node of the tree
		if(node!=nullptr)
		{
			MapInOrder(function,param,node.LeftChild());
			function(node.Element(),param);
			MapInOrder(function,param,node.RightChild());

		}
	}

	/* ************************************************************************ */

	// Specific member functions (inherited from InOrderFoldableContainer)

	template <typename DataType>
	void BinaryTree<DataType>::FoldInOrder(const FoldFunctor function, const void* param,void* acc) const{

	} // Override InOrderFoldableContainer member

	// Auxiliary member functions (for InOrderFoldableContainer)
	template <typename DataType>
	void BinaryTree<DataType>::FoldInOrder(const FoldFunctor function,const void* param,void* acc, Node& node) const{// Accessory function executing from one node of the tree
		if(node!=nullptr)
		{
			FoldInOrder(function,param,acc,node.LeftChild());
			function(node.Element(),param);
			FoldInOrder(function,param,acc,node.RightChild());


		}
	}

	/* ************************************************************************ */
	// Specific member functions (inherited from BreadthMappableContainer)

	template <typename DataType>
	void BinaryTree<DataType>::MapBreadth(const MapFunctor, void* param) {} // Override BreadthMappableContainer member

	// Auxiliary member functions (for BreadthMappableContainer)

	template <typename DataType>
	void BinaryTree<DataType>::MapBreadth(const MapFunctor function, void* param, Node&){} // Accessory function executing from one node of the tree

	/* ************************************************************************ */

	// Specific member functions (inherited from BreadthFoldableContainer)

	template <typename DataType>
	void BinaryTree<DataType>::FoldBreadth(const FoldFunctor function, const void* param,void* acc) const {} // Override BreadthFoldableContainer member

	// Auxiliary member functions (for BreadthFoldableContainer)

	template <typename DataType>
	void BinaryTree<DataType>::FoldBreadth(const FoldFunctor function,const void* param,void* acc, Node&) const{} // Accessory function executing from one node of the tree
}
