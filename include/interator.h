#ifndef ITERATOR
#define ITERATOR

namespace edb{

	template <typename T>
    class Iterator { 
    public: 
        Iterator( ); 
        const T & operator* ( ) const; 
        Iterator & operator++ ( ); 

        // ++it; 
        Iterator operator++ ( int ); 

        // it++; 
        Iterator & operator-- ( ); 

        // --it;
        Iterator operator-- ( int ); 

        // it--; 
        bool operator== ( const MyIterator & rhs ) const; 

        bool operator!= ( const MyIterator & rhs ) const; 

        private: 
            T *current; 
        };

#include "iterator.inl"

#endif
