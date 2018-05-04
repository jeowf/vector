#ifndef VECTOR
#define VECTOR

#include <iostream>
#include <stdexcept>
#include <initializer_list>


#include "iterator.h"

namespace sc{
    
    template <typename T>
    /*! @class vector
     *
     * @brief A class that manages actions on a dinamic list
    */
    class vector{
    	
    public:
        using size_type = size_t;                   /*!< aaaa */

        const static size_type DEFAULT_SIZE = 0;    /*!< Variable to storage the default size of vector */ 

        using iter     = sc::MyIterator<T>;         /*!< Variable to store a iterator */ 
        using c_iter   = sc::MyIterator<const T>;   /*!< Variable to store an iterator that cannot be modified */ 
        using ref      = T&;                        /*!< Variable to store an iterator reference*/ 
        using c_ref    = const T&;                  /*!< Variable to store an iterator reference that cannot be modified  */ 
        using pointer  = sc::MyIterator<T>*;        /*!< Vamos descobrir */ 

        // SPECIAL MEMBERS

        /*! 
        * @brief Vector Constructor
        *
        * Initializes the vector with a empty list 
        */
        vector( void );

        vector( const std::initializer_list<T> il );
        
        /*! 
        * @brief Vector Destructor
        *
        * Destructs the list
        */
        ~vector( void );

        /*! 
        * @brief Vector Constructor
        *
        * Initializes the vector with the elements of other 
        *
        *@param other vector object   
        */
        vector (const vector &);

        /*! 
        * @brief Vector Constructor
        *
        * Initializes move contructor to "steal" the resources held by the argument 
        *
        *@param arg vector object   
        */
    //  vector (vector &&);


        /*! 
        * @brief Vector Constructor
        *
        * Initializes contructor with the content of the range [first, last)
        *
        *@param first begin of range
        *@param last end of range    
        */
        
        template <typename InputItr>
        vector ( InputItr, InputItr);

        /*! 
        * @brief '=' Overload
        *
        * Overload '=' operator to replace the content with the copy of the content of other
        *
        * @param rhs const vector object 
        *
        * @return Return the new content from other
        */ 
        vector & operator= (const vector &);

        /*! 
        * @brief '=' Overload
        *
        * Overload '=' operator to replace the content with the copy of the alterable content of other
        *
        * @param rhs vector object 
        *
        * @return Return the new content from other
        */ 
        vector & operator= (vector &);

        // ITERATORS

        /*! 
        * @brief Begin
        *
        * Sets the first item in the list like begin of list
        *
        * @return Returns an iterator pointing to the first item in the list
        */ 
        iter begin( void );

        /*! 
        * @brief End
        *
        * Sets the item after last element in the list like end of list
        *
        * @return Returns an iterator pointing to the end mark in the list
        */ 
        iter end( void );

        /*! 
        * @brief Const Begin
        *
        * Sets the first item in the list like begin of list and constant
        *
        * @return Returns a constant iterator pointing to the first item in the list
        */ 
        c_iter cbegin( void );

        /*! 
        * @brief Const End
        *
        * Sets the item after last element in the list Sets the item after last element in the list like end of list and constant 
        *
        * @return returns a constant iterator pointing to the end mark in the list
        */  
        c_iter cend ( void );

        // CAPACITY

        /*! 
        * @brief Size
        *
        * Contain the number of elements on the list
        *
        * @return Return the number of elements in the container.
        */ 
        size_type size( void ) const;

        /*! 
        * @brief Capacity
        *
        * Calcules the capacity of list
        *
        * @return Return the internal storage capacity of the array
        */ 
        size_type capacity( void ) const;
        
        /*! 
        * @brief Empty
        *
        * Verifies if the list is empty 
        *
        * @return Return true if the container contains no elementsr
        */ 
        bool empty ( void ) const;

        /*! 
        * @brief Clear
        *
        * Remove all elements from the container
        */ 
        void clear ( void );

        /*! 
        * @brief Push Front
        *
        * Adds value to the front of the list
        *
        * @param value value to be added
        *
        */ 
        void push_front ( c_ref );
        
        /*! 
        * @brief Push Back
        *
        * Adds value to the end of the list
        *
        * @param value value to be added
        *
        */  
        void push_back ( c_ref );

        /*! 
        * @brief Pop Front
        *
        * Removes the object at the front of the list
        *
        */  
        void pop_front( void );
        
        /*! 
        * @brief Pop back
        *
        * Removes the object at the endif of the list
        *
        */ 
        void pop_back( void );

        /*! 
        * @brief Insert
        *
        * Adds value into the list before the position given by the iterator pos
        *
        * @param pos iterator object 
        * @param value value to be added 
        *
        * @return Returns an iterator to the position of the inserted item.
        */
        iter insert(iter, c_ref);

        /*! 
        * @brief Insert
        *
        * inserts elements from the range [first; last) before pos
        *
        * @param pos vector object
        * @param first begin of range
        * @param last end of range
        *
        * @return Returns an iterator to the position of the inserted item
        */
        //template <typename InputItr>
        //iter insert(iter, InputItr, InputItr);

        /*! 
        * @brief Insert
        *
        * Inserts elements from the initializer list ilist before pos
        *
        * @param pos vector object
        * @param ilist list object 
        *
        * @return Returns an iterator to the position of the inserted item
        */

        //iter insert(iter, std::initializator_list <T>);

        /*! 
        * @brief Reserve
        *
        * Increase the storage capacity of the array to a value that’s is greater or equal to new_cap
        *
        * @param new_cap new capacity
        *
        */

        void reserve (size_type);

        /*! 
        * @brief Shrink to Fit
        *
        * Overload '=' operator to replace the content with the copy of the content of other
        *
        * @param other vector object 
        *
        */
        //void shrink_to_fit ( void );

        /*! 
        * @brief Assign
        *
        * Replaces the contents with count copies of value value
        *
        * @param count number os values 
        */
        //void assign (c_ref);

        /*! 
        * @brief Assign
        *
        * Replaces the contents of the list with the elements from the initializer list ilist .
        *
        * @param ilist initializer list
        */
        //void assign (std::initializator_list <T>);
        /*! 
        * @brief Assign
        *
        * Replaces the contents of the list with copies of the elements in the range [first; last) .
        *
        * @param first begin of range
        * @param last end of range
        */
        //template <typename InputItr>
        //void assign (InputItr, InputItr);
           /*! 
        * @brief Erase
        *
        * Removes elements in the range [first; last) 
        *
        * @param first begin of range
        * @param last end of range
        *
        * @return Return the iterator for the next element valid
        */
       // iter erase(iter, iter);
                   /*! 
        * @brief Erase
        *
        * Removes the object at position pos
        *
        * @param pos item to be deleted
        *
        * @return Returns an iterator to the element that follows pos before the call.
        */
        //iter erase (iter);

        // ELEMENT ACCESS

        /*! 
        * @brief Back
        *
        * Element on end of the list 
        *
        * @return Returns the object at the end of the list.
        */
        c_ref back (void) const;

        /*! 
        * @brief Front
        *
        * Element on front of the list 
        *
        * @return Returns the object at the beginning of the list.
        */
        c_ref front (void) const;

        /*! 
        * @brief '[]' Overload
        *
        * Overload '[]' operator to take the object in index seted
        *
        * @param pos index
        *
        * @return Returns the constant object at the index pos in the array,with no bounds-checking.
        */
        c_ref operator[] (size_type) const;

        /*! 
        * @brief '[]' Overload
        *
        * Overload '[]' operator to take the object in index seted
        *
        * @param pos index
        *
        * @return Returns the object at the index pos in the array, with no bounds-checking.
        */
        ref operator[] (size_type);

        /*! 
        * @brief At
        *
        * Take the object in index seted
        *
        * @param pos index
        *
        * @return Returns the constant object at the index pos in the array, with bounds-checking.
        */
        c_ref at (size_type) const;

        /*! 
        * @brief At
        *
        * Take the object in index seted
        *
        * @param pos index
        *
        * @return Returns the object at the index pos in the array,with  bounds-checking.
        */
        ref at (size_type);

        /*! 
        * @brief Data
        *
        * Debbug
        *
        */
        //pointer data ( void ); //qm é pointer
                   /*! 
        * @brief Data
        *
        * Debbug
        *
        */
        //c_ref data (void) const;

        // OPERATORS
        /*! 
        * @brief '==' Overload
        *
        * Overload '==' operator to verify if two vectors are equals
        *
        * @param this vector object 
        *
        * @return Return true if  two vectors are equals
        */
        //bool operator==(const vector & ) const;

        /*! 
        * @brief '!=' Overload
        *
        * Overload '!=' operator to verify if two vectors are differents
        *
        * @param this vector object 
        *
        * @return Return true if  two vectors are differents
        */
        //bool operator!=(const vector & ) const;

        // FRIEND FUNCTIONS

        /*! 
        * @brief '<<' Operator
        *
        * Prints the vector on the out stream
        *
        * @param os reference of output stream
        * @param v_ reference of vector object
        *
        * @return Return ostream output stream
        */

        template <typename U>
        friend std::ostream & operator<<( std::ostream & os_, const vector<T> & v_ );

        /*! 
        * @brief Swap
        *
        * Reverses the position of two elements of the vector
        *
        * @param first vector element
        * @param second vector element
        *
        * @return Return true if  two vectors are differents
        */ 

        //friend void swap( vector<T> & first_, vector<T> & second_ ); 

    private:
        size_type m_end;/*!< Variable to storage the end of vector */ 
        size_type m_capacity;/*!< Variable to storage capacity */ 
        T *m_storage;/*!< Variable to storage the values */ 

    };
}

#include "vector.inl"

#endif
