#pragma once
#include "pch.h"
using namespace std;

int64_t Solutions::d8_p1(vector<string> input)
{

	string directions = removeCharacters(input[0], {' '});
	unordered_map<string, pair<string, string>> nodes;
	for (int i = 2; i < input.size(); i++) {	
		string str = removeCharacters(input[i], {' ', '(', ')'} );

		vector<string> splitStr = split(str, '=');
		string nodeName = splitStr[0];
		vector<string> elements = split(splitStr[1], ',');

		nodes.insert({ nodeName, {elements[0], elements[1]}});
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
				cout << "!! PROGRAM NO WORK !!" << endl;
				found = true;
				break;
			}

			//cout << curNode.c_str() << "->";

			if (c == 'L')
				curNode = nodes[curNode].first;
			else if (c == 'R')
				curNode = nodes[curNode].second;
			
			//cout << curNode.c_str() << endl;
			steps++;
		}
	}

	return steps;
}

// my baby brute force <3
int64_t Solutions::d8_p2(vector<string> input)
{
	string directions = removeCharacters(input[0], { ' ' });
	unordered_map<string, pair<string, string>> nodes;
	vector<string> startingNodes;
	for (int i = 2; i < input.size(); i++) {
		string str = removeCharacters(input[i], { ' ', '(', ')' });

		vector<string> splitStr = split(str, '=');
		string nodeName = splitStr[0];
		vector<string> elements = split(splitStr[1], ',');

		nodes.insert({ nodeName, {elements[0], elements[1]} });
		if (nodeName[2] == 'A')
			startingNodes.push_back(nodeName);
	}

	vector<int64_t> stepsToEnd;
	for (string& node : startingNodes) {
		cout << "Starting new Node: " << node;
		int64_t steps = 0;
		bool found = false;
		while (!found) {
			for (char c : directions) {
				if (node[2] == 'Z') {
					cout << "->" << node.c_str();
					found = true;
					break;
				}

				//cout << node.c_str() << "->";

				if (c == 'L')
					node = nodes[node].first;
				else if (c == 'R')
					node = nodes[node].second;

				//cout << node.c_str() << endl;

				++steps;
			}
		}
		cout << "->" << steps << endl;
		stepsToEnd.push_back(steps);
	}
	
	int64_t summation = stepsToEnd[0];
	for (int i = 1; i < stepsToEnd.size(); i++)
		summation = std::lcm(summation, stepsToEnd[i]);

	return summation;
}
