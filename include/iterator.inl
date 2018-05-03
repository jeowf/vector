#include <iterator.h>

namespace sc {

	template <typename T>
	MyIterator<T>::MyIterator(void) : current(nullptr){ }

	template <typename T>
	MyIterator<T>::MyIterator(T* ptr) : current(ptr){ }

	template <typename T>
	const typename MyIterator<T>::T& MyIterator<T>::operator*( void ) const{
		return *current;
	}

	template <typename T>
	MyIterator<T> & MyIterator<T>::operator++ (void){
		return ++current;
	}

	template <typename T>
	MyIterator<T> MyIterator<T>::operator++ ( int ){
		MyIterator temp( *this );
        ++current;
        return temp;

	}

	template <typename T>
	MyIterator<T> & MyIterator<T>::operator-- (void){
		return --current;
	}

	template <typename T>
	MyIterator<T> MyIterator<T>::operator-- ( int ){
		MyIterator temp( *this );
        --current;
        return temp;

	}

	template <typename T>
	bool MyIterator<T>::operator==( const MyIterator& rhs ) const {
	    return current == rhs.current;
	}

	template <typename T>
	bool MyIterator<T>::operator!=( const MyIterator& rhs ) const {
	    return current != rhs.current;
	}



}