#pragma once
#include "pch.h"
using namespace std;

struct Galaxy {
	int id = 0, x = 0, y = 0;
	Galaxy(int ID, int X, int Y) { id = ID; x = X; y = Y; }
	Galaxy() = default;
};

int64_t Solutions::d11_p1(vector<string> input)
{
	vector<Galaxy> galaxies;
	vector<string> expanded;

	auto addColumn = [&expanded](int column) -> void {
		for (int i = 0; i < expanded.size(); i++)
			expanded[i].insert(column + 1, 1,'.');
	};

	// add rows. iterate over ROW
	for (int i = 0; i < input.size(); i++) { 
		expanded.push_back(input[i]);
		bool empty = true;
		for (int j = 0; j < input[i].size(); j++)
			if (input[i][j] != '.') {
				empty = false;
				break;
			}
		if (empty) expanded.push_back(input[i]); // add empty row
	}

	// add columns. iterate over COLUMN
	for (int i = 0; i < expanded[0].size(); i++) {
		bool empty = true;
		for (int j = 0; j < expanded.size(); j++)
			if (expanded[j][i] != '.') {
				empty = false;
				break;
			}
		if (empty)
			addColumn(i++);
	}

	for (int i = 0; i < expanded.size(); i++)
		for (int j = 0; j < expanded[i].size(); j++)
			if (expanded[i][j] != '.')
				galaxies.push_back(Galaxy(galaxies.size() + 1, j, i));

	//for (string s : input)
	//	cout << s << endl;
	//cout << endl;
	//
	//int galaxyCount = 0;
	//for (int i = 0; i < expanded.size(); i++) {
	//	for (int j = 0; j < expanded[i].size(); j++)
	//		if (expanded[i][j] != '.')
	//			cout << galaxies[galaxyCount++].id;
	//		else 
	//			cout << '.';
	//	cout << endl;
	//}

	int64_t summation = 0;
	// get pairs
	for (int i = 0; i < galaxies.size(); i++) {
		Galaxy& g0 = galaxies[i];
		for (int j = i + 1; j < galaxies.size(); j++) {
			Galaxy& g1 = galaxies[j];
			
			int sum = 0;
			if (g0.x > g1.x) sum += (g0.x - g1.x);
			else sum += (g1.x - g0.x);
			
			if (g0.y > g1.y) sum += (g0.y - g1.y);
			else sum += (g1.y - g0.y);
			
			//printf("\n%d -> %d | ", g0.id, g1.id);
			//printf("%d", sum);
			summation += sum;
		}
		//printf("\n");
	}

	return summation;
}

// calculate empty zones as an offset for each galaxy's coords.
int64_t Solutions::d11_p2(vector<string> input)
{
	vector<Galaxy> galaxies;
	vector<string> expanded;

	auto addColumn = [&expanded](int column) -> void {
		for (int i = 0; i < expanded.size(); i++)
			expanded[i].insert(column + 1, 1, '.');
	};

	// add rows. iterate over ROW
	for (int i = 0; i < input.size(); i++) {
		expanded.push_back(input[i]);
		bool empty = true;
		for (int j = 0; j < input[i].size(); j++)
			if (input[i][j] != '.') {
				empty = false;
				break;
			}
		if (empty) expanded.push_back(input[i]); // add empty row
	}

	// add columns. iterate over COLUMN
	for (int i = 0; i < expanded[0].size(); i++) {
		bool empty = true;
		for (int j = 0; j < expanded.size(); j++)
			if (expanded[j][i] != '.') {
				empty = false;
				break;
			}
		if (empty)
			addColumn(i++);
	}

	for (int i = 0; i < expanded.size(); i++)
		for (int j = 0; j < expanded[i].size(); j++)
			if (expanded[i][j] != '.')
				galaxies.push_back(Galaxy(galaxies.size() + 1, j, i));

	vector<Galaxy> summation1;
	for (int i = 0; i < galaxies.size(); i++) {
		Galaxy& g0 = galaxies[i];
		for (int j = i + 1; j < galaxies.size(); j++) {
			Galaxy& g1 = galaxies[j];

			int64_t sum = 0;
			if (g0.x > g1.x) sum += (g0.x - g1.x);
			else sum += (g1.x - g0.x);
			int64_t sum1 = sum;

			if (g0.y > g1.y) sum += (g0.y - g1.y);
			else sum += (g1.y - g0.y);
			int64_t sum2 = sum - sum1;

			summation1.push_back(Galaxy(sum, sum1, sum2));
		}
	}

	/*--------------------------------------------
	----------------------------------------------
	--------------------------------------------*/

	galaxies.clear();
	constexpr int spaceConst = 1;

	for (int i = 0; i < input.size(); i++)
		for (int j = 0; j < input[i].size(); j++)
			if (input[i][j] != '.')
				galaxies.push_back(Galaxy(galaxies.size() + 1, j, i));

	for (int i = 0; i < input.size(); i++) {
		bool empty = true;
		for (int j = 0; j < input[i].size(); j++)
			if (input[i][j] != '.') {
				empty = false;
				break;
			}
		if (empty)
			for (Galaxy& g : galaxies)
				if (g.y > i) g.y += spaceConst;
	}

	for (int i = 0; i < input[0].size(); i++) {
		bool empty = true;
		for (int j = 0; j < input.size(); j++)
			if (input[j][i] != '.') {
				empty = false;
				break;
			}
		if (empty) {
			for (Galaxy& g : galaxies)
				if (g.x > i) g.x += spaceConst;
			//i++;
		}
	}
	
	int64_t summation = 0;
	int counter = 0;
	for (int i = 0; i < galaxies.size(); i++) {
		Galaxy& g0 = galaxies[i];
		for (int j = i + 1; j < galaxies.size(); j++) {
			Galaxy& g1 = galaxies[j];
			Galaxy& s1 = summation1[counter];

			int64_t sum = 0;
			if (g0.x > g1.x) sum += (g0.x - g1.x);
			else sum += (g1.x - g0.x);
			int64_t sum1 = sum;

			if (g0.y > g1.y) sum += (g0.y - g1.y);
			else sum += (g1.y - g0.y);
			int64_t sum2 = sum - sum1;
			
			printf("\n%d -> %d | ", g0.id, g1.id);
			printf("%d | ", sum - s1.id);
			printf("(%d,%d), (%d,%d)", s1.x, s1.y, sum1, sum2);
			counter++;
			summation += sum;
		}
		cout << endl;
	}

	return summation;
}