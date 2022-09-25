#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
#include "vec_iterator.hpp"

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
        /* member types
            - reverse_iterator
            - const_reverse_iterator
            - difference_type*/
    public:
        typedef T                                             value_type;
        typedef Alloc                                         allocator_type;
        typedef typename allocator_type::reference            reference;
        typedef typename allocator_type::const_reference      const_reference;
        typedef typename allocator_type::pointer              pointer;
        typedef typename allocator_type::const_pointer        const_pointer;
        typedef typename allocator_type::size_type            size_type;
        typedef ft::vectorIterator<value_type>                iterator;
        typedef ft::vectorIterator<const value_type>          const_iterator;
        // typedef ft::vectorRevIterator<iterator>            reverse_iterator;
    private:
        allocator_type      _alloc;
        pointer             _begin;
        size_type             _end;
        size_type             _capacity;

    public:
        explicit vector(const allocator_type& alloc = allocator_type()) :
        _alloc(alloc),
        _begin(NULL),
        _end(NULL),
        _capacity(0) {};

        explicit vector(size_type n, const value_type& val = value_type(),
                        const allocator_type& alloc = allocator_type()) :
                        _alloc(alloc),
                        _begin(NULL),
                        _end(0),
                        _capacity(0) {
                            allocNew(*this, n, val);
                        };
        // vector(const vector& x) {};
        ~vector() {}; // have to use free here
        // vector& operator=(vector& src) {};

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
        // rbegin(); have to do cons
        // rend(); have to do const

        // Capacity


        size_t    size() const {
            return _end;
        }

        size_type    max_capacity() const {
            return (allocator_type().max_size());
        }

        void    resize(size_type n, value_type val = value_type()) {
            if (n < size())
                reduce(_begin + n, n, val);
            else if (n > size()) {
                if (n > _capacity)
                    reserve(n);
                addOn(_begin + n, n, val);
            }
        }

        size_type    capacity() const {
            return _capacity - _end;
        }

        bool    empty() const {
            return (_end);
        }

        void    reserve(size_type n) {
            if (n > max_capacity())
                throw std::length_error("Vector reserve error");
            else if (n > capacity()) {

            }
        }

        // Element access

        reference   operator[](size_type _n) {
            return *(_begin + _n);
        }

        reference   at(size_type _n) {
            _range_check(_n);
            return (*this)[_n];
        }

        reference   front() {
            return *begin();
        }

        reference   back() {
            return *(end() - 1);
        }

        // Modifiers

        // assign();
        // void    assign(size_type _n, bool& _x) {

        // }

        void    push_back(const value_type& _val) {
            if (this->_end != this->_capacity) {
                _alloc.construct(_end + 1, _val);
                ++this->_end;
            }
            // else

        }

        void pop_back() {
            _alloc.destroy( _begin + _end);
            _end--;
        }
        // insert();

        iterator    insert( iterator pos, const value_type & val) {
            // if (_end >= _capacity) {
            // }
            size_type i;
            for (i = _end; _begin[i] != pos; i--) {
                _begin[i] = _begin[i - 1];
            }
            _begin[i] = pos;
            return (_begin);
        }

        void    insert(iterator pos, size_type n, const value_type &val) {
            size_type i;
            for (i = _end; _begin[i] != pos; i--) {
                _begin[i + n] = _begin[i - 1];
            }
            for (; n != 0; n--, i--)
                _begin[i] = pos;
        }
        // erase();
        iterator erase(iterator position) {
            _alloc.destory(&(*position));

            size_type   len = _end - &(*position) - 1;
            pointer     tmp = &(*position);
            while (len--) {
                _alloc.construct(tmp, *(tmp + 1));
                _alloc.destroy(tmp++);
            }
            --_end;
            return (position);
        }

        // iterator erase(iterator first, iterator last) {
        //     pointer tmp = &(*first);
        //     while (tmp != &(*last))
        //         _alloc.destroy(tmp++);
        //     size_type len = _end - &(*last);
        //     size_type range =
        // }

        void swap(vector& x) {
            allocator_type tmp = x._alloc;
            pointer tmp_begin = x._begin;
            pointer tmp_end = x._end;
            pointer tmp_capacity = x._capacity;

            x._alloc = _alloc;
            x._begin = _begin;
            x._end = _end;
            x._capacity = _capacity;

            _alloc = tmp;
            _begin = tmp_begin;
            _end = tmp_end;
            _capacity = tmp_capacity;
        }
        void clear() {
            while (_begin != _end)
                _alloc.destroy(--_end);
        }

        // Allocator

        allocator_type get_allocator() const {
            return (_alloc);
        }
    private:

        void    _range_check(size_type _n) const {
            if (_n >= this->size())
                throw   std::out_of_range("Error: out of size range.");
        }

        void    allocNew(vector &v, size_t &n, const value_type &val) {
            if (n) {
                v._begin = _alloc.allocate(n * 2);
                v._capacity = (n * 2);
                v._end = n;
            }
            for (size_type i = 0; i < n; i++)
                _alloc.construct(&_begin[i], val);
        }

        iterator    addOn(iterator position, size_t &n, const value_type &val) {
            for (size_type i = _end; i < n; i++)
                _alloc.construct(&_begin[i], val);
            return (position);
        }

        void    replace(size_type len) {
            pointer tmp = _begin;
            pointer val = _begin;
            iterator i = begin();
            _begin = _alloc.allocate(len * 2);
            _capacity = len;
            _end = _begin + _capacity;
            for (size_type i = 0; i < _capacity; i++, val++)
                _alloc.construct(&_begin[i], *val);
            remove(tmp);
        }

        void    remove(pointer _tbd) {
            size_type  _len = _capacity * 2;

            for (size_type i = 0; i < _len; i++)
                _alloc.destroy(&_tbd[i]);
        }

        iterator    reduce(iterator position, size_t &n, const value_type &val) {
            size_type i = 0;

            for (; i < n; i++) {
                _alloc.construct(&_begin[i], val);
            }
            // for (; i < _end; i++) {
            //     _alloc.destory(&_begin[i]);
            // }
            return (position);
        }

        // iterator erase(iterator first, iterator last) {
        //     size_type len = 0;
        //     pointer tmp = &(*first);
        //     while (tmp != &(*last)) {
        //         len++;
        //         _alloc.destroy(tmp++);
        //     }
        //     size_type n = _end - &(*last);
        //     tmp = &(*first);
        //     while (n--) {
        //         _alloc.construct(tmp, *last++);
        //         _alloc.destroy(tmp++);
        //     }
        //     _end -= len;
        //     return (first);
        // }
    };
}

#endif
