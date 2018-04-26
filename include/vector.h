#ifndef VECTOR
#define VECTOR

namespace edb{

	template < typename T, size_t SIZE=0 >
    class Vector {
        //=== Alias
        typedef T value_type;
        typedef size_t size_type;
        typedef T* pointer;
        typedef T& reference;

        public:
            class iterator {
                public: // iterator traits
                    typedef  std::ptrdiff_t                  difference_type;
                    typedef  T                               value_type;
                    typedef  T*                              pointer;
                    typedef  T&                              reference;
                    typedef  std::bidirectional_iterator_tag iterator_category;

                    /// 2 in 1 Constructor (empty and single value).
                    iterator( pointer ptr=nullptr ) : m_ptr( ptr )
                    { /* empty */ }

                    /// Destructor
                    ~iterator() = default;

                    /// Copy constructor
                    iterator( const iterator& itr ) : m_ptr( itr.m_ptr )
                    { /* empty */ }

                    /// Assign operator
                    iterator& operator=( const iterator& rhs )
                    {
                        m_ptr = rhs.m_ptr;
                    }

                    reference operator* ( void ) const
                    {
                        return *m_ptr;
                    }
                    // ++it
                    iterator operator++()
                    {
                        return ++m_ptr;
                    }

                    // it++
                    iterator operator++( int )
                    {
                        // V. 1
                        iterator temp( *this );
                        ++m_ptr;
                        return temp;

                        // V. 2
                        pointer temp2 = m_ptr;
                        ++m_ptr;
                        return iterator( temp2 );

                        // V. 3
                        return m_ptr++;

                        // V. 4
                        ++m_ptr;
                        return m_ptr-1;
                    }
                    // --it
                    iterator operator--()
                    {
                        return --m_ptr;
                    }
                    iterator operator--( int )
                    {
                        iterator temp( *this );
                        --m_ptr;
                        return temp;
                    }
                    bool operator==( const iterator& rhs ) const
                    {
                        return m_ptr == rhs.m_ptr;
                    }
                    bool operator!=( const iterator& rhs ) const
                    {
                        return m_ptr != rhs.m_ptr;
                    }

                    /*
                    operator +=
                    operator -=
                    operator+
                    operator-
                    */

                private:
                    pointer m_ptr;
            };
            class const_iterator
            {
                private:
            };


            /// Basic constructor
            array( void )
            {
                m_size = SIZE; // stores the array size.
            }
            ~array( ) = default;

            array( const array& original )
            {
                // Copy all elements of original into 'this'.
                std::copy( &original.m_data[0], &original.m_data[original.m_size],
                           &m_data[0] );
                m_size = original.m_size;
            }

            array( const std::initializer_list<T> & il )
            {
                // Copy all elements of original into 'this'.
                std::copy( il.begin(), il.end(), &m_data[0] );
                /*
                auto i(0);
                for ( const auto & e : il )
                    m_data[i++] = e;
                    */

                m_size = il.size();
            }

            iterator begin( void )
            {
                return iterator( &m_data[0] );
                //return iterator( m_data );
            }

            iterator end( void )
            {
                return iterator( &m_data[m_size] );
            }

            reference operator[]( size_type pos )
            {
                return m_data[pos];
            }
            reference at( size_type pos )
            {
                if ( pos < 0 or pos >= m_size )
                    throw std::out_of_range("[array::at()] Acesso fora dos limites do vetor." );

                return m_data[pos];
            }

            size_type size( void ) const
            {
                return m_size;
            }

            bool empty( void ) const
            {
                return m_size == 0;
                //return begin() == end();
            }

            bool operator==( const array<T,SIZE>& rhs ) const 
            {
                if( m_size != rhs.m_size ) return false;
                return std::equal( &rhs.m_data[0], &rhs.m_data[m_size], &m_data[0] );
            }

            // Copy constructor
            friend std::ostream& operator<<( std::ostream& os, const sc::array<T,SIZE>& a )
            {
                os << "[ ";
                for( auto i(0u) ; i < a.m_size ; ++i )
                    //for ( sc::array::iterator it = a.begin() ; it != a.end() ; ++it )
                    // std::cout << *it << " ";
                    os << a.m_data[i] << " ";
                os << "]";
                return os;
            }

        //private:
            size_type m_size; //!< Stores the array size.
            value_type m_data[ SIZE ]; //!< The storage area.
    };

}

#include "vector.inl"

#endif