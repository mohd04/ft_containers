#ifndef ITERATOR_RELATIONAL_OPERATORS_HPP
# define ITERATOR_RELATIONAL_OPERATORS_HPP

namespace ft {
  template <class Iterator1, class Iterator2>
  bool operator== ( const Iterator1 & lhs,
                    const Iterator2 & rhs) {
        return lhs.base() == rhs.base();
        }

  template <class Iterator1, class Iterator2>
  bool operator!= ( const Iterator1 & lhs,
                    const Iterator2 & rhs) {
        return lhs.base() != rhs.base();
        }

  template <class Iterator1, class Iterator2>
  bool operator<  ( const Iterator1 & lhs,
                    const Iterator2 &rhs) {
        return lhs.base() < rhs.base();
        }

  template <class Iterator1, class Iterator2>
  bool operator<= ( const Iterator1  &lhs,
                    const Iterator2 & rhs) {
        return lhs.base() <= rhs.base();
        }

  template <class Iterator1, class Iterator2>
  bool operator>  ( const Iterator1  &lhs,
                    const Iterator2 & rhs) {
        return lhs.base() > rhs.base();
        }

  template <class Iterator1, class Iterator2>
  bool operator>= ( const Iterator1 & lhs,
                    const Iterator2 & rhs) {
        return lhs.base() >= rhs.base();
        }

  template <class Iterator>
  Iterator operator+ (typename Iterator::difference_type n,
             const Iterator& it) {
        return (it + n);
        }

  template <class Iterator1, class Iterator2>
  typename Iterator2::difference_type operator- (const Iterator1& lhs,
             const Iterator2& rhs) {
        return lhs.base() - rhs.base();
        }
}

#endif
