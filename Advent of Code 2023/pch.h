#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <fstream>
#include <sstream>
#include <thread>
#include <filesystem>
#include <iomanip>
#include <vector>
#include <chrono>
#include <algorithm>
#include <queue>
#include <stack>
#include <concurrent_priority_queue.h>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <windows.h>
#include <numeric>
#include <ranges>

using namespace std;
using s64 = int64_t;
using u64 = uint64_t;

// this is gonna get really big lul
class Solutions {
public:
	Solutions() {};
	~Solutions() {};

	s64 strToInt(string str);
	string removeCharacters(const string& str, set<char> chars);
	void outputTxt(vector<string> output);
	vector<string> getInput(string problem);

	s64 d1_p1(vector<string> input);
	s64 d1_p2(vector<string> input);

	s64 d2_p1(vector<string> input);
	s64 d2_p2(vector<string> input);

	s64 d3_p1(vector<string> input);
	s64 d3_p2(vector<string> input);
	
	s64 d4_p1(vector<string> input);
	s64 d4_p2(vector<string> input);
	
	s64 d5_p1(vector<string> input);
	s64 d5_p2(vector<string> input);
	
	s64 d6_p1(vector<string> input);
	s64 d6_p2(vector<string> input);
	
	s64 d7_p1(vector<string> input);
	s64 d7_p2(vector<string> input);
	
	s64 d8_p1(vector<string> input);
	s64 d8_p2(vector<string> input);
	
	s64 d9_p1(vector<string> input);
	s64 d9_p2(vector<string> input);

	s64 d10_p1(vector<string> input);
	s64 d10_p2(vector<string> input);

	s64 d11_p1(vector<string> input);
	s64 d11_p2(vector<string> input);

	s64 d12_p1(vector<string> input);
	s64 d12_p2(vector<string> input);

	s64 d13_p1(vector<string> input);
	s64 d13_p2(vector<string> input);


private:
	std::vector<std::string> split(std::string s, std::string delimiter);
	std::vector<std::string> split(const std::string& s, char delim);
};

