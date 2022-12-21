#ifndef AVLTREE_HPP
# define AVLTREE_HPP

# include <iostream>
# include "../util.hpp"

# define LH +1   // Left High
# define EH 0    // Even High
# define RH -1   // Right High

template <class T>
class Node {
  public:
    T               data;
    int             bal;
    Node<T>         *left_;
    Node<T>         *right_;

  public:
    Node(const T& data): data(d), left_(NULL), right_(NULL) {}
    ~Node() {}
};

template <class Key,
          class T,
          class Compare = std::less<Key>,
          class Alloc = std::allocator<ft::pair<const Key, T> > >
class AVL {

  public:
    typedef Key                                     key_type;
    typedef T                                       mapped_type;
    typedef Compare                                 key_compare;
    typedef Alloc                                   allocator_type;
    typedef ft::pair<const Key, T>                  value_type;
    typedef Node<T>*                                node_ptr;
    typedef Node<value_type>                        node;

  private:
    Node                                                        *_root;
    int                                                         _count;
    key_compare                                                 _compare;
    allocator_type                                              _allocator;
    typename allocator_type::template rebind<Node>::other       _node_allocator;

  public:
    AVL(const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()) : _count(0),
                                                                _root(NULL),
                                                                _compare(comp),
                                                                _allocator(alloc) {
    }

    ~AVL() {
      if (_root)
        _destroy(_root);
    }

    bool  AVL_insert(AVL* tree, value_type data) {
      Node*   new_ptr;
      bool    for_taller;

      new_ptr = _node_allocator().allocate(1);
      new_ptr->bal = EH;
      new_ptr->right = NULL;
      new_ptr->left = NULL;
      new_ptr->data = data;

      tree->_root = _insert(data, new_ptr, for_taller);
      (tree->_count)++;
      return true;
    }

    bool  AVL_Delete(AVL* tree, key_type key) {
      bool    shorter;
      bool    success;
      Node*   new_root;

      new_root = _delete(tree->_root, data, shorter, success);

      if (success) {
        tree->_root = new_root;
        (tree->_count)--;
        return true;
      }
      return false;
    }

    void*   AVL_Retrieve(AVL* tree, key_type key) {
      if (tree->root)
        return _retrieve(tree->_root, key);
      return NULL;
    }

    void    AVL_Traverse(AVL* tree, void (*process)(value_type data)) {
      if (tree->_root)
        _traverse(tree->_root, process);
    }

    bool  AVL_Empty(AVL* tree) {
      return (tree->_count == 0);
    }

    int   AVL_Count(AVL* tree) {
      return tree->_count;
    }

    AVL*  AVL_Destroy(AVL* tree) {
      if (tree->_root)
        _destroy(tree->_root);
      tree->_count = 0;
      tree->_root = NULL;
      return NULL;
    }

    private:

      Node*  _insert(Node* root, const value_type &data, bool &taller) {
        if (!root) {
          AVL *new_node = _node_allocator.allocate(1);
          _node_allocator.construct(new_node, data);
          new_node->_root = new_node;
        }

        if (_compare(data.first, root->data.first))
        {
          root->left = _insert(root->left, data, taller);
          if (taller)
          {
              switch (root->bal)
              {
              case LH:
                root = insLeftBal(root, taller);
                break;

              case EH:
                root->bal = LH;
                break;

              case RH:
                root->bal = EH;
                taller = false;
                break;
              }
          }
          return root;
        }
        else
        {
          root->right = _insert(root->right, data, taller);
          if (taller)
          {
            switch (root->bal)
            {
            case LH:
              taller = false;
              break;

            case EH:
              root->bal = RH;
              break;

            case RH:
              root = insRightBal(root, taller);
              break;
            }
          }
          return root;
        }
        return root;
      }

      Node*   insLeftBal(Node* root, bool &taller) {
        Node* right_tree;
        Node* left_tree;

        left_tree = root->left;
        switch (left_tree->bal)
        {
          case LH:
            root->bal = EH;
            left_tree bal = EH;

            root = rotateRight(root);
            taller = false;
            break;

          // case EH:
            // throw excpetion

          case RH:
            right_tree = left_tree->right;
            switch (right_tree->bal)
            {
            case LH:
              root->bal = RH;
              left_tree->bal = EH;
              break;

            case EH:
              root->bal = EH;
              left_tree->bal = LH;
              break;

            case RH:
              root->bal = EH;
              left_tree->bal = LH;
              break;
            }
            right_tree->bal = EH;
            root->left = rotateLeft(left_tree);
            root = rotateRight(root);
            taller = false;
        }
        return root;
      }

      Node*   rotateLeft(Node* root) {
        Node*   temp_ptr;

        temp_ptr = root->right;
        root->right = temp_ptr->left;
        temp_ptr->left = root;

        return temp_ptr;
      }

      Node*   rotateRight(Node* root) {
        Node*   temp_ptr;

        temp_ptr = root->left;
        root->left = temp_ptr->right;
        temp_ptr->right = root;

        return temp_ptr;
      }

      Node*   _delete(Node* root, key_type key, bool & shorter, bool & success) {
        Node*   dlt_ptr;
        Node*   exch_ptr;
        Node*   new_root;

        if (!root) {
          shorter = false;
          success = false;
          return NULL;
        }

        if (_compare(key, root->data.first)) {
          root->left = _delete(root->left, key, shorter, success);
          if (shorter)
            root = deleteRightBal(root, shorter);
        }
        else if (_compare(root->data.first, key)) {
          root->right = _delete(root->right, key, shorter, success);
          if (shorter)
            root = deleteLeftBal(root, shorter);
        }
        else {
          dlt_ptr = root;
          if (!root->right) {
            new_root = root->left;
            success = true;
            shorter = true;
            _node_allocator.destroy(dlt_ptr);
            _node_allocator.deallocate(dlt_ptr, 1);
            return new_root;
          }
          else if (!root->left) {
            new_root = root->right;
            success = true;
            shorter = true;
            _node_allocator.destroy(dlt_ptr);
            _node_allocator.deallocate(dlt_ptr, 1);
            return new_root;
          }
          else {
            exch_ptr = root->left;
            while (exch_ptr->right)
              exch_ptr = exch_ptr->right;
            root->data = exch_ptr->data;
            root->left = _delete(root->left, exch_ptr->data.first, shorter, success);
            if (shorter)
              root = deleteRightBal(root, shorter);
          }
        }
        return root;
      }

      Node*   deleteRightBal(Node* root, bool shorter) {
        Node*   right_tree;
        Node*   left_tree;

        switch (root->bal)
        {
        case LH:
          root->bal = EH;
          break;

        case EH:
          root->bal = RH;
          shorter = false;
          break;

        case RH:
          right_tree = root->left;
          if (right_tree->bal = LH) {
            left_tree = right_tree->left;
            switch (left_tree->bal)
            {
            case LH:
              right_tree->bal = RH;
              root->bal = EH;
              break;

            case EH:
              root->bal = RH;
              shorter = false;
              break;

            case RH:
              root->bal = LH;
              right_tree->bal = EH;
              break;
            }
            left_tree->bal = EH;

            // rotate right then left
            root->right = rotateRight(right_tree);
            root = rotateLeft(root);
          }
          else
          {
            switch (right_tree->bal)
            {
            case LH:
            case RH:
              root->bal = EH;
              right_tree->bal = EH;
              break;

            case EH:
              root->bal = RH;
              right_tree->bal = LH;
              shorter = false;
              break;
            }
            root = rotateLeft(root);
          }
        }
        return root;
      }

      void*   _retrieve(Node* root, key_type key) {
        if (!root)
          return NULL;
        if (_compare(key, root->data.first))
          return _retrieve(root->left, key);
        else if (_compare(root->data.first, key))
          return _retrieve(root->right, key);
        else
          return root->data.second;
      }

      void   _traversal(Node* root, void (*func)(value_type)) {
        if (!root)
          return;
        _traversal(root->left, func);
        func(root->data);
        _traversal(root->right, func);
      }

      void _destroy(Node* root) {
        if (!root)
          return;
        _destroy(root->left);
        _destroy(root->right);
        _node_allocator.destroy(root);
        _node_allocator.deallocate(root, 1);
      }
};

#endif
