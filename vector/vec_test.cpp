#include <iostream>
#include <memory>
#include "../include/containers/vector.hpp"
// #include "../../lowke/vector/vector.hpp"
#include <vector>
#define TESTED_NAMESPACE ft
#define TESTED_TYPE int

int main(void)
{
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(5,5);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator ite = vct.begin();

  std::cout << "iterator: " << *it << std::endl;

    return (0);
}
