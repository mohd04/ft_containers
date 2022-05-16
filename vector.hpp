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
	private:

	public:
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename allocator_type::size_type			size_type;
		// have to add iterators

	public:
		explicit vector(const allocator_type& alloc = allocator_type()) {};
		explicit vector(size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type()) :
						size_type(n),
						value_type(val) {};
		// vector(const vector& x) : (*this = x) {};å
		~vector() {}; // have to use free here
		vector& operator=(vector& src) {};

		template <typename T> void print(T& n) {
			std::cout << n << std::endl;
		}

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
