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
	int x, y;
	char c;
	vector<Direction> con;
	bool checked;
	Node(int X, int Y, char C) {
		x = X;
		y = Y;
		c = C;
		con = {};
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
	 /*{'.', {}}*/      };

	
	auto getIdx = [&input](int x, int y) -> int 
	{ return (y + x) * input[y].size(); };

	auto ooB = [&input](int x, int y) -> bool 
	{ return (x > input.size() || x < 0 || y > input[y].size() || y < 0); };

	auto isInQueue = [](int x, int y, vector<Node>& queue) -> bool {
		for (Node n : queue) if (n.x == x && n.y == y) return false;
		return true;
	};

	auto 

	auto getOppDirection = [](Direction d) -> Direction {
		switch (d) {
		case NORTH: return SOUTH;
		case EAST: return WEST;
		case SOUTH: return NORTH;
		case WEST: return EAST;
		}
	};

	auto checkDirection = [&](int x, int y, Direction d) -> bool {
		switch (d) {
		case NORTH: y--; break;
		case EAST:  x++; break;
		case SOUTH: y++; break;
		case WEST:  x--; break;
		}

		if (ooB(x, y)) return false;					// if is in bounds
		if (!umap.contains(input[y][x])) return false;	// if is a letter
		for (Direction dir : umap[input[y][x]])			// checks if pipe connects to node we're checking from.
			if (dir == getOppDirection(d))
				return true;
		return false;
	};

	//auto updateNodeConnections = [&](Node& n) -> vector<Direction> {
	//	if (checkDirection(n.x, n.y, NORTH)) n.con.push_back(NORTH);
	//	if (checkDirection(n.x, n.y, EAST )) n.con.push_back(EAST );
	//	if (checkDirection(n.x, n.y, SOUTH)) n.con.push_back(SOUTH);
	//	if (checkDirection(n.x, n.y, WEST )) n.con.push_back(WEST );
	//};

	int startIdx = -1;
	for (int i = 0; i < input.size(); i++)
		for (int j = 0; j < input[i].size(); j++) {
			nodes.emplace_back(j, i, input[i][j]);
			if (input[i][j] == 'S')
				startIdx = getIdx(j, i);
		}
	if (startIdx == -1) return 0; // no start. is fucked.

	/* this is fucking useless...
	* Step 1: Start with node S and enqueue it to the queue.
	* Step 2: Repeat the following steps for all the nodes in the graph.	
	* Step 3: Dequeue S and process it.
	* Step 4: Enqueue all the adjacent nodes of S and process them.
	* [END OF LOOP]
	* Step 6: EXIT
	*/

	vector<Node> queue; queue.push_back(nodes[startIdx]);
	while (!queue.empty()) {
		Node n = queue[0]; // get item at front of queue

		if (checkDirection(n.x, n.y, NORTH))
			if (!isInQueue(n.x, n.y + 1, queue))
				queue.push_back(nodes[getIdx(n.x, n.y + 1)]);
		if (checkDirection(n.x, n.y, EAST))
			if (!isInQueue(n.x + 1, n.y, queue))
				queue.push_back(nodes[getIdx(n.x + 1, n.y + 1)]);
		if (checkDirection(n.x, n.y, NORTH))
			if (!isInQueue(n.x, n.y + 1, queue))
				queue.push_back(nodes[getIdx(n.x, n.y + 1)]);
		if (checkDirection(n.x, n.y, NORTH))
			if (!isInQueue(n.x, n.y + 1, queue))
				queue.push_back(nodes[getIdx(n.x, n.y + 1)]);

	}
		 


	return 0;
}

int64_t Solutions::d10_p2(vector<string> input)
{
	return 0;
}