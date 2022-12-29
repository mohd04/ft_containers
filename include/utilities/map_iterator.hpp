#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "util.hpp"

namespace ft {
  template<typename T, typename node_pointer>
  class map_iterator {

    typedef T value_type;
    typedef value_type* pointer;
    typedef value_type& reference;
    typedef std::ptrdiff_t difference_type;
    typedef ft::bidirectional_iterator_tag iterator_category;

    private:
      node_pointer             _ptr;

    public:
      map_iterator() : _ptr(NULL) {}
      map_iterator(node_pointer ptr) : _ptr(ptr) {}
      map_iterator(map_iterator const &other) : _ptr(other._ptr) { *this = other; }
      virtual ~map_iterator() {}

      node_pointer base() const { return _ptr; }

      map_iterator& operator=(map_iterator const &other) {
        if (this != &other) {
          _ptr = other._ptr;
        }
        return *this;
      }

      T* operator->() const { return &(_ptr->data); }

      T& operator*() const { return *_ptr->data; }

      map_iterator& operator++() {
        std::cout << "Check iterator" << std::endl;
        if (_ptr->right) {
          _ptr = _ptr->right;
          while (_ptr->left)
            _ptr = _ptr->left;
        }
        else {
          std::cout << "here" << std::endl;
          node_pointer tmp = _ptr->parent;
          while (tmp && _ptr == tmp->right) {
            _ptr = tmp;
            tmp = tmp->parent;
          }
          _ptr = tmp;
        }
        return *this;
      }

      map_iterator operator++(int) {
        map_iterator tmp(*this);
        ++(*this);
        return tmp;
      }

      map_iterator& operator--() {
        if (_ptr->left) {
          _ptr = _ptr->left;
          while (_ptr->right)
            _ptr = _ptr->right;
        }
        else {
          node_pointer tmp = _ptr->parent;
          while (tmp && _ptr == tmp->left) {
            _ptr = tmp;
            tmp = tmp->parent;
          }
          _ptr = tmp;
        }
        return *this;
      }

      map_iterator operator--(int) {
        map_iterator tmp(*this);
        --(*this);
        return tmp;
      }

      friend bool operator==(map_iterator const &lhs, map_iterator const &rhs) {
        return lhs._ptr == rhs._ptr;
      }

      friend bool operator!=(map_iterator const &lhs, map_iterator const &rhs) {
        return !(lhs == rhs);
      }

  };
}

#endif
