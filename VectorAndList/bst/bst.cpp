
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
				curr=curr->leftChild;
			else if(value>curr->Element())
				curr=curr->rightChild;
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

			size--;
		}
	}

}
