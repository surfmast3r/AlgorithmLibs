
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

  // ...

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

   virtual unsigned long& RowNumber() const noexcept = 0; // (concrete function should not throw exceptions)
   virtual unsigned long& ColumnNumber() const noexcept = 0; // (concrete function should not throw exceptions)

   virtual void RowResize() = 0;
   virtual void ColumnResize() = 0;

   virtual bool ExistsCell() const noexcept = 0; // (concrete function should not throw exceptions)

   virtual DataType& operator()() = 0; // Mutable access to the element (concrete function should throw exceptions only when out of range)
   virtual DataType const& operator()() const = 0; // Immutable access to the element (concrete function should throw exceptions when not present)

};

/* ************************************************************************** */

}

#include "matrix.cpp"

#endif
