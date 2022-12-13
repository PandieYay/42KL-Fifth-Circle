#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>

namespace ft
{
    template <class T, class Allocator = std::allocator<T> >
    class vector
    {
    public:
        typedef Allocator allocator_type;
        typedef T value_type;
        typedef size_t size_type;

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
        // template <class InputIterator> vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): _alloc(alloc)
        // {
        //     _vector = _alloc.allocate(last - first);
        //     // std::cout << *(first);
        // }

        // Destructor
        ~vector()
        {
            for (size_type i = 0; i < _capacity; i++)
                _alloc.destroy(_vector + i);
            _alloc.deallocate(_vector, _capacity);
        }

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
        T operator[](size_type index)
        {
            return (_vector[index]);
        };
        T operator[](size_type index) const
        {
            return (_vector[index]);
        };
    };
}

#endif