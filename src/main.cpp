#include <iostream>

#include "vector.h"

int main(){
	//sc::MyIterator<const int> it();

	{
		std::cout << ">>> bool empty()\n";

		sc::vector<int> v;
		std::cout << v.empty() << std::endl;

		v.push_back(1);

		std::cout << v.empty() << std::endl;
	}
	

	std::cout << "\n OK " << std::endl;

	return 0;
}