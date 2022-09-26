#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iostream>
#include <memory>
#include <iterator>
#include <cstddef>

namespace ft {
    template < class Iterator >
    class reverse_iterator {
        public:
            typedef Iterator                                        iterator_type;
            typedef iterator_traits<Iterator>::iterator_category    iterator_category;
            typedef iterator_traits<Iterator>::value_type           value_type;
            typedef iterator_traits<Iterator>::difference_type      difference_type;
            typedef iterator_traits<Iterator>::pointer              pointer;
            typedef iterator_traits<Iterator>::reference            reference;

            reverse_iterator() : _rItr(Iterator()) { }

            explicit reverse_iterator(iterator_type it) : _rItr(it) { }

            iterator_type       base() const { return _rItr; }

            reference           operator*() const { iterator_type ptr = _rItr; return *(--ptr); }

            reverse_iterator    operator+( difference_type n ) const { return reverse_iterator(_rItr - n); }

            reverse_iterator&   operator++() { return reverse_iterator(--_rItr); }

            reverse_iterator    operator++(int) { reverse_iterator tmp = _rItr; _rItr--; return reverse_iterator(tmp); }

            reverse_iterator&   operator+=(difference_type n ) { _rItr -= n; return *this; }

            reverse_iterator    operator-( difference_type n ) const { return reverse_iterator(_rItr + n); }

            reverse_iterator&   operator--() { return reverse_iterator(++_rItr); }

            reverse_iterator    operator--(int) { reverse_iterator tmp = _rItr; _rItr++; return reverse_iterator(tmp); }

            reverse_iterator&   operator-=( difference_type n ) { _rItr += n; return *this; }

            pointer             operator->() const { return &(operator*()); }

            reference           operator[]( difference_type n ) const { return _rItr.base()[-n - 1]; }

        protected:
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
