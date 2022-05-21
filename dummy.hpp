#ifndef DUMMY_HPP
#define DUMMY_HPP

#include <iostream>
#include <memory>
#include <iterator>
#include <cstddef>

template<typename vectorType>
class vectorIterator : public std::iterator<std::random_access_iterator_tag,
												vectorType,
												ptrdiff_t,
												vectorType*,
												vectorType&>
{
public:
	typedef typename std::random_access_iterator_tag		iterator_category;
	typedef vectorType										value_type;
	typedef typename std::ptrdiff_t							difference_type;
	typedef vectorType*										pointer;
	typedef vectorType&										reference;

	vectorIterator(vectorType* ptr = nullptr) { m_ptr = ptr; }
	vectorIterator(const vectorIterator<vectorType>& rawIterator) {*this = rawIterator;}
	~vectorIterator() {}

	vectorIterator<vectorType>&		operator=(const vectorIterator<vectorType>& rawIterator){
		if (this != &rawIterator)
			m_ptr = rawIterator.m_ptr;
		return (*this);
	}
	vectorIterator<vectorType>&		operator=(vectorType* ptr) { m_ptr = ptr; return (*this); }

	operator							bool() const
	{
		if (m_ptr)
			return (true);
		else
			return (false);
	}

	bool								operator==(const vectorIterator<vectorType>& rawIterator) const { return (m_ptr == rawIterator.getCosntPtr()); }
	bool								operator!=(const vectorIterator<vectorType>& rawIterator) const { return (m_ptr != rawIterator.getCosntPtr()); }

	vectorIterator<vectorType>&		operator+=(const ptrdiff_t& movement) { m_ptr += movement; return (*this); }
	vectorIterator<vectorType>&		operator-=(const ptrdiff_t& movement) { m_ptr -= movement; return (*this); }
	vectorIterator<vectorType>&		operator++() { ++m_ptr; return (*this); }
	vectorIterator<vectorType>&		operator--() { --m_ptr; return (*this); }
	vectorIterator<vectorType>&		operator++(int) {vectorIterator	temp(*this); ++m_ptr; return (temp); }
	vectorIterator<vectorType>&		operator--(int) {vectorIterator	temp(*this); --m_ptr; return (temp); }
	vectorIterator<vectorType>&		operator+(const ptrdiff_t& movement) { vectorType* oldPtr = m_ptr; m_ptr+=movement; vectorIterator tmp(*this); m_ptr = oldPtr; return (tmp); }
	vectorIterator<vectorType>&		operator-(const ptrdiff_t& movement) { vectorType* oldPtr = m_ptr; m_ptr-=movement; vectorIterator tmp(*this); m_ptr = oldPtr; return (tmp); }

	ptrdiff_t							operator-(const vectorIterator<vectorType>& rawIterator) { return (std::distance(rawIterator.getPtr(), this->getPtr())); }

	vectorType&							operator*() { return (*m_ptr); }
	const vectorType&					operator*() const { return (*m_ptr); }
	vectorType*							operator->() { return (m_ptr); }

	vectorType*							getPtr() const { return (m_ptr); }
	const vectorType*					getConstPtr() const { return (m_ptr); }

	protected:
		vectorType*		m_ptr;
};

#endif
