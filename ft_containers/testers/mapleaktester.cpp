#include "../map.hpp"
#include <map>
#include <string>
#include <iostream>
#include "../functions.hpp"
#include "../redblacktree.hpp"

using std::cout;

void makemap(void)
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

    //Testing range constructor 
    ft::map<int, int> rangecopy(my.begin(), my.end());
    for (ft::map<int,int>::iterator it=rangecopy.begin(); it!=rangecopy.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "Now testing copy constructor\n";
    ft::map<int, int> copy(rangecopy);
    for (ft::map<int,int>::iterator it=copy.begin(); it!=copy.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    ft::map<int, int> equalcopy;
    std::cout << "Now testing equal constructor\n";
    equalcopy = copy;
    for (ft::map<int,int>::iterator it=equalcopy.begin(); it!=equalcopy.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}

int main(void)
{
    makemap();
    system("leaks a.out");
}