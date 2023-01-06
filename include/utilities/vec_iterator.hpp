#ifndef vector_iterator_HPP
#define vector_iterator_HPP

#include "iterator_traits.hpp"

namespace ft {

template <class T>
class vector_iterator : public ft::iterator<std::random_access_iterator_tag, T> {

  public:
    typedef ft::iterator<std::random_access_iterator_tag, T>    traits_type;
    typedef typename traits_type::value_type                    value_type;
    typedef typename traits_type::pointer                       pointer;
    typedef typename traits_type::reference                     reference;
    typedef typename traits_type::difference_type               difference_type;
    typedef typename traits_type::iterator_category             iterator_category;

  private:
    pointer  _ptr;

  public:
    vector_iterator() : _ptr() {}

    vector_iterator(pointer current) : _ptr(current) {}

    template <class U>
    vector_iterator(const vector_iterator<U> &value) : _ptr(value.base()) {}

    ~vector_iterator() {}

    vector_iterator &operator=(const vector_iterator& value) {
      if (this != &value) {
        _ptr = value._ptr;
      }
      return *this;
    }

    reference operator*() const { return *_ptr; }

    pointer operator->() const { return _ptr; }

    pointer base() const { return _ptr; }

    reference operator[](difference_type n) const { return _ptr[n]; }

    vector_iterator operator+(difference_type n) const { return vector_iterator(_ptr + n); }

    vector_iterator operator-(difference_type n) const { return vector_iterator(_ptr - n); }

    vector_iterator &operator++() { _ptr++; return *this; }

    vector_iterator operator++(int) { vector_iterator temp = *this; ++(*this); return temp; }

    vector_iterator &operator--() { _ptr--; return *this; }

    vector_iterator operator--(int) { vector_iterator temp = *this; --(*this); return temp; }

    vector_iterator &operator+=(difference_type n) { _ptr += n; return *this; }

    vector_iterator &operator-=(difference_type n) { _ptr -= n; return *this; }

};

template <class Iter1, class Iter2>
bool operator==(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs) {
  return lhs.base() == rhs.base();
}

template <class Iter1, class Iter2>
bool operator!=(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs) {
  return lhs.base() != rhs.base();
}

template <class Iter1, class Iter2>
bool operator<(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs) {
  return lhs.base() < rhs.base();
}

template <class Iter1, class Iter2>
bool operator<=(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs) {
  return lhs.base() <= rhs.base();
}

template <class Iter1, class Iter2>
bool operator>(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs) {
  return lhs.base() > rhs.base();
}

template <class Iter1, class Iter2>
bool operator>=(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs) {
  return lhs.base() >= rhs.base();
}

template <class Iterator>
typename vector_iterator<Iterator>::difference_type
operator-(const vector_iterator<Iterator> &lhs, const vector_iterator<Iterator> &rhs) {
  return lhs.base() - rhs.base();
}

template <class Iterator, class I2>
typename vector_iterator<Iterator>::difference_type
operator-(const vector_iterator<Iterator> &lhs, const vector_iterator<I2> &rhs) {
  return lhs.base() - rhs.base();
}

template <class Iterator>
vector_iterator<Iterator>
operator+(typename vector_iterator<Iterator>::difference_type n, const vector_iterator<Iterator> &it) {
  return vector_iterator<Iterator>(it.base() + n);
}

}    // namespace ft

#endif
