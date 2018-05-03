#ifndef VECTOR
#define VECTOR

namespace edb{

	template < class T, size_t SIZE=1 >
    class Vector {
    public:
        //=== Alias
        typedef T value_type;
        typedef size_t size_type;
        typedef T* pointer;
        typedef T& reference;

        
    public:
		template <class C>
        class Iterator {

        /// Alias
        public: 
            typedef  std::ptrdiff_t                  difference_type;
            typedef  T                               value_type;
            typedef  T*                              pointer;
            typedef  T&                              reference;
            //typedef  std::bidirectional_Iterator_tag Iterator_category;
        
        private:
            pointer m_ptr;

        public:
            /// 2 in 1 Constructor (empty and single value).
            Iterator( pointer);

            // /// Destructor
            // ~Iterator();

            /// Copy constructor
            Iterator( const Iterator&);

            /// Assign operator
            Iterator& operator=( const Iterator&);

            reference operator* ( void ) const;
            // ++it
            Iterator operator++();

            // it++
            Iterator operator++( int );
            // --it
            Iterator operator--();
            Iterator operator--( int );
            bool operator==( const Iterator&) const;
            bool operator!=( const Iterator&) const;

            
            //operator +=
            //operator -=
            //operator+
            //operator-
            

        
        };
        class const_Iterator
        {
            private:
        };

        

    private:
        size_type m_size; //!< Stores the array size.
        value_type *m_data; //!< The storage area.

    public:
        /// Basic constructor
        Vector( void );
        //~Vector( );

        Vector( const Vector& original );

        // Vector( const std::initializer_list<T> & il )
        // {
        //     // Copy all elements of original into 'this'.
        //     std::copy( il.begin(), il.end(), &m_data[0] );
        //     /*
        //     auto i(0);
        //     for ( const auto & e : il )
        //         m_data[i++] = e;
        //         */

        //     m_size = il.size();
        // }

        // Iterator begin( void )
        // {
        //     return Iterator( &m_data[0] );
        //     //return Iterator( m_data );
        // }

        // Iterator end( void )
        // {
        //     return Iterator( &m_data[m_size] );
        // }

        // reference operator[]( size_type pos )
        // {
        //     return m_data[pos];
        // }
        // reference at( size_type pos )
        // {
        //     if ( pos < 0 or pos >= m_size )
        //         throw std::out_of_range("[array::at()] Acesso fora dos limites do vetor." );

        //     return m_data[pos];
        // }

        // size_type size( void ) const
        // {
        //     return m_size;
        // }

        // bool empty( void ) const
        // {
        //     return m_size == 0;
        //     //return begin() == end();
        // }

        // bool operator==( const array<T,SIZE>& rhs ) const
        // {
        //     if( m_size != rhs.m_size ) return false;
        //     return std::equal( &rhs.m_data[0], &rhs.m_data[m_size], &m_data[0] );
        // }

        // // Copy constructor
        // friend std::ostream& operator<<( std::ostream& os, const sc::array<T,SIZE>& a )
        // {
        //     os << "[ ";
        //     for( auto i(0u) ; i < a.m_size ; ++i )
        //         //for ( sc::array::Iterator it = a.begin() ; it != a.end() ; ++it )
        //         // std::cout << *it << " ";
        //         os << a.m_data[i] << " ";
        //     os << "]";
        //     return os;
        // }

        //private:
            
    };

}

#include "vector.inl"

#endif
