#include <iostream>

#include "iterator.h"

int main(){
	sc::MyIterator<const int> it();
	std::cout << "opa" << std::endl;
	return 0;
}