namespace lasd {

/* ************************************************************************** */

// A list obtained from a LinearContainer
template <typename DataType>
List<DataType>::List(const LinearContainer<DataType>& linearContainer ){
	size=linearContainer.Size();
	head= new Node(linearContainer[0]);
	Node*curr=head;
	for(unsigned long i=1; i<size; i++){
		Node* newNode=new Node(linearContainer[i]);
		curr->next=newNode;
		curr=curr->next;
	}
	tail=curr;
	//std::cout<<"New list constructed LINEAR\n";
}

// Copy constructor
template <typename DataType>
List<DataType>::List(const List<DataType>& list ){
	size=list.Size();
	head= new Node(list.head->value);

	Node*curr=list.head;
	Node*currCopy=head;
	Node* temp = nullptr;
	while(curr->next!=nullptr){
		temp = new Node(curr->next->value);
		currCopy->next=temp;
		curr=curr->next;
		currCopy=currCopy->next;
	}
	tail=currCopy;
	//std::cout<<"New list constructed COPY\n";
}

// Move constructor
template <typename DataType>
List<DataType>::List(List<DataType>&& list ) noexcept{
	std::swap(head,list.head);
	std::swap(tail,list.tail);
	std::swap(size, list.size);
	//std::cout<<"New list constructed MOVE\n";
}

// Destructor
template <typename DataType>
List<DataType>::~List(){

	Node* temp = new Node();
	while(head != nullptr) {
		temp = head;
		head = head->next;
		delete(temp);
	}
	//std::cout<<"List destructed\n";
}

//copy assignment
template <typename DataType>
List<DataType>& List<DataType>::operator=(const List<DataType>& list ){
	List<DataType>* temp = new List<DataType>(list);
	std::swap(*temp,*this);
	delete temp;
	return *this;
}

//move assignment
template <typename DataType>
List<DataType>& List<DataType>::operator=(List<DataType>&& list ) noexcept{
	std::swap(head,list.head);
	std::swap(tail,list.tail);
	std::swap(size, list.size);
	return *this;
}

//comparison operators

template <typename DataType>
bool List<DataType>::operator ==(const List<DataType>& list) const noexcept{
	if(size == list.size){
		Node* curr=head;
		Node* curr2=list.head;
		while(curr2!=nullptr){
			if(curr->value != curr2->value)
				return false;
			curr2=curr2->next;
			curr=curr->next;
		}
		return true;
	}
	else
		return false;
}

template <typename DataType>
bool List<DataType>::operator !=(const List<DataType>& list) const noexcept{
	return !(*this == list);
}

/* ************************************************************************ */

  // Specific member functions
template <typename DataType>
void List<DataType>::InsertAtFront(const DataType& newValue){ // Copy of the value
	Node* newNode=new Node(newValue);
	if(size==0){
		tail=newNode;
	}
	else{
		newNode->next=head;

	}
	head=newNode;
	size++;
}
template <typename DataType>
void List<DataType>::InsertAtFront(DataType&& newValue) noexcept{ // Move of the value
	Node* newNode=new Node(std::move(newValue));
	if(size==0){
		tail=newNode;
	}
	else{
		newNode->next=head;
	}
	head=newNode;
	size++;
}

template <typename DataType>
void List<DataType>::RemoveFromFront(){  // (must throw std::length_error when empty)
	if(size>0){
		Node* temp = head;
		head=head->next;
		delete temp;
		size--;
	}else{
		throw std::length_error("List is empty");
	}
}
template <typename DataType>
DataType List<DataType>::FrontNRemove(){  // (must throw std::length_error when empty) //da sistemare
	if(size>0){
		Node* temp = head;
		DataType returnValue=head->value;
		head=head->next;
		size--;

		delete temp;

		return returnValue;
	}else{
		throw std::length_error("List is empty");
	}
}

template <typename DataType>
void List<DataType>::InsertAtBack(const DataType& newValue){ // Copy of the value
	//std::cout<<"insert back";
	Node* newNode= new Node(newValue);
	if(size==0){
		head=newNode;
	}else
		tail->next=newNode;
	tail=newNode;
	size++;
}
template <typename DataType>
void List<DataType>::InsertAtBack(DataType&& newValue) noexcept{ // Move of the value
	Node* newNode= new Node(newValue);
	if(tail)
		tail->next=newNode;
	tail=newNode;
	size++;
}
  /* ************************************************************************ */

//operator[]
template <typename DataType>
DataType& List<DataType>::operator[](const unsigned long index) const {

	if(index < size )
	{
		Node*curr=head;
		unsigned long i=0;
		while(i<index){
			curr=curr->next;
			i++;
		}
		return curr->value;
	}

	else
		throw std::out_of_range("Out of range index:"+ std::to_string(index));


}

template <typename DataType>
void List<DataType>::Clear() {
	Node* temp = new Node();
	while(head != nullptr) {
		temp = head;
		head = head->next;
		delete(temp);
	}
	tail=nullptr;
	size=0;
}

template <typename DataType>
DataType& List<DataType>::Front() const { // Override LinearContainer member (must throw std::length_error when empty)

	if(size>0)
		return head->value;
	else
		throw std::length_error("List is empty");
}

template <typename DataType>
DataType& List<DataType>::Back() const { // Override LinearContainer member (must throw std::length_error when empty)
	if(size>0)
		return tail->value;
	else
		throw std::length_error("List is empty");
}

//mappable container functions
template <typename DataType>
void List<DataType>::MapPreOrder(const MapFunctor function,void* param){
	MapPreOrder(function,param,head);
}
template <typename DataType>
void List<DataType>::MapPostOrder(const MapFunctor function,void* param){
	MapPostOrder(function,param,head);
}
template <typename DataType>
void List<DataType>::MapPreOrder(const MapFunctor function,void* param, Node* node){
	if(node!=nullptr)
	{
		function(node->value,param);
		MapPreOrder(function,param,node->next);
	}
}
template <typename DataType>
void List<DataType>::MapPostOrder(const MapFunctor function,void* param, Node* node){
	if(node!=nullptr)
	{
		MapPostOrder(function,param,node->next);
		function(node->value,param);
	}

}

//foldable container functions
template <typename DataType>
void List<DataType>::FoldPreOrder(const FoldFunctor function,const void* param, void* acc) const{
	FoldPreOrder(function,param,acc,head);
}
template <typename DataType>
void List<DataType>::FoldPostOrder(const FoldFunctor function,const void* param, void* acc)const{
	FoldPostOrder(function,param,acc,head);
}
template <typename DataType>
void List<DataType>::FoldPreOrder(const FoldFunctor function,const void* param, void* acc, Node* node) const{
	if(node!=nullptr)
	{
		function(node->value,param,acc);
		FoldPreOrder(function,param,acc,node->next);
	}
}
template <typename DataType>
void List<DataType>::FoldPostOrder(const FoldFunctor function,const void* param, void* acc, Node* node)const{
	if(node!=nullptr)
	{
		FoldPostOrder(function,param,acc,node->next);
		function(node->value,param,acc);
	}

}


/* ************************************************************************** */


}
