#include "avlTree.hpp"
#include <map>

int main()
{
    ft::AVL <int, int> avl;
    ft::Node <int> *node = NULL;

    std::cout << avl.height(node) << std::endl;
    avl.newNode(12);
    std::cout << avl.height(node) << std::endl;
}
