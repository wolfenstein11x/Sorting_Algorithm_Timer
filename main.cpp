#include "stdafx.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include "sorting_functions.h"


int main()
{
	std::vector<int> vec1;
	std::vector<int> vec2;
	int n;
	
	while (true) {
		std::cout << "\nEnter the size of the vector to be sorted, or type -1 to quit: ";

		std::cin >> n;

		if (n < 0) {
			break;
		}

		fill_vec(vec1, n);
		scramble(vec1);
		vec2 = vec1;
		print_vec(vec1);
		selectionSort(vec1);
		bubbleSort(vec2);
		print_vec(vec1);
		vec1.clear();
		vec2.clear();
	}

	std::cout << "\n\n";
    return 0;
}

