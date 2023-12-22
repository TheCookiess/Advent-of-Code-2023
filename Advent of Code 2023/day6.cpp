#pragma once
#include "pch.h"

s64 Solutions::d6_p1(vector<string> input)
{
	auto strToInt = [](string num) {
		long long summation = 0;
		for (int i = 0; i < num.size(); i++) {
			summation *= 10;
			summation += num[i] - '0';
		}
		return summation;
	};

	auto strVecToInt = [strToInt](const vector<string>& strVec) {
		vector<long> nums;
		for (string str : strVec)
			if (str != "")
				nums.push_back(strToInt(str));
		return nums;
	};

	long summation = 1; // anything * 0 == 0. so don't start at 0.
	vector<long> time = strVecToInt(split(split(input[0], ':')[1], ' '));
	vector<long> dist = strVecToInt(split(split(input[1], ':')[1], ' '));

	// time (ms) given for race
	// distance (um) to beat.
	// choose X ms to gain acceleration
	// --> what acceleration's will beat the distance?

	for (int i = 0; i < time.size(); i++) { // each race
		//cout << "New Race: " << i << endl;
		int winners = 0;
		for (int t = 0; t < time[i]; t++) {		// each possible acceleration
			// time spent accelerating = acceleration
			int travelledDist = t * (time[i] - t);
			if (travelledDist > dist[i]) {
				winners++;
				//cout << "New Winner: " << travelledDist << "|" << t << endl;
			}
		}
		if (winners != 0)
			summation *= winners;
	}

	return summation;
}

s64 Solutions::d6_p2(vector<string> input)
{
	auto strToInt = [](string num) {
		long long summation = 0;
		for (char c : num) {
			if (c == 32) continue;
			summation *= 10;
			summation += c - '0';
		}
		return summation;
	};

	auto strVecToInt = [strToInt](const vector<string>& strVec) {
		vector<long> nums;
		for (string str : strVec)
			if (str != "")
				nums.push_back(strToInt(str));
		return nums;
	};

	long long time = strToInt(split(input[0], ':')[1]);
	long long dist = strToInt(split(input[1], ':')[1]);

	long long winners = 0;
	long long summation = 0;
	for (int t = 0; t < time; t++) // each possible acceleration
		if (t * (time - t) > dist)
			summation++;

	return summation;
}