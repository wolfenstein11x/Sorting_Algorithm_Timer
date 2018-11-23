#include "stdafx.h"
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>
#include "sorting_functions.h"

void selectionSort(std::vector<int> &vec)
{
	std::cout << "\nSorting by selection sort...\n";
	auto start = std::chrono::high_resolution_clock::now();

	int i, minIndex, minValue;

	for (i = 0; i < (vec.size() - 1); i++)
	{
		minIndex = i;
		minValue = vec[i];
		for (int j = i + 1; j < vec.size(); j++)
		{
			if (vec[j] < minValue)
			{
				minValue = vec[j];
				minIndex = j;
			}
		}
		vec[minIndex] = vec[i];
		vec[i] = minValue;
	}

	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "\nElapsed time for selection sort: " << elapsed.count() << " s\n";
}

void bubbleSort(std::vector<int> &vec)
{
	std::cout << "\nSorting by bubble sort...\n";
	auto start = std::chrono::high_resolution_clock::now();

	int  temp;
	bool swap;

	do
	{
		swap = false;
		for (int count = 0; count < (vec.size() - 1); count++)
		{
			if (vec[count] > vec[count + 1])
			{
				temp = vec[count];
				vec[count] = vec[count + 1];
				vec[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap); 

	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "\nElapsed time for bubble sort: " << elapsed.count() << " s\n";
}

void fill_vec(std::vector<int> &vec, int size) {
	for (int i = 0; i < size; i++) {
		vec.push_back(i+1);
	}
}

void print_vec(std::vector<int> &vec) {
	if (vec.size() <= 100) {
		std::cout << "\n[ ";
		for (auto elem : vec) {
			std::cout << elem << " ";
		}
		std::cout << "]\n";
	}	
}

void scramble(std::vector<int> &vec) {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	shuffle(vec.begin(), vec.end(), std::default_random_engine(seed));
}

