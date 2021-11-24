/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:59:29 by clorin            #+#    #+#             */
/*   Updated: 2021/11/24 17:55:37 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commun.hpp"

int     main(int argc, char** argv)
{
  (void)argv;
    // argv[1] must be the output file
    if (argc < 2)
    {
        std::cerr << "error no output file" << std::endl;
        return 1;
    }
    // std::ofstream out(argv[1]);
    // std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    // std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
{
  NAMESPACE::vector<int> first;
  NAMESPACE::vector<int> second;
  NAMESPACE::vector<int> third;
  second.assign (7,100);             // 7 ints with a value of 100

  NAMESPACE::vector<int>::iterator it;

  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " << int (first.size()) << '\n';
  std::cout << "Size of second: " << int (second.size()) << '\n';
  std::cout << "Size of third: " << int (third.size()) << '\n';
}
    // std::cout.rdbuf(coutbuf); //reset to standard output again
    return 0;
}
