#ifndef ITERATORS_HPP
#define ITERATORS_HPP

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
    struct vecIterator : public ft::iterator<ft::random_access_iterator_tag, T>
    {
    public:

        typedef T       value_type;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category iterator_category;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type difference_type;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer pointer;
        typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference reference;

        pointer p;

    public:
        vecIterator() : p(nullptr) {}
        vecIterator(pointer x) : p(x) {}
        vecIterator(const vecIterator<typename std::remove_const<T>::type> &x) : p(x.p) {}

        vecIterator &operator=(const vecIterator<typename std::remove_const<T>::type> &x)
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
        vecIterator operator+(difference_type other)
        {
            vecIterator<T> temp = *this;
            temp.p = p + other;
            return (temp);
        }
        // vecIterator operator+=(difference_type n)
        // {
        //     p += n;
        //     return (*this);
        // }
        difference_type operator+(const vecIterator &other)
        {
            return (p + other.p);
        }
        vecIterator operator-(difference_type other)
        {
            vecIterator<T> temp = *this;
            temp.p = p - other;
            return (temp);
        }
        // vecIterator operator-=(difference_type n)
        // {
        //     p -= n;
        //     return (*this);
        // }
        size_t operator-(const vecIterator &other)
        {
            size_t distance = p - other.p;
            return distance;
        }
        bool operator==(const vecIterator &rhs) const { return p == rhs.p; }
        bool operator!=(const vecIterator &rhs) const { return p != rhs.p; }
        pointer base(void) const { return this->p; }
        reference operator*() { return *p; }
        reference operator[](difference_type n) { return *(this->p + n); }
        pointer operator->(void) {return this->p; }
    };

    template <class T>    
    vecIterator<T>  operator+(typename vecIterator<T>::difference_type n,
        const vecIterator<T> &other)
    {
        return (other + n);
    }

    template <class T, class U>
    size_t operator-(const vecIterator<T> &lhs, const vecIterator<U> &rhs)
    {
        return (lhs.base() - rhs.base());
    }
}

#endif