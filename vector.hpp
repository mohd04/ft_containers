#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>

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
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::size_type			size_type;
		// have to add iterators
	private:
		allocator_type	_alloc;
		pointer			_start;
		pointer			_end;
		pointer			_lastElem;

	public:
		explicit vector(const allocator_type& alloc = allocator_type()) : _alloc(alloc), _start(NULL), _end(NULL), _lastElem(0) {};
		explicit vector(size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type()) :
						_alloc(alloc),
						_start(_alloc.allocate(n * 2)),
						_end(_start),
						_lastElem(_start + n)
						{
							_alloc.construct(_start, val);
						};
		// vector(const vector& x) {};
		~vector() {}; // have to use free here
		vector& operator=(vector& src) {};

		// Iterators

		// begin();
		// end();
		// rbegin();
		// rend();
		// cbegin();
		// cend();
		// crbegin();
		// crend();

		// Capacity

		// size();
		// max_size();
		// resize();
		// capacity();
		// empty();
		// reserve();
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
	};
}


#endif
