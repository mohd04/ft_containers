#include "dummy.hpp"

int main()
{
    int array[] = {2, 23, 234, 42, 12};

    vectorRawIterator<int> a;
    vectorRawIterator<int> b;

    vectorRawIterator<int>::pointer ptr;
    b = a;
    for (ptr = a.begin(); ptr < ; ptr++)
        std::cout << ptr << std::endl;
}
