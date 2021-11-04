/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:47:51 by clorin            #+#    #+#             */
/*   Updated: 2021/10/27 19:48:08 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

static void	test_push_std(void)
{
	std::vector<int> test;

	std::cout << "## BASIC STD DEMONSTRATION ##" << std::endl;

	std::cout << "Creating std::vector test." << std::endl;

	std::cout << "Empty() = " << std::boolalpha << test.empty() << std::endl << std::endl;

	std::cout << "--PUSH DATA--" << std::endl;
	test.push_back(56);
	std::cout << "Push : " << test[0] << std::endl;
	test.push_back(42);
	std::cout << "Push : " << test[1] << std::endl;

	std::cout << "Empty() = " << std::boolalpha << test.empty() << std::endl << std::endl;

	std::cout << "--INFOS--" << std::endl;
	std::cout << "Size = " <<  test.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << std::endl;

	std::cout << "--PUSH DATA--" << std::endl;
	test.push_back(9);
	std::cout << "Push : " << test[2] << std::endl;
	test.push_back(0);
	std::cout << "Push : " << test[3] << std::endl;
	test.push_back(13);
	std::cout << "Push : " << test[4] << std::endl;

	std::cout << "--PUSH DATA +++ --" << std::endl;
	test.push_back(6);
	std::cout << "Push : " << test[5] << std::endl;
	test.push_back(7);
	std::cout << "Push : " << test[6] << std::endl;
	test.push_back(8);
	std::cout << "Push : " << test[7] << std::endl;
	test.push_back(9);
	std::cout << "Push : " << test[8] << std::endl;

	std::cout << "--INFOS--" << std::endl;
	std::cout << "Size = " <<  test.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << std::endl;
	std::cout << "##                        ##" << std::endl;

	std::cout << "******* TEST resize **********" << std::endl;
	for(size_t i = 0; i < test.size(); i++)
	{
		std::cout << test[i] << " at & " << &test[i] <<std::endl;
	}
		size_t re = 15;
	std::cout << "\t resize("<< re <<")"<<std::endl;

	test.resize(re,666);
	for(size_t i = 0; i < test.size(); i++)
	{
		std::cout << test[i] << " at & " << &test[i] <<std::endl;
	}
	std::cout << "--INFOS--" << std::endl;
	std::cout << "Size = " <<  test.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << std::endl;
	std::cout << "##                        ##" << std::endl;

	std::cout << "--MAX_SIZE--" << std::endl;
	std::cout << test.max_size() << std::endl;

	std::cout << "********* TEST COPY ************" << std::endl;
	std::vector<int> copy;	// or copy(test)
	copy = test;
	for(size_t i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " at & " << &copy[i] <<std::endl;

	std::cout << "***********REVERSE ITERATOR **************"<< std::endl;
	std::vector<int>::reverse_iterator it;
	for ( it = test.rbegin(); it != test.rend(); it++)
		std::cout<< *it << std::endl;

	std::cout << "***********Out of range*************"<< std::endl;
	try
	{
			std::cout << test.at(200);
	}
	catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	std::cout << "test[0] = "<<test[0]<< " & test[200] = "<<test[200]<<std::endl ;

	std::cout << "****************TEST ASSIGN**************"<< std::endl;
	test.assign(5,42);
	for ( it = test.rbegin(); it != test.rend(); it++)
		std::cout<< *it << std::endl;
	std::cout << "--INFOS--" << std::endl;
	std::cout << "Size = " <<  test.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << std::endl;
	std::cout << "##                        ##" << std::endl;

	std::cout << "***********************TEST Construct range ********************"<<std::endl;
	int t[6] = {2, 9, 1, 8, 2, 11};
	std::vector<int> vi1(t, t+6); //construct vector with the 6 values of t
	std::vector<int> vi2(t+1, t+5); // from t[1] ti t[5]
	std::cout << "vi1 = {";
	for(int i = 0; i < vi1.size(); i++)
		std::cout << " " << vi1[i];
	std::cout << "}\nvi2 = {";
	for(std::vector<int>::iterator it = vi2.begin(); it != vi2.end(); it++)
		std::cout << " " << *it;
		std::cout << "}\n";
}	

static void	test_push(void)
{
	ft::vector<int> test;

	std::cout << "##### BASIC FT DEMONSTRATION #####" << std::endl;

	std::cout << "Creating ft::vector test." << std::endl;

	std::cout << "Empty() = " << std::boolalpha << test.empty() << std::endl << std::endl;

	std::cout << "--PUSH DATA--" << std::endl;
	test.push_back(56);
	std::cout << "Push : " << test[0] << std::endl;
	test.push_back(42);
	std::cout << "Push : " << test[1] << std::endl;

	std::cout << "Empty() = " << std::boolalpha << test.empty() << std::endl << std::endl;

	std::cout << "--INFOS--" << std::endl;
	std::cout << "Size = " <<  test.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << std::endl;

	std::cout << "--PUSH DATA--" << std::endl;
	test.push_back(9);
	std::cout << "Push : " << test[2] << std::endl;
	test.push_back(0);
	std::cout << "Push : " << test[3] << std::endl;
	test.push_back(13);
	std::cout << "Push : " << test[4] << std::endl;

	std::cout << "--INFOS--" << std::endl;
	std::cout << "Size = " <<  test.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << std::endl;
	std::cout << "##                       ##" << std::endl;
	std::cout << "--PUSH DATA +++ --" << std::endl;
	test.push_back(6);
	std::cout << "Push : " << test[5] << std::endl;
	test.push_back(7);
	std::cout << "Push : " << test[6] << std::endl;
	test.push_back(8);
	std::cout << "Push : " << test[7] << std::endl;
	test.push_back(9);
	std::cout << "Push : " << test[8] << std::endl;

	std::cout << "--INFOS--" << std::endl;
	std::cout << "Size = " <<  test.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << std::endl;
	std::cout << "##                        ##" << std::endl;

	std::cout << "******* TEST resize **********" << std::endl;
	for(size_t i = 0; i < test.size(); i++)
	{
		std::cout << test[i] << " at & " << &test[i] <<std::endl;
	}
		size_t re = 15;
	std::cout << "\t resize("<< re <<")"<<std::endl;

	test.resize(re, 666);
	for(size_t i = 0; i < test.size(); i++)
	{
		std::cout << test[i] << " at & " << &test[i] <<std::endl;
	}
	std::cout << "--INFOS--" << std::endl;
	std::cout << "Size = " <<  test.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << std::endl;
	std::cout << "##                       ##" << std::endl;

	std::cout << "--MAX_SIZE--" << std::endl;
	std::cout << test.max_size() << std::endl;
	//test_push_std();

	std::cout << "test.back() = " << test.back()<<std::endl;
	std::cout << "test.front() = " << test.front() << std::endl;

	std::cout << "********* TEST COPY ************" << std::endl;

	ft::vector<int> copy;
	copy = test;
	if (copy==test) std::cout << "copy and test are equal\n";
  	if (copy!=test) std::cout << "copy and test are not equal\n";
  	test.resize(10);
  	if (copy==test) std::cout << "after test.resize(10) copy and test are equal\n";
  	if (copy!=test) std::cout << "after test.resize(10) copy and test are not equal\n";
  	if (copy < test) std::cout << "copy < test\n";
  	else if (copy > test) std::cout << "copy > test\n";
	std::cout << "--INFOS--COPY" << std::endl;
	std::cout << "Size = " <<  copy.size() << std::endl;
	std::cout << "Capacity = " << copy.capacity() << std::endl;
	std::cout << "##                       ##" << std::endl;
	for(size_t i = 0; i < copy.size(); i++)
		std::cout << copy[i] << " at & " << &copy[i] <<std::endl;

	std::cout << "***********REVERSE ITERATOR **************"<< std::endl;
	for (ft::vector<int>::reverse_iterator it = copy.rbegin(); it != copy.rend(); it++)
		std::cout<< *it << std::endl;

	std::cout << "***********Out of range*************"<< std::endl;
	try
	{
			std::cout << test.at(200);
	}
	catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
	std::cout << "test[0] = "<<test[0]<< " & test[200] = "<<test[200]<<std::endl ;

	std::cout << "****************TEST ASSIGN**************"<< std::endl;
	test.assign(5,42);

	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout<< *it << std::endl;
	std::cout << "--INFOS--" << std::endl;
	std::cout << "Size = " <<  test.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << std::endl;
	std::cout << "##                        ##" << std::endl;

	std::cout << "***********************TEST Construct range ********************"<<std::endl;
	int t[6] = {2, 9, 1, 8, 2, 11};
	ft::vector<int> vi1(t, t+6); //construct vector with the 6 values of t
	ft::vector<int> vi2(t+1, t+5); // from t[1] ti t[5]
	std::cout << "vi1 = {";
	for(int i = 0; i < vi1.size(); i++)
		std::cout << " " << vi1[i];
	std::cout << "}\nvi2 = {";
	for(ft::vector<int>::iterator it = vi2.begin(); it != vi2.end(); it++)
		std::cout << " " << *it;
		std::cout << "}\n";
}
int 		main(void)
{
	test_push_std();
	test_push();

	return (0);
}