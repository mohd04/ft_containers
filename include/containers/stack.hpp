#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft {
  template < class T, class Container = ft::vector<T> >
  class stack {
    public:
     typedef Container                                    container_type;
     typedef typename container_type::value_type          value_type;
     typedef typename container_type::size_type           size_type;
     typedef typename container_type::reference           reference;
     typedef typename container_type::const_reference     const_reference;

    protected:
      container_type    _container;

    public:
      explicit stack( const Container& cont = container_type()) : _container(cont) {}

      stack( const stack& other) : _container(other._container) {}

      ~stack() {}

      stack& operator=( const stack& other) {
        if (this != &other)
          _container = other._container;
        return *this;
      }

      reference top() {
        return _container.back();
      }

      const_reference top() const {
        return _container.back();
      }

      bool empty() const {
        return _container.empty();
      }

      size_type size() const {
        return _container.size();
      }

      void push(const value_type& val) {
        _container.push_back(val);
      }

      void pop() {
        _container.pop_back();
      }

      friend bool operator==( const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
        return (lhs._container == rhs._container);
      }

      friend bool operator<( const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
        return (lhs._container < rhs._container);
      }
  };

  template <class T, class Container>
  bool operator!=( const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
    return !(lhs == rhs);
  }

  template <class T, class Container>
  bool operator>( const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
    return (rhs < lhs);
  }

  template <class T, class Container>
  bool operator<=( const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
    return !(rhs < lhs);
  }

  template <class T, class Container>
  bool operator>=( const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
    return !(lhs < rhs);
  }
}

#endif
