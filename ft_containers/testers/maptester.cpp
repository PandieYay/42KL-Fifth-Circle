#include "../map.hpp"
#include "../vector.hpp"
#include <map>
#include <string>
#include <iostream>
#include "../functions.hpp"
#include "../redblacktree.hpp"

using std::cout;

// void makemap(void)
// {
//     ft::map<char, int> my;

//     first.insert(ft::make_pair('a', 10));
// }

int main(void)
{
    ft::map<int, int> my;
    ft::map<int, int>::iterator mit;
    std::map<char, int> theirs;
    std::map<char, int>::iterator tit;

    my.insert(ft::make_pair(5, 10));
    my.insert(ft::make_pair(10, 20));
    my.insert(ft::make_pair(15, 30));
    my.insert(ft::make_pair(20, 40));
    my.insert(ft::make_pair(17, 37));
    my.insert(ft::make_pair(16, 37));
    my.insert(ft::make_pair(14, 37));
    theirs.insert(std::make_pair('a', 10));
    theirs.insert(std::make_pair('a', 10));
    // cout << my.erase('a');
    // my.insert(ft::make_pair('b', 20000));
    // my.insert(ft::make_pair('c', 12323));

    // ft::map<char, int> second(my);
    // // my['a'] = 10;
    // // my['b'] = 30;
    // // my['c'] = 50;
    // // my['d'] = 70;

    // // ft::map<char, int> second(my.begin(), my.end());

    mit = my.begin();
    cout << mit->first << endl; // output
    mit++;
    cout << mit->first << endl; // output
    mit++;
    cout << mit->first << endl; // output
    mit++;
    cout << mit->first << endl; // output
    mit++;
    cout << mit->first << endl; // output
    mit++;
    cout << mit->first << endl; // output
    mit++;
    cout << mit->first << endl; // output
    mit++;
    mit--;
    cout << mit->first << endl;

    cout << "Now testing end\n";
    mit = my.end();
    mit--;
    cout << mit->first << endl;
    mit--;
    cout << mit->first << endl;
    mit--;
    cout << mit->first << endl;
    mit--;
    cout << mit->first << endl;
    mit--;
    cout << mit->first << endl;
    mit--;
    cout << mit->first << endl;
    mit--;
    cout << mit->first << endl;
    mit--;

    // tit = theirs.begin();
    // cout << tit->first << endl;
    // cout << tit->first << endl;
    // cout << reinterpret_cast<void *>(my.begin()) << "\n";
    // printf("%p\n", reinterpret_cast<void *>(my.begin()));
    // cout << theirs.begin()->second;
    //inline ft::mapIterator<ft::pair<const char, int>> ft::map<char, int>::begin()
    // inline std::__1::map<char, int>::iterator std::__1::map<char, int>::begin() noexcept

    

    // cout << my.at('a');
    // cout << my.size();

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