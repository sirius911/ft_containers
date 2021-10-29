# ft_containers

## Vector

https://www.cplusplus.com/reference/vector/vector/

### member functions:


Canonique form :

- [X] (1)vector::vector() (default)
- [X] (2)vector::vector(n, val) (fill)
- [ ] (3)vector::vector(first, last) (range)
- [X] (4)vector::vector(vector const &) (copy)
- [X] vector::~vector()
- [X] vector::operator=

- [ ] vector::assign
- [ ] vector::at
- [X] vector::back
- [X] vector::begin
- [X] vector::capacity
- [X] vector::clear
- [X] vector::empty
- [X] vector::end
- [ ] vector::erase
- [X] vector::front
- [X] vector::get_allocator
- [ ] vector::insert
- [X] vector::max_size
- [X] vector::operator[]
- [X] vector::pop_back
- [X] vector::push_back
- [ ] vector::rbegin
- [ ] vector::rend
- [X] vector::reserve
- [X] vector::resize
- [X] vector::size
- [ ] vector::swap

### non-member overloads:

- [X] relational operators (vector)
		- [X] ==
		- [X] !=	a!=b	-> !(a==b)
		- [X] <
		- [X] <=	a<=b	->	!(b < a)
		- [X] >		a>b		->  b < a
		- [X] >=	a>=b	->	!(a < b)
- [ ] swap (vector)
