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
      node_pointer            _ptr;
      node_pointer            _sentinel;
      node_pointer            _max;

    public:
      map_iterator() : _ptr(NULL) {}
      map_iterator(node_pointer ptr) : _ptr(ptr), _sentinel(NULL), _max(NULL) {}
      map_iterator(node_pointer ptr, node_pointer sentinel, node_pointer max) : _ptr(ptr), _sentinel(sentinel), _max(max) {}
      map_iterator(map_iterator const &other) : _ptr(other._ptr) { *this = other; }
      virtual ~map_iterator() {}

      node_pointer base() const { return _ptr; }

      map_iterator& operator=(map_iterator const &other) {
        if (this != &other) {
          _ptr = other._ptr;
          _sentinel = other._sentinel;
          _max = other._max;
        }
        return *this;
      }

      T* operator->() const { return &(_ptr->data); }

      reference operator*() const { return _ptr->data; }

      map_iterator& operator++() {
        if (_ptr == _max) {
          _ptr = _sentinel;
        }
        else if (_ptr == _sentinel) {
          _ptr = _max;
        }
        else if (_ptr->right) {
          _ptr = _ptr->right;
          while (_ptr->left)
            _ptr = _ptr->left;
        }
        else {
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
        if (_ptr == _sentinel) {
          _ptr = _max;
        }
        else if (_ptr->left) {
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
