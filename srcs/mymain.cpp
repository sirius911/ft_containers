/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clorin <clorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:47:51 by clorin            #+#    #+#             */
/*   Updated: 2021/11/22 16:09:48 by clorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "stack.hpp"
#include "pair.hpp"
#include "RBTree.hpp"
#include "map.hpp"
#include <vector>
#include <stack>
#include <map>
#include <string.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096

struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

#define COUNT (MAX_RAM / (int)sizeof(Buffer))


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

	std::cout << "****************TEST ASSIGN  (FILL)**************"<< std::endl;
	test.assign(5,42);

	for ( int i = 0; i < test.size(); i++)
		std::cout<< test[i] << std::endl;
	std::cout << "--INFOS--" << std::endl;
	std::cout << "Size = " <<  test.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << std::endl;
	std::cout << "##                        ##" << std::endl;

	std::cout << "****************TEST ASSIGN  (range)**************"<< std::endl;
	int tab_int[50];
	for (int i = 0 ; i < 25; i++)
		tab_int[i] = i*2;
	test.assign(tab_int+1,tab_int+20);

	for ( int i = 0; i < test.size(); i++)
		std::cout<< test[i] << std::endl;
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
	std::cout << "--INFOS v1--" << std::endl;
	std::cout << "Size = " <<  vi1.size() << std::endl;
	std::cout << "Capacity = " << vi1.capacity() << std::endl;
	std::cout << "##                        ##" << std::endl;
	{
	std::cout << "***************Test sur erase\n";
	std::cout << "construction du vecteur...";
	int 	t[10] = {0,10,20,30,40,50,60,70,80,90};
	std::vector<int>	vect(t,t+10);
	//ft::vector<int> vect(1,10);
	std::cout << " ok\n";
	std::vector<int>::iterator it;
	std::vector<int>::iterator it_begin = vect.begin();
	std::vector<int>::iterator it_end = vect.end();
	for(it = vect.begin(); it != it_end; it++)
		std::cout << *it << "\t"<<&(*it) << std::endl;
	std::cout << "vect.erase(vect.begin() + 3) : \n";
	std::vector<int>::iterator sortie = vect.erase(it_begin + 3);

	std::cout << "After erase sortie = ";
	if (sortie == it_end)
		std::cout<< "end()\n";
	else
		std::cout << *sortie << std::endl;
	for(it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << "\t"<<&(*it) << std::endl;
	std::cout << "Empty() = " << std::boolalpha << vect.empty() << std::endl << std::endl;

	}
	{
			std::cout << "*******test insert ******************\n";
		int t[6] = {2, 9, 1, 8, 2, 11};
		std::vector<int> vict(t, t+6); //construct vector with the 6 values of t
		std::vector<int> empty_vector;
		//std::vector<int> vict(empty_vector);
		std::vector<int>::iterator it;
		std::vector<int>::iterator sortie;

		for(it = vict.begin(); it != vict.end(); it++)
			std::cout << *it << "\t"<<&(*it) << std::endl;
		std::cout << "--INFOS--" << std::endl;
		std::cout << "Size = " <<  vict.size() << std::endl;
		std::cout << "Capacity = " << vict.capacity() << std::endl;
		std::cout << "##                        ##" << std::endl;

		sortie = vict.insert(vict.end(), 42);
		std::cout << "\n************************************\n";
		std::cout << "sortie = " << *sortie << std::endl;
		for(it = vict.begin(); it != vict.end(); it++)
			std::cout << *it << "\t"<<&(*it) << std::endl;
		std::cout << "--INFOS--" << std::endl;
		std::cout << "Size = " <<  vict.size() << std::endl;
		std::cout << "Capacity = " << vict.capacity() << std::endl;
		std::cout << "##                        ##" << std::endl;

		vict.insert(vict.end(),3,24);
		std::cout << "\n************************************\n";
		for(it = vict.begin(); it != vict.end(); it++)
			std::cout << *it << "\t"<<&(*it) << std::endl;
		std::cout << "--INFOS--" << std::endl;
		std::cout << "Size = " <<  vict.size() << std::endl;
		std::cout << "Capacity = " << vict.capacity() << std::endl;
		std::cout << "##                        ##" << std::endl;
		int u[6] = {60,50,40,30,20,10};
		vict.insert(vict.begin(), u+1, u+5);

		std::cout << "\n************************************\n";
		for(it = vict.begin(); it != vict.end(); it++)
			std::cout << *it << "\t"<<&(*it) << std::endl;
		std::cout << "--INFOS--" << std::endl;
		std::cout << "Size = " <<  vict.size() << std::endl;
		std::cout << "Capacity = " << vict.capacity() << std::endl;
		std::cout << "##                        ##" << std::endl;	
	}

	{
		std::vector<int> foo (3,100);   // three ints with a value of 100
  	std::vector<int> bar (5,200);   // five ints with a value of 200

	std::cout << "*********** TEST SWAP ************\n";
	std::cout << "before swap\n";
	std::cout << "foo contains:";
  	for (unsigned i=0; i<foo.size(); i++)
   		std::cout << ' ' << foo[i];
  	std::cout << '\n';

  	std::cout << "bar contains:";
  	for (unsigned i=0; i<bar.size(); i++)
  	  std::cout << ' ' << bar[i];
 	std::cout << '\n';
  	foo.swap(bar);
	std::cout << "After foo.swap(bar)\n";
  	std::cout << "foo contains:";
  	for (unsigned i=0; i<foo.size(); i++)
   		std::cout << ' ' << foo[i];
  	std::cout << '\n';
  	std::cout << "bar contains:";
  	for (unsigned i=0; i<bar.size(); i++)
  	  std::cout << ' ' << bar[i];
 	std::cout << '\n';
	std::swap(bar, foo);
	std::cout << "After ft::swap(bar, foo)"<<std::endl;
  	std::cout << "foo contains:";
  	for (unsigned i=0; i<foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << std::endl;

	std::cout << "bar contains:";
	for (unsigned i=0; i<bar.size(); i++)
  	 	std::cout << ' ' << bar[i];
 	std::cout << std::endl;
	}
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
	// try
	// {
	// 		std::cout << test.at(200);
	// }
	// catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
	//std::cout << "test[0] = "<<test[0]<< " & test[200] = "<<test[200]<<std::endl ;

	std::cout << "****************TEST ASSIGN  (FILL)**************"<< std::endl;
	test.assign(5,42);

	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout<< *it << std::endl;
	std::cout << "--INFOS--" << std::endl;
	std::cout << "Size = " <<  test.size() << std::endl;
	std::cout << "Capacity = " << test.capacity() << std::endl;
	std::cout << "##                        ##" << std::endl;

	std::cout << "****************TEST ASSIGN  (range)**************"<< std::endl;
	int tab_int[50];
	for (int i = 0 ; i < 50; i++)
		tab_int[i] = i*2;
	test.assign(tab_int+1,tab_int+20);

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
	std::cout << "--INFOS v1--" << std::endl;
	std::cout << "Size = " <<  vi1.size() << std::endl;
	std::cout << "Capacity = " << vi1.capacity() << std::endl;
	std::cout << "##                        ##" << std::endl;

	{
	std::cout << "***************Test sur erase\n";
	std::cout << "construction du vecteur...";
	int 	t[10] = {0,10,20,30,40,50,60,70,80,90};
	ft::vector<int>	vect(t,t+10);
	//ft::vector<int> vect(1,10);
	std::cout << " ok\n";
	ft::vector<int>::iterator it;
	ft::vector<int>::iterator it_begin = vect.begin();
	ft::vector<int>::iterator it_end = vect.end();
	for(it = vect.begin(); it != it_end; it++)
		std::cout << *it << "\t"<<&(*it) << std::endl;
	std::cout << "vect.erase(vect.begin() + 3) : \n";
	ft::vector<int>::iterator sortie = vect.erase(it_begin + 3);

	std::cout << "After erase sortie = ";
	if (sortie == it_end)
		std::cout<< "end()\n";
	else
		std::cout << *sortie << std::endl;
	for(it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << "\t"<<&(*it) << std::endl;
	std::cout << "Empty() = " << std::boolalpha << vect.empty() << std::endl << std::endl;

	}

	{
		std::cout << "*******test insert ******************\n";
		int t[6] = {2, 9, 1, 8, 2, 11};
		ft::vector<int> vict(t, t+6); //construct vector with the 6 values of t
		ft::vector<int> empty_vector;
		//ft::vector<int> vict(empty_vector);
		ft::vector<int>::iterator it;
		ft::vector<int>::iterator sortie;

		for(it = vict.begin(); it != vict.end(); it++)
			std::cout << *it << "\t"<<&(*it) << std::endl;
		std::cout << "--INFOS--" << std::endl;
		std::cout << "Size = " <<  vict.size() << std::endl;
		std::cout << "Capacity = " << vict.capacity() << std::endl;
		std::cout << "##                        ##" << std::endl;

		sortie = vict.insert(vict.end(), 42);
		std::cout << "\n************************************\n";
		std::cout << "sortie = " << *sortie << std::endl;
		for(it = vict.begin(); it != vict.end(); it++)
			std::cout << *it << "\t"<<&(*it) << std::endl;
		std::cout << "--INFOS--" << std::endl;
		std::cout << "Size = " <<  vict.size() << std::endl;
		std::cout << "Capacity = " << vict.capacity() << std::endl;
		std::cout << "##                        ##" << std::endl;

		vict.insert(vict.end(),3,24);
		std::cout << "\n************************************\n";
		for(it = vict.begin(); it != vict.end(); it++)
			std::cout << *it << "\t"<<&(*it) << std::endl;
		std::cout << "--INFOS--" << std::endl;
		std::cout << "Size = " <<  vict.size() << std::endl;
		std::cout << "Capacity = " << vict.capacity() << std::endl;
		std::cout << "##                        ##" << std::endl;
		int u[6] = {60,50,40,30,20,10};
		vict.insert(vict.begin(), u+1, u+5);

		std::cout << "\n************************************\n";
		for(it = vict.begin(); it != vict.end(); it++)
			std::cout << *it << "\t"<<&(*it) << std::endl;
		std::cout << "--INFOS--" << std::endl;
		std::cout << "Size = " <<  vict.size() << std::endl;
		std::cout << "Capacity = " << vict.capacity() << std::endl;
		std::cout << "##                        ##" << std::endl;
	}

	{
		ft::vector<int> foo (3,100);   // three ints with a value of 100
  		ft::vector<int> bar (5,200);   // five ints with a value of 200

		std::cout << "*********** TEST SWAP ************\n";
		std::cout << "before swap\n";
		std::cout << "foo contains:";
  		for (unsigned i=0; i<foo.size(); i++)
	   		std::cout << ' ' << foo[i];
	  	std::cout << std::endl;

	  	std::cout << "bar contains:";
	  	for (unsigned i=0; i<bar.size(); i++)
  	  		std::cout << ' ' << bar[i];
 		std::cout << std::endl;
  		foo.swap(bar);
		std::cout << "After foo.swap(bar)"<<std::endl;
  		std::cout << "foo contains:";
  		for (unsigned i=0; i<foo.size(); i++)
	   		std::cout << ' ' << foo[i];
	  	std::cout << std::endl;
	  	std::cout << "bar contains:";
	  	for (unsigned i=0; i<bar.size(); i++)
  	  		std::cout << ' ' << bar[i];
 		std::cout << std::endl;

		ft::swap(bar, foo);
		std::cout << "After ft::swap(bar, foo)"<<std::endl;
  		std::cout << "foo contains:";
  		for (unsigned i=0; i<foo.size(); i++)
	   		std::cout << ' ' << foo[i];
	  	std::cout << std::endl;

	  	std::cout << "bar contains:";
	  	for (unsigned i=0; i<bar.size(); i++)
  	  	std::cout << ' ' << bar[i];
 		std::cout << std::endl;
	}
}

void	pair_tester()
{
	ft::pair <std::string,double> product1;                     // default constructor
  	ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
  	ft::pair <std::string,double> product3 (product2);          // copy constructor

  	product1 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

  product2.first = "shoes";                  // the type of first is string
  product2.second = 39.90;                   // the type of second is double

  std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
  std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
  std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
}

void	test_RBtree(int argc)
{
	srand(argc);
	typedef	ft::pair<const int, int> value;
	typedef ft::Node<value>*   node_ptr;
	ft::RBTree<const int, value,ft::selectFirst<value, int> > tree;
	// tree.insert(ft::make_pair(4,"coucou"));
	// tree.insert(ft::make_pair(3,"hello word"));
	// tree.insert(ft::make_pair(10,"a boy like me"));
	// tree.insert(ft::make_pair(7,"A girl like you"));
	// tree.insert(ft::make_pair(6,"I love you"));

	std::cout << "creating tree with ";
	int nb = 0;
	while(nb < 100)
	{
		int idx = rand() % 250;
		std::cout << " "<<idx;
		if (tree.insert(ft::make_pair(idx,idx)))
			nb++;
	}
	std::cout << " ... ok\n\t total = "<< nb << std::endl;
	// 
	

	tree.print();
	int	to_del = 74;
	std::cout << "rechercher key = "<<to_del<<" -> ";
	node_ptr	node = tree.search(to_del);
	if (node == tree.getNill())
		std::cout << "[not found]\n";
	else
	{
		std::cout << "[Found]\n";
		std::cout << "\tdelete "<< to_del ;
		if(tree.deleteNode(to_del))
			std::cout << " Ok\n";
		else
			std::cout << C_RED<<" KO\n"<<C_RESET;
		tree.print();
	}
	node = tree.max();
	std::cout << "Max = "<< (node->data).second << std::endl;
	std::cout << "delete "<< 82 << std::endl;
	tree.deleteNode(82);
	tree.print();
	node = tree.min();
	std::cout << "Min = "<< (node->data).second << std::endl;
	std::cout << "size = " << tree.getSize()<< std::endl;
}

#define NAMESPACE ft

int 		main(int argc, char **argv)
{
	(void) argv;
	//test_RBtree(argc);
	//return 0;

	NAMESPACE::map<int, int> map_int;
	typedef typename NAMESPACE::map<int,int>::iterator it;
	typedef	NAMESPACE::pair<int, int> value;
	typedef NAMESPACE::Node<value>*   node_ptr;

	NAMESPACE::pair<it,bool> result = map_int.insert(NAMESPACE::make_pair(12,120));
	if(result.second)
		std::cout << "Ok\n";
	else
		std::cout << "KO\n";
	result = map_int.insert(NAMESPACE::make_pair(10,10));
	if(result.second)
		std::cout << "Ok\n";
	else
		std::cout << "KO\n";

	map_int.insert(NAMESPACE::make_pair(13,13));
	map_int.insert(NAMESPACE::make_pair(01,01));

	it	beg = map_int.begin();
	
	map_int.insert(beg, NAMESPACE::make_pair(-5,-5));
	beg = map_int.begin();
	while(beg != map_int.end())
		std::cout << (*(beg++)).second << std::endl;
	
	std::cout <<"\n Revers iterator\n";
	NAMESPACE::map<int,int>::reverse_iterator rit;
	rit = map_int.rbegin();
	while(rit != map_int.rend())
		std::cout << (*(rit++)).second << std::endl;

	std::cout << "size = " << map_int.size() << " empty = " << ((map_int.empty())?"true":"false" )<< " maxsize = "<< map_int.max_size() << std::endl;
	
	std::cout << "Delete by iterator : \n";
	map_int.erase(map_int.begin());
	beg = map_int.begin();
	while(beg != map_int.end())
		std::cout << (*(beg++)).second << std::endl;
	std::cout << "size = " << map_int.size() << " empty = " << ((map_int.empty())?"true":"false" )<< std::endl;
	

	std::cout << "delete by key : \n";
	int nb_erase = map_int.erase(10);
	beg = map_int.begin();
	std::cout << "nb = "<< nb_erase << std::endl;
	while(beg != map_int.end())
		std::cout << (*(beg++)).second << std::endl;
	std::cout << "size = " << map_int.size() << " empty = " << ((map_int.empty())?"true":"false" )<< std::endl;
	nb_erase = map_int.erase(10);	// no eraser
	std::cout << "nb = "<< nb_erase << std::endl;
	

	std::cout << "\n test operator [] :\n with a good value : \n";
	std::cout << "map_int[12] = " << map_int[12]<< std::endl;
	std::cout << "\t with a new value : \n";
	map_int[15] = 150;
	std::cout << "map_int[15] = 150 " << map_int[15] << std::endl;
	map_int[2] = 200;
	beg = map_int.begin();
	while(beg != map_int.end())
		std::cout << (*(beg)).second << " "<<&((*(beg++)).second)<< std::endl;
	std::cout << "size = " << map_int.size() << " empty = " << ((map_int.empty())?"true":"false" )<< std::endl;
	

	NAMESPACE::map<int, int> map_cpy = map_int;

	std::cout << "clear():\n";
	map_int.clear();
	std::cout << "size = " << map_int.size() << " empty = " << ((map_int.empty())?"true":"false" )<< std::endl;
	
	beg = map_cpy.begin();
	while(beg != map_cpy.end())
		std::cout << (*(beg)).second << " "<<&((*(beg++)).second)<< std::endl;
	return 0;
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<int> > stack_deq_buffer;
	
	std::cout << "stack_int.empty() = " << std::boolalpha << stack_int.empty() << std::endl;
	std::cout << "stack_int.size() = " << stack_int.size() << std::endl;
	stack_int.push(10);
	stack_int.push(20);
	std::cout << "stack_int.empty() = " << std::boolalpha << stack_int.empty() << std::endl;
	std::cout << "stack_int.size() = " << stack_int.size() << std::endl;
	std::cout << "stack_int.top() = "<< stack_int.top() << std::endl;
	stack_int.top() -= 5;
	std::cout << "stack_int.top() = "<< stack_int.top() << std::endl;
	stack_int.pop();
	const int const_int = stack_int.top();
	std::cout << "const int = "<< const_int << std::endl;
	return 0;
	std::cout << "COUNT = " << COUNT << std::endl;
	
	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "Normal : "<< e.what()<< std::endl;
		//NORMAL ! :P
	}

	return (0);
}