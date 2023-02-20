#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
    protected:
        typedef Iterator iterator_type;
        typedef typename iterator_traits<Iterator>::value_type value_type;
        typedef typename iterator_traits<Iterator>::pointer pointer;
        typedef typename iterator_traits<Iterator>::reference reference;
        Iterator It;

    public:
        reverse_iterator() : It(nullptr) {}
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
        bool operator==(const reverse_iterator &rhs) const { return (It == rhs.It); }
        bool operator!=(const reverse_iterator &rhs) const { return (It != rhs.It); }
        reference operator*() const {
            iterator_type temp = It;
            return (*temp);
        }
        pointer operator->() const { return &(operator*()); }
    };
}

#endif