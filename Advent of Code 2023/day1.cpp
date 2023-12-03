#pragma once
#include "includes.h"
using namespace std;

Solutions::Solutions() {};
Solutions::~Solutions() {};

int Solutions::d1_p1(vector<string> input)
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

int Solutions::d1_p2(vector<string> input)
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
			if (umap.find(line.substr(i, j)) != umap.end()) 
				return umap[line.substr(i, j)];
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