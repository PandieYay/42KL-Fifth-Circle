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
        typedef std::less<Key> key_compare;
        typedef Allocator allocator_type;
        typedef size_t size_type;
        typedef std::iterator<std::random_access_iterator_tag, T> iterator;

    private:
        node<value_type> _head;
        // node<value_type>  *_nill;
        value_type *_vector;
        key_compare _compare;
        Allocator _alloc;
        size_type _size;
        typedef typename Allocator::template rebind<node<value_type> >::other _nodealloc;

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
            size_type size = last - first;
            for (size_type i = 0; i < size; i++)
            {
                _head.data = _alloc.allocate(1);
                _alloc.construct(_head.data, *first);
                first++;
            }
            _size = size;
        }
        /// @brief Constructs a container with a copy of each of the elements in x, in the same order. NOT DONE
        map(const map &x);
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

        // Element Access
        T &operator[](const Key &key)
        {
            // for (size_type i = 0; i < _size; i++)
            // {

            // }
            // _head.data = _alloc.allocate(1);
            // _alloc.construct(_head.data, make_pair(char('a'),10));
            node<value_type> *temp;
            temp = &_head;
            std::cout << key << "| is the key\n";
            
            // Checks right branches and finds key, returning T
            // while(temp != NULL)
            // {
            //     std::cout << "In the loop bro\n";
            //     if (key == temp->data->first)
            //         return (temp->data->second);
            //     if (temp->right != NULL)
            //         temp = temp->right;
            //     else
            //         break ;
            // }
            while (_compare(temp->data->first, key) == true)
            {
                if (key == temp->data->first)
                    return (temp->data->second);
                temp = temp->right;
            }
            while (_compare(temp->data->first, key) == false)
            {
                if (key == temp->data->first)
                    return (temp->data->second);
                temp = temp->left;
            }
            while (_compare(temp->data->first, key) == true)
            {
                if (key == temp->data->first)
                    return (temp->data->second);
                temp = temp->right;
            }
            return (temp->data->second);
        }

        // Modifiers
        void insert(const value_type &val)
        {
            node<value_type> *temp;

            temp = &_head;
            if (_head.data == NULL)
            {                
                _head.data = _alloc.allocate(1);
                _alloc.construct(_head.data, val);
            }
            else
            {
                // Inserted value key more than
                while (_compare(temp->data->first, val.first) == true)
                {
                    if (temp->right == NULL)
                    {
                        temp->right = _nodealloc(_alloc).allocate(1);
                        temp->right->data = _alloc.allocate(1);
                        _alloc.construct(temp->right->data, val);
                        temp->right->parent = &_head;
                        return ;
                    }
                    temp = temp->right;
                }
                // Inserted value key is less than TODO NOT DONE YET
                while (_compare(temp->data->first, val.first) == false)
                {
                    if (temp->left == NULL)
                    {

                        temp->left = _nodealloc(_alloc).allocate(1);
                        temp->left->data = _alloc.allocate(1);
                        _alloc.construct(temp->left->data, val);
                        temp->left->parent = &_head;
                        return ;
                    }
                    temp = temp->left;
                }
                while (_compare(temp->data->first, val.first) == true)
                {
                    if (temp->right == NULL)
                    {
                        temp->right = _nodealloc(_alloc).allocate(1);
                        temp->right->data = _alloc.allocate(1);
                        _alloc.construct(temp->right->data, val);
                        temp->right->parent = &_head;
                        return ;
                    }
                    temp = temp->right;
                }
            }
        }
    };
}

#endif