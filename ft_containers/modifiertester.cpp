#include "vector.hpp"
#include <vector>
#include <string>
#include <iostream>

using std::cout;

int main(void)
{
    {
        ft::vector<int> g1;
        for (int i = 7; i <= 10; i++)
            g1.push_back(i);
        ft::vector<int> g2;
        g2.assign(5, 9);
        cout << g1.back();
        g1.pop_back();
        cout << g1.back();
        cout << g1.capacity();
        cout << g1.size();
    }
    cout << "\nTest case 2\n";
    {
        ft::vector<int> g1;
        g1.reserve(10);
        for (int i = 7; i <= 10; i++)
            g1.push_back(i);
        g1.insert(g1.begin(), 3, 5);
        for (int i = 0; i < 10; i++)
            cout << g1[i];
    }
}