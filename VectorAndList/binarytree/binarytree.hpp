
#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

#include "../iterator/iterator.hpp"

#include "../queue/queue.hpp"
#include "../stack/stack.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename DataType>
class BinaryTree : virtual protected InOrderMappableContainer<DataType>,
				   virtual protected BreadthMappableContainer<DataType>,
				   virtual protected InOrderFoldableContainer<DataType>,
				   virtual protected BreadthFoldableContainer<DataType>{ // Must extend InOrder/BreadthMappableContainer<Data> and InOrder/BreadthFoldableContainer<Data>

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

    // ...

  public:

    // friend class BinaryTree<Data>;

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
    virtual DataType& Element() const noexcept  = 0; // Immutable access to the element (concrete function should not throw exceptions)

    virtual bool IsLeaf() noexcept = 0; // (concrete function should not throw exceptions)
    virtual bool HasLeftChild() noexcept = 0; // (concrete function should not throw exceptions)
    virtual bool HasRightChild() noexcept = 0; // (concrete function should not throw exceptions)

    virtual Node& LeftChild() = 0; // (concrete function must throw std::out_of_range when not existent)
    virtual Node& RightChild() = 0; // (concrete function must throw std::out_of_range when not existent)

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

	virtual Node& Root() = 0; // (concrete function must throw std::length_error when empty)

	/* ************************************************************************ */

	// Specific member functions (inherited from MappableContainer)

	using typename MappableContainer<DataType>::MapFunctor;

	virtual void MapPreOrder(const MapFunctor, void*) override;// Override MappableContainer member
	virtual void MapPostOrder(const MapFunctor, void*) override;// Override MappableContainer member

	/* ************************************************************************ */

	// Specific member functions (inherited from FoldableContainer)

	using typename FoldableContainer<DataType>::FoldFunctor;

	virtual void FoldPreOrder(const FoldFunctor, const void*,void*) const override;// Override FoldableContainer member
	virtual void FoldPostOrder(const FoldFunctor, const void*,void*) const override= 0;// Override FoldableContainer member

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
	Stack<DataType>* stack = nullptr;
	typename BinaryTree<DataType>::Node* current = nullptr;

public:

  // Specific constructors
	BTPreOrderIterator(BinaryTree<DataType>&); // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
	BTPreOrderIterator(const BinaryTree<DataType>&);

  // Move constructor
	BTPreOrderIterator(BinaryTree<DataType>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
	~BTPreOrderIterator();

  /* ************************************************************************ */

  // Copy assignment
    BTPreOrderIterator& operator=(const BTPreOrderIterator);

  // Move assignment
    BTPreOrderIterator& operator=(BTPreOrderIterator&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
	bool operator==(const BTPreOrderIterator&) const noexcept;
	bool operator!=(const BTPreOrderIterator&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

	DataType& operator*(); // (throw std::out_of_range when terminated)

	bool Terminated() noexcept; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  	void operator++(); // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename DataType>
class BTPostOrderIterator { // Must extend ForwardIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  // BTPostOrderIterator(argument) specifiers; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTPostOrderIterator(argument) specifiers;

  // Move constructor
  // BTPostOrderIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTPostOrderIterator() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

  // type Terminated() specifiers; // (should not throw exceptions)

	DataType& operator*(); // (throw std::out_of_range when terminated)

	bool Terminated() noexcept; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename DataType>
class BTInOrderIterator { // Must extend ForwardIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  // BTInOrderIterator(argument) specifiers; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTInOrderIterator(argument) specifiers;

  // Move constructor
  // BTInOrderIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTInOrderIterator() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

	DataType& operator*(); // (throw std::out_of_range when terminated)

	bool Terminated() noexcept; // (should not throw exceptions)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

  // type Terminated() specifiers; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

template <typename DataType>
class BTBreadthIterator { // Must extend ForwardIterator<Data>

private:

  // ...

protected:

  // ...

public:

  // Specific constructors
  // BTBreadthIterator(argument) specifiers; // An iterator over a given binary tree

  /* ************************************************************************ */

  // Copy constructor
  // BTBreadthIterator(argument) specifiers;

  // Move constructor
  // BTBreadthIterator(argument) specifiers;

  /* ************************************************************************ */

  // Destructor
  // ~BTBreadthIterator() specifiers;

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument) specifiers;

  // Move assignment
  // type operator=(argument) specifiers;

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers;
  // type operator!=(argument) specifiers;

  /* ************************************************************************ */

  // Specific member functions (inherited from Iterator)

	DataType& operator*(); // (throw std::out_of_range when terminated)

	bool Terminated() noexcept; // (should not throw exceptions)

  // type operator*() specifiers; // (throw std::out_of_range when terminated)

  // type Terminated() specifiers; // (should not throw exceptions)

  /* ************************************************************************ */

  // Specific member functions (inherited from ForwardIterator)

  // type operator++() specifiers; // (throw std::out_of_range when terminated)

};

/* ************************************************************************** */

}

#include "binarytree.cpp"

#endif
