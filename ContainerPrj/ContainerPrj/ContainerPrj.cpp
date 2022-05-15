// ContainerPrj.cpp : Defines the entry point for the application.
//

#include "ContainerPrj.h"
#include "ConsistentArray.h"

using namespace std;

int main()
{
	std::cout << "Hello CMake." << std::endl;

	ConArray arr;
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	std::cout << "enter values." << std::endl;
	/*
	for (int i = 0; i < arr.size(); ++i) {
		std::cout << i << "  " << arr[i] << std::endl;
	}
	*/
	return 0;
}
