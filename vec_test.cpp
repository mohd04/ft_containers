// #include <vector>
#include <iostream>
#include <memory>
#include "vector.hpp"
#include <vector>

int main(void)
{
	ft::vector <int> v(2, 5);
	std::vector<int> s(2, 5);

	std::vector<int>::iterator ptr;

	ptr = s.end();
	std::cout << v.end() << std::endl;
	std::cout << *ptr << std::endl;
	return (0);
}
