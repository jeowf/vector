#include <vector.h>

namespace sc {

    template <typename T>
    vector<T>::vector( void ) : m_end(DEFAULT_SIZE), 
                                m_capacity(DEFAULT_SIZE), 
                                m_storage(new T[DEFAULT_SIZE]) { }

    template <typename T>
    vector<T>::vector( const std::initializer_list<T> il ) : m_end(il.size()), 
                                                             m_capacity(il.size()), 
                                                             m_storage(new T[il.size()]){
        //reserve(il.size());

        // Copy all elements of original into 'this'.
        std::copy( il.begin(), il.end(), &m_storage[0] );

        //m_end = il.size();
    }

    
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
    template <typename InputItr>
    vector<T>::vector ( InputItr first, InputItr last) {
        size_type s = last - first;
        
        m_end = s;
        m_capacity = s;
        m_storage = new T[s];

        size_type i = 0;
        while (first != last){
            m_storage[i++] = *first;
            first++;
        }

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
    typename vector<T>::iter vector<T>::begin(){
        return iter( &m_storage[0] );
    }

    template <typename T>
    typename vector<T>::iter vector<T>::end(){
        return iter( &m_storage[m_end] );
    }

    template <typename T>
    typename vector<T>::c_iter vector<T>::cbegin(){
        return c_iter( &m_storage[0] );
    }

    template <typename T>
    typename vector<T>::c_iter vector<T>::cend(){
        return c_iter( &m_storage[m_end] );
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
    void vector<T>::clear( void ){
        if (empty())
            throw std::runtime_error("Vector is empty!");

        for (size_type i = 0; i < m_end; i++)
            m_storage[i].~T();

        m_end = 0;

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
            throw std::runtime_error("Vector is empty!");

        for (size_type i = 0; i < m_end-1; i++)
            m_storage[i] = m_storage[i+1];

        m_storage[m_end-1].~T();
        m_end--;
        
    }

    template <typename T>
    void vector<T>::pop_back( void ){
        if (m_end == 0)
            throw std::runtime_error("Vector is empty!");
        m_storage[m_end-1].~T();
        m_end--;
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

        std::cout << array_size <<"\n";

        if (empty())
            reserve(array_size);
        else if ((m_end + array_size) >= m_capacity)
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
            m_storage[cont+j] = *(first + j);
        }

        //m_end += array_size;

        return iter(&m_storage[cont]);
    }

    template <typename T>
    typename vector<T>::iter vector<T>::insert(iter pos, std::initializer_list<T> l){
        typename vector<T>::iter temp = iter (&m_storage[0]);
        size_type cont = 0;
        size_type total = l.size();

        if (empty())
            reserve(1);
        else if (m_end + total >= m_capacity)
            reserve(m_capacity + total);

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

        m_capacity = new_cap;
        m_storage = temp;
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
        if(empty())
            throw std::runtime_error("Vector is empty");
      
        else if(pos < 0 or pos > m_end)
            throw std::runtime_error("Index out of range");
      
        return m_storage[pos];
      
    }

    template <typename T>
    typename vector<T>::ref vector<T>::at (size_type pos){
        if( empty() )
            throw std::runtime_error("Vector is empty");

        else if(pos < 0 or pos > m_end)
            throw std::runtime_error("Index out of range");

        return m_storage[pos];
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


    template <typename U>
    std::ostream & operator<<( std::ostream & os_, const vector<U> & v_ ){
        std::cout << "[ ";

        for (typename vector<U>::size_type i = 0; i < v_.size(); i++)
            std::cout << v_[i] << " ";
        std::cout << "]";

        return os_;

    }

            
}
