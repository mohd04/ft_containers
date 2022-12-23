#ifndef MAPP_HPP
# define MAPP_HPP

# include <iostream>
# include "../util.hpp"
# include "map_iterator.hpp"

namespace ft
{
  template < class Key,
              class T,
              class Compare = std::less<Key>,
              class Alloc = std::allocator<std::pair<const Key,T> > >
  class map {
    typedef Key                                                     key_type;
    typedef T                                                       mapped_type;
    typedef std::pair<const key_type, mapped_type>                  value_type;
    typedef Compare                                                 key_compare;
    typedef Alloc                                                   allocator_type;
    typedef value_type&                                             reference;
    typedef const value_type&                                       const_reference;
    typedef size_t                                                  size_type;
    typedef ptrdiff_t                                               difference_type;
    typedef typename Alloc::pointer                                 pointer;
    typedef typename Alloc::const_pointer                           const_pointer;
    typedef Node<value_type>                                        Node_type;
    typedef Node_type*                                              node_pointer;
    typedef ft::map_iterator<std::bidirectional_iterator_tag, value_type, key_compare, node_pointer> iterator;
    typedef ft::map_iterator<std::bidirectional_iterator_tag, const value_type, key_compare, node_pointer> const_iterator;
    typedef ft::reverse_iterator<iterator>                          reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>                    const_reverse_iterator;
    typedef typename allocator_type::template rebind<Node>::other   node_allocator;

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

    private:
      node_pointer        _root;
      size_type           _size;
      key_compare         _comp;
      allocator_type      _alloc;
      node_allocator      _node_alloc;
      node_pointer        _end;

    public:

    explicit map( const key_compare& comp = key_compare(),
                  const allocator_type& alloc = allocator_type() ) : _comp(comp), _alloc(alloc) {
      _root = NULL;
      _size = 0;
      _end = _create_node(value_type());
    }

    template <class InputIterator>
    map( InputIterator first, InputIterator last,
         const key_compare& comp = key_compare(),
         const allocator_type& alloc = allocator_type() ) : _comp(comp), _alloc(alloc) {
            _size = 0;
            _root = NULL;
            _end = _create_node(value_type());
            // insert(first, last);
         }

    map( const map& x ) : _comp(x._comp), _alloc(x._alloc) {
      _root = NULL;
      _size = 0;
      _end = _create_node(value_type());
      *this = x;
    }

    ~map() {
      // clear();
      _node_alloc.destroy(_end);
      _node_alloc.deallocate(_end, 1);
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
        return iterator(_end);
      return iterator(_root);
    }

    const_iterator begin() const {
      if (this->_size == 0)
        return const_iterator(_end);
      return const_iterator(_root);
    }

    iterator end() {
      return iterator(_end);
    }

    const_iterator end() const {
      return const_iterator(_end);
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
      if (_root == NULL) {
        _insert_root(value);
        return std::pair<iterator, bool>(iterator(_root), true);
      }
      if (_insert_node(value, _root))
        return std::pair<iterator, bool>(iterator(_root), true);
      return std::pair<iterator, bool>(iterator(_root), false);
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
        _node_alloc.construct(new_node, node(val, NULL, NULL, NULL));
        return new_node;
      }

      bool          _insert_node(const value_type &val, node_pointer node) {
        if (this->_comp(val.first, node->data.first)) {
          if (node->left == NULL) {
            node->left = _create_node(val);
            node->left->parent = node;
            this->_size++;
            return true;
          }
          return _insert_node(val, node->left);
        }
        else if (this->_comp(node->data.first, val.first)) {
          if (node->right == NULL) {
            node->right = _create_node(val);
            node->right->parent = node;
            this->_size++;
            return true;
          }
          else if (node->right == _end) {
            node->right = _create_node(val);
            node->right->parent = node;
            this->_size++;
            return true;
          }
          return _insert_node(val, node->right);
        }
        return false;
      }

      bool          _insert_root(const value_type &val) {
        if (!this->_root) {
          this->_root = _create_node(val);
          _end->parent = this->_root;
          this->_root->parent = _end;
          this->_size++;
          return true;
        }
        if (this->_root == _end) {
          node_pointer  tmp = _create_node(val);
          this->_root->parent = tmp;
          tmp->right = this->_root;
          this->_root = tmp;
          this->_size++;
          return true;
        }
        return false;
      }

  };
}


#endif
