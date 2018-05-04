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
    vector<T>& vector<T>::operator= (const vector & rhs){
        reserve(rhs.m_capacity);

        for (size_type i = 0; i < m_capacity; i++)
            m_storage[i] = rhs.m_storage[i];

        return *this;
    }

    template <typename T>
    vector<T>& vector<T>::operator= (vector & rhs){
        reserve(rhs.m_capacity);

        for (size_type i = 0; i < m_capacity; i++)
            m_storage[i] = rhs.m_storage[i];

        return *this;
    }

    template <typename T>
    typename vector<T>::size_type vector<T>::size( void ) const{
        return m_end;
    }

    template <typename T>
    typename vector<T>::size_type vector<T>::capacity( void ) const{
        return m_capacity;
    }

    template <typename T>
    bool vector<T>::empty ( void ) const{
        return (m_capacity == 0);
    }

    template <typename T>
    void vector<T>::push_front (c_ref value){
        if ( empty() )
            reserve(1);
        else if (m_end == m_capacity)
            reserve(m_capacity * 2);

        // move os elementos para a frente do vetor
        for (size_type i = m_end+1; i > 0; i--){
            m_storage[i] = m_storage[i - 1];
        }

        m_storage[0] = value;
        m_end++;
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
    void vector<T>::pop_front( void ){
        if (m_end == 0)
            throw std::runtime_error("Stack is empty!");

        for (size_type i = 0; i < m_end-1; i++)
            m_storage[i] = m_storage[i+1];

        m_storage[m_end-1].~T();
        m_end--;
        
    }

    template <typename T>
    void vector<T>::pop_back( void ){
        if (m_end == 0)
            throw std::runtime_error("Stack is empty!");
        m_storage[m_end-1].~T();
        m_end--;
    }

    template <typename T>
    void vector<T>::reserve (size_type new_cap){
        T* temp = new T[new_cap];

        for (size_type i = 0; i < m_end; i++)
            temp[i] = m_storage[i];
        
        delete [] m_storage;

        m_capacity = new_cap;
        m_storage = temp;
    }

    template <typename T>
    typename vector<T>::c_ref vector<T>::operator[] (size_type pos) const{
        return m_storage[pos];
    }

    template <typename T>
    typename vector<T>::ref vector<T>::operator[] (size_type pos){
        return m_storage[pos];
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

    template <typename U>
    std::ostream & operator<<( std::ostream & os_, const vector<U> & v_ ){
        std::cout << "[ ";

        for (typename vector<U>::size_type i = 0; i < v_.size(); i++)
            std::cout << v_[i] << " ";
        std::cout << "]";

        return os_;

    }

            
}
