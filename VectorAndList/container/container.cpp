namespace lasd {

/* ************************************************************************** */

template <typename DataType>
void AuxiliaryFoldExists (const DataType& data, const void* value, void* exists){
	if ( data== *((DataType*) value)){
		*((bool*)exists)=true;
	}
}

template <typename DataType>
bool FoldableContainer<DataType>::Exists( const DataType& data) const noexcept{
	 bool exists= false;
	 FoldPreOrder(&AuxiliaryFoldExists<DataType>,&data,&exists);
	 return exists;
}

/* ************************************************************************** */

}
