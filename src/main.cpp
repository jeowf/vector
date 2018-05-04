#include <iostream>
#include <cassert>

#include "vector.h"

int main(){
	//sc::MyIterator<const int> it();

	{
		std::cout << ">>> vector instancied as v\n";
		sc::vector<int> v;

		assert(v.empty());
		std::cout << " v is empty\n";

		std::cout << ">>> added 1 in v\n";
		v.push_back(1);

		assert(!v.empty());
		std::cout << " v is not empty\n";

		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		std::cout << ">>> added [ 2 3 4 ] at end of v\n";
		std::cout << " v is " << v << " cap = " << v.capacity() << " size = " << v.size()<< std::endl;
	
		v.push_front(0);
		v.push_front(-1);
		std::cout << ">>> added [ -1 0 ] at beginning of v\n";
		std::cout << " v is " << v << " cap = " << v.capacity() << " size = " << v.size()<< std::endl;

		v.pop_front();
		std::cout << ">>> popped the first element of v\n";
		std::cout << " v is " << v << " cap = " << v.capacity() << " size = " << v.size()<< std::endl;

		v.pop_back();
		std::cout << ">>> popped the last element of v\n";
		std::cout << " v is " << v << " cap = " << v.capacity() << " size = " << v.size()<< std::endl;




	}

	return 0;
}