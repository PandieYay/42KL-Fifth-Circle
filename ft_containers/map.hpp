#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <functional>
#include "functions.hpp"
#include <iostream>

namespace ft
{
    template <class Key, class T,
              class Compare = std::less<Key>,
              class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map
    {
    public:
        typedef pair<const Key, T> value_type;
        typedef std::less<Key> key_compare;
        typedef Allocator allocator_type;
        typedef size_t size_type;

    private:
        value_type *_vector;
        key_compare _key;
        Allocator _alloc;
        size_type _size;

    public:
        // Constructors
        /// @brief Constructs an empty container, with no elements.
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _key(comp), _alloc(alloc)
        {
            _vector = _alloc.allocate(1000);
            _size = 0;
        }
        /// @brief Constructs a container with as many elements as the range [first,last),
        /// with each element constructed from its corresponding element in that range.
        template <class InputIterator>
        map(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last,
            const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _key(comp), _alloc(alloc)
        {
            size_type size = last - first;
            _vector = _alloc.allocate(size);
            for (size_type i = 0; i < size; i++)
            {
                _alloc.construct(_vector + i, *first);
                first++;
            }
            _size = size;
        }
        /// @brief Copies all the elements from x into the container.
        map &operator=(const map &x)
        {
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(_vector + i);
            _alloc.deallocate(_vector, _size);
            _vector = _alloc.allocate(x._size);
            _size = 0;
            while (_size < x._size)
            {
                _alloc.construct(_vector + _size, x._vector[_size]);
                _size++;
            }
            return *this;
        }

        //Element Access
        T &operator[](const Key &key)
        {
            // for (size_type i = 0; i < _size; i++)
            // {

            // }
            std::cout << key<< "HIII\n";
            // _vector[0].first = key;
            _vector[0].second = 10;
            return (_vector[0].second);
        }
    };
}

#endif