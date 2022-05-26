// #include <vector>
#include <iostream>
#include <memory>
#include "vector.hpp"
#include <vector>

int main(void)
{
	ft::vector <int> v(10, 5);
	std::vector<int> s(10, 5);

	// std::vector<int>::iterator ptr;

	// size_t ptr = s.s();
	std::cout << "mine --- size: " << v.size() << std::endl;
	std::cout << "orig --- size: " << v.size() << std::endl;

	std::cout << "mine --- max size: " << v.max_size() << std::endl;
	std::cout << "orig --- max size: " << s.max_size() << std::endl;

	v.resize(5, 2);
	s.resize(5, 2);

	std::cout << "mine --- resize: " << v.size() << std::endl;
	std::cout << "orig --- resize: " << v.size() << std::endl;

	std::cout << "orig --- capacity: " << v.capacity() << std::endl;

	return (0);
}
