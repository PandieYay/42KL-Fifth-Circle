#include "../map.hpp"
#include <map>
#include <string>
#include <iostream>
#include "../functions.hpp"

using std::cout;

int main(void)
{
    ft::map<char, int> first;

    first.insert(ft::make_pair('a', 10));
    first.insert(ft::make_pair('b', 20000));
    // first['a'] = 10;
    // first['b'] = 30;
    // first['c'] = 50;
    // first['d'] = 70;

    // ft::map<char, int> second(first.begin(), first.end());
    cout << first['a'];
}