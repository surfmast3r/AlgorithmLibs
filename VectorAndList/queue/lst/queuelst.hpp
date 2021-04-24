
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename DataType>
class QueueLst : virtual public Queue<DataType>,
				 virtual protected List<DataType>{ // Must extend Queue<Data> and List<Data>

private:

protected:

	using List<DataType>::size;
	using List<DataType>::head;
	using List<DataType>::tail;

  // ...

public:

  // Default constructor

	QueueLst();

  /* ************************************************************************ */

  // Specific constructor
	QueueLst(const LinearContainer<DataType>&); // A queue obtained from a LinearContainer

  /* ************************************************************************ */

  // Copy constructor
	QueueLst(const QueueLst<DataType>&);

  // Move constructor
	QueueLst(QueueLst<DataType>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
    ~QueueLst() = default;

  /* ************************************************************************ */

    // Copy assignment
    QueueLst& operator=(const QueueLst&);

	// Move assignment
    QueueLst& operator=(QueueLst&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
    bool operator==(const QueueLst&) const noexcept;
    bool operator!=(const QueueLst&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

    void Enqueue(const DataType&) override; // Override Queue member (copy of the value)
    void Enqueue(DataType&&) noexcept override;  // Override Queue member (move of the value)
    DataType& Head() const override; // Override Queue member (must throw std::length_error when empty)
    void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
    DataType HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

    void Clear() override; // Override Container member

};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
