#include <iostream>

#include "vector.h"

int main(){
	//sc::MyIterator<const int> it();

	{
		sc::vector<int> v();

		//int a = 2;

		
		std::cout << v.empty(); << std::endl;
	}
	

	std::cout << "\n OK " << std::endl;

	return 0;
}