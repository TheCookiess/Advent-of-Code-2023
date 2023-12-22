#pragma once
#include "pch.h"

auto strToInt_Signed = [](string num) -> s64 {
	bool isNeg = false;
	if (num[0] == '-') {
		isNeg = true;
		num.erase(num.begin());
	}
	s64 summation = 0;
	for (int i = 0; i < num.size(); i++) {
		summation *= 10;
		summation += num[i] - '0';
	}
	return isNeg ? summation * -1 : summation;
};

s64 Solutions::d9_p1(vector<string> input)
{

	s64 summation = 0;
	vector<vector<s64>> nums(input.size());
	for (s64 i = 0; i < input.size(); i++) {
		vector<string> splitLine = split(input[i], ' ');
		for (string str : splitLine) 
			nums[i].push_back(strToInt_Signed(str));
	}

	for (vector<s64> set : nums) {

		//for (s64 num : set)
		//	cout << num << " ";
		//cout << endl;

		vector<vector<s64>> diffs;
		diffs.push_back(set);

		s64 iter = 0;
		bool diffIsZero = false;
		while (!diffIsZero) {

			if (diffs[iter].size() == 1) break;

			diffIsZero = true;
			diffs.push_back({}); // new set of differences
			for (s64 i = 1; i < diffs[iter].size(); i++) {
				s64 diff = diffs[iter][i] - diffs[iter][i - 1];
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
		s64 next = 0;
		for (s64 i = diffs.size() - 1; i >= 0; i--) {
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

s64 Solutions::d9_p2(vector<string> input)
{
	s64 summation = 0;

	vector<vector<s64>> nums(input.size());
	for (s64 i = 0; i < input.size(); i++) {
		vector<string> splitLine = split(input[i], ' ');
		for (string str : splitLine)
			nums[i].push_back(strToInt_Signed(str));
	}

	for (vector<s64> set : nums) {

		//for (s64 num : set)
		//	cout << num << " ";
		//cout << endl;

		vector<vector<s64>> diffs;
		diffs.push_back(set);

		s64 iter = 0;
		bool diffIsZero = false;
		while (!diffIsZero) {

			if (diffs[iter].size() == 1) break;

			diffIsZero = true;
			diffs.push_back({}); // new set of differences
			for (s64 i = 1; i < diffs[iter].size(); i++) {
				s64 diff = diffs[iter][i] - diffs[iter][i - 1];
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

		s64 next = 0;
		for (s64 i = diffs.size() - 2; i >= 0; i--)
			next = diffs[i][0] - next;
		summation += next;

		//cout << "--> "
		//	<< next
		//	<< endl
		//	<< endl;
	}



	return summation;
}
