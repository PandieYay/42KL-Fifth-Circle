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
    cout << "\nTest case 2 iterator fill\n";
    {
        ft::vector<int> g1;
        // g1.reserve(10);
        for (int i = 7; i <= 10; i++)
            g1.push_back(i);
        g1.insert(g1.begin(), 3, 5);
        for (int i = 0; i < 7; i++)
            cout << g1[i];
    }
    cout << "\nTest case 3 iterator range\n";
    {
        ft::vector<int> g1;
        ft::vector<int> g2;
        g1.reserve(10);
        for (int i = 7; i <= 10; i++)
            g1.push_back(i);
        for (int i = 0; i < 3; i++)
            g2.push_back(3);
        g1.insert(g1.begin(), g2.begin(), g2.end());
        for (size_t i = 0; i < g1.size(); i++)
            cout << g1[i];
        cout << "\nCapacity is " << g1.capacity() << "\n";
    }
    cout << "Erase tester\n";
    {
        ft::vector<int> g1;
        for (int i = 5; i <= 7; i++)
            g1.push_back(i);
        g1.erase(g1.end() - 1);
        for (size_t i = 0; i < g1.size(); i++)
            cout << g1[i];
    }
    cout << "\nErase tester range ver\n";
    {
        ft::vector<int> g1;
        for (int i = 5; i <= 7; i++)
            g1.push_back(i);
        g1.erase(g1.begin(), g1.end() - 1);
        for (size_t i = 0; i < g1.size(); i++)
            cout << g1[i];
    }
    cout << "\nswap tester\n";
    {
        ft::vector<int> foo(3, 100); // three ints with a value of 100
        ft::vector<int> bar(5, 200); // five ints with a value of 200

        foo.swap(bar);

        cout << "foo contains:";
        for (unsigned i = 0; i < foo.size(); i++)
            cout << ' ' << foo[i];
        cout << '\n';

        cout << "bar contains:";
        for (unsigned i = 0; i < bar.size(); i++)
            cout << ' ' << bar[i];
        cout << '\n';
    }
    cout << "resize tester\n";
    {
        ft::vector<int> g1;
        for (int i = 5; i <= 7; i++)
            g1.push_back(i);
        g1.resize(2, 5);
        for (size_t i = 0; i < g1.size(); i++)
            cout << g1[i];
    }
    // system("leaks a.out");
}