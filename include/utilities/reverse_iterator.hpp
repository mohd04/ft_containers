#ifndef REVERSE_iterator_HPP
#define REVERSE_iterator_HPP

namespace ft {
  template < class Iterator >
	class reverse_iterator {
    public:
      typedef Iterator                                                      iterator_type;
      typedef typename iterator_traits<Iterator>::iterator_category    iterator_category;
      typedef typename iterator_traits<Iterator>::value_type           value_type;
      typedef typename iterator_traits<Iterator>::difference_type      difference_type;
      typedef typename iterator_traits<Iterator>::pointer              pointer;
      typedef typename iterator_traits<Iterator>::reference            reference;

      reverse_iterator() : _rItr(Iterator()) { }

      explicit reverse_iterator(iterator_type it) : _rItr(it) { }

      iterator_type       base() const { return _rItr; }

      reference           operator*() const { iterator_type ptr = _rItr; return *(--ptr); }

      reverse_iterator    operator+( difference_type n ) const { return reverse_iterator(_rItr - n); }

      reverse_iterator&   operator++() { _rItr--; return *this; }

      reverse_iterator    operator++(int) { iterator_type tmp = _rItr; _rItr--; return reverse_iterator(tmp); }

      reverse_iterator&   operator+=(difference_type n ) { _rItr -= n; return *this; }

      reverse_iterator    operator-( difference_type n ) const { return reverse_iterator(_rItr + n); }

      reverse_iterator&   operator--() { _rItr++; return *this; }

      reverse_iterator    operator--(int) { iterator_type tmp = _rItr; _rItr++; return reverse_iterator(tmp); }

      reverse_iterator&   operator-=(difference_type n) { _rItr += n; return *this; }

      pointer             operator->() const { return &(operator*()); }

      reference           operator[]( difference_type n ) const { return _rItr.base()[-n - 1]; }

      operator reverse_iterator<const Iterator>() { return reverse_iterator<const Iterator>(this->base()); }


      template <class Iter>
      reverse_iterator(const reverse_iterator<Iter>& rev_rItr) : _rItr(rev_rItr.base()) {}
      ~reverse_iterator() {}

      private:
        Iterator    _rItr;
	};
    template <class Iterator>
        bool operator==( const reverse_iterator<Iterator>& lhs,
                         const reverse_iterator<Iterator>& rhs)
        { return (lhs.base() == rhs.base()); }

    template <class Iterator>
        bool operator!=( const reverse_iterator<Iterator>& lhs,
                         const reverse_iterator<Iterator>& rhs)
        { return (lhs.base() != rhs.base()); }

    template <class Iterator>
        bool operator<( const reverse_iterator<Iterator>& lhs,
                         const reverse_iterator<Iterator>& rhs)
        { return (lhs.base() > rhs.base()); }

    template <class Iterator>
        bool operator<=( const reverse_iterator<Iterator>& lhs,
                         const reverse_iterator<Iterator>& rhs)
        { return (lhs.base() >= rhs.base()); }

    template <class Iterator>
        bool operator>( const reverse_iterator<Iterator>& lhs,
                         const reverse_iterator<Iterator>& rhs)
        { return (lhs.base() < rhs.base()); }

    template <class Iterator>
        bool operator>=( const reverse_iterator<Iterator>& lhs,
                         const reverse_iterator<Iterator>& rhs)
        { return (lhs.base() <= rhs.base()); }

    template <class Iterator>
        reverse_iterator<Iterator> operator+( typename reverse_iterator<Iterator>::difference n,
                    const reverse_iterator<Iterator>& rev_it)
        { return rev_it + n; }

    template <class Iterator>
        typename reverse_iterator<Iterator>::difference_type    operator- (
            const reverse_iterator<Iterator>& lhs,
            const reverse_iterator<Iterator>& rhs)
        { return (lhs.base() - rhs.base()); }
}

#endif
