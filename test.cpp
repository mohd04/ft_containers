#include <iostream>
#include <vector>

int main()
{
    std::vector<int> g1(5, 10);

	auto i = g1.begin();
	std::cout << *i << std::endl;
}
