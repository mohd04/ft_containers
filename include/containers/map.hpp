#ifndef MAPP_HPP
# define MAPP_HPP

# include <iostream>
# include "../utilities/util.hpp"
# include "../utilities/map_iterator.hpp"

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
      clear();
    }

    map& operator= ( const map& x ) {
      if (this != &x) {
        clear();
        if (x._size > 0)
          insert(x.begin(), x.end());
      }
      return *this;
    }

    iterator begin() {
      node_pointer n = _root;
      if (!n->left && !n->right)
        return (end());
      if (!n->left && n->right)
        n = n->right;
      while (n->left)
        n = n->left;
      n->parent = _root;
      return (iterator(n));
    }

    const_iterator begin() const {
      if (this->_size == 0)
        return const_iterator();
      return const_iterator(_root);
    }

    iterator end() {
      node_pointer tmp = _root;
      while (tmp->right != NULL)
        tmp = tmp->right;
      return iterator(tmp);
    }

    const_iterator end() const {
      node_pointer tmp = _root;
      while (tmp->right != NULL)
        tmp = tmp->right;
      return const_iterator(tmp);
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

    void inOrder(node_pointer root) {
      if (root != NULL) {
        inOrder(root->left);
        std::cout << root->data.first << " " << root->data.second << std::endl;
        inOrder(root->right);
      }
    }

    std::pair<iterator, bool>   insert(const value_type& value) {
      _root = _insert(value, _root);
      // node_pointer tmp = _root;
      // std::cout << "Before while" << std::endl;
      // inOrder(tmp);
      // std::cout << "After while" << std::endl;
      return std::pair<iterator, bool>(iterator(_root), true);
    }

    template <class InputIterator>
    void insert(InputIterator first, InputIterator last) {
      while (first != last) {
        insert(*first);
        first++;
      }
    }

    void clear() {
      _clear(_root);
      _root = NULL;
      _size = 0;
    }

    void swap(map& x) {
      std::swap(_root, x._root);
      std::swap(_size, x._size);
      std::swap(_comp, x._comp);
      std::swap(_alloc, x._alloc);
      std::swap(_node_alloc, x._node_alloc);
    }

    size_type count(const key_type& k) const {
      return (find(k) != end());
    }

    iterator find(const key_type& k) {
      node_pointer  node = _root;
      while (node != NULL) {
        if (_comp(k, node->data.first))
          node = node->left;
        else if (_comp(node->data.first, k))
          node = node->right;
        else
        {
          std::cout << "found" << node->data.first << std::endl;
          return iterator(node);
        }
      }
      return end();
    }

    const_iterator find(const key_type& k) const {
      node_pointer  node = _root;
      while (node != NULL) {
        if (_comp(k, node->data.first))
          node = node->left;
        else if (_comp(node->data.first, k))
          node = node->right;
        else
          return const_iterator(node);
      }
      return end();
    }

    std::pair<iterator, iterator> equal_range(const key_type& k) {
      return std::pair<iterator, iterator>(lower_bound(k), upper_bound(k));
    }

    std::pair<const_iterator, const_iterator> equal_range(const key_type& k) const {
      return std::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
    }

    iterator lower_bound(const key_type& k) {
      iterator  it = begin();
      while (it != end()) {
        if (!_comp(it->first, k))
          return it;
        it++;
      }
      return it;
    }

    const_iterator lower_bound(const key_type& k) const {
      const_iterator  it = begin();
      while (it != end()) {
        if (!_comp(it->first, k))
          return it;
        it++;
      }
      return it;
    }

    iterator upper_bound(const key_type& k) {
      iterator  it = begin();
      while (it != end()) {
        if (_comp(k, it->first))
          return it;
        it++;
      }
      return it;
    }

    const_iterator upper_bound(const key_type& k) const {
      const_iterator  it = begin();
      while (it != end()) {
        if (_comp(k, it->first))
          return it;
        it++;
      }
      return it;
    }

    key_compare key_comp() const {
      return _comp;
    }

    value_compare value_comp() const {
      return value_compare(_comp);
    }

    private:
      node_pointer  _create_node(const value_type& val, node_pointer parent) {
        node_pointer new_node = _node_alloc.allocate(1);
        _node_alloc.construct(new_node, node_type(val, NULL, NULL, parent));
        return new_node;
      }

      int height(node_pointer node) {
        if (node == NULL) return 0;
        return node->height;
      }

      int getBalance(node_pointer N) {
        if (N == NULL) return 0;
        return height(N->left) - height(N->right);
      }

      node_pointer    _insert(const value_type& val, node_pointer node) {
        if (node == NULL) {
          _size++;
          return _create_node(val, node);
        }

        if (_comp(val.first, node->data.first)) {
          node->left = _insert(val, node->left);
          // std::cout << "left val: " << node->left->data.first << std::endl;
        }
        else if (_comp(node->data.first, val.first)) {
          node->right = _insert(val, node->right);
          // std::cout << "right val: " << node->right->data.first << std::endl;
        }
        else
          return node;

        node->height = 1 + std::max(height(node->left), height(node->right));

        int bal = height(node->left) - height(node->right);

        if (bal > LH && _comp(val.first, node->left->data.first))
          return _rotate_right(node);

        if (bal < RH && _comp(node->right->data.first, val.first))
          return _rotate_left(node);

        if (bal > LH && _comp(node->left->data.first, val.first)) {
          node->left = _rotate_left(node->left);
          return _rotate_right(node);
        }

        if (bal < RH && _comp(val.first, node->right->data.first)) {
          node->right = _rotate_right(node->right);
          return _rotate_left(node);
        }

        return node;
      }

      node_pointer  _rotate_left(node_pointer &node) {
        // std::cout << "rotate left val: " << node->data.first << std::endl;
        node_pointer right_tree = node->right;
        node_pointer N2 = right_tree->left;

        right_tree->left = node;
        node->right = N2;

        node->height = std::max(height(node->left), height(node->right)) + 1;
        right_tree->height = std::max(height(right_tree->left), height(right_tree->right)) + 1;
        return right_tree;
      }

      node_pointer  _rotate_right(node_pointer &node) {
        // std::cout << "rotate right val: " << node->data.first << std::endl;
        node_pointer left_tree = node->left;
        node_pointer N2 = left_tree->right;
        left_tree->right = node;
        node->left = N2;

        node->height = std::max(height(node->left), height(node->right)) + 1;
        left_tree->height = std::max(height(left_tree->left), height(left_tree->right)) + 1;
        return left_tree;
      }

      void  _clear(node_pointer &node) {
        if (node == NULL) {
          return;
        }
        _clear(node->left);
        _clear(node->right);
        _node_alloc.destroy(node);
        _node_alloc.deallocate(node, 1);
      }
  };

  // template <class Key, class T, class Compare, class Alloc>
  // bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
  //   return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
  // }

  template <class Key, class T, class Compare, class Alloc>
  bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
    return !(lhs == rhs);
  }

  template <class Key, class T, class Compare, class Alloc>
  bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
    return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
  }

  template <class Key, class T, class Compare, class Alloc>
  bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
    return !(rhs < lhs);
  }

  template <class Key, class T, class Compare, class Alloc>
  bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
    return (rhs < lhs);
  }

  template <class Key, class T, class Compare, class Alloc>
  bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ) {
    return !(lhs < rhs);
  }

  template <class Key, class T, class Compare, class Alloc>
  void swap (ft::map<Key,T,Compare,Alloc>& x, ft::map<Key,T,Compare,Alloc>& y) {
    x.swap(y);
  }
}


#endif
