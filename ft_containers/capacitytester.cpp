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
}