# ft_containers

Containers abstracting : 
- vector: Dynamic contiguous array
- list: Circular double linked list
- map: Binary Search Tree of key-value pairs, sorted by unique keys.
- stack: Adapts a container to provide stack (LIFO - Last In First Out)
- queue: Adapts a container to provide queue (FIFO - First In First Out)

## Vector

Containers abstracting : Dynamic contiguous array
Iterator type : Random acces & reverse iterator

https://www.cplusplus.com/reference/vector/vector/

### member functions:

Canonique form :

- [X] (1)vector::vector() (default)
- [X] (2)vector::vector(n, val) (fill)
- [X] (3)vector::vector(first, last) (range)
- [X] (4)vector::vector(vector const &) (copy)
- [X] vector::~vector()
- [X] vector::operator=

- [X] vector::assign(range)
- [X] vector::assign(fill)
- [X] vector::at
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
- [X] vector::rbegin
- [X] vector::rend
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
