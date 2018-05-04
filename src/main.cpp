#include <iostream>

#include "vector.h"

int main(){
	//sc::MyIterator<const int> it();

	{
		std::cout << ">>> ==()\n";

		sc::vector<int> v;
		sc::vector<int> s;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);


		s.push_back(1);
		s.push_back(2);
		s.push_back(3);

		bool a = s != v;

		std::cout << a << std::endl;
	}
	

	std::cout << "\n OK " << std::endl;

	return 0;
}