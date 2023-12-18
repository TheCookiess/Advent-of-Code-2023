#pragma once
#include "pch.h"
using namespace std;

enum Direction {
	NORTH,
	EAST,
	SOUTH,
	WEST
};

struct Node {
	int x, y, dist;
	char c;
	vector<Direction> con;
	bool checked;
	Node(int X, int Y, char C, vector<Direction> CON) {
		x = X;
		y = Y;
		c = C;
		con = CON;
		dist = 0;
		checked = false;
	}
	Node() = default;
};


int64_t Solutions::d10_p1(vector<string> input) 
{
	vector<Node> nodes;
	unordered_map<char, vector<Direction>> umap =
	{{'|', {NORTH,SOUTH}},
	 {'-', {EAST ,WEST} },
	 {'L', {NORTH,EAST} }, 
	 {'J', {NORTH,WEST} }, 
	 {'7', {SOUTH,WEST} }, 
	 {'F', {SOUTH,EAST} }, 
	 {'S', {NORTH,SOUTH,EAST,WEST}},
	 /*{'.', {}}*/      };

	
	auto getIdx = [&input](int x, int y) -> int 
	{ return (y * input[y].size()) + x; };

	auto ooB = [&input](int x, int y) -> bool 
	{ return (x > input.size() || x < 0 || y > input[y].size() || y < 0); };

	auto isInGraph = [](int x, int y, vector<Node>& graph) -> bool {
		for (Node n : graph) if (n.x == x && n.y == y) return true;
		return false;
	};

	auto getOppDirection = [](Direction d) -> Direction {
		switch (d) {
		case NORTH: return SOUTH;
		case EAST: return WEST;
		case SOUTH: return NORTH;
		case WEST: return EAST;
		}
	};

	auto checkDirection = [&](int x, int y, Direction d) -> bool {
		//switch (d) {
		//case NORTH: y--; break;
		//case EAST:  x++; break;
		//case SOUTH: y++; break;
		//case WEST:  x--; break;
		//}

		if (ooB(x, y)) return false;					// if is in bounds
		if (!umap.contains(input[y][x])) return false;	// if is a letter
		for (Direction dir : umap[input[y][x]])			// checks if pipe connects to node we're checking from.
			if (dir == getOppDirection(d))
				return true;
		return false;
	};

	auto traverseNode = [&](int x, int y, Direction d,vector<Node>& graph, Node&  srcNode) -> void {
		Node& n = nodes[getIdx(x, y)];
		if (checkDirection(n.x, n.y, d))
			if (!nodes[getIdx(n.x, n.y)].checked) {
				n.checked = true;
				n.dist = srcNode.dist + 1;
				graph.push_back(nodes[getIdx(n.x, n.y)]);

				//cout << "Valid Node: "
				//	<< n.c
				//	<< " (" << n.x << "," << n.y << ") "
				//	<< endl;
			}
	};

	int startIdx = -1;
	for (int i = 0; i < input.size(); i++)
		for (int j = 0; j < input[i].size(); j++) {
			nodes.emplace_back(j, i, input[i][j], umap[input[i][j]]);
			if (input[i][j] == 'S')
				startIdx = getIdx(j, i);
		}
	if (startIdx == -1) return 0; // no start. is fucked.

	vector<Node> graph; graph.push_back(nodes[startIdx]);
	int front = 0;
	while (graph.size() > front) {
		Node n = graph[front]; // get item at front of graph "queue"
		//cout << "Processing: "
		//	<< n.c
		//	<< " (" << n.x << "," << n.y << ") "
		//	<< endl;

		for (Direction d : n.con) {
			switch (d) {
			case NORTH: traverseNode(n.x, n.y - 1, NORTH, graph, n); break;
			case SOUTH: traverseNode(n.x, n.y + 1, SOUTH, graph, n); break;
			case EAST:  traverseNode(n.x + 1, n.y, EAST , graph, n); break;
			case WEST:  traverseNode(n.x - 1, n.y, WEST , graph, n); break;
			}
		}

		//cout << endl;
		front++;
	}

	//int y = 0;
	//for (Node& n : nodes) {
	//	if (n.y != y) {
	//		y++; cout << endl;
	//	}
	//	if (isInGraph(n.x, n.y, graph))
	//		cout << n.dist;
	//	else
	//		cout << '.';
	//}
	//cout << endl;
		 
	int64_t largest = 0;
	for (Node n : graph)
		if (n.dist > largest) largest = n.dist;

	return largest;
}

int64_t Solutions::d10_p2(vector<string> input)
{
	return 0;
}