#ifndef REDBLACKTREE_HPP
#define REDBLACKTREE_HPP

// Implementing Red-Black Tree in C++
#include "map.hpp"
#include "functions.hpp"
#include <iostream>
using std::string;
using std::cout;
using std::endl;

template <class T>
struct Node
{
  T  *data;
  Node *parent;
  Node *left;
  Node *right;
  int color;
};

template <class T, class Key, class Compare, class Allocator = std::allocator<T> >
class RedBlackTree
{
  typedef Node<T>* NodePtr;
  typedef Compare key_compare;
  typedef size_t size_type;
private:
  NodePtr root;
  NodePtr TNULL;
  key_compare _compare;
  Allocator _alloc;
  typedef typename Allocator::template rebind<Node<T> >::other _nodealloc;

  void initializeNULLNode(NodePtr node, NodePtr parent)
  {
    node->data = nullptr;
    node->parent = parent;
    node->left = nullptr;
    node->right = nullptr;
    node->color = 0;
  }

  // Preorder
  void preOrderHelper(NodePtr node)
  {
    if (node != TNULL)
    {
      cout << node->data->first << " ";
      preOrderHelper(node->left);
      preOrderHelper(node->right);
    }
  }

  // Inorder
  void inOrderHelper(NodePtr node)
  {
    if (node != TNULL)
    {
      inOrderHelper(node->left);
      cout << node->data->first << " ";
      inOrderHelper(node->right);
    }
  }

  // Post order
  void postOrderHelper(NodePtr node)
  {
    if (node != TNULL)
    {
      postOrderHelper(node->left);
      postOrderHelper(node->right);
      cout << node->data->first << " ";
    }
  }

  NodePtr searchTreeHelper(NodePtr node, Key key) const
  {
    if (node == TNULL || key == node->data->first)
    {
      return node;
    }

    if (_compare(key, node->data->first) == true)
    {
      return searchTreeHelper(node->left, key);
    }
    return searchTreeHelper(node->right, key);
  }

  // For balancing the tree after deletion
  void deleteFix(NodePtr x)
  {
    NodePtr s;
    while (x != root && x->color == 0)
    {
      if (x == x->parent->left)
      {
        s = x->parent->right;
        if (s->color == 1)
        {
          s->color = 0;
          x->parent->color = 1;
          leftRotate(x->parent);
          s = x->parent->right;
        }

        if (s->left->color == 0 && s->right->color == 0)
        {
          s->color = 1;
          x = x->parent;
        }
        else
        {
          if (s->right->color == 0)
          {
            s->left->color = 0;
            s->color = 1;
            rightRotate(s);
            s = x->parent->right;
          }

          s->color = x->parent->color;
          x->parent->color = 0;
          s->right->color = 0;
          leftRotate(x->parent);
          x = root;
        }
      }
      else
      {
        s = x->parent->left;
        if (s->color == 1)
        {
          s->color = 0;
          x->parent->color = 1;
          rightRotate(x->parent);
          s = x->parent->left;
        }

        if (s->right->color == 0 && s->right->color == 0)
        {
          s->color = 1;
          x = x->parent;
        }
        else
        {
          if (s->left->color == 0)
          {
            s->right->color = 0;
            s->color = 1;
            leftRotate(s);
            s = x->parent->left;
          }

          s->color = x->parent->color;
          x->parent->color = 0;
          s->left->color = 0;
          rightRotate(x->parent);
          x = root;
        }
      }
    }
    x->color = 0;
  }

  void rbTransplant(NodePtr u, NodePtr v)
  {
    if (u->parent == nullptr)
    {
      root = v;
    }
    else if (u == u->parent->left)
    {
      u->parent->left = v;
    }
    else
    {
      u->parent->right = v;
    }
    v->parent = u->parent;
  }

  size_type deleteNodeHelper(NodePtr node, Key key)
  {
    NodePtr z = TNULL;
    NodePtr x, y;
    while (node != TNULL)
    {
      if (node->data->first == key)
        z = node;
      if (node->data->first <= key)
        node = node->right;
      else
        node = node->left;
    }

    if (z == TNULL)
      return (0);

    y = z;
    int y_original_color = y->color;
    if (z->left == TNULL)
    {
      x = z->right;
      rbTransplant(z, z->right);
    }
    else if (z->right == TNULL)
    {
      x = z->left;
      rbTransplant(z, z->left);
    }
    else
    {
      y = minimum(z->right);
      y_original_color = y->color;
      x = y->right;
      if (y->parent == z)
      {
        x->parent = y;
      }
      else
      {
        rbTransplant(y, y->right);
        y->right = z->right;
        y->right->parent = y;
      }

      rbTransplant(z, y);
      y->left = z->left;
      y->left->parent = y;
      y->color = z->color;
    }
    _alloc.deallocate(z->data, 1);
    _nodealloc(_alloc).deallocate(z, 1);
    if (y_original_color == 0)
    {
      deleteFix(x);
    }
    return (1);
  }

  // For balancing the tree after insertion
  void insertFix(NodePtr k)
  {
    NodePtr u;
    while (k->parent->color == 1)
    {
      if (k->parent == k->parent->parent->right)
      {
        u = k->parent->parent->left;
        if (u->color == 1)
        {
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        }
        else
        {
          if (k == k->parent->left)
          {
            k = k->parent;
            rightRotate(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          leftRotate(k->parent->parent);
        }
      }
      else
      {
        u = k->parent->parent->right;

        if (u->color == 1)
        {
          u->color = 0;
          k->parent->color = 0;
          k->parent->parent->color = 1;
          k = k->parent->parent;
        }
        else
        {
          if (k == k->parent->right)
          {
            k = k->parent;
            leftRotate(k);
          }
          k->parent->color = 0;
          k->parent->parent->color = 1;
          rightRotate(k->parent->parent);
        }
      }
      if (k == root)
      {
        break;
      }
    }
    root->color = 0;
  }

  void printHelper(NodePtr root, string indent, bool last)
  {
    if (root != TNULL)
    {
      cout << indent;
      if (last)
      {
        cout << "R----";
        indent += "   ";
      }
      else
      {
        cout << "L----";
        indent += "|  ";
      }

      string sColor = root->color ? "RED" : "BLACK";
      cout << root->data->first << "(" << sColor << ")" << endl;
      printHelper(root->left, indent, false);
      printHelper(root->right, indent, true);
    }
  }

public:
  RedBlackTree()
  {
    TNULL = _nodealloc(_alloc).allocate(1);
    TNULL->color = 0;
    TNULL->left = nullptr;
    TNULL->right = nullptr;
    TNULL->data = nullptr;
    root = TNULL;
  }

  ~RedBlackTree()
  {
    _nodealloc(_alloc).deallocate(root, 1);
  }

  void preorder()
  {
    preOrderHelper(this->root);
  }

  void inorder()
  {
    inOrderHelper(this->root);
  }

  void postorder()
  {
    postOrderHelper(this->root);
  }

  NodePtr searchTree(const Key &key) const
  {
    return searchTreeHelper(this->root, key);
  }

  NodePtr begin(void) const
  {
    NodePtr temp;

    temp = root;
    if (temp == TNULL)
      return (temp);
    while (temp->left != TNULL)
    {
      temp = temp->left;
    }
    return (temp);
  }

  NodePtr end(void) const
  {
    NodePtr temp;

    if (root == TNULL)
      return (root);
    temp = root;
    while (temp->right != TNULL)
    {
      temp = temp->right;
    }
    temp->right->parent = temp;
    temp = temp->right;
    return (temp);
  }

  NodePtr minimum(NodePtr node)
  {
    while (node->left != TNULL)
    {
      node = node->left;
    }
    return node;
  }

  NodePtr maximum(NodePtr node)
  {
    while (node->right != TNULL)
    {
      node = node->right;
    }
    return node;
  }

  NodePtr successor(NodePtr x)
  {
    if (x->right != TNULL)
    {
      return minimum(x->right);
    }

    NodePtr y = x->parent;
    while (y != TNULL && x == y->right)
    {
      x = y;
      y = y->parent;
    }
    return y;
  }

  NodePtr predecessor(NodePtr x)
  {
    if (x->left != TNULL)
    {
      return maximum(x->left);
    }

    NodePtr y = x->parent;
    while (y != TNULL && x == y->left)
    {
      x = y;
      y = y->parent;
    }

    return y;
  }

  void leftRotate(NodePtr x)
  {
    NodePtr y = x->right;
    x->right = y->left;
    if (y->left != TNULL)
    {
      y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr)
    {
      this->root = y;
    }
    else if (x == x->parent->left)
    {
      x->parent->left = y;
    }
    else
    {
      x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
  }

  void rightRotate(NodePtr x)
  {
    NodePtr y = x->left;
    x->left = y->right;
    if (y->right != TNULL)
    {
      y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr)
    {
      this->root = y;
    }
    else if (x == x->parent->right)
    {
      x->parent->right = y;
    }
    else
    {
      x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
  }

  // Inserting a node
  void insert(const T &val)
  {
    NodePtr node = _nodealloc(_alloc).allocate(1);
    node->parent = nullptr;
    node->data = _alloc.allocate(1);
    _alloc.construct(node->data, val);
    node->left = TNULL;
    node->right = TNULL;
    node->color = 1;

    NodePtr y = nullptr;
    NodePtr x = this->root;

    while (x != TNULL)
    {
      y = x;
      if (_compare(node->data->first, x->data->first) == true)
      {
        x = x->left;
      }
      else
      {
        x = x->right;
      }
    }

    node->parent = y;
    if (y == nullptr)
    {
      root = node;
    }
    else if (node->data->first < y->data->first)
    {
      y->left = node;
    }
    else
    {
      y->right = node;
    }

    if (node->parent == nullptr)
    {
      node->color = 0;
      return;
    }

    if (node->parent->parent == nullptr)
    {
      return;
    }

    insertFix(node);
  }

  NodePtr getRoot()
  {
    return this->root;
  }

  size_type deleteNode(Key key)
  {
   return (deleteNodeHelper(this->root, key));
  }

  void printTree()
  {
    if (root)
    {
      printHelper(this->root, "", true);
    }
  }

  void swap(RedBlackTree &x)
  {
    std::swap(root, x.root);
    std::swap(TNULL, x.TNULL);
    std::swap(_compare, x._compare);
    std::swap(_alloc, x._alloc);
  }

};

#endif