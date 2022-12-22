#ifndef NODE_HPP
# define NODE_HPP

namespace ft
{
  template<class T>
  class Node {
  public:
    typedef T     value_type;

  public:
    int           bf;
    value_type    *data;
    Node<T>       *left;
    Node<T>       *right;
    Node<T>       *parent;
    int           height;

    Node() : bf(0), data(NULL), left(NULL), right(NULL), parent(NULL), height(0) {}

    Node(const value_type &val) : bf(0), data(value_type(val)), left(NULL), right(NULL), parent(NULL), height(0) {}

    Node(const Node& other) : bf(other.bf), data(other.data), left(other.left), right(other.right), parent(other.parent), height(other.height) {}

    Node& operator=(const Node& other) {
      if (this != &other) {
        bf = other.bf;
        data = other.data;
        left = other.left;
        right = other.right;
        parent = other.parent;
        height = other.height;
      }
      return *this;
    }

    virtual ~Node() {}
  };

  template<class T>
  bool operator==(const Node<T>& lhs, const Node<T>& rhs) {
    return lhs.data == rhs.data;
  }

  template<class T>
  bool operator!=(const Node<T>& lhs, const Node<T>& rhs) {
    return !(lhs == rhs);
  }

} // namespace ft

#endif
