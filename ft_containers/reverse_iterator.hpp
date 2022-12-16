#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "vector.hpp"
#include "iterators.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
    protected:
        typedef Iterator iterator_type;
        Iterator It;

    public:
        explicit reverse_iterator(const iterator_type x) : It(x){};
        reverse_iterator &operator++()
        {
            --It;
            return *this;
        }
        reverse_iterator operator++(int)
        {
            reverse_iterator tmp(*this);
            operator++();
            return tmp;
        }
        reverse_iterator &operator--()
        {
            ++It;
            return *this;
        }
        reverse_iterator operator--(int)
        {
            reverse_iterator tmp(*this);
            operator--();
            return tmp;
        }
        reverse_iterator operator+(int other)
        {
            It = It - other;
            return *this;
        }
        reverse_iterator operator-(int other)
        {
            It = It + other;
            return *this;
        }
        int &operator*() { return (*It); }
    };
}

#endif