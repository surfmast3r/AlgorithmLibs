
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename DataType>
class List : virtual public LinearContainer<DataType>,
			 virtual public MappableContainer<DataType>,
			 virtual public FoldableContainer<DataType>{ // Must extend LinearContainer<Data>, MappableContainer<Data>, and FoldableContainer<Data>

private:

  // ...

protected:

  using LinearContainer<DataType>::size;

  struct Node
  {

    // Data
	DataType value;
    Node* next=nullptr;
    /* ********************************************************************** */

    Node()=default;
    // Specific constructors
    Node(const DataType &data){
    	value=data;
    	std::cout<<"new node created with value : "<<value;
    }

    /* ********************************************************************** */

    // Copy constructor
    Node(const Node& node){
    	value=node.value;
    	//next=node.next;
    }

    // Move constructor
    Node(Node&& node) noexcept{
    	std::swap(value, node.value);
    	std::swap(next,node.next);
    }

    /* ********************************************************************** */

    // Destructor
    ~Node(){
    	next=nullptr;
    }

    /* ********************************************************************** */

    // Comparison operators
    bool operator==(const Node& node) const noexcept{
    	return value==node.value;
    }
    bool operator!=(const Node& node) const noexcept{
    	return value!=node.value;
    }

    /* ********************************************************************** */

    // Specific member functions

    // ...

  };

  // ...
  Node *head=nullptr;
  Node *tail=nullptr;

public:

  // Default constructor
  List() = default;

  /* ************************************************************************ */

  // Specific constructor
  List(const LinearContainer<DataType>&); // A list obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  List(const List&);

  // Move constructor
  List(List&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~List();

  /* ************************************************************************ */

  // Copy assignment
  List& operator=(const List&);

  // Move assignment
  List& operator=(List&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const List&) const noexcept;
  bool operator!=(const List&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  void InsertAtFront(const DataType&) ; // Copy of the value
  void InsertAtFront(DataType&&) noexcept; // Move of the value
  void RemoveFromFront(); // (must throw std::length_error when empty)
  DataType& FrontNRemove(); // (must throw std::length_error when empty)

  void InsertAtBack(const DataType&); // Copy of the value
  void InsertAtBack(DataType&&) noexcept; // Move of the value

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  DataType& Front() const override; // Override LinearContainer member (must throw std::length_error when empty)
  DataType& Back() const override; // Override LinearContainer member (must throw std::length_error when empty)

  DataType& operator[](const unsigned long) const override; // Override LinearContainer member (must throw std::out_of_range when out of range)

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  using typename MappableContainer<DataType>::MapFunctor;

  void MapPreOrder(const MapFunctor, void*) override; // Override MappableContainer member
  void MapPostOrder(const MapFunctor, void*) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  using typename FoldableContainer<DataType>::FoldFunctor;

  void FoldPreOrder(const FoldFunctor,const void*,void*) const override; // Override FoldableContainer member
  void FoldPostOrder(const FoldFunctor,const void*,void*) const override; // Override FoldableContainer member

protected:

  // Auxiliary member functions (for MappableContainer)

  // type MapPreOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards
  // type MapPostOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards
  void MapPreOrder(const MapFunctor, void*, Node*); //??
  void MapPostOrder(const MapFunctor, void*, Node*);

  /* ************************************************************************ */

  // Auxiliary member functions (for FoldableContainer)

  // type FoldPreOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards
  // type FoldPostOrder(arguments) specifiers; // Accessory function executing from one point of the list onwards
  void FoldPreOrder(const FoldFunctor,const void*,void*, Node*) const; // ??
  void FoldPostOrder(const FoldFunctor,const void*,void*, Node*) const; //

  void deleteAllNodes();
};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
