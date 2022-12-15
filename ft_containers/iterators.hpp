#ifndef iterators_hpp
#define iterators_hpp

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

    template <class T>
    class vecIterator : public ft::iterator<ft::random_access_iterator_tag, T>
    {
        int *p;

    public:
        vecIterator(int *x) : p(x) {}
        vecIterator(const vecIterator &mit) : p(mit.p) {}
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
            p = p + other;
            return *this;
        }
        vecIterator operator-(int other)
        {
            p = p - other;
            return *this;
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
}

#endif