#include <iostream>
#include <memory>
#include "vector.hpp"
#include <vector>

int main(void)
{
    ft::vector <int> mine(5, 5);
	std::vector<int> orig(5, 5);

    ft::vector<int>::iterator mIter = mine.begin();
    std::vector<int>::iterator oIter = orig.begin();

    std::cout << "mine --- begin: " << *mIter << std::endl;
    std::cout << "orig --- begin: " << *oIter << std::endl;

    mIter = mine.end();
    oIter = orig.end();

    std::cout << "mine --- end: " << *mIter << std::endl;
    std::cout << "orig --- end: " << *oIter << std::endl;

    std::cout << "mine --- size: " << mine.size() << std::endl;
    std::cout << "orig --- size: " << orig.size() << std::endl;

    for (ft::vector<int>::iterator i = mine.begin(); i < mine.end(); i++)
    {
        std::cout << "okay" << std::endl;
        std::cout << "here " << *i << std::endl;
    }

    for (std::vector<int>::iterator i = orig.begin(); i < orig.end(); i++)
        std::cout << "orig " << *i << std::endl;

    std::cout << "mine --- end: " << *mIter << std::endl;
    std::cout << "orig --- end: " << *oIter << std::endl;

    std::cout << "mine --- size: " << mine.size() << std::endl;
    std::cout << "orig --- size: " << orig.size() << std::endl;

    std::cout << "mine --- capacity: " << mine.capacity() << std::endl;
    std::cout << "orig --- capacity: " << orig.capacity() << std::endl;

    mine.reserve(5);
    orig.reserve(5);

    std::cout << "\n--------------- after reserve-------------------" << std::endl;

    mIter = mine.begin();
    oIter = orig.begin();

    std::cout << "mine --- begin: " << *mIter << std::endl;
    std::cout << "orig --- begin: " << *oIter << std::endl;

    mIter = mine.end();
    oIter = orig.end();

    std::cout << "mine --- end: " << *mIter << std::endl;
    std::cout << "orig --- end: " << *oIter << std::endl;

    std::cout << "mine --- size: " << mine.size() << std::endl;
    std::cout << "orig --- size: " << orig.size() << std::endl;

    std::cout << "mine --- capacity: " << mine.capacity() << std::endl;
    std::cout << "orig --- capacity: " << orig.capacity() << std::endl;

    return (0);
}
