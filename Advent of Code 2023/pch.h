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

// this is gonna get really big lul
class Solutions {
public:
	Solutions();
	~Solutions();

	int64_t strToInt(string str);
	string removeCharacters(const string& str, set<char> chars);
	void outputTxt(vector<string> output);
	vector<string> getInput(string problem);

	int64_t d1_p1(vector<string> input);
	int64_t d1_p2(vector<string> input);

	int64_t d2_p1(vector<string> input);
	int64_t d2_p2(vector<string> input);

	int64_t d3_p1(vector<string> input);
	int64_t d3_p2(vector<string> input);
	
	int64_t d4_p1(vector<string> input);
	int64_t d4_p2(vector<string> input);
	
	int64_t d5_p1(vector<string> input);
	int64_t d5_p2(vector<string> input);
	
	int64_t d6_p1(vector<string> input);
	int64_t d6_p2(vector<string> input);
	
	int64_t d7_p1(vector<string> input);
	int64_t d7_p2(vector<string> input);
	
	int64_t d8_p1(vector<string> input);
	int64_t d8_p2(vector<string> input);
	
	int64_t d9_p1(vector<string> input);
	int64_t d9_p2(vector<string> input);

	int64_t d10_p1(vector<string> input);
	int64_t d10_p2(vector<string> input);

	int64_t d11_p1(vector<string> input);
	int64_t d11_p2(vector<string> input);

	int64_t d12_p1(vector<string> input);
	int64_t d12_p2(vector<string> input);

	int64_t d13_p1(vector<string> input);
	int64_t d13_p2(vector<string> input);


private:
	std::vector<std::string> split(std::string s, std::string delimiter);
	std::vector<std::string> split(const std::string& s, char delim);
};

