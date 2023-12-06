#include "pch.h"
using namespace std;

int Solutions::d5_p1(vector<string> input)
{
	long long smallestLocation = INT64_MAX;

	auto strToInt = [](string num) {
		long long summation = 0;
		for (int i = 0; i < num.size(); i++) {
			summation *= 10;
			summation += num[i] - '0';
		}
		return summation;
	};

	auto strVecToInt = [strToInt](const vector<string>& strVec) {
		vector<long long> nums;
		for (string str : strVec)
			if (str != "")
				nums.push_back(strToInt(str));
		return nums;
	};

	auto strVecToUset = [strToInt](const vector<string>& strVec) {
		unordered_set<long long> uset;
		for (string str : strVec)
			if (str != "")
				uset.insert(strToInt(str));
		return uset;
	};

	// Seed --> Soil --> Fertiliser --> Water --> Light --> Temperature --> Humidity --> Location
	vector<vector<vector<long long>>> maps(7);
	unordered_set<long long> seeds = strVecToUset(split(split(input[0], ':')[1], ' ')); // perfection

	int i = 1;
	int mapIdx = 0;
	while (mapIdx < 7) {
		if (input[i] == "") i += 2;
		while (input[i] != "") {
			string& line = input[i];
			// convert line to a vector of ints. Y INDEX, X INDEX, RANGE.
			maps[mapIdx].push_back(strVecToInt(split(line, ' '))); 
			i++;
			if (i == input.size()) break;
		}
		mapIdx++; // empty line therefore new map.
	}

	// Map: []	   = Map e.g fertiliser = 2
	//		[][]   = a set of mapping in that map 
	//		[][][] = each value of a map, stored in: Y INDEX, X INDEX, RANGE

	// X-to-Y map: 
	// Y INDEX | X INDEX | RANGE
	// e.g 
	// seed-to-soil map:
	// 50 98 2
	// seed 98, 99 --> soil 50, 51

	//	loop through all seeds
	//		loop through current map
	//			search X index + range boundary
	//			if seed is within index + range
	//				use Y index for next map.
	//			If Not in any mapping:
	//				use current seed value for next map

	long long value = 0;
	for (auto seed : seeds) {
		value = seed;
		mapIdx = 0; 
		//cout << "Inital value: " << seed << endl;
		while (mapIdx < 7) {

			for (auto mapping : maps[mapIdx]) {
				auto dest  = mapping[0];
				auto src   = mapping[1];
				auto range = mapping[2];
				
				if ((value >= src) && (value < (src + range))) { // NOT inclusive upper bound
					value += (dest - src); // calculate next map's offset
					break;
				}
			}
			//cout << "    New seed: " << value << endl;
			mapIdx++;
		}
		if (value < smallestLocation)
			smallestLocation = value;
		//cout << "================================" << endl;
	}
	//cout << smallestLocation << endl;
	return smallestLocation;
}

// just bruteforce it, this one was a doozy..
// https://youtu.be/1fhA6C5Swok?t=314
int Solutions::d5_p2(vector<string> input) 
{
	long long smallestLocation = INT64_MAX;

	auto strToInt = [](string num) {
		long long summation = 0;
		for (int i = 0; i < num.size(); i++) {
			summation *= 10;
			summation += num[i] - '0';
		}
		return summation;
	};

	auto strVecToInt = [strToInt](const vector<string>& strVec) {
		vector<long long> nums;
		for (string str : strVec)
			if (str != "")
				nums.push_back(strToInt(str));
		return nums;
	};

	auto strVecToUset = [strToInt](const vector<string>& strVec) {
		unordered_set<long long> uset;
		for (string str : strVec)
			if (str != "")
				uset.insert(strToInt(str));
		return uset;
	};


	// Seed --> Soil --> Fertiliser --> Water --> Light --> Temperature --> Humidity --> Location
	vector<vector<vector<long long>>> maps(7);
	
	// change to pairs:
	// first number  = starting value
	// second number = range of values.
	unordered_set<long long> seeds = strVecToUset(split(split(input[0], ':')[1], ' ')); 

	// do some multi-threading
	// would be a good introduction
	// good usage of o'l 2700X

	int i = 1;
	int mapIdx = 0;
	while (mapIdx < 7) {
		if (input[i] == "") i += 2;
		while (input[i] != "") {
			string& line = input[i];
			// convert line to a vector of ints. Y INDEX, X INDEX, RANGE.
			maps[mapIdx].push_back(strVecToInt(split(line, ' ')));
			i++;
			if (i == input.size()) break;
		}
		mapIdx++; // empty line therefore new map.
	}

	long long value = 0;
	for (auto seed : seeds) {
		value = seed;
		mapIdx = 0;
		//cout << "Inital value: " << seed << endl;
		while (mapIdx < 7) {

			for (auto mapping : maps[mapIdx]) {
				auto dest = mapping[0];
				auto src = mapping[1];
				auto range = mapping[2];

				if ((value >= src) && (value < (src + range))) { // NOT inclusive upper bound
					value += (dest - src); // calculate next map's offset
					break;
				}
			}
			//cout << "    New seed: " << value << endl;
			mapIdx++;
		}
		if (value < smallestLocation)
			smallestLocation = value;
		//cout << "================================" << endl;
	}
	//cout << smallestLocation << endl;
	return smallestLocation;
}

//	> loop through map index.
//		> loop through while seed pairs exist
//			> remove current seed pairing from list.
//			> create a new list of seed pairing (newSeedPairs)
//			> if entire range of values fits within mapping
//				> add new seed pair == mapped pair
//			> else check for lower and upper bounds for pairs that aren't inside mapping
//				> add to newSeedPairs
//		> seedPairs = newSeedPairs
// > search seedPairs for lowest starting value (pair index 0)
// > return lowestValue.

/*
int Solutions::d5_p2(vector<string> input)
{
	long long smallestLocation = INT64_MAX;

	auto strToInt = [](string num) {
		long long summation = 0;
		for (int i = 0; i < num.size(); i++) {
			summation *= 10;
			summation += num[i] - '0';
		}
		return summation;
	};

	auto strVecToInt = [strToInt](const vector<string>& strVec) {
		vector<long long> nums;
		for (string str : strVec)
			if (str != "")
				nums.push_back(strToInt(str));
		return nums;
	};

	// Seed --> Soil --> Fertiliser --> Water --> Light --> Temperature --> Humidity --> Location
	vector<vector<vector<long long>>> maps(7);
	auto seedInp = strVecToInt(split(split(input[0], ':')[1], ' '));
	vector<pair<long long, long long>> seeds;

	for (int i = 0; i < seedInp.size(); i += 2)
		seeds.emplace_back(seedInp[i], seedInp[i + 1]);

	int i = 1;
	int mapIdx = 0;
	while (mapIdx < 7) {
		if (input[i] == "") i += 2;
		while (input[i] != "") {
			string& line = input[i];
			// convert line to a vector of ints. Y INDEX, X INDEX, RANGE.
			maps[mapIdx].push_back(strVecToInt(split(line, ' ')));
			i++;
			if (i == input.size()) break;
		}
		mapIdx++; // empty line therefore new map.
	}

	// Map: []	   = Map e.g fertiliser = 2
	//		[][]   = a set of mapping in that map 
	//		[][][] = each value of a map, stored in: Y INDEX, X INDEX, RANGE

	// X-to-Y map: 
	// Y INDEX | X INDEX | RANGE
	// e.g 
	// seed-to-soil map:
	// 50 98 2
	// seed 98, 99 --> soil 50, 51

	//	loop through all seeds
	//		loop through current map
	//			search X index + range boundary
	//			if seed is within index + range
	//				use Y index for next map.
	//			If Not in any mapping:
	//				use current seed value for next map

	//long it = 0;
	//while (seeds.size() > 0) {
	//	auto value = seeds[i];
	//	seeds.pop_back();
	//	mapIdx = 0;
	//	//cout << "Inital value: " << seed << endl;
	//	vector<pair<long long, long long>> newSeeds;
	//	while (mapIdx < 7) {
	//		for (auto mapping : maps[mapIdx]) {
	//			auto dest  = mapping[0];
	//			auto src   = mapping[1];
	//			auto range = mapping[2];
	//			
	//			auto overlapStart = max(value.first, src);
	//			auto overlapEnd = min(value.second, src + range);
	//			if (overlapStart < overlapEnd)
	//
	//			
	//		}
	//		//cout << "    New seed: " << value << endl;
	//		mapIdx++;
	//	}
	//	//if (value < smallestLocation)
	//	//	smallestLocation = value;
	//	//cout << "================================" << endl;
	//}

	for (auto map : maps) {
		vector<pair<long long, long long>> newSeeds;
		int idx = 0;
			
		while (seeds.size() > 0) {
			auto value = seeds[i];
			seeds.pop_back();
			for (auto line : map) {
				auto dest  = line[0];
				auto src   = line[1];
				auto range = line[2];
				
				auto os = max(value.first, src);		  // overlapStart
				auto oe = min(value.second, src + range); // overlapEnd
				if (os < oe) {
					newSeeds.emplace_back(os - src + dest, oe - src + dest);
					if (os > value.first)
						seeds.emplace_back(value.first, os);
					if (value.second > oe)
						seeds.emplace_back(oe, value.second);
					break;
				}
				else
					newSeeds.emplace_back(value);
			}
		}
		seeds = newSeeds;
	}
		
	// binary search FTW
	for (auto val : seeds)
		if (val.first < smallestLocation)
			smallestLocation = val.first;

	return smallestLocation;
}
*/