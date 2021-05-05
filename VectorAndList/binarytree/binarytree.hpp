
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

#include "../iterator/iterator.hpp"

#include "../queue/lst/queuelst.hpp"
#include "../stack/lst/stacklst.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename DataType>
class BinaryTree : virtual public InOrderMappableContainer<DataType>,
				   virtual public BreadthMappableContainer<DataType>,
				   virtual public InOrderFoldableContainer<DataType>,
				   virtual public BreadthFoldableContainer<DataType>{ // Must extend InOrder/BreadthMappableContainer<Data> and InOrder/BreadthFoldableContainer<Data>

private:

  // ...

protected:

   using InOrderMappableContainer<DataType>:: size;
  // ...

public:

  struct Node {

  private:

    // ...

  protected:

	// Comparison operators
	bool operator==(const Node&) const noexcept; // Comparison of abstract types is possible, but should not be visible.
	bool operator!=(const Node&) const noexcept; // Comparison of abstract types is possible, but should not be visible.

  public:

    friend class BinaryTree<DataType>;

    /* ********************************************************************** */

    // Destructor
    virtual ~Node() = default;

    /* ********************************************************************** */

    // Copy assignment
    Node& operator=(const Node&) noexcept = delete; // Copy assignment of abstract types should not be possible.

    // Move assignment
    Node& operator=(Node&&) noexcept= delete; // Move assignment of abstract types should not be possible.

    /* ********************************************************************** */

    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types is possible, but should not be visible.
    // type operator!=(argument) specifiers; // Comparison of abstract types is possible, but should not be visible.

    /* ********************************************************************** */

    // Specific member functions

    virtual DataType& Element() noexcept = 0; // Mutable access to the element (concrete function should not throw exceptions)
    virtual const DataType& Element() const noexcept  = 0; // Immutable access to the element (concrete function should not throw exceptions)

    virtual bool IsLeaf() noexcept = 0; // (concrete function should not throw exceptions)
    virtual bool HasLeftChild() const noexcept= 0; // (concrete function should not throw exceptions)
    virtual bool HasRightChild() const noexcept = 0; // (concrete function should not throw exceptions)

    virtual  Node& LeftChild() = 0; // (concrete function must throw std::out_of_range when not existent)
    virtual  Node& RightChild()  = 0; // (concrete function must throw std::out_of_range when not existent)

  };

	/* ************************************************************************ */

	// Destructor
	virtual ~BinaryTree() = default;

	/* ************************************************************************ */

	// Copy assignment
	BinaryTree& operator=(const BinaryTree&) noexcept = delete; // Copy assignment of abstract types should not be possible.

	// Move assignment
	BinaryTree& operator=(BinaryTree&&) noexcept = delete; // Move assignment of abstract types should not be possible.

	/* ************************************************************************ */

	// Comparison operators
	virtual bool operator==(const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.
	virtual bool operator!=(const BinaryTree&) const noexcept; // Comparison of abstract binary tree is possible.

	/* ************************************************************************ */

	// Specific member functions

	virtual Node& Root() const= 0; // (concrete function must throw std::length_error when empty)

	/* ************************************************************************ */

	// Specific member functions (inherited from MappableContainer)

	using typename MappableContainer<DataType>::MapFunctor;

	virtual void MapPreOrder(const MapFunctor, void*) override;// Override MappableContainer member
	virtual void MapPostOrder(const MapFunctor, void*) override;// Override MappableContainer member

	/* ************************************************************************ */

	// Specific member functions (inherited from FoldableContainer)

	using typename FoldableContainer<DataType>::FoldFunctor;

	virtual void FoldPreOrder(const FoldFunctor, const void*,void*) const override;// Override FoldableContainer member
	virtual void FoldPostOrder(const FoldFunctor, const void*,void*) const override;// Override FoldableContainer member

	/* ************************************************************************ */

	// Specific member functions (inherited from InOrderMappableContainer)

	virtual void MapInOrder(const MapFunctor, void*) override; // Override InOrderMappableContainer member

	/* ************************************************************************ */

	// Specific member functions (inherited from InOrderFoldableContainer)

	virtual void FoldInOrder(const FoldFunctor, const void*,void*) const override; // Override InOrderFoldableContainer member

	/* ************************************************************************ */

	// Specific member functions (inherited from BreadthMappableContainer)

	virtual void MapBreadth(const MapFunctor, void*) override; // Override BreadthMappableContainer member

	/* ************************************************************************ */

	// Specific member functions (inherited from BreadthFoldableContainer)

	virtual void FoldBreadth(const FoldFunctor, const void*,void*) const override; // Override BreadthFoldableContainer member

protected:

	// Auxiliary member functions (for MappableContainer)
	void MapPreOrder(const MapFunctor, void*, Node&); // Accessory function executing from one node of the tree
	void MapPostOrder(const MapFunctor, void*, Node&);// Accessory function executing from one node of the tree

	/* ************************************************************************ */

	// Auxiliary member functions (for FoldableContainer)
	void FoldPreOrder(const FoldFunctor,const void*,void*, Node&) const; // Accessory function executing from one node of the tree
	void FoldPostOrder(const FoldFunctor,const void*,void*, Node&) const;// Accessory function executing from one node of the tree

	/* ************************************************************************ */

	// Auxiliary member functions (for InOrderMappableContainer)

	// type MapInOrder(arguments) specifiers; // Accessory function executing from one node of the tree
	void MapInOrder(const MapFunctor, void*, Node&); // Accessory function executing from one node of the tree

	/* ************************************************************************ */

	// Auxiliary member functions (for InOrderFoldableContainer)

	// type FoldInOrder(arguments) specifiers; // Accessory function executing from one node of the tree
	void FoldInOrder(const FoldFunctor,const void*,void*, Node&) const; // Accessory function executing from one node of the tree

	/* ************************************************************************ */

	// Auxiliary member functions (for BreadthMappableContainer)

	// type MapBreadth(arguments) specifiers; // Accessory function executing from one node of the tree
	void MapBreadth(const MapFunctor, void*, Node&); // Accessory function executing from one node of the tree
	bool AuxiliaryEqualOperatorFunction ( Node& ,  Node& ) const;
	/* ************************************************************************ */

	// Auxiliary member functions (for BreadthFoldableContainer)

	// type FoldBreadth(arguments) specifiers; // Accessory function executing from one node of the tree
	void FoldBreadth(const FoldFunctor,const void*,void*, Node&) const; // Accessory function executing from one node of the tree

};

/* ************************************************************************** */

template <typename DataType>
class BTPreOrderIterator : virtual public ForwardIterator<DataType>{ // Must extend ForwardIterator<Data>

private:

  // ...

protected:

  // ...
	StackLst<typename BinaryTree<DataType>::Node *>* stack = nullptr;
	typename BinaryTree<DataType>::Node* current = nullptr;

public:

  // Specific constructors
	BTPreOrderIterator(const BinaryTree<DataType>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
	BTPreOrderIterator(const BTPreOrderIterator<DataType>&);

  // Move constructor
	BTPreOrderIterator(BTPreOrderIterator<DataType>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
	~BTPreOrderIterator();

  /* ************************************************************************ */

  // Copy assignment
    BTPreOrderIterator& operator=(const BTPreOrderIterator&);

  // Move assignment
    BTPreOrderIterator& operator=(BTPreOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
	bool operator==(const BTPreOrderIterator&) const noexcept;
	bool operator!=(const BTPreOrderIterator&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

	DataType& operator*() const; // (throw std::out_of_range when terminated)

	bool Terminated() const noexcept; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

	BTPreOrderIterator& operator++(); // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename DataType>
class BTPostOrderIterator : virtual public ForwardIterator<DataType>{ // Must extend ForwardIterator<Data>

private:

  // ...

protected:

	typename BinaryTree<DataType>::Node* leftmostLeaf(typename BinaryTree<DataType>::Node*,Stack<typename BinaryTree<DataType>::Node *>*);

	StackLst<typename BinaryTree<DataType>::Node *>* stack = nullptr;
	typename BinaryTree<DataType>::Node* current = nullptr;

public:

  // Specific constructors
	BTPostOrderIterator(const BinaryTree<DataType>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
	BTPostOrderIterator(const BTPostOrderIterator<DataType>&);

  // Move constructor
	BTPostOrderIterator(BTPostOrderIterator<DataType>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
	~BTPostOrderIterator();

  /* ************************************************************************ */

  // Copy assignment
	BTPostOrderIterator& operator=(const BTPostOrderIterator&);

  // Move assignment
	BTPostOrderIterator& operator=(BTPostOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
	bool operator==(const BTPostOrderIterator&) const noexcept;
	bool operator!=(const BTPostOrderIterator&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

	DataType& operator*() const; // (throw std::out_of_range when terminated)

	bool Terminated() const noexcept; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

	BTPostOrderIterator& operator++(); // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename DataType>
class BTInOrderIterator : virtual public ForwardIterator<DataType>{ // Must extend ForwardIterator<Data>

private:

  // ...

protected:

	typename BinaryTree<DataType>::Node* leftmostNode(typename BinaryTree<DataType>::Node*,Stack<typename BinaryTree<DataType>::Node *>*);
	StackLst<typename BinaryTree<DataType>::Node *>* stack = nullptr;
	typename BinaryTree<DataType>::Node* current = nullptr;

public:

  // Specific constructors
	BTInOrderIterator(const BinaryTree<DataType>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
	BTInOrderIterator(const BTInOrderIterator<DataType>&);

  // Move constructor
	BTInOrderIterator(BTInOrderIterator<DataType>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
   ~BTInOrderIterator();

  /* ************************************************************************ */
  // Copy assignment
   BTInOrderIterator& operator=(const BTInOrderIterator&);

  // Move assignment
   BTInOrderIterator& operator=(BTInOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
   bool operator==(const BTInOrderIterator&) const noexcept;
   bool operator!=(const BTInOrderIterator&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

   DataType& operator*() const; // (throw std::out_of_range when terminated)

   bool Terminated() const noexcept; // (should not throw exceptions)


  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

   BTInOrderIterator& operator++(); // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename DataType>
class BTBreadthIterator : virtual public ForwardIterator<DataType>{ // Must extend ForwardIterator<Data>

private:

  // ...

protected:

	QueueLst<typename BinaryTree<DataType>::Node *>* queue = nullptr;
	typename BinaryTree<DataType>::Node* current = nullptr;

public:

  // Specific constructors
	BTBreadthIterator(const BinaryTree<DataType>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
	BTBreadthIterator(const BTBreadthIterator<DataType>&);

  // Move constructor
	BTBreadthIterator(BTBreadthIterator<DataType>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
	~BTBreadthIterator();

  /* ************************************************************************ */

  // Copy assignment
	BTBreadthIterator& operator=(const BTBreadthIterator&);

  // Move assignment
	BTBreadthIterator& operator=(BTBreadthIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
	bool operator==(const BTBreadthIterator&) const noexcept;
	bool operator!=(const BTBreadthIterator&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

	DataType& operator*() const; // (throw std::out_of_range when terminated)

	bool Terminated() const noexcept; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

	BTBreadthIterator& operator++(); // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
