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
    ft::vector<int> copyVec(g1.begin(), g1.end());
    cout << "\nCopyVec Size aft: " << copyVec.size();
    cout << "\nCopyVec[0] aft = " << copyVec[0] << std::endl;
    cout << g1.end() - g1.begin();
}