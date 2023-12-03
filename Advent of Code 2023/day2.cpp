#pragma once
#include "includes.h"
using namespace std;

int Solutions::d2_p1(vector<string> input)
{
	constexpr int red  = 12, green = 13, blue = 14;
	int summation = 0;
	
	/*for (string line : input) {
		constexpr int rLen = 3,  gLen  = 5,  bLen = 4;
		constexpr int firstNum = 8;
		int gameID = line[5] - '0';
		for (int i = firstNum; i < line.size() - 2; i++) {
			if (r > red || g > green || b > blue) { gameID = 0; break; } // invalid game
			char& c = line[i]; // c should always be a number.
		
			if (c == ';') // next set
				r = 0, g = 0, b = 0;

			switch (line[i + 2]) { // get colour of items pulled out.
			case 'r':
				r += c - '0';	   // ASCII --> int
				i += rLen + 2;	   // Index to char after colour name
				break;
			case 'g':
				g += c - '0';
				i += gLen + 2;
				break;
			case 'b':
				b += c - '0';
				i += bLen + 2;
				break;
			}
		}
		summation += gameID;
	}
	*/
	
	for (string line : input) {
		int gameID = strtol(split(split(line, ":")[0], " ")[1].c_str(), nullptr, 10); // absolute line of code
		auto sets = split(line, ": ");
		sets.erase(sets.begin());
		sets = split(sets[0], "; ");

		//cout << "GameID: " << gameID << endl;
		for (auto set : sets) {
			auto cubes = split(set, ", "); // e.g { 13 green, 14 blue }
			for (auto cube : cubes) { // cubes pulled out of the bag
				int r = 0, g = 0, b = 0; // reset as all previous cubes back in bag.
				auto items = split(cube, ' '); // e.g: { 13, green }
				
				if		(items[1] == "red")   r += strtol(items[0].c_str(), nullptr, 10);
				else if (items[1] == "green") g += strtol(items[0].c_str(), nullptr, 10);
				else if (items[1] == "blue")  b += strtol(items[0].c_str(), nullptr, 10);

				//for (auto item : items) cout << item << "|";
				//cout << " --> ";
				//cout << "r: " << r << "|";
				//cout << "g: " << g << "|";
				//cout << "b: " << b << "|" << endl;
				if (r > red || g > green || b > blue) { gameID = 0; break; }
			}
			if (gameID == 0) break; // break out of 2 loops.
		}
		summation += gameID;
		//cout << summation << endl;
		//for (int i = 0; i < 80; i++)
		//	cout << '=';
		//cout << endl;
	}
	return summation;
}

// that was relatively easy..
int Solutions::d2_p2(vector<string> input)
{
	int summation = 0;
	for (string line : input) {
		int gameID = strtol(split(split(line, ":")[0], " ")[1].c_str(), nullptr, 10); // absolute line of code
		auto sets = split(line, ": ");
		sets.erase(sets.begin());
		sets = split(sets[0], "; ");

		int maxR = 0, maxG = 0, maxB = 0;
		for (auto set : sets) {
			auto cubes = split(set, ", "); // e.g { 13 green, 14 blue }
			for (auto cube : cubes) { // cubes pulled out of the bag
				auto items = split(cube, ' '); // e.g: { 13, green }

				int amount = strtol(items[0].c_str(), nullptr, 10);
				if		(items[1] == "red"   && amount > maxR) maxR = amount;
				else if (items[1] == "green" && amount > maxG) maxG = amount;
				else if (items[1] == "blue"  && amount > maxB) maxB = amount;
			}
		}
		//std::cout << "Game " << gameID << ": " 
		//	<< maxR << " * " 
		//	<< maxG << " * " 
		//	<< maxB << " = "
		//	<< (maxR * maxG * maxB) << endl;
		summation += (maxR * maxG * maxB);
	}
	return summation;
}