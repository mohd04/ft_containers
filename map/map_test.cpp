#include "../include/containers/map.hpp"
#include <map>

int main()
{
  ft::map<int, int> tree;
  ft::map<int, int> tree2;
  std::map<int, int> std_tree;

  tree.insert(ft::pair<int, int>(1, 1));
  tree.insert(ft::pair<int, int>(-1, 1));

  ft::map<int, int>::iterator it = tree.begin();
  std::cout << "found: " << it->first << std::endl;
  ft::map<int, int>::iterator end = tree.end();
  std::cout << "found: " << end->first << std::endl;

  tree2.swap(tree);

  std::cout << "count: " << tree.count(1) << std::endl;

  std::cout << "found: " << tree.find(1)->first << std::endl;

  it = tree.lower_bound(1);
  end = tree.upper_bound(1);

  std::cout << "Max size: " << tree.max_size() << std::endl;
  std::cout << "Size: " << tree.size() << std::endl;
  std::cout << "Empty: " << tree.empty() << std::endl;


  while (it != end)
  {
    std::cout << it->first << ":" << it->second << std::endl;
    it++;
  }

}
