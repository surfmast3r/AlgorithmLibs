
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename DataType>
class StackLst : virtual public Stack<DataType>,
				 virtual protected List<DataType>{ // Must extend Stack<Data> and List<Data>

private:

  	List<DataType>* list= nullptr;

protected:

   using List<DataType>::size;

  // ...

public:


  // Default constructor
   StackLst() ;

  /* ************************************************************************ */

  // Specific constructor
   StackLst(const LinearContainer<DataType>&);// A stack obtained from a LinearContainer

  /* ************************************************************************ */
   // Copy constructor
   StackLst(const StackLst&);

   // Move constructor
   StackLst(StackLst&&) noexcept;

  /* ************************************************************************ */

  // Destructor
   ~StackLst();

  /* ************************************************************************ */
   // Copy assignment
   StackLst& operator=(const StackLst&);

   // Move assignment
   StackLst& operator=(StackLst&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
   bool operator==(const StackLst&) const noexcept;
   bool operator!=(const StackLst&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  void Push(const DataType&) override; // Override Stack member (copy of the value)
  void Push(DataType&&) noexcept override; // Override Stack member (move of the value)
  DataType& Top() const override; // Override Stack member (must throw std::length_error when empty)
  void Pop() override; // Override Stack member (must throw std::length_error when empty)
  DataType TopNPop() override; // Override Stack member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  void Clear() override; // Override Container member

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
