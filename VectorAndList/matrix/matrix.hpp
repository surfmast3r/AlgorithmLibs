
#ifndef MATRIX_HPP
#define MATRIX_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename DataType>
class Matrix : virtual public MappableContainer<DataType>,
			   virtual public FoldableContainer<DataType>{ // Must extend MappableContainer<Data> and FoldableContainer<Data>
private:

  // ...

protected:

  unsigned long rowNumber = 0;
  unsigned long columnNumber = 0;

public:

  // Destructor
   virtual ~Matrix() = default;
  /* ************************************************************************ */

  // Copy assignment
   Matrix& operator=(const Matrix&) noexcept = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
   Matrix& operator=(Matrix&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
   bool operator==(const Matrix&) const noexcept= delete; // Comparison of abstract types might not be possible.
   bool operator!=(const Matrix&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

   unsigned long const& RowNumber() const noexcept; // (concrete function should not throw exceptions)
   unsigned long const& ColumnNumber() const noexcept; // (concrete function should not throw exceptions)

   virtual void RowResize(unsigned long&) = 0;
   virtual void ColumnResize(unsigned long&) = 0;

   virtual bool ExistsCell(const unsigned long&, const unsigned long&) const noexcept = 0; // (concrete function should not throw exceptions)

   virtual DataType& operator()(const unsigned long &,const unsigned long &) = 0; // Mutable access to the element (concrete function should throw exceptions only when out of range)
   virtual DataType const& operator()(const unsigned long &, const unsigned long&) const = 0; // Immutable access to the element (concrete function should throw exceptions when not present)

};

/* ************************************************************************** */

}

#include "matrix.cpp"

#endif
