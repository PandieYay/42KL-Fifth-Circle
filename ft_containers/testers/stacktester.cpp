#include "../vector.hpp"
#include "../stack.hpp"
#include <vector>
#include <deque>
#include <string>
#include <iostream>

using std::cout;

int main(void)
{
    {
        ft::stack<int> mystack;

        mystack.push(10);
        mystack.push(20);

        mystack.top() -= 5;

        std::cout << "mystack.top() is now " << mystack.top() << '\n';
    }

    {
        std::deque<int> mydeque(3, 100);  // deque with 3 elements
        ft::vector<int> myvector(2, 200); // vector with 2 elements

        ft::stack<int> first;                            // empty stack
        ft::stack<int, std::deque<int> > second(mydeque); // stack initialized to copy of deque

        ft::stack<int, ft::vector<int> > third; // empty stack using vector
        ft::stack<int, ft::vector<int> > fourth(myvector);
        // ft::stack<int> fourth(myvector); // THIS ALSO WORKS

        std::cout << "size of first: " << first.size() << '\n';
        std::cout << "size of third: " << third.size() << '\n';
        std::cout << "size of fourth: " << fourth.size() << '\n';
    }
}