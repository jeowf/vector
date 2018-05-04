#include <iostream>

#include "vector.h"

int main(){
	//sc::MyIterator<const int> it();

	{
		std::cout << ">>> FIT()\n";

		sc::vector<int> v;
		sc::vector<int> s;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);


		s.push_back(1);
		s.push_back(2);
		s.push_back(1);

 		v.assign(0);

		std::cout << v[2] << std::endl;
	}
	

	std::cout << "\n OK " << std::endl;

	return 0;
}