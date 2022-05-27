// #include <vector>
#include <iostream>
#include <memory>
#include "vector.hpp"
#include <vector>

int main(void)
{
    ft::vector <int> v(10, 5);
	std::vector<int> s(10, 5);

    // std::vector<int>::iterator::o
    ft::vector<int>::iterator it = v.begin();
    // it++;
    // std::vector<int>::iterator::
    // ptr = s.begin();
    // ptr--;

    std::cout << "mine --- begin: " << v.begin() << std::endl;
    std::cout << "orig --- begin: " << s.begin() << std::endl;

    // size_t ptr = s.s();
    // std::cout << "mine --- size: " << v.size() << std::endl;
    // std::cout << "orig --- size: " << v.size() << std::endl;

    // std::cout << "mine --- max size: " << v.max_size() << std::endl;
    // std::cout << "orig --- max size: " << s.max_size() << std::endl;

    // v.resize(5, 2);
    // s.resize(6, 2);

    // std::cout << "mine --- resize: " << v.size() << std::endl;
    // std::cout << "orig --- resize: " << s.size() << std::endl;

    // std::cout << "orig --- capacity: " << s.capacity() << std::endl;
    // std::cout << "mine --- capacity: " << s.capacity() << std::endl;

    return (0);
}
