
#ifndef STACK_HPP
#define STACK_HPP

/* ************************************************************************** */

#include "../container/container.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename DataType>
class Stack : public virtual Container{ // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
	virtual ~Stack() = default;

  /* ************************************************************************ */

  // Copy assignment
	Stack& operator=(const Stack&) noexcept= delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
	Stack& operator=(Stack&&) noexcept= delete; // Move assignment of abstract types should not be possible.


  /* ************************************************************************ */

  // Comparison operators
	bool operator==(const Stack&) const noexcept = delete;
	bool operator!=(const Stack&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

  virtual void Push(const DataType& ) = 0; // Copy of the value
  virtual void Push(DataType&&) noexcept = 0; // Move of the value
  virtual DataType& Top() const = 0; // (concrete function must throw std::length_error when empty)
  virtual void Pop() = 0; // (concrete function must throw std::length_error when empty)
  virtual DataType TopNPop() = 0; // (concrete function must throw std::length_error when empty)


};

/* ************************************************************************** */

}

#endif
