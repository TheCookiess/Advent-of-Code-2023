#pragma once
#include "pch.h"
using namespace std;

int64_t Solutions::d3_p1(vector<string> input)
{
	int summation = 0;
	int yBound = input.size();
	int xBound = input[0].size(); // all lines are same length

	auto isCharNumber = [](char c)
	{ return (c >= '0' && c <= '9'); };

	auto isCharSymbol = [isCharNumber](char c)
	{ return (!isCharNumber(c) && c != '.'); };

	auto isInBounds = [xBound, yBound](int x, int y)
	{ return (x >= 0 && y >= 0 && x < xBound && y < yBound);  };

	//auto isNegative = [&input, isInBounds](int x, int y)
	//{ return (isInBounds(x, y) && input[y][x] == '-'); };

	auto isPart = [&input, isInBounds, isCharSymbol](int x, int y) {
		for (int dY = -1; dY <= 1; dY++)
			for (int dX = -1; dX <= 1; dX++)
				if (isInBounds(x + dX, y + dY) && isCharSymbol(input[y + dY][x + dX])) {
					return true;
					//cout << input[y][x] << " has: " << input[y + dY][x + dX] << " as a neighbour" << endl;
				}
		return false;
	};

	auto strToInt = [](string num) {
		int summation = 0;
		for (int i = 0; i < num.size(); i++) {
			summation *= 10;
			summation += num[i] - '0';
		}
		return summation;
	};

	for (int y = 0; y < input.size(); y++) { // each line
		string& line = input[y];
		int num = 0;
		for (int x = 0; x < line.size(); x++) { // each character
			if (!isCharNumber(line[x])) continue;

			// have to include first char!
			int dX = 1;
			string num; num += line[x];
			bool isValidPart = isPart(x,y);
			while (isInBounds(x+dX, y) && isCharNumber(line[x + dX])) { // num.size() acts as a counter technically but ruins readability.
				num += line[x + dX];
				if (isPart(x + dX, y)) 
					isValidPart = true;
				dX++;
			}

			if (isValidPart)
				summation += strToInt(num);

			x += dX; // advance past number.
		}
	}
	return summation;
}

int64_t Solutions::d3_p2(vector<string> input)
{
	long long summation = 0;
	int yBound = input.size();
	int xBound = input[0].size(); // all lines are same length

											// note to self: multimaps BAD!!
	unordered_map<int, vector<int>> umap;	// int1 == absolute index of a gear
											// vec<int> == all numbers neighbouring the gear.

	auto isCharNumber = [](char c)
	{ return (c >= '0' && c <= '9'); };

	auto isCharGear = [](char c)
	{ return (c == '*'); };

	auto isInBounds = [xBound, yBound](int x, int y)
	{ return (x >= 0 && y >= 0 && x < xBound&& y < yBound);  };


	auto absoluteIndex = [xBound](int x, int y)
	{ return y * xBound + x;  };

	auto strToInt = [](string num) {
		int summation = 0;
		for (int i = 0; i < num.size(); i++) {
			summation *= 10;
			summation += num[i] - '0';
		}
		return summation;
	};

	// absolute clusterfuckery
	auto checkForGears = [&input, &umap, isInBounds, isCharGear, absoluteIndex](int x, int y, int num, int length) {
		for (int dY = -1; dY <= 1; dY++)
			for (int dX = -1; dX <= length; dX++)
				if (isInBounds(x + dX, y + dY) && isCharGear(input[y + dY][x + dX])) {
					int gearIndex = absoluteIndex(x + dX, y + dY);
					umap[gearIndex].push_back(num);
					//else
					//if (umap.contains(gearIndex))
					//	umap[gearIndex] = {num};
					return;
				}
		return;
	};

	for (int y = 0; y < input.size(); y++) {
		string& line = input[y];
		for (int x = 0; x < line.size(); x++) {
			if (!isCharNumber(input[y][x])) continue;

			int dX = 1;
			string num = ""; num += line[x];
			while (isInBounds(x + dX, y) && isCharNumber(line[x + dX])) { // num.size() acts as a counter technically but ruins readability.
				num += line[x + dX];
				dX++;
			}
			checkForGears(x, y, strToInt(num), num.size());

			x += dX;
		}
	}

	for (const auto& n : umap)
		if (n.second.size() == 2)
			summation += (n.second[0] * n.second[1]);
			//cout << n.second[0] << endl << n.second[1] << endl << "--" << endl;

	return summation;
}