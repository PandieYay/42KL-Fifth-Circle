#include "../vector.hpp"
#include <vector>
#include <string>
#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
    ft::vector<int> g1;
    for (int i = 7; i <= 10; i++)
        g1.push_back(i);
    ft::vector<int> copyVec(g1.begin(), g1.end());
    cout << "CopyVec Size aft: " << copyVec.size();
    cout << "\nCopyVec[0] aft = " << copyVec[0] << std::endl;
    cout << g1.end() - g1.begin() << std::endl;
    cout << *(g1.rbegin()) << std::endl;
    cout << *(g1.rbegin() + 1) << std::endl;
    cout << *(g1.rend()) << endl;
    ft::vector<int> copyVec2(g1);

    ft::vector<int> myvector;

    // set some values (from 1 to 10)
    for (int i = 1; i <= 10; i++)
        myvector.push_back(i);

    // erase the 6th element
    myvector.erase(myvector.begin() + 5);

    // erase the first 3 elements:
    myvector.erase(myvector.begin(), myvector.begin() + 3);

    std::cout << "myvector contains:";
    for (unsigned i = 0; i < myvector.size(); ++i)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';
}