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
        pointer             _capacity;

    public:
        explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _begin(NULL), _end(NULL), _capacity(0) {};
        explicit vector(size_type _n, const value_type& _val = value_type(),
                        const allocator_type& alloc = allocator_type()) :
                        _alloc(alloc)
                        {
                            _M_initialize(_n);
                            for (int i = 0; i < _n; i++)
                                _alloc.construct(&_begin[i], _val);
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
        // const_iterator  begin() const {
        //     return (const_iterator(this->begin));
        // }
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
        size_type    size() const {
            return size_type(_end - _begin);
        }
        // max_capacity();
        size_type    max_capacity() const {
            return (allocator_type().max_capacity());
        }
        // resize();
        // void    resize(size_type n, value_type val = value_type()) {
        //     size_type    _c_capacity = size();
        //     if (_c_capacity < n)
        //     {
        //         iterator    _iter;
        //         size_type    _capa = capacity();
        //         size_type    _diff = n - _c_capacity;
        //         if (_diff <= _capa && _capa <= _capa - _diff)
        //         {
        //             _iter = end();
        //             _capacity += _diff;
        //         }
        //         else
        //         {
        //             vector _v(_alloc());

        //         }
        //     }
        // }
        // capacity();
        size_type    capacity() const {
            return size_type(_capacity - _begin);
        }
        // empty();
        bool    empty() const {
            return (_begin == _end);
        }
        // reserve();

        void    reserve(size_t _n) {
            // if (n > max_capacity)
                // have to throw error
            // if (capacity() < n)
            //     _M_replace(n);
            const size_type _old_capacity = size();
            pointer  _tmp = _M_allocate(_n);
            _M_deallocate();
            this->_begin = _tmp;
            this->_end = _tmp + _old_capacity;
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
    private:

    protected:
        //allocate
        pointer _M_allocate(size_t _n) {
            return (_alloc.allocate(_n * 2));
        }
        //deallocate
        void _M_deallocate() {
            const size_t _n = _end - _begin;
            _alloc.deallocate(_begin, _capacity - _begin);
        }
        //reallocate
        void    _M_replace(size_t len) {
            pointer tmp = _begin;
            iterator i = begin();
            _M_initialize(len);
            for (int i = 0; i < _capacity; i++)
                this->_alloc.construct(_begin + i, 0);
            _M_delete(tmp);
        }

        void    _M_delete(pointer _tbd) {
            size_type  _len = _capacity * 2;

            for (size_type i = 0; i < _len; i++)
                _alloc.destroy(&_tbd[i]);
        }

        void _M_initialize(size_type _n) {
            this->_begin = this->_M_allocate(_n);
            this->_capacity = _begin + _n;
            this->_end = this->_begin;
        }

    };
}

// template <typename iterator> pointer
//     _M_allocate_copy(size_type _n, iterator _start, iterator _end)
//     {
//         pointer _rtn = this->_M_allocate(_n);
//         try
//         {

//         }
//         catch(const std::exception& e)
//         {
//             std::cerr << e.what() << '\n';
//         }

//     }

#endif
