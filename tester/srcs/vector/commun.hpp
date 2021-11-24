#ifndef COMMUN_HPP
# define COMMUN_HPP

#include "../srcs/vector.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#ifndef NAMESPACE
    # define NAMESPACE ft
#endif

template <typename T>
void    print_vector(NAMESPACE::vector<T> &vector_test, bool capacity = false)
{
    for(size_t i = 0; i < vector_test.size(); i++)
	{
		std::cout << vector_test[i] << std::endl;
	}
    if(capacity)
    {
            std::cout << "--INFOS--" << std::endl;
	        std::cout << "Size = " <<  vector_test.size();
            if(vector_test.empty())
            {
                std::cout << " [empty]";
            }
            std::cout << std::endl << "Capacity = " << vector_test.capacity() << std::endl;
            std::cout << "Max_size = "<< vector_test.max_size() << std::endl;
    }
}


#endif