#ifndef MAPP_HPP
# define MAPP_HPP

# include <iostream>
# include "../util.hpp"
# include "map_iterator.hpp"

# define LH +1   // Left High
# define EH 0    // Even High
# define RH -1   // Right High

namespace ft
{
  template < class Key,
              class T,
              class Compare = std::less<Key>,
              class Alloc = std::allocator<std::pair<const Key,T> > >
  class map {
    public:

      typedef Key                                                     key_type;
      typedef T                                                       mapped_type;
      typedef ft::pair<const key_type, mapped_type>                   value_type;
      typedef Compare                                                 key_compare;

      class value_compare : public std::binary_function<value_type, value_type, bool> {
        protected:
          Compare comp;
          value_compare (Compare c) : comp(c) {}
        public:
          typedef bool result_type;
          typedef value_type first_argument_type;
          typedef value_type second_argument_type;
          bool operator() (const value_type& x, const value_type& y) const {
            return comp(x.first, y.first);
          }
      };

      typedef Alloc                                                   allocator_type;
      typedef typename allocator_type::reference                      reference;
      typedef typename allocator_type::const_reference                const_reference;
      typedef typename allocator_type::pointer                        pointer;
      typedef typename allocator_type::const_pointer                  const_pointer;
      typedef size_t                                                  size_type;
      typedef std::ptrdiff_t                                          difference_type;
      typedef Node<value_type>                                        node_type;
      typedef node_type*                                              node_pointer;
      typedef ft::map_iterator<value_type, node_pointer>              iterator;
      typedef ft::map_iterator<const value_type, node_pointer>        const_iterator;
      typedef ft::reverse_iterator<iterator>                          reverse_iterator;
      typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;
      typedef typename allocator_type::template rebind<node_type>::other   node_allocator;


    private:
      node_pointer        _root;
      size_type           _size;
      key_compare         _comp;
      allocator_type      _alloc;
      node_allocator      _node_alloc;

    public:

    explicit map( const key_compare& comp = key_compare(),
                  const allocator_type& alloc = allocator_type() ) : _comp(comp), _alloc(alloc) {
      _root = NULL;
      _size = 0;
    }

    template <class InputIterator>
    map( InputIterator first, InputIterator last,
         const key_compare& comp = key_compare(),
         const allocator_type& alloc = allocator_type() ) : _comp(comp), _alloc(alloc) {
            _size = 0;
            _root = NULL;
            insert(first, last);
         }

    map( const map& x ) : _comp(x._comp), _alloc(x._alloc) {
      _root = NULL;
      _size = 0;
      *this = x;
    }

    ~map() {
      // clear();
    }

    map& operator= ( const map& x ) {
      if (this != &x) {
        // clear();
        if (x._size > 0)
          insert(x.begin(), x.end());
      }
      return *this;
    }

    iterator begin() {
      if (this->_size == 0)
        return iterator();
      return iterator(_root);
    }

    const_iterator begin() const {
      if (this->_size == 0)
        return const_iterator();
      return const_iterator(_root);
    }

    iterator end() {
      return iterator();
    }

    const_iterator end() const {
      return const_iterator();
    }

    reverse_iterator rbegin() {
      return reverse_iterator(end());
    }

    const_reverse_iterator rbegin() const {
      return const_reverse_iterator(end());
    }

    reverse_iterator rend() {
      return reverse_iterator(begin());
    }

    const_reverse_iterator rend() const {
      return const_reverse_iterator(begin());
    }

    bool empty() const {
      return (_size == 0);
    }

    size_type size() const {
      return _size;
    }

    size_type max_size() const {
      return _alloc.max_size();
    }

    T& operator[] (const key_type& k) {
      iterator it = find(k);
      if (it == end()) {
        it = insert(value_type(k, T())).first;
      }
      return it->second;
    }

    iterator    insert(iterator position, const value_type& val) {
      (void)position;
      return insert(val).first;
    }

    std::pair<iterator, bool>   insert(const value_type& value) {
      bool  taller = false;
      bool  inserted = _insert(value, _root, taller);
      return std::pair<iterator, bool>(iterator(_root), inserted);
    }

    template <class InputIterator>
    void insert(InputIterator first, InputIterator last) {
      while (first != last) {
        insert(*first);
        first++;
      }
    }

    private:
      node_pointer  _create_node(const value_type& val) {
        node_pointer new_node = _node_alloc.allocate(1);
        _node_alloc.construct(new_node, node_type(val, NULL, NULL, NULL));
        return new_node;
      }

      bool    _insert(const value_type& val, node_pointer &node, bool &taller) {
        if (node == NULL) {
          std::cout << "inserting: " << val.first << std::endl;
          node = _create_node(val);
          _size++;
          taller = true;
          return true;
        }
        if (_comp(val.first, node->data.first)) {
          std::cout << "going left" << std::endl;
          _insert(val, node->left, taller);
          if (taller) {
            switch (node->bal) {
              case LH:
                node = _left_balance(node, taller);
                break;

              case EH:
                node->bal = LH;
                taller = true;
                break;

              case RH:
                node->bal = EH;
                taller = false;
                break;
            }
          }
          return true;
        }
        else if (_comp(node->data.first, val.first)) {
          std::cout << "going right" << std::endl;
          _insert(val, node->right, taller);
          if (taller) {
            switch (node->bal) {
              case LH:
                node->bal = EH;
                taller = false;
                break;

              case EH:
                node->bal = RH;
                taller = true;
                break;

              case RH:
                node = _right_balance(node, taller);
                break;
            }
          }
          return true;
        }
        return false;
      }

      node_pointer  _left_balance(node_pointer &node, bool &taller) {
        node_pointer left_tree = node->left;
        switch (left_tree->bal) {
          case LH:
            node->bal = EH;
            left_tree->bal = EH;
            node = _rotate_right(node);
            taller = false;
            break;

          case EH:
            std::cout << "Error: _left_balance: left_tree->bal == EH" << std::endl;
            break;

          case RH:
            node_pointer right_tree = left_tree->right;
            switch (right_tree->bal) {
              case LH:
                node->bal = RH;
                left_tree->bal = EH;
                break;

              case EH:
                node->bal = EH;
                left_tree->bal = EH;
                break;

              case RH:
                node->bal = EH;
                left_tree->bal = LH;
                break;
            }
            right_tree->bal = EH;
            node->left = _rotate_left(left_tree);
            node = _rotate_right(node);
            taller = false;
            break;
        }
        return node;
      }

      node_pointer  _right_balance(node_pointer &node, bool &taller) {
        node_pointer right_tree = node->right;
        switch (right_tree->bal) {
          case RH:
            node->bal = EH;
            right_tree->bal = EH;
            node = _rotate_left(node);
            taller = false;
            break;

          case EH:
            std::cout << "Error: _right_balance: right_tree->bal == EH" << std::endl;
            break;

          case LH:
            node_pointer left_tree = right_tree->left;
            switch (left_tree->bal) {
              case RH:
                node->bal = LH;
                right_tree->bal = EH;
                break;

              case EH:
                node->bal = EH;
                right_tree->bal = EH;
                break;

              case LH:
                node->bal = EH;
                right_tree->bal = RH;
                break;
            }
            left_tree->bal = EH;
            node->right = _rotate_right(right_tree);
            node = _rotate_left(node);
            taller = false;
            break;
        }
        return node;
      }

      node_pointer  _rotate_left(node_pointer &node) {
        node_pointer right_tree = node->right;
        node->right = right_tree->left;
        right_tree->left = node;
        return right_tree;
      }

      node_pointer  _rotate_right(node_pointer &node) {
        node_pointer left_tree = node->left;
        node->left = left_tree->right;
        left_tree->right = node;
        return left_tree;
      }

  };
}


#endif
