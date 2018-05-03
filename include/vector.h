#ifndef VECTOR
#define VECTOR

#include "iterator.h"
#include <iostream>

namespace sc{

	template <class T>
    class vector{
    	
    public:
        const static size_type DEFAULT_SIZE = 0;

        using iter   = sc::Iterator<T>;
        using c_iter = sc::Iterator<const T>;
        using c_ref  = const sc::Iterator<T>&;
        using ref  = sc::Iterator<T>&;
        using pointer  = sc::Iterator<T>*; // sei la?

        // SPECIAL MEMBERS
        vector();
        
        ~vector();
        
        vector (const vector &);
        
        vector (vector &&);

        template <typename InputItr>
        vector ( InputItr, InputItr);

        vector & operator= (const vector &);
        vector & operator= (vector &);

        // ITERATORS
        iter begin( void );
        iter end( void );
        c_iter cbegin( void );
        c_iter cend ( void );

        // CAPACITY
        size_type size( void ) const;
        size_type capacity( void ) const;
        bool empty ( void ) const;

        void clear ( void );
        void push_front ( c_ref );
        void push_back ( c_ref );
        void pop_front( void );
        void pop_back( void );

        iter insert(iter, c_ref);

        template <typename InputItr>
        iter insert(iter, InputItr, InputItr);

        iter insert(iter, std::initializator_list <T>);

        void reserve (size_type);

        void shrink_to_fit ( void );

        void assign (c_ref);
        void assign (std::initializator_list <T>);

        template <typename InputItr>
        void assign (InputItr, InputItr);

        iter erase(iter, iter);
        iter erase (iter);

        // ELEMENT ACCESS
        c_ref back (void) const;
        c_ref front (void) const;
        c_ref operator[] (size_type) const;
        ref operator[] (size_type);
        c_ref at (size_type) const;
        ref at (size_type);
        pointer data ( void ); //qm é pointer
        c_ref data (void) const;

        // OPERATORS
        bool operator==(const vector & ) const;
        bool operator!=(const vector & ) const;

        // FRIEND FUNCTIONS
        friend std::ostream & operator<<( std::ostream & os_, const vector<T> & v_ ); 
        friend void swap( vector<T> & first_, vector<T> & second_ ); 

    private:
        size_type m_end;
        size_type m_capacity;
        T *m_storage;

    };

#include "vector.inl"

#endif
