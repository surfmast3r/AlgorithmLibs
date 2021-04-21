
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename DataType>
class QueueVec : virtual public Queue<DataType>,
				 virtual protected Vector<DataType>{ // Must extend Queue<Data> and List<Data>

private:


	unsigned long queueSize=0;
	unsigned long head=0;
	unsigned long tail=0;


protected:

	using Vector<DataType>::size;
	using Vector<DataType>::Elements;

public:

	// Default constructor

	QueueVec();

  /* ************************************************************************ */

	// Specific constructor
	QueueVec(const LinearContainer<DataType>&); // A queue obtained from a LinearContainer

  /* ************************************************************************ */

	// Copy constructor
	QueueVec(const QueueVec<DataType>&);

	// Move constructor
	QueueVec(QueueVec<DataType>&&) noexcept;


  /* ************************************************************************ */

	// Destructor
	~QueueVec();

  /* ************************************************************************ */

	// Copy assignment
	QueueVec& operator=(const QueueVec&);

	// Move assignment
	QueueVec& operator=(QueueVec&&) noexcept;

  /* ************************************************************************ */

	// Comparison operators
	bool operator==(const QueueVec&) const noexcept;
	bool operator!=(const QueueVec&) const noexcept;


  /* ************************************************************************ */


	// Specific member functions (inherited from Queue)

	void Enqueue(const DataType&) override; // Override Queue member (copy of the value)
	void Enqueue(DataType&&) noexcept override;  // Override Queue member (move of the value)
	DataType& Head() const override; // Override Queue member (must throw std::length_error when empty)
	void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
	DataType HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)

  /* ************************************************************************ */

	// Specific member functions (inherited from Container)

	bool Empty() const noexcept override; // Override Container member

	unsigned long Size() const noexcept override; // Override Container member

	void Clear() override; // Override Container member

protected:

	// Auxiliary member functions

	void Expand(const unsigned long);
	void Reduce();
	bool fullQueue() const;
	bool emptyQueue() const;
    //void SwapVectors()noexcept;

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
