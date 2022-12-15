#include "vector.hpp"
#include <vector>
#include <string>
#include <iostream>

using std::cout;

int main(void)
{
    // real vector
    {
        std::vector<int> g1;

        for (int i = 1; i <= 5; i++)
            g1.push_back(i);
        cout << "Size : " << g1.size();
        cout << "\nCapacity : " << g1.capacity();
        cout << "\nMax_Size : " << g1.max_size();
        cout << "\ng1[0] = " << g1[0];
    }
    /// @brief Testing default constructor
    {
        ft::vector<int> g2;
        for (int i = 1; i <= 5; i++)
            g2.push_back(i);
        cout << "\nSize : " << g2.size();
        cout << "\ng2[0] = " << g2[1];
    }
    /// @brief Testing fill constructor
    {
        ft::vector<int> test(10, 5);
        cout << "\nSize : " << test.size();
        cout << "\nTest[5] = " << test[5];
    }
    /// @brief Testing range constructor
    {
        std::vector<int> g1;
        for (int i = 7; i <= 10; i++)
            g1.push_back(i);
        ft::vector<int> test(g1.begin(),g1.end());
        cout << "\nSize : " << test.size();
        cout << "\nTest[0] = " << test[0];
    }
}