#pragma once
#include "pch.h"
using namespace std;

auto strToInt_Signed = [](string num) -> int64_t {
	bool isNeg = false;
	if (num[0] == '-') {
		isNeg = true;
		num.erase(num.begin());
	}
	int64_t summation = 0;
	for (int i = 0; i < num.size(); i++) {
		summation *= 10;
		summation += num[i] - '0';
	}
	return isNeg ? summation * -1 : summation;
};

int64_t Solutions::d9_p1(vector<string> input)
{

	int64_t summation = 0;
	vector<vector<int64_t>> nums(input.size());
	for (int64_t i = 0; i < input.size(); i++) {
		vector<string> splitLine = split(input[i], ' ');
		for (string str : splitLine) 
			nums[i].push_back(strToInt_Signed(str));
	}

	for (vector<int64_t> set : nums) {

		//for (int64_t num : set)
		//	cout << num << " ";
		//cout << endl;

		vector<vector<int64_t>> diffs;
		diffs.push_back(set);

		int64_t iter = 0;
		bool diffIsZero = false;
		while (!diffIsZero) {

			if (diffs[iter].size() == 1) break;

			diffIsZero = true;
			diffs.push_back({}); // new set of differences
			for (int64_t i = 1; i < diffs[iter].size(); i++) {
				int64_t diff = diffs[iter][i] - diffs[iter][i - 1];
				diffs[iter + 1].push_back(diff);
				
				if (diff != 0) diffIsZero = false;

				//cout << diff << " ";
			}
			//cout << endl;
			iter++;
		}
		
		// extrapolate next history: 
		// for each set of differences. NOT INCLUDING last as last is all 0's
		// add diff to next diff up (i - 1) += i
		// repeat until i == 0
		int64_t next = 0;
		for (int64_t i = diffs.size() - 1; i >= 0; i--) {
			next += diffs[i][diffs[i].size() - 1];
		}
		summation += next;

		//cout << "--> "
		//	<< next
		//	<< endl
		//	<< endl;
	}


	return summation;
}

int64_t Solutions::d9_p2(vector<string> input)
{
	int64_t summation = 0;

	vector<vector<int64_t>> nums(input.size());
	for (int64_t i = 0; i < input.size(); i++) {
		vector<string> splitLine = split(input[i], ' ');
		for (string str : splitLine)
			nums[i].push_back(strToInt_Signed(str));
	}

	for (vector<int64_t> set : nums) {

		//for (int64_t num : set)
		//	cout << num << " ";
		//cout << endl;

		vector<vector<int64_t>> diffs;
		diffs.push_back(set);

		int64_t iter = 0;
		bool diffIsZero = false;
		while (!diffIsZero) {

			if (diffs[iter].size() == 1) break;

			diffIsZero = true;
			diffs.push_back({}); // new set of differences
			for (int64_t i = 1; i < diffs[iter].size(); i++) {
				int64_t diff = diffs[iter][i] - diffs[iter][i - 1];
				diffs[iter + 1].push_back(diff);

				if (diff != 0) diffIsZero = false;

				//cout << diff << " ";
			}
			cout << endl;
			iter++;
		}

		// extrapolate next history: 
		// for each set of differences. NOT INCLUDING last as last is all 0's
		// add diff to next diff up (i - 1) += i
		// repeat until i == 0

		int64_t next = 0;
		for (int64_t i = diffs.size() - 2; i >= 0; i--)
			next = diffs[i][0] - next;
		summation += next;

		//cout << "--> "
		//	<< next
		//	<< endl
		//	<< endl;
	}



	return summation;
}
