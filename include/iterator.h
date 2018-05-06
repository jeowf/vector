#ifndef ITERATOR
#define ITERATOR

#include <iostream>
#include <iterator> //distance
    /*! @namespace sc
    *
    * @brief Scope of Vector
    */
namespace sc{
 /*! @tparam T
    *
    * @brief Template to class MyIterator
    */
	template <typename T>
   /*! @class MyIterator
     *
     * @brief A class that manage the acess the elements in a list
    */
    class MyIterator { 
    public: 
        using size_type = int;
        /*! @typedef ref
        *
        * @brief Replace all incidences of type MyIterator& to ref
        */
        typedef MyIterator& ref ;

        /*! 
        * @brief MyIterador Constructor
        *
        * Initializes the iterator with null pointer  
        *
        * @param nullptr null pointer
        */

        MyIterator(void); 

        /*! 
        * @brief MyIterador Constructor
        *
        * Initializes the iterator with non-null pointer  
        *
        * @param ptr non-null pointer
        */

        MyIterator(T*); 
        /*! 
        * @brief '*' Overload
        *
        * Overload '*' operator to take the current element in list
        *
        * @return Return a reference to the object in the position poited by the iterator
        */
        const T& operator* (void) const;

        T& operator* (void);

        /*! 
        * @brief '++' Overload
        *
        * Overload '++' operator to advances iterator to the next location within the list
        *
        * @return Return a reference to the object in the position poited by the iterator
        */ 
        MyIterator & operator++ (void);  // ++it; 
        /*! 
        * @brief '++' Overload
        *
        * Overload '++' operator to return the current element in the list and advances iterator to the next location within the list
        *
        * @return Return a reference to the object in the previous position poited by the iterator
        */ 
        MyIterator operator++ (int); // it++; 
        /*! 
        * @brief '--' Overload
        *
        * Overload '--'operator to back iterator to the previous location within the list
        *
        * @return Return a reference to the object in the position poited by the iterator
        */ 
        MyIterator & operator-- (void); // --it;
        /*! 
        * @brief '--' Overload
        *
        * Overload '--' operator to return the current element in the list and back iterator to the previous location within the list
        *
        * @return Return a reference to the object in the previous position poited by the iterator
        */ 
        MyIterator operator-- (int); // it--; 
        /*! 
        * @brief '==' Overload
        *
        * Overload '==' operator to verify if two iterators points to same localization in the list
        *
        * @return Return true if two iterators points to same localization in the list
        */ 
        bool operator== (const MyIterator &) const; 
        /*! 
        * @brief '!=' Overload
        *
        * Overload '!=' operator to verify if two iterators points to differentes localization in the list
        *
        * @return Return true if two iterators points to differentes localization in the list
        */ 
        bool operator!= (const MyIterator &) const; 

        size_type operator-( const MyIterator & );

        MyIterator operator+( const int & );

    private: 
        T *current; /*!< Variable to storage the current element in the list */ 
    };

    template <typename T>
    size_t distance(MyIterator<T> b, MyIterator<T> l){
        size_t dist = b - l;
        if (dist < 0)
            return -1*dist;
        
        return dist;
    }
}

#include "iterator.inl"

#endif
