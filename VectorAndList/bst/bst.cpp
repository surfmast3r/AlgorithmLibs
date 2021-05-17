
namespace lasd {

/* ************************************************************************** */

  // Specific constructors
	template<typename DataType>
	BST<DataType>::BST(const LinearContainer<DataType>& container){ // A bst obtained from a LinearContainer

		for(unsigned long i=0;i<container.Size();i++){
			Insert(container[i]);
		}
	}

  // Copy constructor
	template<typename DataType>
	BST<DataType>::BST(const BST<DataType>& searchTree) : BinaryTreeLnk<DataType>::BinaryTreeLnk(searchTree){}

  // Move constructor
	template<typename DataType>
	BST<DataType>::BST(BST<DataType>&& searchTree) noexcept : BinaryTreeLnk<DataType>::BinaryTreeLnk(std::move(searchTree)){}

  /* ************************************************************************ */

  // Copy assignment
	template<typename DataType>
	BST<DataType>& BST<DataType>::operator=(const BST<DataType>& searchTree) noexcept{
		BinaryTreeLnk<DataType>::operator =(searchTree);
		return *this;
	}

  // Move assignment
	template<typename DataType>
	BST<DataType>& BST<DataType>::operator=(BST<DataType>&& searchTree) noexcept{
		BinaryTreeLnk<DataType>::operator =(std::move(searchTree));
		return *this;
	}

  // Comparison operators
	template<typename DataType>
	bool BST<DataType>::operator==(const BST<DataType>& searchTree) const noexcept{
		if(this->Size()==searchTree.Size()){
			BTInOrderIterator<DataType> iterator1 (*this);
			BTInOrderIterator<DataType> iterator2 (searchTree);
			while(!iterator1.Terminated()){
				if(*iterator1!=*iterator2)
					return false;
				++iterator1;
				++iterator2;
			}
			return true;
		}else
			return false;
	}

	template<typename DataType>
	bool BST<DataType>::operator!=(const BST<DataType>& searchTree) const noexcept{
		return !(*this==searchTree);
	}

/* ************************************************************************** */

	// Specific member functions

	template<typename DataType>
	void BST<DataType>::Insert(const DataType& value) noexcept{ // Copy of the value

		typename BST<DataType>::NodeLnk*& curr=FindPointerTo(root,value);
		if(curr==nullptr){
			curr = new typename BST<DataType>::NodeLnk(value);
			size++;
		}
	}
	template<typename DataType>
	void BST<DataType>::Insert(DataType&& value) noexcept{ // Move of the value

		typename BST<DataType>::NodeLnk*& curr=FindPointerTo(root,value);
		if(curr==nullptr){
			curr = new typename BST<DataType>::NodeLnk(std::move(value));
			size++;
		}
	}
	template<typename DataType>
	void BST<DataType>::Remove(const DataType& value) noexcept{
		typename BST<DataType>::NodeLnk*& curr=FindPointerTo(root,value);
		if(curr!=nullptr){
			delete Detach(curr);
		}
	}
	template<typename DataType>
	const DataType& BST<DataType>::Min() const{ // (concrete function must throw std::length_error when empty)
		if(size>0){
			typename BST<DataType>::NodeLnk* const& min=FindPointerToMin(root);
			return min->data;
		}
		else
			throw std::length_error("Tree is empty");


	}

	template<typename DataType>
	DataType BST<DataType>::MinNRemove(){ // (concrete function must throw std::length_error when empty)

		if(size>0){
			typename BST<DataType>::NodeLnk* min=DetachMin(root);
			DataType value=min->data;
			delete min;
			min= nullptr;
			return value;
		}
		else
			throw std::length_error("Tree is empty");
	}

	template<typename DataType>
	void BST<DataType>::RemoveMin(){ // (concrete function must throw std::length_error when empty)

		if(size>0){
			typename BST<DataType>::NodeLnk* min=DetachMin(root);
			delete min;
			min= nullptr;

		}
		else
			throw std::length_error("Tree is empty");
	}

	template<typename DataType>
	const DataType& BST<DataType>::Max() const{ // (concrete function must throw std::length_error when empty)
		if(size>0){
			typename BST<DataType>::NodeLnk* const& max=FindPointerToMax(root);
			return max->data;
		}
		else
			throw std::length_error("Tree is empty");
	}

	template<typename DataType>
	DataType BST<DataType>::MaxNRemove(){ // (concrete function must throw std::length_error when empty)
		if(size>0){
			typename BST<DataType>::NodeLnk* max=DetachMax(root);
			DataType maxValue=max->data;
			delete max;
			max=nullptr;
			return maxValue;
		}
		else
			throw std::length_error("Tree is empty");

	}

	template<typename DataType>
	void BST<DataType>::RemoveMax(){ // (concrete function must throw std::length_error when empty)

		if(size>0){
			typename BST<DataType>::NodeLnk* max=DetachMax(root);
			delete max;
			max=nullptr;
		}
		else
			throw std::length_error("Tree is empty");
	}


	template<typename DataType>
	const DataType& BST<DataType>::Predecessor(const DataType& value) const{ // (concrete function must throw std::length_error when empty OR not found)

		typename BST<DataType>::NodeLnk*const& pred=FindPointerToPredecessor(root, value);
		if(pred!=nullptr){
			return pred->data;
		}
		else
			throw std::length_error("Not Found");
	}

	template<typename DataType>
	DataType BST<DataType>::PredecessorNRemove(const DataType& value){ // (concrete function must throw std::length_error when empty OR not found)

		typename BST<DataType>::NodeLnk*& pred=FindPointerToPredecessor(root, value);
		if(pred!=nullptr){
			DataType retValue=pred->data;
			delete Detach(pred);
			return retValue;
		}
		else
			throw std::length_error("Not Found");
	}

	template<typename DataType>
	void BST<DataType>::RemovePredecessor(const DataType& value){ // (concrete function must throw std::length_error when empty OR not found)

		typename BST<DataType>::NodeLnk*& pred=FindPointerToPredecessor(root, value);
		if(pred!=nullptr){
			delete Detach(pred);
		}
		else
			throw std::length_error("Not Found");

	}

	template<typename DataType>
	const DataType& BST<DataType>::Successor(const DataType& value) const{ // (concrete function must throw std::length_error when empty OR not found)

		typename BST<DataType>::NodeLnk*const& succ=FindPointerToSuccessor(root, value);
		if(succ!=nullptr){
			return succ->data;
		}
		else
			throw std::length_error("Not Found");
	}

	template<typename DataType>
	DataType BST<DataType>::SuccessorNRemove(const DataType& value){ // (concrete function must throw std::length_error when empty OR not found)
		typename BST<DataType>::NodeLnk*& succ=FindPointerToSuccessor(root, value);
		if(succ!=nullptr){

			DataType retValue=succ->data;
			delete Detach(succ);
			return retValue;
		}
		else
			throw std::length_error("Not Found");

	}

	template<typename DataType>
	void BST<DataType>::RemoveSuccessor(const DataType& value){ // (concrete function must throw std::length_error when empty OR not found)
		typename BST<DataType>::NodeLnk*& succ=FindPointerToSuccessor(root, value);
		if(succ!=nullptr){

			delete Detach(succ);
		}
		else
			throw std::length_error("Not Found");

	}

	template<typename DataType>
	bool BST<DataType>::Exists(const DataType& value) const noexcept {
		return (FindPointerTo(root,value)!=nullptr);
	} // Override TestableContainer member


/****************************************************************************************************/
	template<typename DataType>
	typename BST<DataType>::NodeLnk* BST<DataType>::Detach(typename BST<DataType>::NodeLnk*& nodeLnk){

		if(nodeLnk->leftChild==nullptr){
			return SkipOnRight(nodeLnk);
		}
		else if(nodeLnk->rightChild==nullptr){
			return SkipOnLeft(nodeLnk);
		}
		else{
			typename BST<DataType>::NodeLnk* temp = DetachMin(nodeLnk->rightChild);
			std::swap(temp->data,nodeLnk->data);
			return temp;
		}

	}


	template<typename DataType>
	typename BST<DataType>::NodeLnk* BST<DataType>::DetachMin(typename BST<DataType>::NodeLnk*& nodeLnk){ //argument root of subTree
		return SkipOnRight(FindPointerToMin(nodeLnk));
	}

	template<typename DataType>
	typename BST<DataType>::NodeLnk* BST<DataType>::DetachMax(typename BST<DataType>::NodeLnk*& nodeLnk){ //argument root of subTree

		return SkipOnLeft(FindPointerToMax(nodeLnk));
	}

	template<typename DataType>
	typename BST<DataType>::NodeLnk* BST<DataType>::SkipOnLeft(typename BST<DataType>::NodeLnk*& nodeLnk){
		typename BST<DataType>::NodeLnk* temp=nodeLnk;
		if(nodeLnk!= nullptr){
			nodeLnk=nodeLnk->leftChild;
			temp->leftChild=nullptr;
			size--;
		}
		return temp;
	}

	template<typename DataType>
	typename BST<DataType>::NodeLnk* BST<DataType>::SkipOnRight(typename BST<DataType>::NodeLnk*& nodeLnk){
		typename BST<DataType>::NodeLnk* temp=nodeLnk;
		if(nodeLnk!= nullptr){
			nodeLnk=nodeLnk->rightChild;
			temp->rightChild=nullptr;
			size--;
		}
		return temp;

	}

	template<typename DataType>
	typename BST<DataType>::NodeLnk*& BST<DataType>::FindPointerTo(typename BST<DataType>::NodeLnk*& root, const DataType& value) {//argument root of subTree and data to find
		return const_cast<typename BST<DataType>::NodeLnk*&>(static_cast<const BST<DataType>*>(this)->FindPointerTo(root,value));

	}
	template<typename DataType>
	typename BST<DataType>::NodeLnk*const& BST<DataType>::FindPointerTo(typename BST<DataType>::NodeLnk* const& root, const DataType& value) const{//argument root of subTree and data to find
			typename BST<DataType>::NodeLnk*const* address=&root;
			typename BST<DataType>::NodeLnk*curr=root;
			while(curr!=nullptr){
				if(value==curr->Element())
					return *address;
				if(value<curr->Element())
				{
					address=&curr->leftChild;
					curr=curr->leftChild;

				}

				else if(value>curr->Element())
				{
					address=&curr->rightChild;
					curr=curr->rightChild;

				}

			}
			return *address;
		}

	template<typename DataType>
	typename BST<DataType>::NodeLnk*& BST<DataType>::FindPointerToMin(typename BST<DataType>::NodeLnk*& root) {
		return const_cast<typename BST<DataType>::NodeLnk*&>(static_cast<const BST<DataType>*>(this)->FindPointerToMin(root));

	}
	template<typename DataType>
	typename BST<DataType>::NodeLnk*const& BST<DataType>::FindPointerToMin(typename BST<DataType>::NodeLnk* const& root) const{
		typename BST<DataType>::NodeLnk* const* address= &root;
		typename BST<DataType>::NodeLnk* curr=root;
		if(curr!=nullptr)
			while(curr->leftChild!=nullptr){
				address=&curr->leftChild;
				curr=curr->leftChild;

			}
		return *address;
	}

	template<typename DataType>
	typename BST<DataType>::NodeLnk*& BST<DataType>::FindPointerToMax(typename BST<DataType>::NodeLnk*& root) {
		return const_cast<typename BST<DataType>::NodeLnk*&>(static_cast<const BST<DataType>*>(this)->FindPointerToMax(root));

	}
	template<typename DataType>
	typename BST<DataType>::NodeLnk*const& BST<DataType>::FindPointerToMax(typename BST<DataType>::NodeLnk* const& root) const{
		typename BST<DataType>::NodeLnk* const* address= &root;
		typename BST<DataType>::NodeLnk* curr=root;
		if(curr!=nullptr)
			while(curr->rightChild!=nullptr){
				address=&curr->rightChild;
				curr=curr->rightChild;

			}
		return *address;
	}

	template<typename DataType>
	typename BST<DataType>::NodeLnk*& BST<DataType>::FindPointerToPredecessor( typename BST<DataType>::NodeLnk*& root,const DataType& value) {
		return const_cast<typename BST<DataType>::NodeLnk*&>(static_cast<const BST<DataType>*>(this)->FindPointerToPredecessor(root, value));
	}
	template<typename DataType>
	typename BST<DataType>::NodeLnk*& BST<DataType>::FindPointerToSuccessor( typename BST<DataType>::NodeLnk*& root,const DataType& value) {
		return root;
	}

	template<typename DataType>
	typename BST<DataType>::NodeLnk*const& BST<DataType>::FindPointerToPredecessor( typename BST<DataType>::NodeLnk*const& root,const DataType& value) const{
		typename BST<DataType>::NodeLnk* const* currAddress= &root;
		typename BST<DataType>::NodeLnk* const* predAddress= nullptr;
		typename BST<DataType>::NodeLnk* curr=root;

		while(curr!=nullptr){

			if(curr->data<value)
			{
				predAddress=currAddress;
				currAddress=&curr->rightChild;
				curr=curr->rightChild;
			}
			else if (curr->data>value)
			{
				currAddress=&curr->leftChild;
				curr=curr->leftChild;
			}
			else{

				if(curr->HasLeftChild()){
					return FindPointerToMax(curr->leftChild);
				}
				else return *predAddress;

			}

		}
		return *predAddress;
	}
	template<typename DataType>
	typename BST<DataType>::NodeLnk*const& BST<DataType>::FindPointerToSuccessor( typename BST<DataType>::NodeLnk*const& root,const DataType& value) const{
		return root;
	}
}
