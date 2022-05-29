#include <iostream>
#include <memory>
#include "vector.hpp"
#include <vector>

int main(void)
{
    ft::vector <int> mine(10, 5);
	std::vector<int> orig(10, 5);

    ft::vector<int>::iterator mIter = mine.begin();
    std::vector<int>::iterator oIter = orig.begin();

    std::cout << "mine --- size: " << mine.size() << std::endl;
    std::cout << "orig --- size: " << orig.size() << std::endl;

    std::cout << "mine --- begin: " << *mIter << std::endl;
    std::cout << "orig --- begin: " << *oIter << std::endl;

    std::cout << "mine --- capacity: " << mine.capacity() << std::endl;
    std::cout << "orig --- capacity: " << orig.capacity() << std::endl;

    mine.reserve(12);
    orig.reserve(12);

    std::cout << "mine --- capacity after reserve: " << mine.capacity() << std::endl;
    std::cout << "orig --- capacity after reserve: " << orig.capacity() << std::endl;

    std::cout << "mine --- size: " << mine.size() << std::endl;
    std::cout << "orig --- size: " << orig.size() << std::endl;

    std::cout << "mine --- not empty: " << mine.empty() << std::endl;
    std::cout << "orig --- not empty: " << orig.empty() << std::endl;

    ft::vector <int> test_mine;
	std::vector<int> test_orig;

    std::cout << "mine --- empty: " << test_mine.empty() << std::endl;
    std::cout << "orig --- empty: " << test_orig.empty() << std::endl;

    std::cout << "mine --- begin: " << *mIter << std::endl;
    std::cout << "orig --- begin: " << *oIter << std::endl;

    // ft::vector<int>::const_iterator ct_mIter = mine.begin();
    // std::vector<int>::const_iterator ct_oIter = orig.begin();

    // std::cout << "mine --- begin: " << *mIter << std::endl;
    // std::cout << "orig --- begin: " << *ct_oIter << std::endl;

    mIter = mine.end();
    oIter = orig.end();

    std::cout << "mine --- end: " << *mIter << std::endl;
    std::cout << "orig --- end: " << *oIter << std::endl;

    size_t oPtr = orig.size();
    size_t mPtr = mine.size();

    std::cout << "mine --- size: " << mine.size() << std::endl;
    std::cout << "orig --- size: " << orig.size() << std::endl;

    std::cout << "mine --- max size: " << mine.max_size() << std::endl;
    std::cout << "orig --- max size: " << orig.max_size() << std::endl;

    // mine.resize(5, 2);
    // orig.resize(6, 2);

    // std::cout << "mine --- resize: " << mine.size() << std::endl;
    // std::cout << "orig --- resize: " << orig.size() << std::endl;

    return (0);
}
