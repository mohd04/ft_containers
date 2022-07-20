#ifndef AVLTREE_HPP
# define AVLTREE_HPP

#include <iostream>

namespace ft {
    template <class T>
    struct Node {
        T       data;
        int     balance;
        int     height;
        Node*   left;
        Node*   right;
        Node*   parent;

        Node(): left(NULL), right(NULL), parent(NULL) {}
        Node(const T& _data): data(_data) {}
        Node(const T& _data, const int _height): data(_data), balance(0), height(_height), left(NULL), right(NULL), parent(NULL) {}
    };

    template <class T, class key, class compare = std::less<key>, class Alloc = std:: allocator<Node<T> > >
    class AVL {
        public:
            typedef T                                       value_type;
            typedef Alloc                                   allocator_type;
            typedef compare                                 key_compare;
            typedef Node<T>*                                nodePtr;
            typedef typename allocator_type::size_type      size_type;

        private:
            nodePtr             _root;
            nodePtr             _end;
            allocator_type      _alloc;
            key_compare         _cmp;
            size_type           _height;

        public:
            AVL(const allocator_type alloc = allocator_type(), const key_compare& cmp = key_compare()) :
                _root(NULL),
                _end(NULL),
                _alloc(alloc),
                _cmp(cmp),
                _height(0) {
                _end = _alloc.allocate(1);
                _alloc.construct(_end);
            }

            ~AVL() {
                _alloc.deallocate(_end, 1);
                _end = NULL;
            }

            int     height(nodePtr N) {
                if (N == NULL)
                    return (0);
                return (_height);
            }

            int     max(int a, int b) {
                return (a > b)? a : b;
            }

            nodePtr     newNode(value_type data) {
                nodePtr     node = _alloc.allocate(1);
                _alloc.construct(node, data, 0);
                node->data = data;
                node->left = NULL;
                node->right = NULL;
                node->parent = node;
                this->_height++;

                std::cout<< _height << std::endl;

                return (node);
            }
    };
}

#endif
