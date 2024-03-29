#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {
  template <class T1, class T2>
  struct pair {
    typedef T1       first_type;
    typedef T2       second_type;

    first_type                first;
    second_type               second;

    pair() : first(first_type()), second(second_type()) {}

    pair( const T1& x, const T2& y ) : first(x), second(y) {}

    template< class U1, class U2 >
    pair( const pair<U1, U2>& p ) : first(p.first), second(p.second) { }

    ~pair() {}

    pair& operator= (const pair& pr) {
      if (this != &pr) {
        first = pr.first;
        second = pr.second;
      }
      return *this;
    }
  };

  template <class T1, class T2>
  bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return lhs.first==rhs.first && lhs.second==rhs.second;
  }
  template <class T1, class T2>
  bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return !(lhs==rhs);
  }
  template <class T1, class T2>
  bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
  }
  template <class T1, class T2>
  bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return !(rhs<lhs);
  }
  template <class T1, class T2>
  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return rhs<lhs;
  }
  template <class T1, class T2>
  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
    return !(lhs<rhs);
  }
}

#endif
