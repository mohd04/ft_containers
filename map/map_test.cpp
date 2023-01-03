#include "../include/containers/map.hpp"
#include <iostream>
#include <map>

void ft_map() {
  ft::map<int, std::string> mp;

  ft::map<int, std::string>::iterator it = mp.begin();
  ft::map<int, std::string>::const_iterator ite = mp.begin();

  ft::map<int, std::string>::reverse_iterator rit(it);
}

void std_map() {
  std::map<int, std::string> mp;

  mp.insert(std::pair<int, std::string>(42, "lol"));
  mp.insert(std::pair<int, std::string>(42, "hello"));
  mp.insert(std::pair<int, std::string>(50, "mdr"));
  mp.insert(std::pair<int, std::string>(35, "funny"));
  mp.insert(std::pair<int, std::string>(45, "bunny"));
  mp.insert(std::pair<int, std::string>(21, "fizz"));
  mp.insert(std::pair<int, std::string>(38, "buzz"));

  std::map<int, std::string>::iterator it = mp.begin();
  std::cout << it->first << " " << it->second << std::endl;
  std::map<int, std::string>::iterator ite = mp.end();
  std::cout << ite->first << " " << ite->second << std::endl;

  while (it != ite) {
    std::cout << it->first << " " << it->second << std::endl;
    it++;
  }

}

int main()
{
  ft_map();

  // std_map();


}

// [{
// 	"resource": "/c:/Users/patmo/OneDrive/Desktop/ft_containers/map/map_test.cpp",
// 	"owner": "C/C++1",
// 	"code": "312",
// 	"severity": 8,
// 	"message": "no suitable user-defined conversion from \"ft::map_iterator<ft::pair<const int, std::__cxx11::string>, ft::Node<ft::pair<const int, std::__cxx11::string>> *>\" to \"ft::map_iterator<const ft::pair<const int, std::__cxx11::string>, ft::Node<ft::pair<const int, std::__cxx11::string>> *>\" exists",
// 	"source": "C/C++",
// 	"startLineNumber": 20,
// 	"startColumn": 50,
// 	"endLineNumber": 20,
// 	"endColumn": 52
// }]
