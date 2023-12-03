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
class Solutions {
public:
	Solutions();
	~Solutions();

	void updateFrameTiming(float period);
	void outputTxt(vector<string> output);
	vector<string> getInput(string problem);

	int d1_p1(vector<string> input);
	int d1_p2(vector<string> input);
	
	int d2_p1(vector<string> input);
	int d2_p2(vector<string> input);
};

