#pragma once
#include "includes.h"
using namespace std;

// FPS Diagnostics
void Solutions::updateFrameTiming(float period)
{
	static unsigned int frames = 0;
	frames++;
	static auto start = std::chrono::steady_clock::now();
	auto end = std::chrono::steady_clock::now();

	auto seconds = std::chrono::duration< float >(end - start).count();
	if (seconds >= period)
	{
		std::cout
			<< std::setprecision(1) << std::fixed << frames / seconds << " FPS ("
			<< frames << " frames in "
			<< std::setprecision(1) << std::fixed << seconds << " seconds = "
			<< std::setprecision(3) << std::fixed << seconds / frames * 1000.0 << " ms/frame)\n";
		frames = 0;
		start = end;
	}
}

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