#include "../map.hpp"
#include <map>
#include <string>
#include <iostream>
#include "../functions.hpp"
#include "../redblacktree.hpp"

using std::cout;

// void makemap(void)
// {
//     std::map<char, int> my;

//     first.insert(ft::make_pair('a', 10));
// }

int main(void)
{
    ft::map<int, int> my;
    ft::map<int, int>::iterator mit;

    my.insert(ft::make_pair(5, 10));
    my.insert(ft::make_pair(10, 20));
    my.insert(ft::make_pair(15, 30));
    my.insert(ft::make_pair(20, 40));
    my.insert(ft::make_pair(17, 37));
    my.insert(ft::make_pair(16, 37));
    my.insert(ft::make_pair(14, 37));

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

    // Testing range constructor
    ft::map<int, int> rangecopy(my.begin(), my.end());
    for (ft::map<int, int>::iterator it = rangecopy.begin(); it != rangecopy.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "Now testing copy constructor\n";
    ft::map<int, int> copy(rangecopy);
    for (ft::map<int, int>::iterator it = copy.begin(); it != copy.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    ft::map<int, int> equalcopy;
    std::cout << "Now testing equal constructor\n";
    equalcopy = copy;
    for (ft::map<int, int>::iterator it = equalcopy.begin(); it != equalcopy.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
    std::cout << "Now testing reverse constructor\n";
    for (ft::map<int, int>::reverse_iterator rit = equalcopy.rbegin(); rit != equalcopy.rend(); ++rit)
        std::cout << rit->first << " => " << rit->second << '\n';
    cout << equalcopy.at(20) << endl;

    std::cout << "Now testing [] element access\n";
    ft::map<char, string> mymap;

    mymap['a']="an element";
    mymap['b']="another element";
    mymap['c']=mymap['b'];

    std::cout << "mymap['a'] is " << mymap['a'] << '\n';
    std::cout << "mymap['b'] is " << mymap['b'] << '\n';
    std::cout << "mymap['c'] is " << mymap['c'] << '\n';
    std::cout << "mymap['d'] is " << mymap['d'] << '\n';

    std::cout << "mymap now contains " << mymap.size() << " elements.\n";

    mymap.insert(ft::make_pair('a', "TEST"));
    std::cout << "mymap['a'] is " << mymap['a'] << '\n';
    mymap.erase(mymap.begin());
    std::cout << "mymap['a'] is " << mymap['a'] << '\n';
    // tit = theirs.begin();
    // cout << tit->first << endl;
    // cout << tit->first << endl;
    // cout << reinterpret_cast<void *>(my.begin()) << "\n";
    // printf("%p\n", reinterpret_cast<void *>(my.begin()));
    // cout << theirs.begin()->second;

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