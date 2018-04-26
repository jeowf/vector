#include <vector.h>

namespace edb {
  ///ITERATOR
  Vector::Iterator::Iterator( pointer ptr=nullptr ) : m_ptr( ptr )
  { /* empty */ }

  /// Destructor
  Vector::Iterator::~Iterator() = default;

  /// Copy constructor
  Vector::Iterator::Iterator( const Iterator& itr ) : m_ptr( itr.m_ptr )
  { /* empty */ }

  /// Assign operator
  Vector::Iterator& Vector::Iterator::operator=( const Iterator& rhs )
  {
      m_ptr = rhs.m_ptr;
  }

  Vector::Iterator::reference Vector::Iterator::operator* ( void ) const
  {
      return *m_ptr;
  }
  // ++it
  Vector::IteratorVector::Iterator::operator++()
  {
      return ++m_ptr;
  }

  // it++
  Vector::Iterator Vector::Iterator::operator++( int )
  {
      // V. 1
      Iterator temp( *this );
      ++m_ptr;
      return temp;

      // V. 2
      pointer temp2 = m_ptr;
      ++m_ptr;
      return Iterator( temp2 );

      // V. 3
      return m_ptr++;

      // V. 4
      ++m_ptr;
      return m_ptr-1;
  }
  // --it
  Vector::Iterator:: Vector::Iterator::operator--()
  {
      return --m_ptr;
  }
  Vector::Iterator:: Vector::Iterator::operator--( int )
  {
      Iterator temp( *this );
      --m_ptr;
      return temp;
  }
  bool Vector::Iterator::operator==( const Iterator& rhs ) const
  {
      return m_ptr == rhs.m_ptr;
  }
  bool Vector::Iterator::operator!=( const Iterator& rhs ) const
  {
      return m_ptr != rhs.m_ptr;
  }


  /// VECTOR
  Vector::Vector( void )

      m_size = SIZE; // stores the array size.
  }
  Vector::~Vector( );

  Vector::Vector( const array& original )
  {
      // Copy all elements of original into 'this'.
      std::copy( &original.m_data[0], &original.m_data[original.m_size],
                 &m_data[0] );
      m_size = original.m_size;
  }

  Vector( const std::initializer_list<T> & il )
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

  Iterator begin( void )
  {
      return Iterator( &m_data[0] );
      //return Iterator( m_data );
  }

  Iterator end( void )
  {
      return Iterator( &m_data[m_size] );
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
          //for ( sc::array::Iterator it = a.begin() ; it != a.end() ; ++it )
          // std::cout << *it << " ";
          os << a.m_data[i] << " ";
      os << "]";
      return os;
  }


}
