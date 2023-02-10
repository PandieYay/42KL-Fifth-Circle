#include "../map.hpp"
#include <map>
#include <string>
#include <iostream>
#include "../functions.hpp"
#include "../redblacktree.hpp"

using std::cout;

// void makemap(void)
// {
//     ft::map<char, int> first;

//     first.insert(ft::make_pair('a', 10));
// }

int main(void)
{
    ft::map<char, int> first;

    first.insert(ft::make_pair('a', 10));
    // makemap();
    // first.insert(ft::make_pair('b', 20000));
    // first.insert(ft::make_pair('c', 12323));

    // ft::map<char, int> second(first);
    // // first['a'] = 10;
    // // first['b'] = 30;
    // // first['c'] = 50;
    // // first['d'] = 70;

    // // ft::map<char, int> second(first.begin(), first.end());
    // cout << first['a'];
    cout << first.max_size();
    // cout << first.size();

    // RedBlackTree<int, ft::pair<int, int> > bst;
    // bst.insert(ft::make_pair(55, 10));
    // bst.insert(ft::make_pair(40, 20000));
    // bst.insert(ft::make_pair(65, 123123));
    // bst.insert(ft::make_pair(60, 123123));
    // bst.insert(ft::make_pair(75, 123123));
    // bst.insert(ft::make_pair(57, 123123));

    // bst.insert(55);
    // bst.insert(40);
    // bst.insert(65);
    // bst.insert(60);
    // bst.insert(75);
    // bst.insert(57);

    // bst.printTree();
    // cout << endl
    //      << "After deleting" << endl;
    // bst.deleteNode(40);
    // bst.printTree();
    // system("leaks a.out");
}