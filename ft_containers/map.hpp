#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <functional>
#include "functions.hpp"
#include <iostream>
#include "redblacktree.hpp"
#include "mapIterator.hpp"

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
        typedef mapIterator<value_type> iterator;
        typedef mapIterator<value_type> const_iterator;
        // typedef mapIterator<value_type> &iterator_ref;

        class value_compare : std::binary_function<T, T, bool>
        { // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
        protected:
            key_compare _comp;
            value_compare(const key_compare &c) : _comp(c) {} // constructed with map's comparison object
        public:
            bool operator()(const value_type &x, const value_type &y) const
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
            _size = 0;
                for ( ; first != last; ++first)
                {
                    _rbt.insert(*first);
                    _size++;
                }
        }
        /// @brief Constructs a container with a copy of each of the elements in x, in the same order.
        map(const map &x) : _compare(x._compare), _alloc(x._alloc), _size(x._size)
        {
            for (const_iterator first = x.begin(); first != x.end(); ++first)
                _rbt.insert(*first);
        }
        /// @brief Copies all the elements from x into the container. NOT DONE
        map &operator=(const map &x)
        {
            for (size_type i = 0; i < _size; ++i)
                _rbt.deleteNode(_rbt.begin()->data->first);
            _compare = x._compare;
            _alloc = x._alloc;
            _size = x._size;            
            for (const_iterator first = x.begin(); first != x.end(); ++first)
                _rbt.insert(*first);
            return *this;
        }
        ~map()
        {
            for (size_type i = 0; i < _size; ++i)
                _rbt.deleteNode(_rbt.begin()->data->first);
        }

        //Iterators
        iterator begin() { return (iterator(_rbt.begin())); }
        const_iterator begin() const { return (const_iterator(_rbt.begin())); }
        iterator end() { return (iterator(_rbt.end())); }
        const_iterator end() const { return (const_iterator(_rbt.end())); }

        // Capacity
        bool empty() const { return (_size == 0); };
        size_type size(void) const { return (_size); };
        size_type max_size() const { return (_alloc.max_size()); };

        // Element Access
        T &operator[](const Key &key)
        {
            return (_rbt.searchTree(key)->data->second);
        }

        T &at(const Key &key)
        {
            Node<value_type> *node;

            node = _rbt.searchTree(key);
            if (node->left == nullptr && node->right == nullptr)
                throw std::out_of_range("map::at: key not found");
            else
                return (node->data->second);
        }
        const T &at(const Key &key) const
        {
            Node<value_type> *node;

            node = _rbt.searchTree(key);
            if (node->left == nullptr && node->right == nullptr)
                throw std::out_of_range("map::at: key not found");
            else
                return (node->data->second);
        }

        // Modifiers
        void insert(const value_type &val)
        {
            _rbt.insert(val);
            _size++;
        }
        size_type erase(const Key &key)
        {
            if (_rbt.deleteNode(key) == 1)
            {
                _size--;
                return (1);
            }
            else
                return (0);
        }
    };
}

#endif