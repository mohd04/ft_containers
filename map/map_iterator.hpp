#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "../util.hpp"

namespace ft {
  template<class T, class Node, class Compare, class tree>
  class map_iterator : std::iterator<std::bidirectional_iterator_tag, T> {

    private:
      Node*             _ptr;
      tree              const *_tree;
      Compare           _comp;

    public:
      map_iterator() : _ptr(NULL), _tree(NULL) {}
      map_iterator(Node* ptr, tree const *treee) : _ptr(ptr), _tree(treee) {}
      map_iterator(map_iterator const &other) { *this = other; }
      virtual ~map_iterator() {}

      Node* base() const { return _ptr; }

      map_iterator& operator=(map_iterator const &other) {
        if (this != &other) {
          _ptr = other._ptr;
          _tree = other._tree;
        }
        return *this;
      }

      T* operator->() const { return &(_ptr->data); }

      T& operator*() const { return *_ptr->data; }

      map_iterator& operator++() {
        if (_ptr->right) {
          _ptr = _ptr->right;
          while (_ptr->left)
            _ptr = _ptr->left;
        }
        else {
          Node* tmp = _ptr->parent;
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
          Node* tmp = _ptr->parent;
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
