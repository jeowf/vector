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
        * Overload '*' operator to take the current element const in list
        *
        * @return Return a const reference to the object in the position poited by the iterator
        */
        const T& operator* (void) const;
        /*! 
        * @brief '*' Overload
        *
        * Overload '*' operator to take the current element in list
        *
        * @return Return a reference to the object in the position poited by the iterator
        */
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
        /*! 
        * @brief '-' Overload
        *
        * Overload '-' operator to verify the diference beetwen two iterators
        *
        * @return Return the diference beetwen two iterators
        */
        size_type operator-( const MyIterator & );
        /*! 
        * @brief '+' Overload
        *
        * Overload '+' operator to increse a iterator position
        *
        * @return Return the iterator position with increase position
        */
        MyIterator operator+( const int & );

    private: 
        T *current; /*!< Variable to storage the current element in the list */ 
    };

}

#include "iterator.inl"

#endif
