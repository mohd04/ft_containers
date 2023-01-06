#include <iostream>
#include <memory>
// #include "../include/containers/vector.hpp"
#include "../../lowke/vector/vector.hpp"
#include <vector>
#define TESTED_NAMESPACE ft
#define TESTED_TYPE int

int main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator ite = vct.begin();

    return (0);
}
