#ifndef AVLTREE_HPP
# define AVLTREE_HPP

# include <iostream>
# include "../util.hpp"
# include "map_iterator.hpp"

namespace ft {
template <class T, class Compare = std::less<typename T::first_type>, class Alloc = std::allocator<T> >
class AVL {
  public:
    typedef T                                                               value_type;
    typedef ft::Node<const T>                                               const_node;
    typedef ft::Node<T>                                                     node;
    typedef Alloc                                                           allocator_type;
    typedef typename Alloc::template rebind<node>::other                    node_allocator;
    typedef ft::map_iterator<T, ft::Node<T>, Compare, AVL>                  iterator;
    typedef ft::map_iterator<const T, ft::Node<const T>, Compare, AVL>      const_iterator;
    typedef ft::reverse_iterator<iterator>                                  reverse_iterator;
    typedef typename value_type::first_type                                 key;
    typedef typename value_type::second_type                                val;

  private:
    ft::Node<T>*    _root;
    node_allocator  _node_allocator;
    size_t          _size;
    pair_alloc      _pair_allocator;
    Compare         _comp;

  public:
    AVL(): _root(NULL), _size(0) {}

    AVL(const AVL &x) {
        _root = NULL;
        _size = 0;
        *this = x;
    }

    ~AVL() {
        // clear();
    }
};
}

#endif
