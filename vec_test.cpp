// #include <vector>
#include <iostream>
#include <memory>
#include "vector.hpp"

int main(void)
{
	std::allocator<int> myalloc;

	int i = 2;
	ft::vector <int> v(2);

	v.print(i);

	int* arr = myalloc.allocate(5);
	myalloc.construct(arr, 100);
	arr[3] = 10;

	std::cout << arr[3] << std::endl;
	std::cout << arr[1] << std::endl;

	myalloc.deallocate(arr, 5);

	return (0);
}
