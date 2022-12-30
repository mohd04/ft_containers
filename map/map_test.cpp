#include "../include/containers/map.hpp"
#include <map>

void ft_map() {
  ft::map<int, int> tree;
  ft::map<int, int> tree2;

  tree.insert(ft::pair<int, int>(1, 1));
  tree.insert(ft::pair<int, int>(-1, 1));
  tree.insert(ft::pair<int, int>(4, 1));
  tree.insert(ft::pair<int, int>(5, 1));
  tree.insert(ft::pair<int, int>(-32, 1));
  tree.insert(ft::pair<int, int>(0, 1));

  ft::map<int, int>::iterator it = tree.begin();
  std::cout << "Value of begin: " << it->first << ":" << it->second << std::endl;
  ft::map<int, int>::iterator end = tree.end();
  std::cout << "Value of end: " << end->first << ":" << end->second << std::endl;

  while (it != end)
  {
    // std::cout << "Check" << std::endl;
    std::cout << it->first << ":" << it->second << std::endl;
    // std::cout << "Ctest" << std::endl;
    it++;
  }
  std::cout << "-------------------------------------" << std::endl;
}

void std_map() {
  std::map<int, int> std_tree;
  std_tree.insert(std::pair<int, int>(1, 1));
  std_tree.insert(std::pair<int, int>(-1, 1));
  std_tree.insert(std::pair<int, int>(4, 1));
  std_tree.insert(std::pair<int, int>(5, 1));
  std_tree.insert(std::pair<int, int>(-32, 1));

  std::map<int, int>::iterator it = std_tree.begin();
  std::cout << "Value of begin: " << it->first << ":" << it->second << std::endl;
  std::map<int, int>::iterator end = std_tree.end();
  std::cout << "Value of end: " << end->first << ":" << end->second << std::endl;

  while (it != end) {
    std::cout << it->first << ":" << it->second << std::endl;
    it++;
  }

}

int main()
{
  ft_map();

  std_map();


}
