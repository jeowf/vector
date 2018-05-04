#include <iostream>

#include "vector.h"

int main(){
	//sc::MyIterator<const int> it();

	
		std::cout << ">>> FIT()\n";

		sc::vector<int> v;
		

		v.push_back(1);
		v.push_back(2);
		v.push_back(5);

	
	std::cout << v[2] << std::endl;

	 int a [] = {1,2,3,4,5};
	 v.assign(a[0],a[4]); 
	std::cout <<  v[3] << std::endl;
	std::cout << "\n OK " << std::endl;

	return 0;
}