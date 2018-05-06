#include <vector.h>

namespace sc {

    template <typename T>
    vector<T>::vector( void ) : m_end(DEFAULT_SIZE), 
                                m_capacity(DEFAULT_SIZE), 
                                m_storage(new T[DEFAULT_SIZE]) { }
    
    template <typename T>
    vector<T>::~vector( void ){
        for (size_type i = 0; i < m_capacity; i++)
            m_storage[i].~T();

        delete [] m_storage;
    }

    template <typename T>
    vector<T>::vector( const vector& other ) {
        // Copy all elements of other into 'this'.
        std::copy( &other.m_storage[0], &other.m_storage[other.m_end],
                 &m_storage[0] );
        m_end = other.m_end;
    }

    template <typename T>
    vector<T>::vector(vector && other){
      m_capacity = other.m_capacity;
      m_storage = new T[m_capacity];
      for (size_type i = 0; i < other.m_end; i++){
        m_storage[i] = std::move(other.m_storage[i]);
      }
      m_end = other.m_end;
      other.assign(0);
      other.m_capacity = 0;
      other.m_end = 0;
    }

    template <typename T>
    bool vector<T>::empty ( void ) const{
        return (m_capacity == 0);
    }

    template <typename T>
    void vector<T>::push_back (c_ref value){
        if ( empty() )
            reserve(1);
        else if (m_end == m_capacity)
            reserve(m_capacity * 2);

        m_storage[m_end++] = value;
    }
    
    template <typename T>
    typename vector<T>::iter vector<T>::insert(iter pos, c_ref value){
        typename vector<T>::iter temp = iter (&m_storage[0]);
        size_type cont = 0;
        if (empty())
            reserve(1);
        else if (m_end == m_capacity)
            reserve(m_capacity*2);

        while( temp != pos){
          temp++;
          cont++;
        }
        for (size_type i = m_end; i > cont; i--){
            m_storage[i] = m_storage[i - 1];
        }
        

        m_storage[cont] = value;
        m_end++;

        return iter(&m_storage[cont]);
    }

    template <typename T>
    template <typename InputItr>
    typename vector<T>::iter vector<T>::insert(iter pos, InputItr first, InputItr last){
        typename vector<T>::iter temp = iter (&m_storage[0]);
        size_type cont = 0;
        size_type array_size =last - first;
        if (empty())
            reserve(1);
        else if (m_end == m_capacity)
            reserve(m_capacity*2);

        while( temp != pos){
          temp++;
          cont++;
        }
        m_end += array_size;
        for (size_type i = m_end; i > array_size + cont; i--){
            m_storage[i] = m_storage[i - array_size - 1];
        }

        for (size_type j = 0; j < array_size; j++){
            m_storage[cont+j] = first + j;
        }

        return iter(&m_storage[cont]);
    }

    template <typename T>
    typename vector<T>::iter vector<T>::insert(iter pos, std::initializer_list<T> l){
    typename vector<T>::iter temp = iter (&m_storage[0]);
        size_type cont = 0;
        size_type total = l.size();
        if (empty())
            reserve(1);
        else if (m_end == m_capacity)
            reserve(m_capacity*2);

        size_type a =  pos != iter (&m_storage[0]) ;
        while( temp != pos){
          temp++;
          cont++;
        }
        m_end +=total;
        for (size_type i = m_end; i >total+ cont; i--){
            m_storage[i - 1] = m_storage[i - total - 1];
        }

        for (size_type j = 0; j < l.size(); j++){
            m_storage[cont+j] = *(l.begin()+j);
        }

        return iter(&m_storage[cont]);
    }


    template <typename T>
    void vector<T>::reserve (size_type new_cap){
        T* temp = new T[new_cap];

        for (size_type i = 0; i < m_end; i++)
            temp[i] = m_storage[i];
        
        delete [] m_storage;

        m_storage = temp;
        m_capacity = new_cap;
    }

    template <typename T>
    void vector<T>::shrink_to_fit (void){
        T* temp = new T[m_end];

        for (size_type i = 0; i < m_end; i++)
            temp[i] = m_storage[i];
        
        delete [] m_storage;

        m_storage = temp;
        m_capacity = m_end;
    }
    template <typename T>
    void vector<T>::assign (c_ref value){
      for(size_type i = 0; i < m_capacity ; i++){
          m_storage[i] = value;
      }
    }

    template <typename T>
    void vector<T>::assign (std::initializer_list<T> l){
      reserve(l.size());
      for(size_type i = 0;i < l.size(); i++){
        m_storage[i] = *(l.begin()+i);
      }
    }

    template <typename T>
    template <typename InputItr>
    void vector<T>::assign (InputItr first, InputItr last){
      size_type size = last - first;
      reserve(size);
      for(size_type i = 0;i < size; i++){
        m_storage[i] = first+i;
      }
    }

    template <typename T>
    typename vector<T>::c_ref vector<T>::back (void) const{
         return m_storage[m_end - 1];
    }

    template <typename T>
    typename vector<T>::c_ref vector<T>::front (void) const{
         return m_storage[0];
    }

    template <typename T>
    typename vector<T>::c_ref vector<T>::operator[] (size_type pos) const{
        return m_storage[pos];
    }

    template <typename T>
    typename vector<T>::ref vector<T>::operator[] (size_type pos){
        return m_storage[pos];
    }

    template <typename T>
    typename vector<T>::c_ref vector<T>::at (size_type pos) const{
      if(empty() == true){
          throw std::runtime_error("Stack is empty");
      }
      else if(pos < 0 or pos > m_end){
         throw std::runtime_error("Index out of range");
      }
      else{
         return m_storage[pos];
      }
    }

    template <typename T>
    typename vector<T>::ref vector<T>::at (size_type pos){
      if(empty()){
        throw std::runtime_error("Stack is empty");
      }
      else if(pos < 0 or pos > m_end){
        throw std::runtime_error("Index out of range");
      }
      else{
        return m_storage[pos];
      }
    }

    template <typename T>
    bool vector<T>::operator== (const vector & v) const{
      if( this->m_capacity != v.m_capacity){
           return false;
      }else{
        for (int i = 0; i < this->m_capacity; i++){
          if (this->m_storage[i] != v.m_storage[i]){
            return false;
          } 
        }
      }          
      return true;
    }

    template <typename T>
    bool vector<T>::operator!= (const vector & v) const{
      if( this->m_capacity != v.m_capacity){
           return true;
      }else{
        for (int i = 0; i < this->m_capacity; i++){
          if (this->m_storage[i] != v.m_storage[i]){
            return true;
          } 
        }
      }          
      return false;
    }

  // vector::vector( const array& original )
  // {
  //     // Copy all elements of original into 'this'.
  //     std::copy( &original.m_data[0], &original.m_data[original.m_size],
  //                &m_data[0] );
  //     m_size = original.m_size;
  // }

  // vector( const std::initializer_list<T> & il )
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

    // VEC_SIG
    // vector<T, SIZE>::vector( void ) : m_size (SIZE) { }

    // VEC_SIG
    // vector<T, SIZE>::vector( const vector& original ) {
    //     // Copy all elements of original into 'this'.
    //     std::copy( &original.m_data[0], &original.m_data[original.m_size],
    //                &m_data[0] );
    //     m_size = original.m_size;
    // }
            
}
