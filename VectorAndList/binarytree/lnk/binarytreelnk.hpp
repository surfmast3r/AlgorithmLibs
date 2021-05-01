
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

  // using BinaryTree<Data>::???;

  // ...

  struct NodeLnk : Node{ // Must extend Node

  private:

    DataType data;
    Node* leftChild= nullptr;
    Node* rightChild= nullptr;

  protected:

    // ...

  public:

    // Destructor
    virtual ~NodeLnk() = default;

    /* ********************************************************************** */

    // Copy assignment
    NodeLnk& operator=(const NodeLnk&) noexcept;

    // Move assignment
    NodeLnk& operator=(NodeLnk&&) noexcept;

    /* ********************************************************************** */

    // Comparison operators
    // type operator==(argument) specifiers; // Comparison of abstract types is possible, but should not be visible.
    // type operator!=(argument) specifiers; // Comparison of abstract types is possible, but should not be visible.

    /* ********************************************************************** */

    // Specific member functions

    DataType& Element() noexcept ; // Mutable access to the element (concrete function should not throw exceptions)
    DataType& Element() const noexcept ; // Immutable access to the element (concrete function should not throw exceptions)

    bool IsLeaf() noexcept; // (concrete function should not throw exceptions)
    bool HasLeftChild() noexcept; // (concrete function should not throw exceptions)
    bool HasRightChild() noexcept ; // (concrete function should not throw exceptions)

    NodeLnk& LeftChild(); // (concrete function must throw std::out_of_range when not existent)
    NodeLnk& RightChild(); // (concrete function must throw std::out_of_range when not existent)

  };

  NodeLnk* root = nullptr;

public:

  // Default constructor
  BinaryTreeLnk() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeLnk(LinearContainer<DataType> container); // A binary tree obtained from a LinearContainer

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
  BinaryTreeLnk& operator=(const BinaryTreeLnk) noexcept;

  // Move assignment
  BinaryTreeLnk& operator=(BinaryTreeLnk&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
   bool operator==(const BinaryTreeLnk&) const noexcept;
   bool operator!=(const BinaryTreeLnk&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  Node& Root(); // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear(); // Override Container member

};

/* ************************************************************************** */

}

#include "binarytreelnk.cpp"

#endif
