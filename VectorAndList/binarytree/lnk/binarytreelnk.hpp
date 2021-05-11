
#ifndef BINARYTREELNK_HPP
#define BINARYTREELNK_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename DataType>
class BinaryTreeLnk : virtual public BinaryTree<DataType>{ // Must extend BinaryTree<Data>

private:

  // ...

protected:

  using BinaryTree<DataType>::size;

  // ...

  struct NodeLnk : public BinaryTree<DataType>::Node { // Must extend Node

  private:

  protected:

  public:
	DataType data;
	NodeLnk* leftChild= nullptr;
	NodeLnk* rightChild= nullptr;

	NodeLnk()=default;
	NodeLnk(const DataType&);
    // Destructor
    virtual ~NodeLnk() = default;

    /* ********************************************************************** */

    // Copy assignment
    NodeLnk& operator=(const NodeLnk&) noexcept;

    // Move assignment
    NodeLnk& operator=(NodeLnk&&) noexcept;

    /* ********************************************************************** */

    // Comparison operators
	bool operator==(const NodeLnk&) const noexcept; // Comparison of abstract types is possible, but should not be visible.
	bool operator!=(const NodeLnk&) const noexcept; // Comparison of abstract types is possible, but should not be visible.

    /* ********************************************************************** */

    // Specific member functions

    DataType& Element() noexcept ; // Mutable access to the element (concrete function should not throw exceptions)
    const DataType& Element() const noexcept ; // Immutable access to the element (concrete function should not throw exceptions)

    bool IsLeaf() const noexcept; // (concrete function should not throw exceptions)
    bool HasLeftChild() const noexcept; // (concrete function should not throw exceptions)
    bool HasRightChild() const noexcept ; // (concrete function should not throw exceptions)

     NodeLnk& LeftChild() const; // (concrete function must throw std::out_of_range when not existent)
     NodeLnk& RightChild() const; // (concrete function must throw std::out_of_range when not existent)

  };

  NodeLnk* root = nullptr;

public:

  // Default constructor
  BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeLnk(const LinearContainer<DataType>& container); // A binary tree obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeLnk(const BinaryTreeLnk&) noexcept;

  // Move constructor
  BinaryTreeLnk(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  ~BinaryTreeLnk();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeLnk& operator=(const BinaryTreeLnk&) noexcept;

  // Move assignment
  BinaryTreeLnk& operator=(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
   bool operator==(const BinaryTreeLnk&) const noexcept;
   bool operator!=(const BinaryTreeLnk&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

   typename BinaryTree<DataType>::Node& Root() const override; // Override BinaryTree member (throw std::length_error when empty)


  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

protected:
  	NodeLnk* buildTreeFromLinearContainer(const LinearContainer<DataType>&, int, int);
	NodeLnk* binaryTreeCopy( NodeLnk* root);
	void deleteBinaryTree(NodeLnk* root);
};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
