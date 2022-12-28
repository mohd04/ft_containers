#include "../util.hpp"
#include "map.hpp"
#include <map>

int main()
{
  ft::map<int, int> tree;

  tree.insert(ft::pair<int, int>(1, 1));
  tree.insert(ft::pair<int, int>(-1, 1));

  ft::map<int, int>::iterator it = tree.begin();
  ft::map<int, int>::iterator end = tree.end();

  while (it != end)
  {
    std::cout << it->first << ":" << it->second << std::endl;
    it++;
  }

}
