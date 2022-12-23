#ifndef NODE_HPP
# define NODE_HPP

namespace ft
{

template <typename T>
struct Node {
  T data;
  Node *left;
  Node *right;
  Node *parent;

  Node (T val, Node *l, Node *r, Node *p) : data(val), left(l), right(r), parent(p) {}
};

} // namespace ft

#endif
