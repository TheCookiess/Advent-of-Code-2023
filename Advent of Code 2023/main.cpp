#pragma once
#include "includes.h"

using namespace std;

int main()
{
	Solutions* AOC = new Solutions;
	vector<string> lines = AOC->getInput("2");

	int part1 = 0, part2 = 0;

	constexpr int loops = 1;
	auto p1_t1 = chrono::high_resolution_clock::now();

	for (int i = 0; i < loops; i++)
		part1 = AOC->d2_p1(lines);

	auto p1_t2 = chrono::high_resolution_clock::now();

	auto p2_t1 = chrono::high_resolution_clock::now();

	for (int i = 0; i < loops; i++)
		part2 = AOC->d2_p2(lines);

	auto p2_t2 = chrono::high_resolution_clock::now();

	chrono::duration<double, micro> p1_time = (p1_t2 - p1_t1) / loops;
	chrono::duration<double, micro> p2_time = (p2_t2 - p2_t1) / loops;

	// all this code for dumb little formatting lol
	string p1_padding = "", p2_padding = "";
	int paddingAmt = (to_string(part2).size()) - (to_string(part1).size());
	unsigned int clampedAmt = paddingAmt; // clamps to positive
	if (paddingAmt > 0)
		for (int i = 0; i < clampedAmt; i++) p1_padding += " ";
	else
		for (int i = 0; i < clampedAmt; i++) p2_padding += " ";

	cout << endl;
	cout << "Solution 1: " << part1 << p1_padding << " Executed in: " << p1_time.count() / 1000 << "ms" << endl;
	cout << "Solution 2: " << part2 << p2_padding << " Executed in: " << p2_time.count() / 1000 << "ms" << endl;
	cout << "Problem outputted to file." << endl;

	return 1;
}
