
namespace lasd {

/* ************************************************************************** */

template <typename DataType>
unsigned long const& Matrix<DataType>::RowNumber() const noexcept{
	return rowNumber;
}

template <typename DataType>
unsigned long const& Matrix<DataType>::ColumnNumber() const noexcept{
	return columnNumber;
}

/* ************************************************************************** */

}
