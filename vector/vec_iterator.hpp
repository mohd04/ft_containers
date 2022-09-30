#ifndef VEC_ITERATOR_HPP
#define VEC_ITERATOR_HPP

#include <iostream>
#include <memory>
#include <iterator>
#include <cstddef>
#include "iterator_traits.hpp"

namespace ft
{
    template<typename vectorType>
    class vectorIterator : public std::iterator<std::random_access_iterator_tag,
                                                    vectorType,
                                                    ptrdiff_t,
                                                    vectorType*,
                                                    vectorType&>
    {
    public:
        typedef typename std::random_access_iterator_tag        iterator_category;
        typedef vectorType                                        value_type;
        typedef typename std::ptrdiff_t                            difference_type;
        typedef vectorType*                                        pointer;
        typedef vectorType&                                        reference;

        vectorIterator() {this->m_ptr = NULL;}
        vectorIterator(vectorType* ptr = nullptr) { m_ptr = ptr; }
        vectorIterator(const vectorIterator<vectorType>& rawIterator) {*this = rawIterator;}
        ~vectorIterator() {}

        vectorIterator<vectorType>&        operator=(const vectorIterator<vectorType>& rawIterator){
            if (this != &rawIterator)
                m_ptr = rawIterator.m_ptr;
            return (*this);
        }
        vectorIterator<vectorType>&        operator=(vectorType* ptr) { m_ptr = ptr; return (*this); }

        operator                            bool() const
        {
            if (m_ptr)
                return (true);
            else
                return (false);
        }

        bool                            operator==(const vectorIterator<vectorType>& rawIterator) const { return (m_ptr == rawIterator.getCosntPtr()); }
        bool                            operator!=(const vectorIterator<vectorType>& rawIterator) const { return (m_ptr != rawIterator.getCosntPtr()); }

        vectorIterator<vectorType>&        operator+=(const ptrdiff_t& movement) { m_ptr += movement; return (*this); }
        vectorIterator<vectorType>&        operator-=(const ptrdiff_t& movement) { m_ptr -= movement; return (*this); }
        vectorIterator<vectorType>        operator++() { ++m_ptr; return (*this); }
        vectorIterator<vectorType>        operator--() { --m_ptr; return (*this); }
        vectorIterator<vectorType>         operator++(int) {vectorIterator    temp(*this); ++m_ptr; return (temp); }
        vectorIterator<vectorType>        operator--(int) {vectorIterator    temp(*this); --m_ptr; return (temp); }
        vectorIterator<vectorType>&        operator+(const ptrdiff_t& movement) { vectorType* oldPtr = m_ptr; m_ptr+=movement; vectorIterator tmp(*this); m_ptr = oldPtr; return (tmp); }
        vectorIterator<vectorType>&        operator-(const ptrdiff_t& movement) { vectorType* oldPtr = m_ptr; m_ptr-=movement; vectorIterator tmp(*this); m_ptr = oldPtr; return (tmp); }

        ptrdiff_t                        operator-(const vectorIterator<vectorType>& rawIterator) { return (std::distance(rawIterator.getPtr(), this->getPtr())); }

        vectorType&                        operator*() { return (*m_ptr); }
        const vectorType&                operator*() const { return (*m_ptr); }
        vectorType*                        operator->() { return (std::addressof(*m_ptr)); }

        vectorType*                        getPtr() const { return (m_ptr); }
        const vectorType*                getConstPtr() const { return (m_ptr); }

        protected:
            pointer            m_ptr;
            int                index;
    };
// Reverse Iterator

//     template<typename vectorType>
//     class vectorRevIterator : public vectorIterator<vectorType>
//     {
//     public:
//         vectorRevIterator(vectorType* ptr = nullptr) : vectorRevIterator<vectorType>(ptr) {}
//         vectorRevIterator(const vectorIterator<vectorType>& rawIterator) { this->m_ptr = rawIterator.getPtr();}
//         vectorRevIterator(const vectorRevIterator<vectorType>& rawRevIterator) { *this = rawRevIterator;}
//         ~vectorRevIterator() {}

//         vectorRevIterator<vectorType>&        operator=(const vectorRevIterator<vectorType>& rawRevIterator) { m_ptr = ptr; return (*this); }
//         vectorRevIterator<vectorType>&        operator=(const vectorIterator<vectorType>& rawIterator) {this->m_ptr = rawIterator.getPtr(); return (*this); }
//         vectorRevIterator<vectorType>&        operator=(vectorType* ptr) { this->setPtr(ptr); return (*this); }

//         vectorRevIterator<vectorType>&        operator+=(const ptrdiff_t& movement) {this->m_ptr -= movement; return (*this); }
//         vectorRevIterator<vectorType>&        operator-=(const ptrdiff_t& movement) {this->m_ptr += movement; return (*this); }
//         vectorRevIterator<vectorType>&        operator++(){--this->m_ptr; reutrn (*this); }
//         vectorRevIterator<vectorType>&        operator--(){++this->m_ptr; reutrn (*this); }
//         vectorRevIterator<vectorType>&        operator++(int) {vectorRevIterator    temp(*this); --m_ptr; return (temp); }
//         vectorRevIterator<vectorType>&        operator--(int) {vectorRevIterator    temp(*this); ++m_ptr; return (temp); }
//         vectorRevIterator<vectorType>&        operator+(const intt& movement) { vectorType* oldPtr = m_ptr; m_ptr-=movement; vectorRevIterator tmp(*this); m_ptr = oldPtr; return (tmp); }
//         vectorRevIterator<vectorType>&        operator-(const intt& movement) { vectorType* oldPtr = m_ptr; m_ptr+=movement; vectorRevIterator tmp(*this); m_ptr = oldPtr; return (tmp); }

//         ptrdiff_t                            operator-(const vectorRevIterator<vectorType>& rawRevIterator) { return (std::distance(this->getPtr(), rawRevIterator.getPtr())); }

//         // vectorIterator<vectorType>            base() { vectorIterator<vectorType> forward}
//     };
}


#endif
