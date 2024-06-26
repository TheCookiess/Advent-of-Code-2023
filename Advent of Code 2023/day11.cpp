#pragma once
#include "pch.h"

s64 solution(vector<string> grid, s64 spacing)
{
	auto getNumDotsInterval = [](vector<s64>& prefix_sum, s64 i, s64 j) -> s64 {
		if (i > j) swap(i, j);

		if (i == 0)
			return prefix_sum[j];
		else
			return prefix_sum[j] - prefix_sum[i - 1];
	};

	auto initPrefixSum = [](vector<s64>& arr, vector<s64>& prefix_sum) {
		prefix_sum[0] = arr[0];
		for (int i = 1; i < arr.size(); ++i) {
			prefix_sum[i] = prefix_sum[i - 1] + arr[i];
		}
	};

	vector<s64> all_dot_rows(grid.size());
	vector<s64> all_dot_cols(grid[0].size());

	for (int i = 0; i < grid.size(); ++i) {
		bool all_dot = grid[i].find_first_not_of('.') == string::npos;
		if (all_dot) {
			all_dot_rows[i] = 1;
		}
	}

	for (int c = 0; c < grid[0].size(); ++c) {
		bool all_dot = true;
		for (int r = 0; r < grid.size(); ++r) {
			if (grid[r][c] != '.') {
				all_dot = false;
				break;
			}
		}

		if (all_dot) {
			all_dot_cols[c] = 1;
		}
	}

	vector<s64> prefix_sum_rows(grid.size());
	vector<s64> prefix_sum_cols(grid[0].size());
	initPrefixSum(all_dot_rows, prefix_sum_rows);
	initPrefixSum(all_dot_cols, prefix_sum_cols);

	vector<pair<s64, s64>> galaxies;

	for (int r = 0; r < grid.size(); ++r)
		for (int c = 0; c < grid[r].size(); ++c)
			if (grid[r][c] == '#')
				galaxies.push_back({ r, c });

	u64 sum = 0;

	for (int i = 0; i < galaxies.size(); ++i) {

		int r1 = galaxies[i].first, c1 = galaxies[i].second;

		for (int j = i + 1; j < galaxies.size(); ++j) {
			int r2 = galaxies[j].first, c2 = galaxies[j].second;

			sum += abs(r1 - r2) + abs(c1 - c2);
			sum += getNumDotsInterval(prefix_sum_rows, r1, r2) * spacing;
			sum += getNumDotsInterval(prefix_sum_cols, c1, c2) * spacing;
		}
	}

	return sum;
}

s64 Solutions::d11_p1(vector<string> input) 
{
	return solution(input, 1);
}

s64 Solutions::d11_p2(vector<string> input)
{
	return solution(input, (1e6 - 1));
}						   
