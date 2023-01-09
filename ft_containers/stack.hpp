#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
    public:
        typedef Container container_type;
        typedef T value_type;
        typedef size_t size_type;

    protected:
        Container c;

    public:
        explicit stack(const container_type &cont = container_type()) : c(cont) {}

        // Element access
        value_type &top(){ return (c.back()); }
        const value_type &top() const { return (c.back()); }

        // Capacity
        bool empty() const { return (c.empty()); }
        size_type size() const { return (c.size()); }

        // Modifiers
        void push (const value_type& val) { c.push_back(val); }
        void pop() { c.pop_back(); }
    };
}
#endif