#ifndef ITERATOR
#define ITERATOR

namespace sc{

	template <typename T>
    class MyIterator { 
    public: 

        typedef MyIterator& ref ;

        MyIterator(void); 

        MyIterator(T*); 
        
        const T& operator* (void) const; 
        MyIterator & operator++ (void);  // ++it; 

        MyIterator operator++ (int); // it++; 

        MyIterator & operator-- (void); // --it;

        MyIterator operator-- (int); // it--; 

        bool operator== (const MyIterator &) const; 

        bool operator!= (const MyIterator &) const; 

    private: 
        T *current; 
    };
}

#include "iterator.inl"

#endif
