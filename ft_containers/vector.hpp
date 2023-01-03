#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>
#include "functions.hpp"
#include "iterators.hpp"
#include "reverse_iterator.hpp"

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
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

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
        iterator end() { return (iterator(_vector + _size)); };
        const_iterator end() const { return (const_iterator(_vector + _size)); };
        reverse_iterator rbegin() { return (reverse_iterator(iterator(_vector + _size - 1))); };
        const_reverse_iterator rbegin() const { return (const_reverse_iterator(const_iterator(_vector + _size - 1))); };
        reverse_iterator rend() { return (reverse_iterator(iterator(_vector - 1))); };
        const_reverse_iterator rend() const { return (const_reverse_iterator(iterator(_vector - 1))); };

        // Capacity
        size_type size() const
        {
            return (_size);
        };
        size_type max_size() const
        {
            return (_alloc.max_size());
        }
        size_type capacity() const
        {
            return (_capacity);
        }
        bool empty() const
        {
            if (_size == 0)
                return (true);
            return (false);
        }
        void reserve(size_type new_cap)
        {
            if (new_cap > _capacity)
            {
                T *temp = _vector;
                _vector = _alloc.allocate(new_cap);
                for (size_type i = 0; i < _size; i++)
                    _alloc.construct(_vector + i, temp[i]);
                for (size_type i = 0; i < _capacity; i++)
                    _alloc.destroy(temp + i);
                _alloc.deallocate(temp, _capacity);
                _capacity = new_cap;
            }
        }

        // Element Access
        reference operator[](size_type index)
        {
            return (_vector[index]);
        };
        const_reference operator[](size_type index) const
        {
            return (_vector[index]);
        };
        reference at(size_type pos)
        {
            if (pos >= _size)
                throw std::out_of_range("vector");
            return (_vector[pos]);
        }
        const_reference at(size_type pos) const
        {
            if (pos >= _size)
                throw std::out_of_range("vector");
            return (_vector[pos]);
        }
        reference front()
        {
            return (_vector[0]);
        }
        reference front() const
        {
            return (_vector[0]);
        }
        reference back()
        {
            return (_vector[_size - 1]);
        }
        reference back() const
        {
            return (_vector[_size - 1]);
        }
        value_type *data()
        {
            return (_vector);
        }
        const value_type *data() const
        {
            return (_vector);
        }

        // Modifiers
        template <class InputIterator>
        void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
        {
            size_type size = last - first;

            for (size_type i = 0; i < _capacity; i++)
                _alloc.destroy(_vector + i);
            if (size > _capacity)
            {
                _alloc.deallocate(_vector, _capacity);
                _vector = _alloc.allocate(size);
                for (size_type i = 0; i < size; i++)
                {
                    _alloc.construct(_vector + i, *first);
                    first++;
                }
                _capacity = size;
                _size = _capacity;
            }
            else
            {
                for (size_type i = 0; i < size; i++)
                {
                    _alloc.construct(_vector + i, *first);
                    first++;
                }
                _size = size;
            }
        }
        void assign(size_type n, const value_type &val)
        {
            for (size_type i = 0; i < _capacity; i++)
                _alloc.destroy(_vector + i);
            if (n > _capacity)
            {
                _alloc.deallocate(_vector, _capacity);
                _vector = _alloc.allocate(n);
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(_vector + i, val);
                _capacity = n;
                _size = _capacity;
            }
            else
            {
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(_vector + i, val);
                _size = n;
            }
        }
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
        void pop_back()
        {
            _alloc.destroy(_vector + _size);
            _size--;
        }
        /// @brief Insert function, single element, fill, and range
        iterator insert(iterator pos, const value_type &val)
        {
            size_t index = pos - this->begin();
            iterator end = iterator(_vector + _size);

            if (_size + 1 > _capacity)
            {
                T *temp = _vector;
                _vector = _alloc.allocate(_size + 1);
                for (size_type i = 0; i < index; i++)
                    _alloc.construct(_vector + i, temp[i]);
                _alloc.construct(_vector + index, val);
                for (size_type i = index; i < _size; i++)
                    _alloc.construct(_vector + i + 1, temp[i]);
                for (size_type i = 0; i < _capacity; i++)
                    _alloc.destroy(temp + i);
                _alloc.deallocate(temp, _capacity);
                _capacity++;
            }
            else
            {
                T temp;
                T temp2;

                temp = *pos;
                *pos = val;
                while (pos != end)
                {
                    pos++;
                    temp2 = *pos;
                    *pos = temp;
                    temp = temp2;
                }
            }
            _size++;
            return (this->begin() + index);
        }
        iterator insert(iterator pos, size_type count, const T &val)
        {
            size_t index = pos - this->begin();

            if (_size + count > _capacity)
            {
                T *temp = _vector;
                _vector = _alloc.allocate(_size + count);
                for (size_type i = 0; i < index; i++)
                    _alloc.construct(_vector + i, temp[i]);
                for (size_type i = 0; i < count; i++)
                    _alloc.construct(_vector + index + i, val);
                for (size_type i = index; i < _size; i++)
                    _alloc.construct(_vector + i + count, temp[i]);
                for (size_type i = 0; i < _capacity; i++)
                    _alloc.destroy(temp + i);
                _alloc.deallocate(temp, _capacity);
                _capacity = _size + count;
            }
            else
            {
                T *arr = new T[_size];

                for (size_t i = 0; i < _size; i++)
                    arr[i] = _vector[i];
                for (size_type i = 0; i < count; i++)
                {
                    *pos = val;
                    pos++;
                }
                for (size_t i = 0; i < _size - index; i++)
                {
                    *pos = arr[index + i];
                    pos++;
                }
                delete[] arr;
            }
            _size += count;
            return (this->begin() + index);
        }
        template <class InputIterator>
        iterator insert(iterator pos, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
        {
            size_t index = pos - this->begin();
            size_t count = last - first;

            if (_size + count > _capacity)
            {
                T *temp = _vector;
                _vector = _alloc.allocate(_size + count);
                for (size_type i = 0; i < index; i++)
                    _alloc.construct(_vector + i, temp[i]);
                for (size_type i = 0; i < count; i++)
                {
                    _alloc.construct(_vector + index + i, *first);
                    first++;
                }
                std::cout << "Index is " << index << std::endl;
                for (size_type i = index; i < _size; i++)
                    _alloc.construct(_vector + i + count, temp[i]);
                for (size_type i = 0; i < _capacity; i++)
                    _alloc.destroy(temp + i);
                _alloc.deallocate(temp, _capacity);
                _capacity = _size + count;
            }
            else
            {
                T *arr = new T[_size];

                for (size_t i = 0; i < _size; i++)
                    arr[i] = _vector[i];
                for (size_type i = 0; i < count; i++)
                {
                    *pos = *first;
                    pos++;
                    first++;
                }
                for (size_t i = 0; i < _size - index; i++)
                {
                    *pos = arr[index + i];
                    pos++;
                }
                delete[] arr;
            }
            _size += count;
            return (this->begin() + index);
        }
        iterator erase(iterator pos)
        {
            size_t index = pos - this->begin();
            while (pos != this->end() - 1)
            {
                *pos = *(pos + 1);
                pos++;
            }
            _size--;
            _alloc.destroy(_vector + _size);
            return (this->begin() + index);
        }
        iterator erase (iterator first, iterator last)
        {
            size_t index = first - this->begin();
            size_t distance = last - first;
            size_t i = 0;

            while (first != this->end() - 1)
            {
                *first = *(first + distance + i);
                first++;
                i++;
            }
            _size -= distance;
            return (this->begin() + index);
        }
        void swap (vector& x)
        {
            vector temp = *this;
            *this = x;
            x = temp;
        }
        void clear()
        {
            for (size_t i = 0; i < _size; i++)
               _alloc.destroy(_vector + i);
            _size = 0;
        }
        void resize (size_type count, value_type val = value_type())
        {
            if (count > _capacity)
            {
                T *temp = _vector;
                _vector = _alloc.allocate(count);
                for (size_type i = 0; i < _size; i++)
                    _alloc.construct(_vector + i, temp[i]);
                for (size_type i = 0; i < count - _size; i++)
                    _alloc.construct(_vector + _size + i, val);
                for (size_type i = 0; i < _capacity; i++)
                    _alloc.destroy(temp + i);
                _alloc.deallocate(temp, _capacity);
                _capacity = count;
                _size = count;
            }
            else
            {
                if (count > _size)
                {
                    for (size_type i = 0; i < count - _size; i++)
                        _alloc.construct(_vector + _size + i, val);
                }
                else
                {
                    for (size_type i = 0; i < _size - count; i++)
                        this->pop_back();
                }
                _size = count;
            }
        }
    };
}

#endif