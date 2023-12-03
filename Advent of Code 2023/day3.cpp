#pragma once
#include "includes.h"
using namespace std;

int Solutions::d3_p1(vector<string> input)
{
	int summation = 0;
	for (int y = 1; y < input.size() - 1; y++) {
		string& line = input[y];
		string num = "";
		bool isValid = true;
		for (int x = 1; x < line.size() - 1; x++) {
			char c = line[x]; // reference (i64) > char (i8)
			if (isdigit(c)) { // capturing a number (multiple digits)
				num += c;
				for (int i = -1; i < 1; i++)
					for (int j = -1; j < 1; j++) {
						char dC = input[y + i][x + j];
						if (dC == '.') // if adj char is == '.'
							isValid = false;
					}
			}
			else if (!num.empty()) { // number captured, check neighbours for symbols
				//fo`r (int i = -1; i <= num.size(); i++) {// check neighbours for whole length of number
				//	f`or (int j = -1; j <= 1; j++) { // check top & bot neighbours
				//		`//if (y + i >= input.size() || y + i < 0 || x + j >= line.size() || x + j < 0) continue; // bounds check
				//		`if (input[y + i][x + j - num.size() - 1] != '.') // x is currently char after word. so go back
				//		`	summation += strtol(num.c_str(), nullptr, 10);
				//	}`
				//}
				if (isValid)
					summation += strtol(num.c_str(), nullptr, 10);
				//cout << "number captured: " << num << endl;
				//cout << "x: " << x << endl;
				//cout << "y: " << y << endl;
				//for (int i = 0; i < 80; i++)
				//	cout << '=';
				//cout << endl;

				num = "";
				isValid = true;
			}
			else { num = ""; isValid = true; };
		}
	}
	return summation;
}

int Solutions::d3_p2(vector<string> input)
{
	int summation = 0;

	return summation;
}