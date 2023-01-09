#include <utility>
#include <string>
#include <iostream>
#include "../map.hpp"
#include "../functions.hpp"

int main()
{
    ft::pair<std::string, double> product1;
    ft::pair<std::string, double> product2("tomatoes", 2.30); // value init
    ft::pair<std::string, double> product3(product2);         // copy constructor

    product1 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

    product2.first = "shoes"; // the type of first is string
    product2.second = 39.90;  // the type of second is double

    std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
    std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
    std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
}