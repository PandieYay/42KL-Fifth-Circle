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
    std::cout << "size: " << g1.size() << "\n";
    std::cout << "capacity: " << g1.capacity() << "\n";
    std::cout << "max_size: " << g1.max_size() << "\n";
    try
    {
        std::cout << "g1 var: " << g1.at(4);
    }
    catch (std::out_of_range const & exc)
    {
        std::cout << exc.what() << '\n';
    }
    int *p = g1.data();
    p[3] = 100;
    std::cout << g1.back();
}