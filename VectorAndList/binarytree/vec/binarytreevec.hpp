
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename DataType>
class BinaryTreeVec : virtual public BinaryTree<DataType>{ // Must extend BinaryTree<Data>

private:

  // ...

protected:

   using BinaryTree<DataType>::size;
  // ...

  struct NodeVec : public BinaryTree<DataType>::Node{ // Must extend Node


  private:


  protected:



  public:


    DataType data;
    unsigned int index=0;
    Vector<NodeVec>*btVec=nullptr;

    NodeVec()=default;
    NodeVec(const DataType&, unsigned int&,Vector<NodeVec>&);
    // Destructor
    virtual ~NodeVec() = default;

    /* ********************************************************************** */

    // Copy assignment
    NodeVec& operator=(const NodeVec&) noexcept;

    // Move assignment
    NodeVec& operator=(NodeVec&&) noexcept;

    /* ********************************************************************** */

    // Comparison operators
	bool operator==(const NodeVec&) const noexcept;
	bool operator!=(const NodeVec&) const noexcept;

    /* ********************************************************************** */

    // Specific member functions

    DataType& Element() noexcept ; // Mutable access to the element (concrete function should not throw exceptions)
    const DataType& Element() const noexcept ; // Immutable access to the element (concrete function should not throw exceptions)

    bool IsLeaf() noexcept; // (concrete function should not throw exceptions)
    bool HasLeftChild() const noexcept; // (concrete function should not throw exceptions)
    bool HasRightChild() const noexcept ; // (concrete function should not throw exceptions)

    NodeVec& LeftChild() ; // (concrete function must throw std::out_of_range when not existent)
    NodeVec& RightChild() ; // (concrete function must throw std::out_of_range when not existent)

  };

  Vector<NodeVec>binaryTreeVector;

public:

  // Default constructor
   BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
   BinaryTreeVec(const LinearContainer<DataType>& container); // A binary tree obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
   BinaryTreeVec(const BinaryTreeVec&) noexcept;

  // Move constructor
   BinaryTreeVec(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
   ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
   BinaryTreeVec& operator=(const BinaryTreeVec&) noexcept;

  // Move assignment
   BinaryTreeVec& operator=(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
   bool operator==(const BinaryTreeVec&) const noexcept;
   bool operator!=(const BinaryTreeVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

   typename BinaryTree<DataType>::Node& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

   virtual void MapBreadth(const typename BinaryTree<DataType>::MapFunctor, void*) override; // Override BreadthMappableContainer member
   virtual void FoldBreadth(const typename BinaryTree<DataType>::FoldFunctor, const void*,void*) const override; // Override BreadthFoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

   void Clear() override; // Override Container member

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
