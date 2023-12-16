#pragma once
#include "pch.h"
using namespace std;

int Solutions::d8_p1(vector<string> input)
{

	string directions = input[0];
	removeCharacters(directions, {' '});
	unordered_map<string, pair<string, string>> nodes;
	for (int i = 2; i < input.size(); i++) {	
		string& str = input[i];
		removeCharacters(str, {' ', '(', ')'} );

		vector<string> splitStr = split(str, '=');
		string nodeName = splitStr[0];
		vector<string> elements = split(splitStr[1], ',');
		nodes.insert({ split(str, '=')[0], {elements[0], elements[1]}});
	}

	string wantedNode = "ZZZ";
	string curNode = "AAA";//split(input[2], '=')[0];
	bool found = false;
	long steps = 0;
	while (!found) {
		for (char c : directions) {	
			if (curNode == wantedNode) {
				found = true;
				break;
			}
			if (curNode == "") {
				cout << curNode;
				found = true; 
				break;
				//throw curNode;
			}

			//cout << curNode.c_str() << "->";

			if (c == 'L')
				curNode = nodes[curNode].first;
			else if (c == 'R')
				curNode = nodes[curNode].second;
			else
				cout << "this program aint working.. " << steps << endl;
			
			//cout << curNode.c_str() << endl;
			steps++;
		}
		cout << "Looped through all directions | steps: " << steps << endl;
	}

	return steps;
}

int Solutions::d8_p2(vector<string> input)
{
	return 0;
}