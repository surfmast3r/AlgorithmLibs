
#ifndef BST_HPP
#define BST_HPP

/* ************************************************************************** */

#include "../binarytree/lnk/binarytreelnk.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename DataType>
class BST : virtual public BinaryTreeLnk<DataType>{ // Must extend BinaryTreeLnk<Data>

private:

  // ...

protected:

   using BinaryTreeLnk<DataType>::size;
   using BinaryTreeLnk<DataType>::root;

  // ...

public:

  // Default constructor
   BST() = default;

  /* ************************************************************************ */

  // Specific constructors
   BST(const LinearContainer<DataType>&); // A bst obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
   BST(const BST<DataType>& bt);

  // Move constructor
   BST(BST<DataType>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
   ~BST() = default;

  /* ************************************************************************ */

  // Copy assignment
   BST& operator=(const BST&) noexcept;

  // Move assignment
   BST& operator=(BST&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
   bool operator==(const BST&) const noexcept;
   bool operator!=(const BST&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

   void Insert(const DataType&) noexcept; // Copy of the value
   void Insert(DataType&&) noexcept; // Move of the value
   void Remove(const DataType&) noexcept;

   const DataType& Min() const; // (concrete function must throw std::length_error when empty)
   DataType MinNRemove(); // (concrete function must throw std::length_error when empty)
   void RemoveMin(); // (concrete function must throw std::length_error when empty)

   const DataType& Max() const; // (concrete function must throw std::length_error when empty)
   DataType MaxNRemove(); // (concrete function must throw std::length_error when empty)
   void RemoveMax(); // (concrete function must throw std::length_error when empty)

   const DataType& Predecessor(const DataType&) const; // (concrete function must throw std::length_error when empty OR not found)
   DataType PredecessorNRemove(const DataType&); // (concrete function must throw std::length_error when empty OR not found)
   void RemovePredecessor(const DataType&); // (concrete function must throw std::length_error when empty OR not found)

   const DataType& Successor(const DataType&) const; // (concrete function must throw std::length_error when empty OR not found)
   DataType SuccessorNRemove(const DataType&); // (concrete function must throw std::length_error when empty OR not found)
   void RemoveSuccessor(const DataType&); // (concrete function must throw std::length_error when empty OR not found)

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

   bool Exists(const DataType&) const noexcept override; // Override TestableContainer member

protected:

  // Auxiliary member functions

  // type DataNDelete(argument) specifiers;

   typename BST<DataType>::NodeLnk* Detach(typename BST<DataType>::NodeLnk*&);

   typename BST<DataType>::NodeLnk* DetachMin(typename BST<DataType>::NodeLnk*&); //argument root of subTree
   typename BST<DataType>::NodeLnk* DetachMax(typename BST<DataType>::NodeLnk*&); //argument root of subTree

   typename BST<DataType>::NodeLnk* SkipOnLeft(typename BST<DataType>::NodeLnk*&);
   typename BST<DataType>::NodeLnk* SkipOnRight(typename BST<DataType>::NodeLnk*&);

   typename BST<DataType>::NodeLnk*& FindPointerToMin(typename BST<DataType>::NodeLnk*&);//argument root of subTree
   typename BST<DataType>::NodeLnk* const& FindPointerToMin( typename BST<DataType>::NodeLnk * const&) const;

   typename BST<DataType>::NodeLnk*& FindPointerToMax(typename BST<DataType>::NodeLnk*&) ;//argument root of subTree
   typename BST<DataType>::NodeLnk* const& FindPointerToMax( typename BST<DataType>::NodeLnk * const&) const;

   typename BST<DataType>::NodeLnk*& FindPointerTo( typename BST<DataType>::NodeLnk*& ,const DataType&) ;//argument root of subTree and data to find
   typename BST<DataType>::NodeLnk* const& FindPointerTo(typename BST<DataType>::NodeLnk* const&,const DataType&) const;//argument root of subTree and data to find

   typename BST<DataType>::NodeLnk*& FindPointerToPredecessor( typename BST<DataType>::NodeLnk*&,const DataType&) ;
   typename BST<DataType>::NodeLnk* const& FindPointerToPredecessor( typename BST<DataType>::NodeLnk*const&,const DataType&) const;
   typename BST<DataType>::NodeLnk*& FindPointerToSuccessor( typename BST<DataType>::NodeLnk*&,const DataType&);
   typename BST<DataType>::NodeLnk* const& FindPointerToSuccessor( typename BST<DataType>::NodeLnk*const&,const DataType&) const;

};

/* ************************************************************************** */

}

#include "bst.cpp"

#endif
