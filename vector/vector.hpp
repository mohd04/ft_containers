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
            - value_type
            - allocator_type
            - reference
            - const_reference
            - pointer
            - const_pointer
            - iterator
            - const_iterator
            - reverse_iterator
            - const_reverse_iterator
            - difference_type
            - size_type */
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
        // have to add iterators
    private:
        allocator_type      _alloc;
        pointer             _begin;
        pointer             _end;
        pointer             _capacity;

    public:
        explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _begin(NULL), _end(NULL), _capacity(0) {};
        explicit vector(size_type n, const value_type& val = value_type(),
                        const allocator_type& alloc = allocator_type()) :
                        _alloc(alloc),
                        _begin(NULL),
                        _end(NULL),
                        _capacity(0)
                        {
                            _begin = _alloc.allocate(n * 2);
                            _capacity = _begin + n;
                            _end = _begin + n;
                            for (int i = 0; i < n; i++)
                                _alloc.construct(&_begin[i], val);
                        };
        // vector(const vector& x) {};
        ~vector() {}; // have to use free here
        vector& operator=(vector& src) {};

        // Iterators

        // begin();
        iterator    begin() {
            return (_begin);
        }
        // const begin()
        const_iterator  begin() const {
            return (_begin);
        }
        // end();
        iterator    end() {
            return (_end);
        }
        // rbegin(); have to do cons
        // rend(); have to do const
        // cbegin();
        // const_iterator  cbegin() {
        // }

        // Capacity

        // size();
        size_t    size() const {
            return size_type(_end - _begin);
        }
        // max_capacity();
        size_type    max_capacity() const {
            return (allocator_type().max_size());
        }
        resize();
        void    resize(size_type n, value_type val = value_type()) {
            if (n < size())
                erase(_begin + n, _end);
            else if (n > size())
                insert();
        }
        // capacity();
        size_type    capacity() const {
            return size_type(_capacity - _begin);
        }
        // empty();
        bool    empty() const {
            return (_begin == _end);
        }
        // reserve();

        void    reserve(size_type n) {
            if (n > max_capacity())
                throw std::length_error("Vector reserve error");
            else if (n > capacity()) {
                pointer start = _begin;
                pointer finish = _end;
                pointer capa = _capacity;

                _begin = _alloc.allocate(n);
                _end = _begin;
                _capacity = _begin + n;
                pointer tmp = start;
                while (tmp != finish) {
                    _alloc.construct(_end++, *tmp);
                    _alloc.destroy(tmp++);
                }
                _alloc.deallocate(start, _capacity - start);
            }
        }
        // shrink_to_fit();
        // void    shrink_to_fit() {
        //     if (capacity() - size() < int())
        // }

        // Element access

        // operator[]();
        reference   operator[](size_type _n) {
            return *(_begin + _n);
        }
        // at();
        reference   at(size_type _n) {
            _range_check(_n);
            return (*this)[_n];
        }
        // front();
        reference   front() {
            return *begin();
        }
        // back();
        reference   back() {
            return *(end() - 1);
        }
        // data();

        // Modifiers

        // assign();
        // void    assign(size_type _n, bool& _x) {

        // }
        // push_back();
        void    push_back(const value_type& _val) {
            if (this->_end != this->_capacity) {
                _alloc.construct(_end + 1, _val);
                ++this->_end;
            }
            // else

        }
        // pop_back();

        void pop_back() {
            _alloc.destroy(--_end);
        }
        // insert();
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
        //     size_type range = ft::distance
        // }
        // swap();

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
        // clear();

        void clear() {
            while (_begin != _end)
                _alloc.destroy(--_end);
        }

        // Allocator

        // get_allocator();

        allocator_type get_allocator() const {
            return (_alloc);
        }
    private:

        void    _range_check(size_type _n) const {
            if (_n >= this->size())
                throw   std::out_of_range("Error: out of size range.");
        }

        void    replace(size_type len) {
            pointer tmp = _begin;
            pointer val = _begin;
            iterator i = begin();
            _begin = _alloc.allocate(len * 2);
            _capacity = len;
            _end = _begin + _capacity;
            for (int i = 0; i < _capacity; i++, val++)
                _alloc.construct(&_begin[i], *val);
            remove(tmp);
        }

        void    remove(pointer _tbd) {
            size_type  _len = _capacity * 2;

            for (size_type i = 0; i < _len; i++)
                _alloc.destroy(&_tbd[i]);
        }

        iterator erase(iterator first, iterator last) {
            size_type len = 0;
            pointer tmp = &(*first);
            while (tmp != &(*last)) {
                len++;
                _alloc.destroy(tmp++);
            }
            size_type n = _end - &(*last);
            tmp = &(*first);
            while (n--) {
                _alloc.construct(tmp, *last++);
                _alloc.destroy(tmp++);
            }
            _end -= len;
            return (first);
        }
    };
}

#endif
