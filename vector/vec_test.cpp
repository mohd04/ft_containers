#include <iostream>
#include <memory>
#include "vector.hpp"
#include <vector>

int main(void)
{
    ft::vector <int> mine(5, 5);
	std::vector<int> orig(10, 5);

    ft::vector<int>::iterator mIter = mine.begin();
    std::vector<int>::iterator oIter = orig.begin();

    std::cout << "mine --- begin: " << *mIter << std::endl;
    std::cout << "orig --- begin: " << *oIter << std::endl;

    ft::vector<int>::size_type Msize = mine.size();
    std::vector<int>::size_type Osize = orig.size();

    std::cout << "mine -- size: " << Msize << std::endl;
    std::cout << "orig -- size: " << Osize << std::endl;

    Msize = mine.max_capacity();
    Osize = orig.max_size();

    std::cout << "mine -- max size: " << Msize << std::endl;
    std::cout << "orig -- max size: " << Osize << std::endl;

    Msize = mine.capacity();
    Osize = orig.capacity();

    std::cout << "mine -- capacity: " << Msize << std::endl;
    std::cout << "orig -- capacity: " << Osize << std::endl;

    bool Mempty = mine.empty();
    bool Oempty = orig.empty();

    std::cout << "mine -- empty: " << Mempty << std::endl;
    std::cout << "orig -- empty: " << Oempty << std::endl;

    mine.resize(10);
    orig.resize(10);

    Msize = mine.size();
    Osize = orig.size();

    std::cout << "mine -- size after reserve: " << Msize << std::endl;
    std::cout << "orig -- size after reserve: " << Osize << std::endl;

    Msize = mine.capacity();
    Osize = orig.capacity();

    std::cout << "mine -- capacity after reserve: " << Msize << std::endl;
    std::cout << "orig -- capacity after reserve: " << Osize << std::endl;

    return (0);
}
