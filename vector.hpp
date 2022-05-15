#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class Vector
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
		value_type				_val;
		allocator_type			_alloc;
		reference				_ref;
		const_reference			_c_ref;
		pointer					_ptr;
		const_pointer			_c_ptr;
		iterator				_iter;
		const_iterator			_c_iter;
		reverse_iterator		_rev_iter;
		const_reverse_iterator	_c_rev_iter;
		difference_type			_diff_type;
		size_type				_size_type;
	public:
		Vector();
		~Vector();
		Vector& operator=();

		// Iterators

		begin();
		end();
		rbegin();
		rend();
		cbegin();
		cend();
		crbegin();
		crend();

		// Capacity

		size();
		max_size();
		resize();
		capacity();
		empty();
		reserve();
		shrink_to_fit();

		// Element access

		operator[]();
		at();
		front();
		back();
		data();

		// Modifiers

		assign();
		push_back();
		pop_back();
		insert();
		erase();
		swap();
		clear();
		emplace();
		emplace_back();

		// Allocator

		get_allocator();
	};
}


#endif
