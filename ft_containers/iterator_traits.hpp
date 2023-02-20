#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include "iterators.hpp"

namespace ft
{
    template <class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::difference_type difference_type;
        typedef typename Iterator::value_type value_type;
        typedef typename Iterator::pointer pointer;
        typedef typename Iterator::reference reference;
        typedef typename Iterator::iterator_category iterator_category;
    };
    // template <class T>
    // class iterator_traits<T *>
    // {
    //     typedef T Iterator::value_type;
    //     typedef T* Iterator::pointer;
    //     typedef T& Iterator::reference;
    // }
    // template <class T>
    // class iterator_traits<const T *>
    // {
    //     typedef const T* Iterator::pointer;
    //     typedef const T& Iterator::reference;
    // }
}
#endif