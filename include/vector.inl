#include <vector.h>

namespace sc {

    //contrutor padrão
    template <typename T>
    vector<T>::vector( void ) : m_end(DEFAULT_SIZE), 
                                m_capacity(DEFAULT_SIZE), 
                                m_storage(new T[DEFAULT_SIZE]) { }


    //contrutor iniciado com os elementos de uma lista
    template <typename T>
    vector<T>::vector( const std::initializer_list<T> il ) : m_end(il.size()), 
                                                             m_capacity(il.size()), 
                                                             m_storage(new T[il.size()]){
        //copia os elementos da lista para vetor
        std::copy( il.begin(), il.end(), &m_storage[0] );

    }

    //destrutor
    template <typename T>
    vector<T>::~vector( void ){
        //destroi todos os elementos de m_storage
        for (size_type i = 0; i < m_capacity; i++)
            m_storage[i].~T();
        
        //deleta o vetor
        delete [] m_storage;
    }

    //construtor cópia
    template <typename T>
    vector<T>::vector( const vector& other ) {
        //copia todos os elementos de 'other' para o novo vetor
        std::copy( &other.m_storage[0], &other.m_storage[other.m_end],
                 &m_storage[0] );
        //copia o ultimo elemento e a capacidade de 'other'
        m_end = other.m_end;
        m_capacity = other.m_capacity;

    }

    //construtor por intervalo
    template <typename T> 
    template <typename InputItr>
    vector<T>::vector ( InputItr first, InputItr last) {
        size_type s = last - first;
        
        m_end = s;
        m_capacity = s;
        m_storage = new T[s];

        size_type i = 0;

        // copia os elementos do intervalo para o vetor m_storage
        while (first != last){
            m_storage[i++] = *first;
            first++;
        }

    }

    //sobrecarga do operador=
    template <typename T>
    vector<T>& vector<T>::operator= (const vector & rhs){
        //redimensiona o vetor
        reserve(rhs.m_capacity);

        //copia elementos de rhs para m_storage
        m_end = rhs.m_end;
        std::copy(&rhs.m_storage[0], &rhs.m_storage[m_end], &m_storage);

        return *this;
    }

    template <typename T>
    vector<T>& vector<T>::operator= (vector & rhs){
        //redimensiona o vetor
        reserve(rhs.m_capacity);

        //copia elementos de rhs para m_storage
        m_end = rhs.m_end;
        std::copy(&rhs.m_storage[0], &rhs.m_storage[m_end], &m_storage);

        return *this;
    }

    //retorna um iterator para o início do vetor
    template <typename T>
    typename vector<T>::iter vector<T>::begin(){
        return iter( &m_storage[0] );
    }

    //retorna um iterator para o final do vetor
    template <typename T>
    typename vector<T>::iter vector<T>::end(){
        return iter( &m_storage[m_end] );
    }

    //retorna um iterator constante para o início do vetor
    template <typename T>
    typename vector<T>::c_iter vector<T>::cbegin(){
        return c_iter( &m_storage[0] );
    }

    //retorna um iterator constante para o final do vetor
    template <typename T>
    typename vector<T>::c_iter vector<T>::cend(){
        return c_iter( &m_storage[m_end] );
    }

    //retorna o tamanho lógico do vetor
    template <typename T>
    typename vector<T>::size_type vector<T>::size( void ) const{
        return m_end;
    }

    //retorna a capacidade do vetor
    template <typename T>
    typename vector<T>::size_type vector<T>::capacity( void ) const{
        return m_capacity;
    }

    //verifica se o vetor está vazio ou nao
    template <typename T>
    bool vector<T>::empty ( void ) const{
        return (m_capacity == 0);
    }

    //limpa o vetor
    template <typename T>
    void vector<T>::clear( void ){
        //caso o vetor esteja vazia, então não será possível dar clear
        if (empty())
            throw std::runtime_error("Vector is empty!");

        //destroi todos elementos do vetor
        for (size_type i = 0; i < m_end; i++)
            m_storage[i].~T();

        //reseta o tamanho logico do vetor
        m_end = 0;

    }

    //insere um elemento no inicio do vetor
    template <typename T>
    void vector<T>::push_front (c_ref value){
        //verifica se há espaço para adicionar o vetor
        //caso não haja, o vetor será redimensionado
        if ( empty() )
            reserve(1);
        else if (m_end == m_capacity)
            reserve(m_capacity * 2);

        //move os elementos do vetor para a direita
        for (size_type i = m_end+1; i > 0; i--){
            m_storage[i] = m_storage[i - 1];
        }

        //adiciona o elemento no início
        m_storage[0] = value;
        m_end++;
    }

    //insere um elemento no fim do vetor
    template <typename T>
    void vector<T>::push_back (c_ref value){
        //verifica se há espaço para adicionar o vetor
        //caso não haja, o vetor será redimensionado
        if ( empty() )
            reserve(1);
        else if (m_end == m_capacity)
            reserve(m_capacity * 2);

        //adiciona o elemento ao final do vetor
        m_storage[m_end++] = value;
    }

    //apaga um elemento na frente do vetor
    template <typename T>
    void vector<T>::pop_front( void ){
        //verifica se o vetor está vazia e dispara uma exceção caso esteja
        if (m_end == 0)
            throw std::runtime_error("Vector is empty!");

        //move os elementos para a direita
        for (size_type i = 0; i < m_end-1; i++)
            m_storage[i] = m_storage[i+1];

        // destroi o ultimo elemento
        m_storage[m_end-1].~T();
        m_end--;
        
    }

    //apaga o ultimo elemento do vetor
    template <typename T>
    void vector<T>::pop_back( void ){
        //verifica se o vetor está vazia e dispara uma exceção caso esteja
        if (m_end == 0)
            throw std::runtime_error("Vector is empty!");

        //destroi o ultimo elemento e diminui o tamanho logico
        m_storage[m_end-1].~T();
        m_end--;
    }

    //insere um elemento em uma posição dada no vetor
    template <typename T>
    typename vector<T>::iter vector<T>::insert(iter pos, c_ref value){
        typename vector<T>::iter temp = iter (&m_storage[0]);
        size_type cont = 0;

        //verifica se há espaço no vetor e redimensiona, caso não haja
        if (empty())
            reserve(1);
        else if (m_end == m_capacity)
            reserve(m_capacity*2);

        //procura índice numérico de pos
        while( temp != pos){
          temp++;
          cont++;
        }

        //move elementos para a direita
        for (size_type i = m_end; i > cont; i--){
            m_storage[i] = m_storage[i - 1];
        }
        
        //adiciona o valor desejado na posição especificada
        m_storage[cont] = value;
        m_end++;

        //retorna posição onde o elemento foi adicionado
        return iter(&m_storage[cont]);
    }

    //insere um intervalo de elementos no vetor
    template <typename T>
    template <typename InputItr>
    typename vector<T>::iter vector<T>::insert(iter pos, InputItr first, InputItr last){
        typename vector<T>::iter temp = iter (&m_storage[0]);
        size_type cont = 0;
        size_type array_size =last - first;

        //verifica se há espaço no vetor e redimensiona, caso não haja
        if (empty())
            reserve(array_size);
        else if ((m_end + array_size) >= m_capacity)
            reserve(m_capacity*2);

        //procura índice numérico de pos
        while( temp != pos){
          temp++;
          cont++;
        }

        //incrementa tamanho lógico
        m_end += array_size;
        
        //move os elementos que estão no intervalo para a direita
        for (size_type i = m_end; i > array_size + cont; i--){
            m_storage[i] = m_storage[i - array_size - 1];
        }

        //insere os elementos do intervalo no espaço liberado
        for (size_type j = 0; j < array_size; j++){
            m_storage[cont+j] = *(first + j);
        }

        //retorna posição onde o elemento foi adicionado
        return iter(&m_storage[cont]);
    }

    //insere uma lista em uma posição do vetor
    template <typename T>
    typename vector<T>::iter vector<T>::insert(iter pos, std::initializer_list<T> l){
        typename vector<T>::iter temp = iter (&m_storage[0]);
        size_type cont = 0;
        size_type total = l.size();

        //verifica se há espaço no vetor e redimensiona, caso não haja
        if (empty())
            reserve(1);
        else if (m_end + total >= m_capacity)
            reserve(m_capacity + total);

        //procura índice numérico de pos
        size_type a =  pos != iter (&m_storage[0]) ;
        while( temp != pos){
          temp++;
          cont++;
        }

        //incrementa tamanho lógico do vetor
        m_end +=total;

        //move os elementos que estão no intervalo para a direita
        for (size_type i = m_end; i >total+ cont; i--){
            m_storage[i - 1] = m_storage[i - total - 1];
        }

        //insere os elementos do intervalo no espaço liberado
        for (size_type j = 0; j < l.size(); j++){
            m_storage[cont+j] = *(l.begin()+j);
        }

        //retorna posição onde o elemento foi adicionado
        return iter(&m_storage[cont]);
    }


    //redimensiona vetor
    template <typename T>
    void vector<T>::reserve (size_type new_cap){
        //cria um vetor temporário de capacidade  maior
        T* temp = new T[new_cap];

        //ove os elementos do vetor antigo pro temporario
        for (size_type i = 0; i < m_end; i++)
            temp[i] = m_storage[i];
        
        // deleta o vator antigo
        delete [] m_storage;

        //copia os valores de capacidade e tamanho
        m_capacity = new_cap;

        //substitui vetores
        m_storage = temp;
    }

    //redimensiona vetor com base no tamanho lógico
    template <typename T>
    void vector<T>::shrink_to_fit (void){
        //cria um vetor temporário com o tamanho lógico
        T* temp = new T[m_end];

        //copia os elementos do vetor antigo pro temporário
        for (size_type i = 0; i < m_end; i++)
            temp[i] = m_storage[i];
        
        //deltea vetor antigo
        delete [] m_storage;

        //copia os valores de capacidade e tamanho
        m_storage = temp;

        //substitui vetores
        m_capacity = m_end;
    }

    //preenche todo o vetor com um valor
    template <typename T>
    void vector<T>::assign (c_ref value){
      for(size_type i = 0; i < m_capacity ; i++){
          m_storage[i] = value;
      }
    }

    //preenche todo o vetor com uma lista
    template <typename T>
    void vector<T>::assign (std::initializer_list<T> l){
      reserve(l.size());
      for(size_type i = 0;i < l.size(); i++){
        m_storage[i] = *(l.begin()+i);
      }
    }

    //preenche todo o vetor com os elementos de um intervalo
    template <typename T>
    template <typename InputItr>
    void vector<T>::assign (InputItr first, InputItr last){
      size_type size = last - first;
      reserve(size);
      for(size_type i = 0;i < size; i++){
        m_storage[i] = first+i;
      }
    }

    //apaga os elementos no vetor dentro de um intervalo
    template <typename T>
    typename vector<T>::iter vector<T>::erase(iter first,iter last){
        typename vector<T>::iter temp = iter (&m_storage[0]);
        size_type cont = 0;
        size_type array_size = last - first;

        //encontra índice do início do intervalo
        while( temp != first){
            temp++;
            cont++;
        }

        //destroi elementos do intervalo
        for (size_type j = 0; j < array_size; j++)
            m_storage[cont+j].~T();
        
        //move os elementos para a esquerda
        for (size_type i = cont; i < cont+array_size ; i++)
            m_storage[i] = m_storage[i + array_size];
        
        //decrementa tamanho logico
        m_end -= array_size;

        //retorna iterador da última posição valida
        return iter(&m_storage[m_end]);
    }

    template <typename T>
    typename vector<T>::iter vector<T>::erase(iter pos){
        typename vector<T>::iter temp = iter (&m_storage[0]);
        size_type cont = 0;

        //encontra o índice numérico
        while( temp != pos){
          temp++;
          cont++;
        }

        //destroi o elemento na posição dada
        m_storage[cont].~T();

        //move os elementos para a esquerda
        for (size_type i = cont; i < m_end; i++){
            m_storage[i] = m_storage[i + 1];
        }

        //decrementa tamanho logico
        m_end--;

        //retorna iterador da última posição valida
        return iter(&m_storage[m_end]);
    }

    //retorna o último elemento do vetor
    template <typename T>
    typename vector<T>::c_ref vector<T>::back (void) const{
         return m_storage[m_end - 1];
    }

    //retorna o primeiro elemento do vetor
    template <typename T>
    typename vector<T>::c_ref vector<T>::front (void) const{
         return m_storage[0];
    }

    //retorna o elemento na posição dada
    template <typename T>
    typename vector<T>::c_ref vector<T>::operator[] (size_type pos) const{
        return m_storage[pos];
    }

    //retorna o elemento na posição dada
    template <typename T>
    typename vector<T>::ref vector<T>::operator[] (size_type pos){
        return m_storage[pos];
    }

    //retorna o elemento na posição dada, porém trata exceções casa o
    //vetor esteja vazio ou o índice esteja fora do intervlao do vetor
    template <typename T>
    typename vector<T>::c_ref vector<T>::at (size_type pos) const{
        if(empty())
            throw std::runtime_error("Vector is empty");
      
        else if(pos < 0 or pos > m_end)
            throw std::out_of_range("Index out of range");
      
        return m_storage[pos];
      
    }

    //retorna o elemento na posição dada, porém trata exceções casa o
    //vetor esteja vazio ou o índice esteja fora do intervlao do vetor
    template <typename T>
    typename vector<T>::ref vector<T>::at (size_type pos){
        if( empty() )
            throw std::runtime_error("Vector is empty");

        else if(pos < 0 or pos > m_end)
            throw std::out_of_range("Index out of range");

        return m_storage[pos];
    }

    //verifica se dois vetores são iguais
    template <typename T>
    bool vector<T>::operator== (const vector & v) const{
        //se a capacidade for diferente, os vetores sao diferentes
        if( this->m_capacity != v.m_capacity){
            return false;
        }else{
            //verifica algum elemento é diferente
            //caso sim, retorna false
            //caso nao, retorna true
            for (int i = 0; i < this->m_capacity; i++){
                if (this->m_storage[i] != v.m_storage[i]){
                    return false;
                } 
            }
        }          
        return true;
    }

    //verifica se dois vetores são iguais
    template <typename T>
    bool vector<T>::operator!= (const vector & v) const{
        //se a capacidade for diferente, os vetores sao diferentes
        if( this->m_capacity != v.m_capacity){
            return true;
        }else{
            //verifica algum elemento é diferente
            //caso sim, retorna true
            //caso nao, retorna false
            for (int i = 0; i < this->m_capacity; i++){
                if (this->m_storage[i] != v.m_storage[i]){
                    return true;
                } 
            }
        }          
        return false;
    }

    //imprime o vetor
    template <typename U>
    std::ostream & operator<<( std::ostream & os_, const vector<U> & v_ ){
        std::cout << "[ ";

        //percorre o vetor e imprime seus elementos
        for (typename vector<U>::size_type i = 0; i < v_.size(); i++)
            std::cout << v_[i] << " ";
        std::cout << "]";

        //retorna a stream de output
        return os_;

    }

}
