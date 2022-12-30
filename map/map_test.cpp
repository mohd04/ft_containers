#include "../include/containers/map.hpp"
#include <iostream>
#include <map>

void ft_map() {
  ft::map<int, std::string> mp, mp2;

  mp.insert(ft::pair<int, std::string>(42, "lol"));
  mp.insert(ft::pair<int, std::string>(42, "hello"));
  mp.insert(ft::pair<int, std::string>(50, "mdr"));
  mp.insert(ft::pair<int, std::string>(35, "funny"));
  mp.insert(ft::pair<int, std::string>(45, "bunny"));
  mp.insert(ft::pair<int, std::string>(21, "fizz"));
  mp.insert(ft::pair<int, std::string>(38, "buzz"));

  mp.print2D();

  ft::map<int, std::string>::iterator it = mp.begin();
  std::cout << "begin" << it->first << " " << it->second << std::endl;
  ft::map<int, std::string>::iterator ite = mp.end();
  std::cout << ite->first << " " << ite->second << std::endl;

  while (it != ite) {
    std::cout << it->first << " " << it->second << std::endl;
    it++;
  }
  std::cout << "----------------" << std::endl;
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

  std_map();


}
