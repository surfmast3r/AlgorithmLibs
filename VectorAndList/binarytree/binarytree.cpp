
 #include "../queue/lst/queuelst.hpp"
 #include "../stack/lst/stacklst.hpp"

namespace lasd {

/* ************************************************************************** */
template <typename DataType>
bool BinaryTree<DataType>::Node::operator==(const Node& node) const noexcept{

	return node.Element()==this->Element();
}

template <typename DataType>
bool BinaryTree<DataType>::Node::operator!=(const Node& node) const noexcept{
	return !(*this==node);
}

template<typename DataType>
bool BinaryTree<DataType>::Node::IsLeaf() const noexcept{
	return (!HasLeftChild()&&!HasRightChild());
} // (concrete function should not throw exceptions)

/* ************************************************************************** */
template <typename DataType>
bool BinaryTree<DataType>::operator==(const BinaryTree<DataType>& binaryTree) const noexcept{

	if(size==binaryTree.size)
	{
		if(size>0)
			return AuxiliaryEqualOperatorFunction( Root(),binaryTree.Root());
		else
			return true; //equals couse both empty
	}else return false;

}
template <typename DataType>
bool BinaryTree<DataType>::operator!=(const BinaryTree& binaryTree) const noexcept{
	return !(*this == binaryTree);
}

template <typename DataType>
bool BinaryTree<DataType>::AuxiliaryEqualOperatorFunction( Node& node1,  Node& node2) const {

	if(node1==node2){
		if(node1.HasLeftChild()==node2.HasLeftChild()){
			if(node1.HasLeftChild()){
				return AuxiliaryEqualOperatorFunction(node1.LeftChild(),node2.LeftChild());
			}
		}
		else return false;

		if(node1.HasRightChild()==node2.HasRightChild()){
			if(node1.HasRightChild())
				return AuxiliaryEqualOperatorFunction(node1.RightChild(),node2.RightChild());
		}
		else return false;

		return true;
	}
	else return false;
}

/* ************************************************************************** */
	//mappable container functions
	template <typename DataType>
	void BinaryTree<DataType>::MapPreOrder(const MapFunctor function,void* param){

		try{
			MapPreOrder(function,param, this->Root());//check root
		} catch(std::length_error& exc) {}


	}
	template <typename DataType>
	void BinaryTree<DataType>::MapPostOrder(const MapFunctor function,void* param){

		try{
			MapPostOrder(function,param, this->Root());//check root
		} catch(std::length_error& exc) {}
	}

	// Auxiliary member functions (for MappableContainer)
	template <typename DataType>
	void BinaryTree<DataType>::MapPreOrder(const MapFunctor function, void* param, Node& node){// Accessory function executing from one node of the tree

		function(node.Element(),param);
		if(node.HasLeftChild())
			MapPreOrder(function,param,node.LeftChild());
		if(node.HasRightChild())
			MapPreOrder(function,param,node.RightChild());


	}
	template <typename DataType>
	void BinaryTree<DataType>::MapPostOrder(const MapFunctor function, void* param, Node& node){// Accessory function executing from one node of the tree

		if(node.HasLeftChild())
			MapPostOrder(function,param,node.LeftChild());
		if(node.HasRightChild())
			MapPostOrder(function,param,node.RightChild());
		function(node.Element(),param);

	}
	/* ************************************************************************ */

	// Specific member functions (inherited from FoldableContainer)

	template <typename DataType>
	void BinaryTree<DataType>::FoldPreOrder(const FoldFunctor function, const void* param, void*acc) const {// Override FoldableContainer member

		try{
			FoldPreOrder(function,param,acc, this->Root());//check root
		} catch(std::length_error& exc) {}
	}
	template <typename DataType>
	void BinaryTree<DataType>::FoldPostOrder(const FoldFunctor function, const void* param, void*acc) const {// Override FoldableContainer member

		try{
			FoldPostOrder(function,param,acc, this->Root());//check root
		} catch(std::length_error& exc) {}
	};

	// Auxiliary member functions (for FoldableContainer)
	template <typename DataType>
	void BinaryTree<DataType>::FoldPreOrder(const FoldFunctor function,const void*param, void* acc, Node& node) const{// Accessory function executing from one node of the tree

		function(node.Element(),param,acc);
		if(node.HasLeftChild())
			FoldPreOrder(function,param,acc,node.LeftChild());
		if(node.HasRightChild())
			FoldPreOrder(function,param,acc,node.RightChild());

	}
	template <typename DataType>
	void BinaryTree<DataType>::FoldPostOrder(const FoldFunctor function,const void* param, void* acc, Node& node) const{// Accessory function executing from one node of the tree

		if(node.HasLeftChild())
			FoldPostOrder(function,param,acc,node.LeftChild());
		if(node.HasRightChild())
			FoldPostOrder(function,param,acc,node.RightChild());
		function(node.Element(),param,acc);

	}
	/* ************************************************************************ */
	// Specific member functions (inherited from InOrderMappableContainer)

	template <typename DataType>
	void BinaryTree<DataType>::MapInOrder(const MapFunctor function, void* param) {// Override InOrderMappableContainer member

		try{
			MapInOrder(function,param,this->Root());//check root
		} catch(std::length_error& exc) {}
	}

	// Auxiliary member functions (for InOrderMappableContainer)

	template <typename DataType>
	void BinaryTree<DataType>::MapInOrder(const MapFunctor function, void* param, Node& node){// Accessory function executing from one node of the tree

		if(node.HasLeftChild())
			MapInOrder(function,param,node.LeftChild());
		function(node.Element(),param);
		if(node.HasRightChild())
			MapInOrder(function,param,node.RightChild());


	}

	/* ************************************************************************ */

	// Specific member functions (inherited from InOrderFoldableContainer)

	template <typename DataType>
	void BinaryTree<DataType>::FoldInOrder(const FoldFunctor function, const void* param,void* acc) const{

		try{
			FoldInOrder(function,param,acc,Root()); //check root
		} catch(std::length_error& exc) {}

	} // Override InOrderFoldableContainer member

	// Auxiliary member functions (for InOrderFoldableContainer)
	template <typename DataType>
	void BinaryTree<DataType>::FoldInOrder(const FoldFunctor function,const void* param,void* acc, Node& node) const{// Accessory function executing from one node of the tree

		if(node.HasLeftChild())
			FoldInOrder(function,param,acc,node.LeftChild());
		function(node.Element(),param,acc);
		if(node.HasRightChild())
			FoldInOrder(function,param,acc,node.RightChild());


	}

	/* ************************************************************************ */
	// Specific member functions (inherited from BreadthMappableContainer)

	template <typename DataType>
	void BinaryTree<DataType>::MapBreadth(const MapFunctor function, void* param) {// Override BreadthMappableContainer member

		try{
			MapBreadth(function,param,this->Root()); //check root
		} catch(std::length_error& exc) {}
	}

	// Auxiliary member functions (for BreadthMappableContainer)

	template <typename DataType>
	void BinaryTree<DataType>::MapBreadth(const MapFunctor function, void* param, Node& node){// Accessory function executing from one node of the tree

		QueueLst<Node*> myQueue;

		myQueue.Enqueue(&node);
		while (myQueue.Size()>0) {
			Node* n =  myQueue.Head();
			myQueue.Dequeue();
			function(n->Element(),param);
			if (n->HasLeftChild())
				myQueue.Enqueue(&n->LeftChild());
			if (n->HasRightChild())
				myQueue.Enqueue(&n->RightChild());
		}
	}

	/* ************************************************************************ */

	// Specific member functions (inherited from BreadthFoldableContainer)

	template <typename DataType>
	void BinaryTree<DataType>::FoldBreadth(const FoldFunctor function, const void* param,void* acc) const {// Override BreadthFoldableContainer member

		try{
			FoldBreadth(function,param,acc,this->Root());
		} catch(std::length_error& exc) {}
	}

	// Auxiliary member functions (for BreadthFoldableContainer)

	template <typename DataType>
	void BinaryTree<DataType>::FoldBreadth(const FoldFunctor function,const void* param,void* acc, Node& node) const{// Accessory function executing from one node of the tree

		QueueLst<Node*> myQueue;
		myQueue.Enqueue(&node);
		while (myQueue.Size()>0) {
			Node& n =  *myQueue.Head();
			myQueue.Dequeue();
			function(n.Element(),param,acc);
			if (n.HasLeftChild())
				myQueue.Enqueue(&n.LeftChild());
			if (n.HasRightChild())
				myQueue.Enqueue(&n.RightChild());
		}
	}

	/* ************************************************************************ */
	//BTPreOrderIterator

	// Specific constructors
	template<typename DataType>
	BTPreOrderIterator<DataType>::BTPreOrderIterator(const BinaryTree<DataType>& bt){ // An iterator over a given binary tree
		try{
			current=&bt.Root(); //check if exists
		}catch (std::length_error&) {
			current=nullptr;
		}
		stack= new StackLst<typename BinaryTree<DataType>::Node *>();

	}
	/* ************************************************************************ */

	// Copy constructor
	template<typename DataType>
	BTPreOrderIterator<DataType>::BTPreOrderIterator(const BTPreOrderIterator<DataType>& iterator){

		stack=new StackLst<typename BinaryTree<DataType>::Node *>(*iterator.stack);
		current=iterator.current;
	}

	// Move constructor
	template<typename DataType>
	BTPreOrderIterator<DataType>::BTPreOrderIterator(BTPreOrderIterator<DataType>&& iterator) noexcept{
		std::swap(stack, iterator.stack);
		std::swap(current, iterator.current);
	}

	/* ************************************************************************ */

	// Destructor
	template<typename DataType>
	BTPreOrderIterator<DataType>::~BTPreOrderIterator(){
		delete stack;
	}

	/* ************************************************************************ */

	// Copy assignment
	template<typename DataType>
	BTPreOrderIterator<DataType>& BTPreOrderIterator<DataType>::operator=(const BTPreOrderIterator & iterator){

		BTPreOrderIterator<DataType>* temp = new BTBreadthIterator<DataType>(iterator);
		std::swap(*this,*temp);
		delete temp;
		return *this;
	}

	// Move assignment
	template<typename DataType>
	BTPreOrderIterator<DataType>& BTPreOrderIterator<DataType>::operator=(BTPreOrderIterator&& iterator) noexcept{
		std::swap(stack, iterator.stack);
		std::swap(current, iterator.current);
		return *this;
	}

	/* ************************************************************************ */

	// Comparison operators
	template<typename DataType>
	bool BTPreOrderIterator<DataType>::operator==(const BTPreOrderIterator& iterator) const noexcept{
		return( (*stack==*iterator.stack) && (current==iterator.current) );
	}

	template<typename DataType>
	bool BTPreOrderIterator<DataType>::operator!=(const BTPreOrderIterator& iterator) const noexcept{
		return !(*this==iterator);
	}

	/* ************************************************************************ */

	// Specific member functions (inherited from Iterator)
	template<typename DataType>
	DataType& BTPreOrderIterator<DataType>::operator*() const{ // (throw std::out_of_range when terminated)
		if(Terminated())
			throw std::out_of_range(" Iterator is terminated");
		return (*current).Element();
	}
	template<typename DataType>
	bool BTPreOrderIterator<DataType>::Terminated() const noexcept{ // (should not throw exceptions)
		return (current==nullptr);
	}
	/* ************************************************************************ */

	// Specific member functions (inherited from ForwardIterator)

	template<typename DataType>
	BTPreOrderIterator<DataType>& BTPreOrderIterator<DataType>::operator++(){// (throw std::out_of_range when terminated)
		if(!Terminated()){
			if(current->HasLeftChild()){
				if(current->HasRightChild())
					stack->Push(&current->RightChild());
				current=&current->LeftChild();

			}else if( current->HasRightChild()){
				current=&current->RightChild();
			}else{
				if(stack->Size()>0){
					current=stack->Top();
					stack->Pop();
				}else
					current=nullptr;
			}
		}else throw std::out_of_range(" Iterator is terminated");


		return *this;
	}

	/* ************************************************************************ */
	//BTPostOrderIterator

	// Specific constructors
	template<typename DataType>
	BTPostOrderIterator<DataType>::BTPostOrderIterator(const BinaryTree<DataType>& bt){ // An iterator over a given binary tree
		stack= new StackLst<typename BinaryTree<DataType>::Node *>();
		try{
			current=leftmostLeaf(&bt.Root(),stack); //check if exists
		}catch (std::length_error&) {
			current=nullptr;
		}

	}
	/* ************************************************************************ */

	// Copy constructor
	template<typename DataType>
	BTPostOrderIterator<DataType>::BTPostOrderIterator(const BTPostOrderIterator<DataType>& iterator){
		stack=new StackLst<typename BinaryTree<DataType>::Node*>(*iterator.stack);
		current=iterator.current;
	}

	// Move constructor
	template<typename DataType>
	BTPostOrderIterator<DataType>::BTPostOrderIterator(BTPostOrderIterator<DataType>&& iterator) noexcept{
		std::swap(stack, iterator.stack);
		std::swap(current, iterator.current);
	}

	/* ************************************************************************ */

	// Destructor
	template<typename DataType>
	BTPostOrderIterator<DataType>::~BTPostOrderIterator(){
		delete stack;
	}

	/* ************************************************************************ */

	// Copy assignment
	template<typename DataType>
	BTPostOrderIterator<DataType>& BTPostOrderIterator<DataType>::operator=(const BTPostOrderIterator & iterator){

		BTPostOrderIterator<DataType>* temp = new BTPostOrderIterator<DataType>(iterator);
		std::swap(*this,*temp);
		delete temp;
		return *this;
}

	// Move assignment
	template<typename DataType>
	BTPostOrderIterator<DataType>& BTPostOrderIterator<DataType>::operator=(BTPostOrderIterator&& iterator) noexcept{
		std::swap(stack, iterator.stack);
		std::swap(current, iterator.current);
		return *this;
	}

	/* ************************************************************************ */

	// Comparison operators
	template<typename DataType>
	bool BTPostOrderIterator<DataType>::operator==(const BTPostOrderIterator& iterator) const noexcept{
		return( (*stack==*iterator.stack) && (current==iterator.current) );
	}

	template<typename DataType>
	bool BTPostOrderIterator<DataType>::operator!=(const BTPostOrderIterator& iterator) const noexcept{
		return !(*this==iterator);
	}

	/* ************************************************************************ */

	// Specific member functions (inherited from Iterator)
	template<typename DataType>
	DataType& BTPostOrderIterator<DataType>::operator*() const{ // (throw std::out_of_range when terminated)
		if(Terminated())
			throw std::out_of_range(" Iterator is terminated");
		return (*current).Element();
	}
	template<typename DataType>
	bool BTPostOrderIterator<DataType>::Terminated() const noexcept{ // (should not throw exceptions)
		return (current==nullptr);
	}
	/* ************************************************************************ */

	// Specific member functions (inherited from ForwardIterator)

	template<typename DataType>
	BTPostOrderIterator<DataType>& BTPostOrderIterator<DataType>::operator++(){// (throw std::out_of_range when terminated)
		if(!Terminated()){
			if(stack->Size()>0){
				if(stack->Top()->HasLeftChild() && current==&stack->Top()->LeftChild() && stack->Top()->HasRightChild()){ //se torno da sx e esiste il dx
					current=leftmostLeaf(&stack->Top()->RightChild(),stack);
				}
				else{
					current=stack->Top();
					stack->Pop();

				}
			}
			else current=nullptr;
		}else throw std::out_of_range(" Iterator is terminated");

		return *this;

	}

	template<typename DataType>
	typename BinaryTree<DataType>::Node* BTPostOrderIterator<DataType>::leftmostLeaf(typename BinaryTree<DataType>::Node* root, Stack<typename BinaryTree<DataType>::Node *>* st){
		if(root->HasLeftChild()){
			st->Push(root);
			return leftmostLeaf(&root->LeftChild(),st);
		}
		else if( root->HasRightChild()){
			st->Push(root);
			return leftmostLeaf(&root->RightChild(),st);
		}
		else
			return root;
	}

	/* ************************************************************************ */
		//BTInOrderIterator

		// Specific constructors
		template<typename DataType>
		BTInOrderIterator<DataType>::BTInOrderIterator(const BinaryTree<DataType>& bt){ // An iterator over a given binary tree
			stack= new StackLst<typename BinaryTree<DataType>::Node *>();
			try{
				current=leftmostNode(&bt.Root(),stack); //check if exists
			}catch (std::length_error&) {
				current=nullptr;
			}


		}
		/* ************************************************************************ */

		// Copy constructor
		template<typename DataType>
		BTInOrderIterator<DataType>::BTInOrderIterator(const BTInOrderIterator<DataType>& iterator){
			stack= new StackLst<typename BinaryTree<DataType>::Node*>(*iterator.stack);
			current=iterator.current;
		}

		// Move constructor
		template<typename DataType>
		BTInOrderIterator<DataType>::BTInOrderIterator(BTInOrderIterator<DataType>&& iterator) noexcept{
			std::swap(stack, iterator.stack);
			std::swap(current, iterator.current);
		}

		/* ************************************************************************ */

		// Destructor
		template<typename DataType>
		BTInOrderIterator<DataType>::~BTInOrderIterator(){
			delete stack;
		}

		/* ************************************************************************ */

		// Copy assignment
		template<typename DataType>
		BTInOrderIterator<DataType>& BTInOrderIterator<DataType>::operator=(const BTInOrderIterator & iterator){

			BTInOrderIterator<DataType>* temp = new BTInOrderIterator<DataType>(iterator);
			std::swap(*this,*temp);
			delete temp;
			return *this;
		}

		// Move assignment
		template<typename DataType>
		BTInOrderIterator<DataType>& BTInOrderIterator<DataType>::operator=(BTInOrderIterator&& iterator) noexcept{
			std::swap(stack, iterator.stack);
			std::swap(current, iterator.current);
			return *this;
		}

		/* ************************************************************************ */

		// Comparison operators
		template<typename DataType>
		bool BTInOrderIterator<DataType>::operator==(const BTInOrderIterator& iterator) const noexcept{
			return( (*stack==*iterator.stack) && (current==iterator.current) );
		}

		template<typename DataType>
		bool BTInOrderIterator<DataType>::operator!=(const BTInOrderIterator& iterator) const noexcept{
			return !(*this==iterator);
		}

		/* ************************************************************************ */

		// Specific member functions (inherited from Iterator)
		template<typename DataType>
		DataType& BTInOrderIterator<DataType>::operator*() const{ // (throw std::out_of_range when terminated)
			if(Terminated())
				throw std::out_of_range(" Iterator is terminated");
			return (*current).Element();
		}
		template<typename DataType>
		bool BTInOrderIterator<DataType>::Terminated() const noexcept{ // (should not throw exceptions)
			return (current==nullptr);
		}
		/* ************************************************************************ */

		// Specific member functions (inherited from ForwardIterator)

		template<typename DataType>
		BTInOrderIterator<DataType>& BTInOrderIterator<DataType>::operator++(){// (throw std::out_of_range when terminated)
			if(!Terminated()){

				if(current->HasRightChild()){
					current=leftmostNode(&current->RightChild(),stack);
				}
				else if(stack->Size()>0){
					current=stack->Top();
					stack->Pop();

				}

				else current=nullptr;
			}else throw std::out_of_range(" Iterator is terminated");

			return *this;
		}

		template<typename DataType>
		typename BinaryTree<DataType>::Node* BTInOrderIterator<DataType>::leftmostNode(typename BinaryTree<DataType>::Node* root, Stack<typename BinaryTree<DataType>::Node *>* st){
			if(root->HasLeftChild()){
				st->Push(root);
				return leftmostNode(&root->LeftChild(),st);
			}
			else
				return root;
		}

	/* ************************************************************************ */
		//BTBreadthIterator

		// Specific constructors
		template<typename DataType>
		BTBreadthIterator<DataType>::BTBreadthIterator(const BinaryTree<DataType>& bt){ // An iterator over a given binary tree
			try{
				current=&bt.Root(); //check if exists
			}catch (std::length_error&) {
				current=nullptr;
			}
			queue= new QueueLst<typename BinaryTree<DataType>::Node *>();


		}
		/* ************************************************************************ */

		// Copy constructor
		template<typename DataType>
		BTBreadthIterator<DataType>::BTBreadthIterator(const BTBreadthIterator<DataType>& iterator){
			queue= new QueueLst<typename BinaryTree<DataType>::Node*>(*iterator.queue);
			current=iterator.current;
		}

		// Move constructor
		template<typename DataType>
		BTBreadthIterator<DataType>::BTBreadthIterator(BTBreadthIterator<DataType>&& iterator) noexcept{
			std::swap(queue, iterator.queue);
			std::swap(current, iterator.current);
		}

		/* ************************************************************************ */

		// Destructor
		template<typename DataType>
		BTBreadthIterator<DataType>::~BTBreadthIterator(){
			delete queue;
		}

		/* ************************************************************************ */

		// Copy assignment
		template<typename DataType>
		BTBreadthIterator<DataType>& BTBreadthIterator<DataType>::operator=(const BTBreadthIterator & iterator){
			BTBreadthIterator<DataType>* temp = new BTBreadthIterator<DataType>(iterator);
			std::swap(*this,*temp);
			delete temp;
			return *this;
		}

		// Move assignment
		template<typename DataType>
		BTBreadthIterator<DataType>& BTBreadthIterator<DataType>::operator=(BTBreadthIterator&& iterator) noexcept{
			std::swap(queue, iterator.queue);
			std::swap(current, iterator.current);
			return *this;
		}

		/* ************************************************************************ */

		// Comparison operators
		template<typename DataType>
		bool BTBreadthIterator<DataType>::operator==(const BTBreadthIterator& iterator) const noexcept{
			return( (*queue==*iterator.queue) && (current==iterator.current) );
		}

		template<typename DataType>
		bool BTBreadthIterator<DataType>::operator!=(const BTBreadthIterator& iterator) const noexcept{
			return !(*this==iterator);
		}

		/* ************************************************************************ */

		// Specific member functions (inherited from Iterator)
		template<typename DataType>
		DataType& BTBreadthIterator<DataType>::operator*() const{ // (throw std::out_of_range when terminated)
			if(Terminated())
				throw std::out_of_range(" Iterator is terminated");
			return (*current).Element();
		}
		template<typename DataType>
		bool BTBreadthIterator<DataType>::Terminated() const noexcept{ // (should not throw exceptions)
			return (current==nullptr);
		}
		/* ************************************************************************ */

		// Specific member functions (inherited from ForwardIterator)

		template<typename DataType>
		BTBreadthIterator<DataType>& BTBreadthIterator<DataType>::operator++(){// (throw std::out_of_range when terminated)
			if(!Terminated()){

				if(current->HasLeftChild()){
					queue->Enqueue(&current->LeftChild());
				}
				if(current->HasRightChild()){
					queue->Enqueue(&current->RightChild());
				}
				if(queue->Size()>0)
				{
					current=queue->Head();
					queue->Dequeue();
				}else
					current=nullptr;
			}else throw std::out_of_range(" Iterator is terminated");

			return *this;
		}

}

