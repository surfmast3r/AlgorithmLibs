#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename DataType>
class Vector : virtual public LinearContainer<DataType>,
			   virtual public MappableContainer<DataType>,
			   virtual public FoldableContainer<DataType>{

private:

  // ...

protected:

  using LinearContainer<DataType>::size;

  DataType* Elements=nullptr;
  // ...

public:

  // Default constructor
  Vector() = default;

  /* ************************************************************************ */

  // Specific constructors
  Vector(const unsigned long& size); // A vector with a given initial dimension
  Vector(const LinearContainer<DataType>& ); // A vector obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
  Vector(const Vector&) ;

  // Move constructor
  Vector(Vector&&) ;

  /* ************************************************************************ */

  // Destructor
  ~Vector();

  /* ************************************************************************ */

  // Copy assignment
  Vector& operator=(const Vector&);

  // Move assignment
  Vector& operator=(Vector&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const Vector&) const noexcept ;
  bool operator!=(const Vector&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  // type Resize(argument) specifiers; // Resize the vector to a given size

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  DataType& Front() const override; // Override LinearContainer member (must throw std::length_error when empty)
  DataType& Back() const override; // Override LinearContainer member (must throw std::length_error when empty)

  DataType& operator[](const unsigned long&) const override; // Override LinearContainer member (must throw std::out_of_range when out of range)

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)

  using typename MappableContainer<DataType>::MapFunctor;

  void MapPreOrder(const MapFunctor, void*) override; // Override MappableContainer member
  void MapPostOrder(const MapFunctor, void*) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

  using typename FoldableContainer<DataType>::FoldFunctor;

  void FoldPreOrder(const FoldFunctor, const void*,void*) override; // Override FoldableContainer member
  void FoldPostOrder(const FoldFunctor, const void*,void*) override; // Override FoldableContainer member

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
