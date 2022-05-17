// ArrayContainer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Array.hpp"


int main()
{
		std::cout << "Hello CMake." << std::endl;

		ConArray arr;
		arr.push_back(2);
		std::cout << "size: " <<  arr.size() << std::endl;
		arr.push_back(3);
		std::cout << "size: " << arr.size() << std::endl;
		arr.push_back(4);
		std::cout << "size: " << arr.size() << std::endl;

		std::cout << "enter values." << std::endl;
		
		for (int i = 0; i < arr.size(); ++i) {
			std::cout << i << "  " << arr[i] << std::endl;
		}


    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
