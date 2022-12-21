#include "vector.hpp"
#include <vector>
#include <string>
#include <iostream>

using std::cout;

int main(void)
{
    ft::vector<int> g1;
    for (int i = 7; i <= 10; i++)
        g1.push_back(i);
    ft::vector<int> g2;
    g2.assign(5, 9);
    cout << g2.front();
    cout << g2.capacity();
    cout << g2.size();
}