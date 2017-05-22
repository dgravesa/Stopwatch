/*
	Daniel Graves
	test.cpp
*/

#include "Stopwatch.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	Stopwatch sw(true);
	int N = 10000000;

	for (int i = 0; i < N; ++i)
		int j = 2 + 7 * i + 3 * i * i;

	std::cout << "loop1 time = " << sw.lap() << " seconds\n";

	for (int i = 0; i < N; ++i)
		int j = 3 + 17 * i + 5 * i * i;

	std::cout << "loop2 time = " << sw.read() << " seconds\n";

	return 0;
}

