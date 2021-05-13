
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
	BST<DataType>::NodeLnk<DataType>*& BST<DataType>::FindPointerTo(const NodeLnk<DataType>& root,const DataType& value) const{//argument root of subTree and data to find
		NodeLnk*&curr=&root;
		while(curr!=nullptr){
			if(value==curr->Element())
				return curr;
			if(value<curr->Element())
				curr=&curr->leftChild;
			else if(value>curr->Element())
				curr=&curr->rightChild;
		}
		return curr;
	}
	template<typename DataType>
	void BST<DataType>::Insert(const DataType& value) noexcept{ // Copy of the value

		NodeLnk*& curr=FindPointerTo(*root,value);
		if(curr==nullptr){
			curr = new NodeLnk(value);
			size++;
		}
	}
	template<typename DataType>
	void BST<DataType>::Insert(DataType&& value) noexcept{ // Move of the value

		NodeLnk*& curr=FindPointerTo(*root,value);
		if(curr==nullptr){
			curr = new NodeLnk(std::move(value));
			size++;
		}
	}
	template<typename DataType>
	void BST<DataType>::Remove(const DataType& value) noexcept{
		NodeLnk*& curr=FindPointerTo(*root,value);
		if(curr!=nullptr){
			delete Detach(curr);
		}
	}
	template<typename DataType>
	const DataType& BST<DataType>::Min() const{ // (concrete function must throw std::length_error when empty)
		if(size>0){
			NodeLnk*& min=FindPointerToMin(*root);
			return min->data;
		}
		else
			throw std::length_error("Tree is empty");


	}

	template<typename DataType>
	DataType BST<DataType>::MinNRemove(){ // (concrete function must throw std::length_error when empty)

		if(size>0){
			NodeLnk*& min=DetachMin(*root);
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
			NodeLnk*& min=DetachMin(*root);
			delete min;
			min= nullptr;

		}
		else
			throw std::length_error("Tree is empty");
	}

	template<typename DataType>
	const DataType& BST<DataType>::Max() const{ // (concrete function must throw std::length_error when empty)
	}

	template<typename DataType>
	DataType BST<DataType>::MaxNRemove(){ // (concrete function must throw std::length_error when empty)
	}

	template<typename DataType>
	void BST<DataType>::RemoveMax(){ // (concrete function must throw std::length_error when empty)
	}

	template<typename DataType>
	BST<DataType>::NodeLnk<DataType>* BST<DataType>::Detach(NodeLnk<DataType>*& nodeLnk){

		if(nodeLnk->leftChild==nullptr){
			return SkipOnRight(nodeLnk);
		}
		else if(nodeLnk->rightChild==nullptr){
			return SkipOnLeft(nodeLnk);
		}
		else{
			NodeLnk* temp= DetachMin(nodeLnk->rightChild);
			std::swap(temp->data,nodeLnk->data);
			return temp;
		}

	}

	template<typename DataType>
	BST<DataType>::NodeLnk<DataType>* BST<DataType>::DetachMin(NodeLnk<DataType>*& nodeLnk){ //argument root of subTree
		return SkipOnRight(FindPointerToMin(NodeLnk));
	}

	template<typename DataType>
	BST<DataType>::NodeLnk<DataType>* BST<DataType>::DetachMax(NodeLnk<DataType>*& nodeLnk){ //argument root of subTree

		return SkipOnLeft(FindPointerToMax(NodeLnk));
	}

	template<typename DataType>
	BST<DataType>::NodeLnk<DataType>* BST<DataType>::SkipOnLeft(NodeLnk<DataType>*& nodeLnk){
		NodeLnk* temp=nodeLnk;
		if(nodeLnk!= nullptr){
			nodeLnk=nodeLnk->leftChild;
			temp->leftChild=nullptr;
			size--;
		}
		return temp;
	}

	template<typename DataType>
	BST<DataType>::NodeLnk<DataType>* BST<DataType>::SkipOnRight(NodeLnk<DataType>*& nodeLnk){
		NodeLnk* temp=nodeLnk;
		if(nodeLnk!= nullptr){
			nodeLnk=nodeLnk->rightChild;
			temp->rightChild=nullptr;
			size--;
		}
		return temp;

	}

	template<typename DataType>
	BST<DataType>::NodeLnk<DataType>*& BST<DataType>::FindPointerToMin(const NodeLnk<DataType>*& root) const{
		NodeLnk*&curr=root;
		while(curr->leftChild!=nullptr){
			curr=&curr->leftChild;
		}
		return curr;
	}
	template<typename DataType>
	BST<DataType>::NodeLnk<DataType>*& BST<DataType>::FindPointerToMax(const NodeLnk<DataType>*& root) const{
		NodeLnk*&curr=root;
		while(curr->rightChild!=nullptr){
			curr=&curr->rightChild;
		}
		return curr;
	}

	template<typename DataType>
	BST<DataType>::NodeLnk<DataType>*& BST<DataType>::FindPointerToPredecessor(const NodeLnk<DataType>& root,const DataType& value) const{

	}
	template<typename DataType>
	BST<DataType>::NodeLnk<DataType>*& BST<DataType>::FindPointerToSuccessor(const NodeLnk<DataType>& root,const DataType& value) const{

	}
}
