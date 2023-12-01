#pragma once
#include "includes.h"
using namespace std;

// includes phonetic spelling, e.g "nine" = 9.
//vector<string> phoneticNums = { "one", "two", "three", "four", "five", "six", "seven", "eight ","nine" }; 
//bool checkDigit(string line, int idx, string& numbers, int part)
//{
//	if (isdigit(line[idx])) { numbers += line[idx]; return true; }
//
//	if (part != 2) return false;
//	
//	// check phonetics
//	for (int i = 0; i < phoneticNums.size(); i++) {
//		string& str = phoneticNums[i];
//		bool correct = true;
//		for (int j = 0; j < str.length(); j++) {
//			if (j + idx >= line.size()) { correct = false; break; } // out of range, can't be true.
//			//if (line[idx + j] != str[j]) { correct = false; break; }
//			if (line[i] >= '0' && line[i] <= '9') return line[i] - '0';
//			if (line.substr(i, 4) == "zero") return 0;
//			if (line.substr(i, 3) == "one") return 1;
//			if (line.substr(i, 3) == "two") return 2;
//			if (line.substr(i, 5) == "three") return 3;
//			if (line.substr(i, 4) == "four") return 4;
//			if (line.substr(i, 4) == "five") return 5;
//			if (line.substr(i, 3) == "six") return 6;
//			if (line.substr(i, 5) == "seven") return 7;
//			if (line.substr(i, 5) == "eight") return 8;
//			if (line.substr(i, 4) == "nine") return 9;
//		}
//		if (!correct) continue;
//		numbers += (++i) + '0'; // == i + 1
//		return true;
//	}
//			
//	return false;
//}

Solutions::Solutions() {};
Solutions::~Solutions() {};

int Solutions::p1_p1(vector<string> input)
{
	int summation = 0;
	for (string line : input) {
		int first = 0, last = 0;
		for (int i = 0; i < line.length(); i++)
			if (line[i] >= '0' && line[i] <= '9') { first = line[i] - '0'; break; }
		for (int i = line.length() - 1; i >= 0; i--)
			if (line[i] >= '0' && line[i] <= '9') { last = line[i] - '0'; break;  }
		summation += first * 10 + last;
	}
	return summation;
}

//vector<string> phoneticNums = { "one", "two", "three", "four", "five", "six", "seven", "eight ","nine" };
int Solutions::p1_p2(vector<string> input)
{
	int summation = 0;
	unordered_map<string, int> umap;
	umap["one"] = 1, umap["two"]   = 2, umap["three"] = 3, umap["four"] = 4, umap["five"] = 5,
	umap["six"] = 6, umap["seven"] = 7, umap["eight"] = 8, umap["nine"] = 9;

	// lamba function oooh
	auto findNumber = [](string line, int i, unordered_map<string, int>& umap)
	{
		if (isdigit(line[i])) return line[i] - '0';
		for (int j = 3; j <= 5; j++) // checking all possible lengths of the word, 3 characters --> 5
			if (umap.find(line.substr(i, j)) != umap.end()) return umap[line.substr(i, j)];
		return -1;
	};

	for (string line : input) {
		int first = -1, last = -1;
		for (int i = 0; i < line.length(); i++) {
			first = findNumber(line, i, umap);
			if (first != -1) break;
		}
		for (int i = line.length() - 1; i >= 0; i--) {
			last = findNumber(line, i, umap);
			if (last != -1) break;
		}
		summation += first * 10 + last;
	}
	return summation;
}
