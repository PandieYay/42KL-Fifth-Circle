#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include "redblacktree.hpp"

namespace ft
{
    template <class Category, class T, class Distance = ptrdiff_t,
              class Pointer = T *, class Reference = T &>
    struct iterator
    {
        typedef T value_type;
        typedef Distance difference_type;
        typedef Pointer pointer;
        typedef Reference reference;
        typedef Category iterator_category;
    };

    struct random_access_iterator_tag
    {
    };
    struct bidirectional_iterator_tag
    {
    };

    template <class T>
    class vecIterator : public ft::iterator<ft::random_access_iterator_tag, T>
    {
    private:
        int *p;

    public:
        vecIterator() : p(nullptr) {}
        vecIterator(int *x) : p(x) {}
        vecIterator(const vecIterator &x) : p(x.p) {}
        vecIterator &operator=(const vecIterator &x)
        {
            p = x.p;
            return *this;
        }
        vecIterator &operator++()
        {
            ++p;
            return *this;
        }
        vecIterator operator++(int)
        {
            vecIterator tmp(*this);
            operator++();
            return tmp;
        }
        vecIterator &operator--()
        {
            --p;
            return *this;
        }
        vecIterator operator--(int)
        {
            vecIterator tmp(*this);
            operator--();
            return tmp;
        }
        vecIterator operator+(int other)
        {
            vecIterator<T> temp = *this;
            temp.p = p + other;
            return (temp);
        }
        vecIterator operator-(int other)
        {
            vecIterator<T> temp = *this;
            temp.p = p - other;
            return (temp);
        }
        size_t operator-(vecIterator other)
        {
            size_t distance = p - other.p;
            return distance;
        }
        bool operator==(const vecIterator &rhs) const { return p == rhs.p; }
        bool operator!=(const vecIterator &rhs) const { return p != rhs.p; }
        int &operator*() { return *p; }
    };

    template <class T>
    class mapIterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
    {
    private:
        T *p;

    public:
        mapIterator() : p(nullptr) {}
        mapIterator(T *x) : p(x) {}
        mapIterator(const mapIterator &x) : p(x.p) {}
        mapIterator &operator=(const mapIterator &x)
        {
            p = x.p;
            return *this;
        }
        mapIterator &operator++()
        {
            ++p;
            return *this;
        }
        mapIterator operator++(int)
        {
            mapIterator tmp(*this);
            operator++();
            return tmp;
        }
        bool operator==(const mapIterator &rhs) const { return p == rhs.p; }
        bool operator!=(const mapIterator &rhs) const { return p != rhs.p; }
        T   &operator*() { return *p; }
        T* operator->() { return p; }
    };
}

#endif