#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

#include "functions.hpp"

template <class T>
struct node
{
    T   *data;
    node *parent;
    node *left;
    node *right;
    int color; //0 black, 1 red

    node() {
        data = NULL;
        parent = NULL;
        left = NULL;
        right = NULL;
        color = 0;
    }
};

#endif