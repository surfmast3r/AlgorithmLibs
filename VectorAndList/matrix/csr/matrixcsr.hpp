
#ifndef MATRIXCSR_HPP
#define MATRIXCSR_HPP

/* ************************************************************************** */

#include "../matrix.hpp"

#include "../../list/list.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename DataType>
class MatrixCSR : virtual public Matrix<DataType>,
				  virtual protected List<std::pair<DataType,unsigned long>>{ // Must extend Matrix<Data>

private:

  // ...

protected:

   using Matrix<DataType>::rowNumber;
   using Matrix<DataType>::columnNumber;
   using List<std::pair<DataType,unsigned long>>::head;
   using List<std::pair<DataType,unsigned long>>::tail;
   using List<std::pair<DataType,unsigned long>>::size;

   Vector<typename List<std::pair<DataType,unsigned long>>::Node**> rowVector = Vector<typename List<std::pair<DataType,unsigned long>>::Node**>(1);
  // ...

public:

  // Default constructor
   MatrixCSR();

  /* ************************************************************************ */

  // Specific constructors
   MatrixCSR(unsigned long , unsigned long ); // A matrix of some specified dimension

  /* ************************************************************************ */

  // Copy constructor
   MatrixCSR(const MatrixCSR&);

  // Move constructor
   MatrixCSR(MatrixCSR&&) noexcept;

  /* ************************************************************************ */

  // Destructor
   ~MatrixCSR() = default;

  /* ************************************************************************ */

  // Copy assignment
   MatrixCSR& operator=(const MatrixCSR&) noexcept;

  // Move assignment
   MatrixCSR& operator=(MatrixCSR&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
   bool operator==(const MatrixCSR&) const noexcept;
   bool operator!=(const MatrixCSR&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Matrix)

   void RowResize(unsigned long&) override; // Override Matrix member
   void ColumnResize(unsigned long&) override; // Override Matrix member

   bool ExistsCell(const unsigned long&,const unsigned long&) const noexcept override; // Override Matrix member (should not throw exceptions)

   DataType& operator()(const unsigned long&,const unsigned long&) override; // Override Matrix member (mutable access to the element; throw out_of_range when out of range)
   DataType const& operator()(const unsigned long&,const unsigned long&) const override; // Override Matrix member (immutable access to the element; throw out_of_range when out of range and length_error when not present)

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

private:
   void expandRowVector(unsigned long newRowSize);
   void reduceRowVector(unsigned long newRowSize);
   void deleteListFrom(typename List<std::pair<DataType,unsigned long>>::Node* ptr);


};

/* ************************************************************************** */

}

#include "matrixcsr.cpp"

#endif
