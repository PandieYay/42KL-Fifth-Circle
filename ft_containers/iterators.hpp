#ifndef ITERATORS_HPP
#define ITERATORS_HPP

#include "redblacktree.hpp"

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
    class vecIterator : public ft::iterator<ft::random_access_iterator_tag, T>
    {
    private:
        int *p;

    public:
        vecIterator() : p(nullptr) {}
        vecIterator(int *x) : p(x) {}
        vecIterator(const vecIterator &x) : p(x.p) {}
        vecIterator &operator=(const vecIterator &x)
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
        vecIterator operator+(int other)
        {
            vecIterator<T> temp = *this;
            temp.p = p + other;
            return (temp);
        }
        vecIterator operator-(int other)
        {
            vecIterator<T> temp = *this;
            temp.p = p - other;
            return (temp);
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

    template <class value_type>
    class mapIterator : public ft::iterator<ft::bidirectional_iterator_tag, value_type>
    {
        typedef Node<value_type> *NodePtr;

    private:
        NodePtr p;

    public:
        mapIterator() : p(nullptr) {}
        mapIterator(NodePtr x) : p(x) {}
        mapIterator(const mapIterator &x) : p(x.p) {}
        mapIterator &operator=(const mapIterator &x)
        {
            p = x.p;
            return *this;
        }
        mapIterator &operator++()
        {
            // if (p->right->data)
            // {
            //     p = p->right;
            //     while (p->left->data)
            //         p = p->left;
            // }
            // else
            // {
            //     NodePtr temp = p->parent;
            //     while(temp->data && p == temp->right)
            //     {
            //         p = temp;
            //         temp = temp->parent;
            //     }
            //     p = temp;
            // }
            if (p->right->data == nullptr)
            {
                NodePtr temp = p->parent;
                while(temp->data != nullptr && p == temp->right)
                {
                    p = p->parent;
                    // This means past end of iterator
                    if (temp->parent == nullptr)
                    {
                        while (temp->right->data != nullptr)
                            temp = temp->right;
                        p = temp;
                        p->right->parent = p;
                        p = p->right;
                        return *this;
                    }
                    temp = temp->parent;
                }
                p = temp;
            }
            else
            {
                p = p->right;
                while (p->left->data != nullptr)
                    p = p->left;
            }
            return *this;
        }
        mapIterator operator++(int)
        {
            mapIterator tmp(*this);
            operator++();
            return tmp;
        }
        mapIterator &operator--()
        {
            if (p->left == nullptr || p->left->data == nullptr)
            {
                NodePtr temp = p->parent;
                while(temp->data != nullptr && p == temp->left && p->data != nullptr)
                {
                    p = p->parent;
                    // This means past start of iterator
                    if (temp->parent == nullptr)
                    {
                        while (temp->left->data != nullptr)
                            temp = temp->right;
                        p = temp;
                        p->left->parent = p;
                        p = p->left;
                        return *this;
                    }
                    temp = temp->parent;
                }
                p = temp;
            }
            else
            {
                p = p->left;
                while (p->right->data != nullptr)
                    p = p->right;
            }
            return *this;
        }
        mapIterator operator--(int)
        {
            mapIterator tmp(*this);
            operator--();
            return tmp;
        }
        bool operator==(const mapIterator &rhs) const { return p == rhs.p; }
        bool operator!=(const mapIterator &rhs) const { return p != rhs.p; }
        value_type &operator*() { return *p->data; }
        value_type *operator->() { return p->data; }
    };
}

#endif