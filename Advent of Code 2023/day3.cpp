#pragma once
#include "includes.h"
using namespace std;

int Solutions::d3_p1(vector<string> input)
{
	int summation = 0;
	for (int y = 0; y < input.size(); y++) {
		string& line = input[y];
		string num = "";
		for (int x = 0; x < line.size(); x++) {
			char c = line[x]; // reference (i64) > char (i8)
			if (isdigit(c)) // capturing a number (multiple digits)
				num += c;
			else if (!num.empty()) { // number captured, check neighbours for symbols
				for (int i = -1; i <= num.size(); i++) // check neighbours for whole length of number
					for (int j = -1; j <= 1; j++) { // check top & bot neighbours
						if (y + i >= input.size() || y + i < 0 || x + j >= line.size() || x + j < 0) continue; // bounds check
						if (input[y + i][x + j] != '.')
							summation += strtol(num.c_str(), nullptr, 10);
					}
			}
			else continue; // no number captured 
		}
	}
	return summation;
}

int Solutions::d3_p2(vector<string> input)
{
	int summation = 0;

	return summation;
}