#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <iostream>
#include <memory>
#include <iterator>
#include <cstddef>

template<typename vectorType>
class vectorRawIterator : public std::iterator<std::random_access_iterator_tag,
												vectorType,
												ptrdiff_t,
												vectorType*,
												vectorType&>
{
public:
struct Iterator
{
	public:
		typedef typename std::random_access_iterator_tag		iterator_category;
		typedef vectorType										value_type;
		typedef typename std::ptrdiff_t							difference_type;
		typedef vectorType*										pointer;
		typedef vectorType&										reference;

	public:
		vectorRawIterator(vectorType* ptr = nullptr) { m_ptr = ptr; }
		vectorRawIterator(const vectorRawIterator<vectorType>& rawIterator) {*this = rawIterator;}
		~vectorRawIterator() {}

		vectorRawIterator<vectorType>&		operator=(const vectorRawIterator<vectorType>& rawIterator){
			if (this != &rawIterator)
				m_ptr = rawIterator.m_ptr;
			return (*this);
		}
		vectorRawIterator<vectorType>&		operator=(vectorType* ptr) { m_ptr = ptr; return (*this); }

		operator							bool() const
		{
			if (m_ptr)
				return (true);
			else
				return (false);
		}

		bool								operator==(const vectorRawIterator<vectorType>& rawIterator) const { return (m_ptr == rawIterator.getCosntPtr()); }
		bool								operator!=(const vectorRawIterator<vectorType>& rawIterator) const { return (m_ptr != rawIterator.getCosntPtr()); }

		vectorRawIterator<vectorType>&		operator+=(const ptrdiff_t& movement) { m_ptr += movement; return (*this); }
		vectorRawIterator<vectorType>&		operator-=(const ptrdiff_t& movement) { m_ptr -= movement; return (*this); }
		vectorRawIterator<vectorType>&		operator++() { ++m_ptr; return (*this); }
		vectorRawIterator<vectorType>&		operator--() { --m_ptr; return (*this); }
		vectorRawIterator<vectorType>&		operator++(int) {vectorRawIterator	temp(*this); ++m_ptr; return (temp); }
		vectorRawIterator<vectorType>&		operator--(int) {vectorRawIterator	temp(*this); --m_ptr; return (temp); }
		vectorRawIterator<vectorType>&		operator+(const ptrdiff_t& movement) { vectorType* oldPtr = m_ptr; m_ptr+=movement; vectorRawIterator tmp(*this); m_ptr = oldPtr; return (tmp); }
		vectorRawIterator<vectorType>&		operator-(const ptrdiff_t& movement) { vectorType* oldPtr = m_ptr; m_ptr-=movement; vectorRawIterator tmp(*this); m_ptr = oldPtr; return (tmp); }

		ptrdiff_t							operator-(const vectorRawIterator<vectorType>& rawIterator) { return (std::distance(rawIterator.getPtr(), this->getPtr())); }

		vectorType&							operator*() { return (*m_ptr); }
		const vectorType&					operator*() const { return (*m_ptr); }
		vectorType*							operator->() { return (m_ptr); }

		vectorType*							getPtr() const { return (m_ptr); }
		const vectorType*					getConstPtr() const { return (m_ptr); }



	protected:
		vectorType		m_ptr[200];
};
	Iterator begin() { return (Iterator(&m_ptr[0])); }
	Iterator end() { return (Iterator(&m_ptr[200])); }
};

#endif
