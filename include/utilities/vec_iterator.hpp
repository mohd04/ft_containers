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

      pointer                   base() const { return this->m_ptr; }

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

      vectorIterator<vectorType>&        operator+=(const ptrdiff_t& movement) { m_ptr += movement; return (*this); }
      vectorIterator<vectorType>&        operator-=(const ptrdiff_t& movement) { m_ptr -= movement; return (*this); }
      vectorIterator<vectorType>        operator++() { ++m_ptr; return (*this); }
      vectorIterator<vectorType>        operator--() { --m_ptr; return (*this); }
      vectorIterator<vectorType>         operator++(int) {vectorIterator    temp(*this); ++m_ptr; return (temp); }
      vectorIterator<vectorType>        operator--(int) {vectorIterator    temp(*this); --m_ptr; return (temp); }
      vectorIterator<vectorType>&        operator+(const ptrdiff_t& movement) { vectorType* oldPtr = m_ptr; m_ptr+=movement; vectorIterator tmp(*this); m_ptr = oldPtr; return (tmp); }
      vectorIterator<vectorType>&        operator-(const ptrdiff_t& movement) { vectorType* oldPtr = m_ptr; m_ptr-=movement; vectorIterator tmp(*this); m_ptr = oldPtr; return (tmp); }

      reference                 operator [] (difference_type const & n) { return this->m_ptr[n]; }

      ptrdiff_t                        operator-(const vectorIterator<vectorType>& rawIterator) { return (std::distance(rawIterator.getPtr(), this->getPtr())); }

      vectorType&                        operator*() { return (*m_ptr); }
      const vectorType&                operator*() const { return (*m_ptr); }
      vectorType*                        operator->() { return (std::addressof(*m_ptr)); }

      vectorType*                        getPtr() const { return (m_ptr); }
      const vectorType*                getConstPtr() const { return (m_ptr); }

      // template <class Iterator1, class Iterator2>
      // friend bool operator== ( const Iterator1 & lhs, const Iterator2 & rhs);

      // template <class Iterator1, class Iterator2>
      // friend bool operator!= ( const Iterator1 & lhs, const Iterator2 & rhs);

      // template <class Iterator1, class Iterator2>
      // friend bool operator< ( const Iterator1 & lhs, const Iterator2 & rhs);

      // template <class Iterator1, class Iterator2>
      // friend bool operator<= ( const Iterator1 & lhs, const Iterator2 & rhs);

      // template <class Iterator1, class Iterator2>
      // friend bool operator> ( const Iterator1 & lhs, const Iterator2 & rhs);

      // template <class Iterator1, class Iterator2>
      // friend bool operator>= ( const Iterator1 & lhs, const Iterator2 & rhs);

      // template <class Iterator>
      // friend Iterator operator+ (typename Iterator::difference_type n, const Iterator& it);

      // template <class Iterator1, class Iterator2>
      // friend typename Iterator2::difference_type operator- (const Iterator1& lhs, const Iterator2& rhs);

        protected:
            pointer            m_ptr;
            int                index;
    };


}


#endif
