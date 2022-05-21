// #include <vector>
#include <iostream>
#include <memory>
#include "vector.hpp"
#include <vector>

int main(void)
{
	ft::vector <int> v;
	std::vector<int> s;

	auto i = s.begin();
	std::cout << v.begin() << std::endl;
	std::cout << *i << std::endl;
	return (0);
}
