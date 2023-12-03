#pragma once

#include <iostream>
#include <string>
#include <string_view>
#include <fstream>
#include <sstream>
#include <thread>
#include <iomanip>
#include <vector>
#include <chrono>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// this is gonna get really big lul
class Solutions {
public:
	Solutions();
	~Solutions();

	void outputTxt(vector<string> output);
	vector<string> getInput(string problem);

	int d1_p1(vector<string> input);
	int d1_p2(vector<string> input);
	
	int d2_p1(vector<string> input);
	int d2_p2(vector<string> input);

	int d3_p1(vector<string> input);
	int d3_p2(vector<string> input);

	int d4_p1(vector<string> input);
	int d4_p2(vector<string> input);

	int d5_p1(vector<string> input);
	int d5_p2(vector<string> input);

private:
	std::vector<std::string> split(std::string s, std::string delimiter);
	std::vector<std::string> split(const std::string& s, char delim);
};

