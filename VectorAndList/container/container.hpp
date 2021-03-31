
#ifndef CONTAINER_HPP
#define CONTAINER_HPP

/* ************************************************************************** */

#include <stdexcept>
#include <functional>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

class Container {

private:

  // ...


protected:
	unsigned long size;
  // ...

public:

	// Destructor
	virtual ~Container() = default;

  /* ************************************************************************ */

  // Copy assignment
	Container& operator=(const Container&) noexcept= delete;

  // Move assignment
	Container& operator=(Container&&) noexcept= delete;

  /* ************************************************************************ */

  // Comparison operators
	bool operator==(const Container&) const noexcept = delete;
	bool operator!=(const Container&) const noexcept = delete;

  /* ************************************************************************ */

  // Specific member functions

	virtual bool Empty() const noexcept { return (size==0);}; // (concrete function should not throw exceptions)

	virtual unsigned long Size() const noexcept { return size;}; // (concrete function should not throw exceptions)

    virtual void Clear() = 0;

};

/* ************************************************************************** */

template <typename DataType>
class LinearContainer : public virtual Container { // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~LinearContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  LinearContainer& operator=(const LinearContainer&) noexcept = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  LinearContainer& operator=(LinearContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const LinearContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const LinearContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual DataType& Front() const = 0; // (concrete function must throw std::length_error when empty)
  virtual DataType& Back() const = 0; // (concrete function must throw std::length_error when empty)

  virtual DataType& operator[](const unsigned long &) const = 0; // (concrete function must throw std::out_of_range when out of range)

};

/* ************************************************************************** */

template <typename DataType>
class TestableContainer : virtual public Container{ // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~TestableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  TestableContainer& operator=(const TestableContainer&) noexcept = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  TestableContainer& operator=(TestableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const TestableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const TestableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  virtual bool Exists(const DataType&) const noexcept = 0; // (concrete function should not throw exceptions) //virtual

};

/* ************************************************************************** */

template <typename DataType>
class MappableContainer : virtual public Container{ // Must extend Container

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~MappableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  MappableContainer& operator=(const MappableContainer&) noexcept = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  MappableContainer& operator=(MappableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const MappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const MappableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  typedef std::function<void(DataType&, void*)> MapFunctor;

  virtual void MapPreOrder(const MapFunctor, void*) = 0;
  virtual void MapPostOrder(const MapFunctor, void*) = 0;

};

/* ************************************************************************** */

template <typename DataType>
class FoldableContainer : virtual public TestableContainer<DataType> { // Must extend TestableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  virtual ~FoldableContainer() = 0;

  /* ************************************************************************ */

  // Copy assignment
  FoldableContainer& operator=(const FoldableContainer&) noexcept = delete; // Copy assignment of abstract types should not be possible.

  // Move assignment
  FoldableContainer& operator=(FoldableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const FoldableContainer&) const = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const FoldableContainer&) const = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  typedef std::function<void(const DataType&, const void*, void*) noexcept> FoldFunctor;

  virtual void FoldPreOrder(const FoldFunctor, const void*,void*) = 0;
  virtual void FoldPostOrder(const FoldFunctor, const void*,void*) = 0;

  virtual bool Exists(const DataType&) const noexcept override; // Override TestableContainer member

};

/* ************************************************************************** */

template <typename DataType>
class BreadthMappableContainer : virtual public MappableContainer<DataType>{ // Must extend MappableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BreadthMappableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // using typename MappableContainer<Data>::MapFunctor;

  // type MapBreadth(arguments) specifiers;

};

/* ************************************************************************** */

template <typename DataType>
class BreadthFoldableContainer { // Must extend FoldableContainer

private:

  // ...

protected:

  // ...

public:

  // Destructor
  // ~BreadthFoldableContainer() specifiers

  /* ************************************************************************ */

  // Copy assignment
  // type operator=(argument); // Copy assignment of abstract types should not be possible.

  // Move assignment
  // type operator=(argument); // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  // type operator==(argument) specifiers; // Comparison of abstract types might not be possible.
  // type operator!=(argument) specifiers; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member functions

  // using typename FoldableContainer<Data>::FoldFunctor;

  // type FoldBreadth(arguments) specifiers;

};

/* ************************************************************************** */

}

#include "container.cpp"

#endif
