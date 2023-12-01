#pragma once
#include "includes.h"

using namespace std;

int main()
{
	Solutions* AOC = new Solutions;
	vector<string> lines = AOC->getInput("1");

	int solution1 = AOC->p1_p1(lines);

	auto t1 = chrono::high_resolution_clock::now();
	int solution2 = AOC->p1_p2(lines);
	auto t2 = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> time = t2 - t1;

	cout << solution1 << "\n";
	cout << solution2 << " executed in: " << time.count() << "ms\n";
	cout << "Problem outputted to file.\n";

	return 1;
}
