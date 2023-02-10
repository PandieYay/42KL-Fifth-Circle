#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <functional>
#include "functions.hpp"
#include <iostream>
#include "redblacktree.hpp"

namespace ft
{
    template <class Key, class T,
              class Compare = std::less<Key>,
              class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map
    {
    public:
        typedef pair<const Key, T> value_type;
        typedef Compare key_compare;
        typedef Allocator allocator_type;
        typedef size_t size_type;
        typedef std::iterator<std::random_access_iterator_tag, T> iterator;

        class value_compare : std::binary_function<T, T, bool>
        {   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
        protected:
            key_compare _comp;
            value_compare (const key_compare &c) : _comp(c) {}  // constructed with map's comparison object
        public:
            bool operator() (const value_type& x, const value_type& y) const
            {
                return _comp(x.first, y.first);
            }
        };

    private:
        RedBlackTree<value_type, Key, Compare, Allocator> _rbt;
        value_type *_vector;
        key_compare _compare;
        value_compare value_comp() const;
        Allocator _alloc;
        size_type _size;

    public:
        // Constructors
        /// @brief Constructs an empty container, with no elements.
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _compare(comp), _alloc(alloc)
        {
            _size = 0;
        }
        /// @brief Constructs a container with as many elements as the range [first,last),
        /// with each element constructed from its corresponding element in that range. W.I.P NEED TO TEST
        template <class InputIterator>
        map(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last,
            const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _compare(comp), _alloc(alloc)
        {
            (void)first;
            (void)last;
        //     size_type size = last - first;
        //     for (size_type i = 0; i < size; i++)
        //     {
        //         _head.data = _alloc.allocate(1);
        //         _alloc.construct(_head.data, *first);
        //         first++;
        //     }
        //     _size = size;
        }
        /// @brief Constructs a container with a copy of each of the elements in x, in the same order.
        map(const map &x) : _compare(x._compare), _alloc(x._alloc), _size(x._size)
        {
            (void)x;
            // Iterate and insert?
        }
        /// @brief Copies all the elements from x into the container. NOT DONE
        map &operator=(const map &x)
        {
            (void)x;
            //TODO DEALLOC, then iterate and insert
        }

        // Element Access
        T &operator[](const Key &key)
        {
            return (_rbt.searchTree(key)->data->second);
        }

        // Capacity
        bool empty() const { return (_size == 0); };
        size_type size(void) const { return (_size); };
        size_type max_size() const { return (_alloc.max_size()); };
        // Modifiers
        void insert(const value_type &val)
        {
            _rbt.insert(val);
            _size++;
        }
    };
}

#endif