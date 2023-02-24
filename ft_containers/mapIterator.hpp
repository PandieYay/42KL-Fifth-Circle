#ifndef MAPITERATOR_HPP
#define MAPITERATOR_HPP

#include "redblacktree.hpp"
#include "iterators.hpp"

namespace ft
{
    template <class T>
    struct mapIterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
    {
        typedef T       value_type;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category iterator_category;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type difference_type;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer pointer;
        typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference reference;

        typedef Node<value_type> *NodePtr;
        NodePtr p;

        mapIterator() : p(nullptr) {}
        mapIterator(NodePtr x) : p(x) {}
        mapIterator(const mapIterator<typename std::remove_const<T>::type> &x) : p(x.p) {}
        mapIterator &operator=(const mapIterator<typename std::remove_const<T>::type> &x)
        {
            p = x.p;
            return *this;
        }
        mapIterator &operator++()
        {
            if (p->right->data == nullptr)
            {
                NodePtr temp = p->parent;
                if (temp == nullptr)
                {
                    while (p->right->data != nullptr)
                        p = p->right;
                    // p = temp;
                    p->right->parent = p;
                    p = p->right;
                    return *this;
                }
                while (temp->data != nullptr && p == temp->right)
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
                while (temp->data != nullptr && p == temp->left && p->data != nullptr)
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
        value_type   &operator*() const { return *p->data; }
        value_type   *operator->() const { return p->data; }
    };
}

#endif