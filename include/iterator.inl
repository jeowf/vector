#include <iterator.h>

namespace sc {
	//construtor inicado com ponteiro nulo
	template <typename T>
	MyIterator<T>::MyIterator(void) : current(nullptr){ }
	
	//construtor inicado com ponteiro não nulo
	template <typename T>
	MyIterator<T>::MyIterator(T* ptr) : current(ptr){ }

	//operador * sobrecarregado para pegar o valor do elemento atual da lista sem alterá-lo
	template <typename T>
	const T& MyIterator<T>::operator*( void ) const{
		return *current;
	}
	//operador * sobrecarregado para pegar o valor do elemento atual da lista
	template <typename T>
	T& MyIterator<T>::operator*( void ) {
		return *current;
	}
	//operador ++ sobrecarregado para pegar o valor do  próximo elemento da lista
	template <typename T>
	MyIterator<T> & MyIterator<T>::operator++ (void){
		return ++current;
	}
	//operador ++ sobrecarregado para pegar o valor do elemento atual da lista e em seguida
	//passar o iterador para o próximo elemento da lista
	template <typename T>
	MyIterator<T> MyIterator<T>::operator++ ( int ){
		MyIterator temp( *this );
        ++current;
        return temp;

	}
	//operador -- sobrecarregado para pegar o valor do elemento anterior da lista
	template <typename T>
	MyIterator<T> & MyIterator<T>::operator-- (void){
		return --current;
	}
	//operador -- sobrecarregado para pegar o valor do elemento atual da lista e em seguida
	//passar o iterador para o elemento anterior da lista
	template <typename T>
	MyIterator<T> MyIterator<T>::operator-- ( int ){
		MyIterator temp( *this );
        --current;
        return temp;

	}
	//operador == sobrecarregado para verificar se dois iteradores apontam para o mesmo elemento
	template <typename T>
	bool MyIterator<T>::operator==( const MyIterator& rhs ) const {
	    return current == rhs.current;
	}
	//operador == sobrecarregado para verificar se dois iteradores não apontam para o mesmo elemento
	template <typename T>
	bool MyIterator<T>::operator!=( const MyIterator& rhs ) const {
	    return current != rhs.current;
	}
	//operador - sobrecarregado para pegar a diferença entre dois iteradores
	template <typename T>
	typename MyIterator<T>::size_type MyIterator<T>::operator-( const MyIterator& rhs ) {
	    
	    return current -rhs.current;
	}
	//operador + sobrecarregado para incrementar a posĩção de um iterador
	template <typename T>
	MyIterator<T> MyIterator<T>::operator+( const int& rhs ) {
	    
	    return current + rhs;
	}

}