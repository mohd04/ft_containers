#ifndef UTIL_HPP
# define UTIL_HPP

# include "enable_if.hpp"
# include "is_integral.hpp"
# include "iterator_traits.hpp"
# include "lexicographical_compare.hpp"
# include "make_pair.hpp"
# include "pair.hpp"
# include "reverse_iterator.hpp"
# include "Node.hpp"
# include "equal.hpp"
# include "vec_iterator.hpp"

namespace ft {

  template<class Iterator1, class Iterator2>
  typename iterator_traits<Iterator1>::difference_type
  distance (Iterator1 first, Iterator2 last)
  {
    typename iterator_traits<Iterator1>::difference_type diff;
    for(diff = 0; &(*first) != &(*last); first++, diff++);
    return diff;
  }
}


#endif
