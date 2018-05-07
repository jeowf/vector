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

		sc::MyIterator<int> x = v.begin();
		sc::MyIterator<int> y = v.end();
		std::cout << ">>> testing iterators of v at [begin;end) i.e ";

		std::cout << "[ ";
		while (x != y){
			std::cout << *x << " ";
			x++;
		}
		std::cout << "]\n";

		v.clear();
		std::cout << ">>> clearing v\n";
		std::cout << " v is " << v << " cap = " << v.capacity() << " size = " << v.size()<< std::endl;
	}

	std::cout << std::endl;

	{	
		sc::vector<int> v = {0, 1, 2};
		std::cout << ">>> created v = [ 0 1 2 ]\n";

		sc::vector<int> x (v.begin(), v.end());
		std::cout << ">>> created x with values in the iterval [v.begin(), v.end())\n";

		std::cout << " v is " << v << " cap = " << v.capacity() << " size = " << v.size()<< std::endl;
		std::cout << " x is " << x << " cap = " << x.capacity() << " size = " << x.size()<< std::endl;

		x.insert(x.begin() + 1, 3);
		std::cout << ">>> inserted 3 at position 1 in x\n";
		std::cout << " x is " << x << " cap = " << x.capacity() << " size = " << x.size()<< std::endl;


		v.insert(v.begin() + 2, { 4,5,6 });
		std::cout << ">>> inserted [ 4 5 6 ] at position 2 in v\n";
		std::cout << " v is " << v << " cap = " << v.capacity() << " size = " << v.size()<< std::endl;

		x.insert(x.begin() + 1, v.begin(), v.end());
		std::cout << ">>> inserted " << v << " at position 1 in v\n";
		std::cout << " x is " << x << " cap = " << x.capacity() << " size = " << x.size()<< std::endl;

		x.erase(x.begin() + 1);
		std::cout << ">>> erased at position 1 in x\n";
		std::cout << " x is " << x << " cap = " << x.capacity() << " size = " << x.size()<< std::endl;

		x.erase(x.begin() + 1, x.begin() + 5);
		std::cout << ">>> erased from position 1 to 4 in x\n";
		std::cout << " x is " << x << " cap = " << x.capacity() << " size = " << x.size()<< std::endl;

	}

	return 0;
}