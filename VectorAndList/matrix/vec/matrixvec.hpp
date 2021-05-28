
#ifndef MATRIXVEC_HPP
#define MATRIXVEC_HPP

/* ************************************************************************** */

#include "../matrix.hpp"

#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename DataType>
class MatrixVec : virtual public Matrix<DataType>,
				  virtual protected Vector<DataType>{ // Must extend Matrix<Data>

private:

  // ...

protected:

  using Matrix<DataType>::rowNumber;
  using Matrix<DataType>::columnNumber;
  using Vector<DataType>::size;
  using Vector<DataType>::Elements;

  // ...

public:

  // Default constructor
   MatrixVec() = default;

  /* ************************************************************************ */

  // Specific constructors
   MatrixVec(const unsigned long&,const unsigned long&); // A matrix of some specified dimension

  /* ************************************************************************ */

  // Copy constructor
   MatrixVec( const MatrixVec<DataType>&);

  // Move constructor
   MatrixVec(MatrixVec<DataType>&&);

  /* ************************************************************************ */

  // Destructor
   ~MatrixVec() = default;

  /* ************************************************************************ */

  // Copy assignment
   MatrixVec<DataType>& operator=(const MatrixVec<DataType>&) noexcept;

  // Move assignment
   MatrixVec<DataType>& operator=(MatrixVec<DataType>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
   bool operator==(const MatrixVec<DataType>&) const noexcept;
   bool operator!=(const MatrixVec<DataType>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Matrix)

   void RowResize(unsigned long&) override; // Override Matrix member
   void ColumnResize(unsigned long&) override; // Override Matrix member

   bool ExistsCell(const unsigned long&, const unsigned long&) const noexcept override; // Override Matrix member (should not throw exceptions)

   DataType& operator()(const unsigned long&, const unsigned long&) override ; // Override Matrix member (mutable access to the element; throw out_of_range when out of range)
   DataType const& operator()(const unsigned long&, const unsigned long&) const override; // Override Matrix member (immutable access to the element; throw out_of_range when out of range and length_error when not present)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

   void Clear() override; // Override Container member

  /* ************************************************************************ */

  // Specific member functions (inherited from MappableContainer)
   using typename FoldableContainer<DataType>::FoldFunctor;
   using typename MappableContainer<DataType>::MapFunctor;

   void MapPreOrder(const MapFunctor, void*) override; // Override MappableContainer member
   void MapPostOrder(const MapFunctor, void*) override; // Override MappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from FoldableContainer)

   void FoldPreOrder(const FoldFunctor,const void*,void*) const override; // Override FoldableContainer member
   void FoldPostOrder(const FoldFunctor,const void*,void*) const override; // Override FoldableContainer member

};

/* ************************************************************************** */

}

#include "matrixvec.cpp"

#endif
