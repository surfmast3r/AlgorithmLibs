
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename DataType>
class StackVec : virtual public Stack<DataType>,
				 protected Vector<DataType>{ // Must extend Stack<Data> and Vector<Data>

private:

	unsigned long stackSize=0;
	unsigned long top;


protected:

	using Vector<DataType>::size;
	using Vector<DataType>::Elements;

  // ...

public:

  // Default constructor
	StackVec();

  /* ************************************************************************ */

  // Specific constructor
	StackVec(const LinearContainer<DataType>&); // A stack obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
	StackVec(const StackVec<DataType>&);

  // Move constructor
	StackVec(StackVec<DataType>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
	~StackVec();

  /* ************************************************************************ */

  // Copy assignment
	StackVec<DataType>& operator=(const StackVec<DataType>&);

  // Move assignment
	StackVec<DataType>& operator=(StackVec<DataType>&&);

  /* ************************************************************************ */

  // Comparison operators
	bool operator==(const StackVec<DataType>&) const noexcept;
	bool operator!=(const StackVec<DataType>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

	void Push(const DataType&) override; // Override Stack member (copy of the value)
	void Push(DataType&&) noexcept override; // Override Stack member (move of the value)
	DataType& Top() const override; // Override Stack member (must throw std::length_error when empty)
	void Pop() override; // Override Stack member (must throw std::length_error when empty)
	DataType TopNPop() override; // Override Stack member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

	bool Empty() const noexcept override; // Override Container member

	unsigned long Size() const noexcept override; // Override Container member

	void Clear() override; // Override Container member

protected:

  // Auxiliary member functions

	void Expand();
	void Reduce();
	bool fullStack() const;
	bool emptyStack() const;
};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
