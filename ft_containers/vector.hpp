#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>
#include "functions.hpp"
#include "iterators.hpp"

namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
    public:
        typedef T value_type;
        typedef Allocator allocator_type;
        typedef size_t size_type;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef vecIterator<T> iterator;
        typedef vecIterator<const T> const_iterator;

    private:
        T *_vector;
        size_type _size;
        size_type _capacity;
        Allocator _alloc;

    public:
        // Constructors
        /// @brief Constructs an empty container, with no elements.
        explicit vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc)
        {
            _vector = NULL;
            _size = 0;
            _capacity = 0;
        }
        /// @brief Constructs a container with n elements. Each element is a copy of val.
        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _alloc(alloc)
        {
            _vector = _alloc.allocate(n);
            for (size_type i = 0; i < n; i++)
                _alloc.construct(_vector + i, val);
            _size = n;
            _capacity = n;
        }
        /// @brief Constructs a container with as many elements as the range [first,last),
        /// with each element constructed from its corresponding element in that range, in the same order.
        template <class InputIterator>
        vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type &alloc = allocator_type()) : _alloc(alloc)
        {
            size_type size = last - first;
            _vector = _alloc.allocate(size);
            for (size_type i = 0; i < size; i++)
            {
                _alloc.construct(_vector + i, *first);
                first++;
            }
            _size = size;
            _capacity = size;
        }
        /// @brief Constructs a container with a copy of each of the elements in x, in the same order.
        vector(const vector &x)
        {
            _alloc = x._alloc;
            _vector = _alloc.allocate(x._size);
            _capacity = x._size;
            _size = 0;
            while (_size < _capacity)
            {
                _alloc.construct(_vector + _size, x._vector[_size]);
                _size++;
            }
        }
        /// @brief Copies all the elements from x into the container.
        vector &operator=(const vector &x)
        {
            for (size_type i = 0; i < _capacity; i++)
                _alloc.destroy(_vector + i);
            _alloc.deallocate(_vector, _capacity);
            _vector = _alloc.allocate(x._size);
            _capacity = x._size;
            _size = 0;
            while (_size < _capacity)
            {
                _alloc.construct(_vector + _size, x._vector[_size]);
                _size++;
            }
            return *this;
        }
        // Destructor
        ~vector()
        {
            for (size_type i = 0; i < _capacity; i++)
                _alloc.destroy(_vector + i);
            _alloc.deallocate(_vector, _capacity);
        }
        // Iterators
        iterator begin() { return (iterator(_vector)); };
        const_iterator begin() const { return (const_iterator(_vector)); };
        const_iterator cbegin() const { return (const_iterator(_vector)); };
        iterator end() { return (iterator(_vector+_size)); };
        const_iterator end() const { return (const_iterator(_vector+_size)); };
        const_iterator cend() const { return (const_iterator(_vector+_size)); };
        // Functions
        void push_back(const T &val)
        {
            if (_size + 1 > _capacity)
            {
                T *temp = _vector;
                _vector = _alloc.allocate(_size + 1);
                for (size_type i = 0; i < _capacity; i++)
                    _alloc.construct(_vector + i, temp[i]);
                for (size_type i = 0; i < _capacity; i++)
                    _alloc.destroy(temp + i);
                _alloc.deallocate(temp, _capacity);
                _capacity++;
            }
            _vector[_size] = val;
            _size++;
        };
        size_type size() const
        {
            return (_size);
        };
        reference operator[](size_type index)
        {
            return (_vector[index]);
        };
        const_reference operator[](size_type index) const
        {
            return (_vector[index]);
        };
    };
}

#endif