#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
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
        typedef T                                            value_type;
        typedef Alloc                                        allocator_type;
        typedef typename allocator_type::reference            reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer        const_pointer;
        typedef typename allocator_type::size_type            size_type;
        typedef ft::vectorIterator<value_type>                iterator;
        typedef ft::vectorIterator<const value_type>          const_iterator;
        // typedef ft::vectorRevIterator<value_type>            reverse_iterator;
        // have to add iterators
    private:
        allocator_type      _alloc;
        pointer             _begin;
        pointer             _end;
        size_type           _size;

    public:
        explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _begin(NULL), _end(NULL), _size(0) {};
        explicit vector(size_type n, const value_type& val = value_type(),
                        const allocator_type& alloc = allocator_type()) :
                        _alloc(alloc),
                        _begin(NULL),
                        _end(NULL),
                        _size(0)
                        {
                            _begin = _alloc.allocate(n * 2);
                            _size = n;
                            _end = _begin + _size;
                            for (int i = 0; i < _size; i++)
                                _alloc.construct(&_begin[i], val);
                        };
        // vector(const vector& x) {};
        ~vector() {}; // have to use free here
        vector& operator=(vector& src) {};

        // Iterators

        // begin();
        iterator    begin() {
            return (iterator(this->_begin));
        }
        // const begin()
        const_iterator  begin() const {
            return (const_iterator(this->begin));
        }
        // end();
        iterator    end() {
            return (iterator(this->_end));
        }
        // rbegin(); have to do cons
        // reverse_iterator    rbegin()
        // {
        //     reutrn (reverse_iterator(this->_end));
        // }
        // rend(); have to do const
        // cbegin();
        // cend();
        // crbegin();
        // crend();

        // Capacity

        // size();
        size_t    size() const {
            return (_size);
        }
        // max_size();
        size_type    max_size() const {
            return (allocator_type().max_size());
        }
        // resize();
        // void    resize(size_type n, value_type val = value_type()) {
        //     size_type    _c_size = size();
        //     if (_c_size < n)
        //     {
        //         iterator    _iter;
        //         size_type    _capa = capacity();
        //         size_type    _diff = n - _c_size;
        //         if (_diff <= _capa && _capa <= _capa - _diff)
        //         {
        //             _iter = end();
        //             _size += _diff;
        //         }
        //         else
        //         {
        //             vector _v(_alloc());

        //         }
        //     }
        // }
        // capacity();
        size_type    capacity() const {
            return static_cast<size_type>(_size);
        }
        // empty();
        bool    empty() const {
            return (_begin == _end);
        }
        // reserve();

        void    reserve(size_type n) {
            size_t __cap = _size;
            if (__cap < n) {

            }
        }
        // shrink_to_fit();

        // Element access

        // operator[]();
        // at();
        // front();
        // back();
        // data();

        // Modifiers

        // assign();
        // push_back();
        // pop_back();
        // insert();
        // erase();
        // swap();
        // clear();
        // emplace();
        // emplace_back();

        // Allocator

        // get_allocator();

        void    replace(size_type len) {
            pointer tmp = _begin;

            for (iterator i = begin(); i <= end(); i++)

        }

        void    delete(pointer _tbd) {
            size_type  _len = _size * 2;

            for (size_type i = 0; i < _len; i++)
                _alloc.destroy(&_tbd[i]);
        }
    };
}


#endif
