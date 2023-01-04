#include <iostream>
#include <memory>
#include "../include/containers/vector.hpp"
#include <vector>

int main(void)
{
    ft::vector <int> mine(5, 5);

    std::cout << "mine: " << mine[1] << std::endl;

    return (0);
}
