# ft_containers

Containers abstracting : 
- vector: Dynamic contiguous array
- list: Circular double linked list
- map: Binary Search Tree of key-value pairs, sorted by unique keys.
- stack: Adapts a container to provide stack (LIFO - Last In First Out)
- queue: Adapts a container to provide queue (FIFO - First In First Out)

## Stack

Stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out), where elements are inserted and extracted only from one end of the container.

https://www.cplusplus.com/reference/stack/stack/

### member functions:

- [X] Constructors
- [X] Destructors
- [X] stack::empty()
- [X] stack::size()
- [X] stack::top()
- [X] stack::push()
- [X] stack::pop()

### non-member function overloads:

- [ ] relational operators

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
- [X] vector::erase
- [X] vector::front
- [X] vector::get_allocator
- [X] vector::insert
- [X] vector::max_size
- [X] vector::operator[]
- [X] vector::pop_back
- [X] vector::push_back
- [X] vector::rbegin
- [X] vector::rend
- [X] vector::reserve
- [X] vector::resize
- [X] vector::size
- [X] vector::swap

### non-member overloads:

- [X] relational operators (vector)
		- [X] ==
		- [X] !=	a!=b	-> !(a==b)
		- [X] <
		- [X] <=	a<=b	->	!(b < a)
		- [X] >		a>b		->  b < a
		- [X] >=	a>=b	->	!(a < b)
- [X] swap (vector)


## usefull sites :

http://carl.seleborg.free.fr/cpp/cours/chap2/arbres.html
https://cours.etsmtl.ca/SEG/FHenri/inf145/Suppl%C3%A9ments/arbres%20binaires.htm

	https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/

https://www.cs.usfca.edu/~galles/visualization/RedBlack.html