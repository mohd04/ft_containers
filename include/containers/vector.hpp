#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include "../utilities/util.hpp"

namespace ft
{
  template <class T, class Alloc = std::allocator<T> >
  class vector
  {

  public:
    typedef T                                             value_type;
    typedef Alloc                                         allocator_type;
    typedef typename allocator_type::reference            reference;
    typedef typename allocator_type::const_reference      const_reference;
    typedef typename allocator_type::pointer              pointer;
    typedef typename allocator_type::const_pointer        const_pointer;
    typedef typename allocator_type::size_type            size_type;
    typedef ft::vector_iterator<value_type>                  iterator;
    typedef ft::vector_iterator<const value_type>            const_iterator;
    typedef ft::reverse_iterator<iterator>                reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>          const_reverse_iterator;
    typedef ptrdiff_t                                     difference_type;

  private:
    allocator_type      _alloc;
    pointer             _begin;
    size_type             _end;
    size_type             _capacity;

  public:
    explicit vector(const allocator_type& alloc = allocator_type()) :
    _alloc(alloc),
    _begin(NULL),
    _end(0),
    _capacity(0) {};

    explicit vector(size_type n, const value_type& val = value_type(),
                    const allocator_type& alloc = allocator_type()) :
                    _alloc(alloc),
                    _begin(NULL),
                    _end(0),
                    _capacity(0) {
                    if (n > max_size())
                      throw std::length_error("Vector constructor error");
                    _allocate(*this, n, val);
                    };

    template <class InputIterator>
    vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last,
           const allocator_type& alloc = allocator_type()) :
           _alloc(alloc),
           _begin(NULL),
           _end(0),
           _capacity(0) {
           size_type n = ft::distance(first, last);
           if (n > max_size())
             throw std::length_error("Vector constructor error");
           _allocate(*this, n, value_type());
           assign(first, last);
           };

    vector(const vector& x) : _alloc(x.get_allocator()), _begin(NULL), _end(0), _capacity(0) {
      *this = x;
    };

    ~vector() {
      if (_begin) {
        clear();
        _alloc.deallocate(_begin, _capacity);
        _capacity = 0;
      }
    };

    vector& operator=(vector const & x) {
      clear();
      _alloc.deallocate(_begin, _capacity);

      _end = _capacity = x._end;
      _begin = _alloc.allocate(_end);

      for (size_type i = 0; i < _end; i++) {
        _alloc.construct( _begin + i, *(x._begin + i));
      }

      return (*this);
    };

    void assign(size_type n, const value_type& val) {
      if (n > max_size())
        throw std::length_error("Vector assign error");
      if (n > _capacity)
        reserve(n);
      for (size_type i = 0; i < n; i++)
        _alloc.construct(_begin + i, val);
      for (size_type i = n; i < _end; i++)
        _alloc.destroy(_begin + i);
      _end = n;
    }

    template <class InputIterator>
    void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last) {
      size_type n = 0;
      for (InputIterator it = first; it != last; it++)
        n++;
      if (n > max_size())
        throw std::length_error("Vector assign error");
      if (n > _capacity)
        reserve(n);
      for (size_type i = 0; i < n; i++)
        _alloc.construct(_begin + i, *first++);
      for (size_type i = n; i < _end; i++)
        _alloc.destroy(_begin + i);
      _end = n;
    }

    // Iterators

    iterator    begin() {
      return iterator(_begin);
    }

    const_iterator  begin() const {
      return const_iterator(_begin);
    }

    iterator    end() {
      return iterator(_begin + _end);
    }

    const_iterator  end() const {
        return const_iterator(_begin + _end);
    }

    reverse_iterator    rbegin() {
      return reverse_iterator(end());
    }

    const_reverse_iterator  rbegin() const {
      return const_reverse_iterator(end());
    }

    reverse_iterator    rend() {
      return reverse_iterator(begin());
    }

    const_reverse_iterator  rend() const {
      return const_reverse_iterator(begin());
    }

    // Capacity

    bool    empty() const {
      return (_end == 0);
    }

    size_type    size() const {
      return _end;
    }

    size_type    max_size() const {
      return (allocator_type().max_size());
    }

    size_type    capacity() const {
      return _capacity;
    }

    void    resize(size_type n, value_type val = value_type()) {
      if (n <= size()) {
        for (size_type i = n; i < size(); i++)
          _alloc.destroy(_begin + i);
        _end = n;
      }
      reserve(n);
      if (n > size()) {
        for (size_type i = size(); i < n; i++)
          _alloc.construct(_begin + i, val);
        _end = n;
      }
    }

    void    reserve(size_type n) {
      if (n > max_size())
        throw std::length_error("Vector reserve error");
      else if (_capacity < n) {
        pointer tmp = _alloc.allocate(n);
        size_type s = _end;
        for (size_type i = 0; i < _end; i++)
          _alloc.construct(tmp + i, _begin[i]);
        this->~vector();

        _begin = tmp;
        _capacity = n;
        _end = s;
      }
    }

    void clear() {
      for (size_type i = 0; i < _end; i++)
        _alloc.destroy(_begin + i);
      _end = 0;
    }

    void insert(iterator position, size_type n, const value_type &val) {
      size_type pos = position - begin();
      if (n > max_size() - size())
        throw std::length_error("Vector insert error");
      if (n > _capacity - size())
        reserve(std::max(_capacity *2, _end + n));
      for (size_type i = size(); i > pos; i--)
        _begin[i + n - 1] = _begin[i - 1];
      for (size_type i = 0; i < n; i++)
        _alloc.construct(_begin + pos + i, val);
      _end += n;
    }

    iterator insert(iterator position, const value_type &val) {
      insert(position, 1, val);
      return (begin() + (position - begin()));
    }

    template <class InputIterator>
    void insert (iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value,InputIterator>::type first, InputIterator last) {
      size_type n = ft::distance(first, last);
      size_type pos = position - begin();
      if (n > max_size() - size())
        throw std::length_error("Vector insert error");
      if (n > _capacity - size())
        reserve(std::max(_capacity *2, _end + n));
      for (size_type i = size(); i > pos; i--)
        _begin[i + n - 1] = _begin[i - 1];
      for (size_type i = 0; i < n; i++)
        _alloc.construct(_begin + pos + i, *(first++));
      _end += n;
    }

    iterator erase(iterator position) {
      size_type pos = position - begin();
      for (size_type i = pos; i < size() - 1; i++)
        _begin[i] = _begin[i + 1];
      _alloc.destroy(_begin + size() - 1);
      _end--;
      return (begin() + pos);
    }

    iterator erase(iterator first, iterator last) {
      size_type n = last - first;
      size_type pos = first - begin();
      for (size_type i = pos; i < size() - n; i++)
        _begin[i] = _begin[i + n];
      for (size_type i = 0; i < n; i++)
        _alloc.destroy(_begin + size() - i - 1);
      _end -= n;
      return (begin() + pos);
    }

    void push_back(const value_type& val) {
      if (!_capacity)
        reserve(1);
      else if (_end == _capacity)
        reserve(_capacity * 2);
      _alloc.construct(_begin + _end, val);
      _end++;
    }

    void pop_back() {
      resize(size() - 1);
    }

    // Element access

    reference   operator[](size_type _n) {
        return *(_begin + _n);
    }

    const_reference operator[](size_type _n) const {
        return *(_begin + _n);
    }

    reference   at(size_type _n) {
        _range_check(_n);
        return (*this)[_n];
    }

    const_reference at(size_type _n) const {
        _range_check(_n);
        return (*this)[_n];
    }

    reference   front() {
        return *begin();
    }

    const_reference front() const {
        return *begin();
    }

    reference   back() {
        return *(end() - 1);
    }

    const_reference back() const {
        return *(end() - 1);
    }

    pointer data() {
        return _begin;
    }

    const_pointer data() const {
        return _begin;
    }

    void swap(vector& x) {
        allocator_type tmp = x._alloc;
        pointer tmp_begin = x._begin;
        size_type tmp_end = x._end;
        size_type tmp_capacity = x._capacity;

        x._alloc = _alloc;
        x._begin = _begin;
        x._end = _end;
        x._capacity = _capacity;

        _alloc = tmp;
        _begin = tmp_begin;
        _end = tmp_end;
        _capacity = tmp_capacity;
    }

    // Allocator

    allocator_type get_allocator() const {
        return (_alloc);
    }

  private:

    void    _range_check(size_type _n) const {
      if (_n >= size())
          throw std::out_of_range("Error: out of size range.");
    }

    void    _allocate(vector &v, size_t &n, const value_type &val) {
      if (n) {
        v._begin = _alloc.allocate(n);
        v._capacity = (n);
        v._end = n;
      }
      for (size_type i = 0; i < n; i++)
        _alloc.construct(&_begin[i], val);
    }

  };

  template <class T, class Alloc>
  bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    if (lhs.size() != rhs.size())
      return false;
    return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
  }

  template <class T, class Alloc>
  bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    return !(lhs == rhs);
  }

  template <class T, class Alloc>
  bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
  }

  template <class T, class Alloc>
  bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    return !(rhs < lhs);
  }

  template <class T, class Alloc>
  bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    return rhs < lhs;
  }

  template <class T, class Alloc>
  bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
    return !(lhs < rhs);
  }
}

#endif
