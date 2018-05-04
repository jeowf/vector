#include <iostream>

#include "vector.h"

int main(){
	//sc::MyIterator<const int> it();

	
		std::cout << ">>> FIT()\n";

		sc::vector<int> v;


		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(10);
		sc::MyIterator<int> s(&v[4]);
	
	std::cout << v[4] << std::endl;

	//int a [] = {5,6,7,8,9};
	 v.insert(s,{5,6,7,8,9}); 
	std::cout <<  v[4] << std::endl;
	std::cout <<  v[5] << std::endl;
	std::cout <<  v[6] << std::endl;
	std::cout <<  v[9] << std::endl;
	std::cout << "\n OK " << std::endl;

	return 0;
}