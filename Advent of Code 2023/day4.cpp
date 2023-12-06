#pragma once
#include "pch.h"
using namespace std;

int Solutions::d4_p1(vector<string> input)
{
	int summation = 0;
	
	auto increaseScore = [](int cardWinSum)
	{ return (cardWinSum == 0) ? 1 : cardWinSum * 2; };

	auto strToInt = [](string num) {
		int summation = 0;
		for (int i = 0; i < num.size(); i++) {
			summation *= 10;
			summation += num[i] - '0';
		}
		return summation;
	};

	auto strVecToInt = [strToInt](const vector<string>& strVec) {
		vector<int> nums;
		for (string str : strVec)
			if (str != "")
				nums.push_back(strToInt(str));
		return nums;
	};

	for (string line : input) {
		line = split(line, ':')[1]; // removes "Game XXX:"
		vector<string> nums = split(line, '|');
		vector<int> winningNums = strVecToInt(split(nums[0], ' '));
		vector<int> myNums      = strVecToInt(split(nums[1], ' '));

		int cardWinSum = 0;
		for (int num : myNums)
			if (find(winningNums.begin(), winningNums.end(), num) != winningNums.end())
				cardWinSum = increaseScore(cardWinSum);
		summation += cardWinSum;
	}

	return summation;
}

int Solutions::d4_p2(vector<string> input)
{
	int summation = 0;

	auto strToInt = [](string num) {
		int summation = 0;
		for (int i = 0; i < num.size(); i++) {
			summation *= 10;
			summation += num[i] - '0';
		}
		return summation;
	};

	auto strVecToVec = [strToInt](const vector<string>& strVec) {
		vector<int> nums;
		for (string str : strVec)
			if (str != "")
				nums.push_back(strToInt(str));
		return nums;
	};

	auto strVecToUset = [strToInt](const vector<string>& strVec) {
		unordered_set<int> uset;
		for (string str : strVec)
			if (str != "")
				uset.insert(strToInt(str));
		return uset;
	};

	auto strVecToSet = [strToInt](const vector<string>&strVec) {
		set<int> set;
		for (string str : strVec)
			if (str != "")
				set.insert(strToInt(str));
		return set;
	};
	

	vector<int> played(input.size(), 0);
	for (int i = 0; i < input.size(); i++) {
		played[i]++;

		vector<string> numbers = split(input[i], ':'); // isolate numbers
		numbers = split(numbers[1], '|');
		set<int> winNums  = strVecToSet(split(numbers[0], ' '));
		set<int> cardNums = strVecToSet(split(numbers[1], ' '));

		vector<int> winners;
		set_intersection(winNums.begin(), winNums.end(), 
						cardNums.begin(), cardNums.end(),back_inserter(winners));
		
		cout << "Line: " << i + 1 << " ";
		for (int j = 0; j < winners.size(); j++) {
			cout << winners[j] << ", ";
			if (i + j + 1 < input.size())
				played[i + j + 1] += played[i];
		}
		cout << endl;
	}
	
	for (int num : played)
		summation += num;

	return summation;
}