#pragma once
#include "includes.h"
using namespace std;

void Solutions::outputTxt(vector<string> output)
{
	if (remove("../Resources/output.txt") != 0)
		throw runtime_error("output.txt couldn't be cleansed");
	cout << "Output cleansed\n";

	fstream file("../Resources/output.txt");
	if (!file.is_open())
		throw runtime_error("File not found!");

	for (auto line : output)
		file << line << endl;

	file.close();
}

vector<string> Solutions::getInput(string problem)
{
	fstream input("../Resources/" + problem + "/input.txt");
	if (!input.is_open())
		throw runtime_error("File not found!");

	string line;
	vector<string> lines;
	while (getline(input, line))
		lines.push_back(line);
	input.close();
	return lines;
}

std::vector<std::string> Solutions::split(std::string s, std::string delimiter) {
	size_t pos_start = 0, pos_end, delim_len = delimiter.length();
	std::string token;
	std::vector<std::string> res;

	while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
		token = s.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}

	res.push_back(s.substr(pos_start));
	return res;
}

std::vector<std::string> Solutions::split(const std::string& s, char delim) {
	std::vector<std::string> result;
	std::stringstream ss(s);
	std::string item;

	while (getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}