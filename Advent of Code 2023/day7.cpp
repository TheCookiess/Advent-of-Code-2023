#pragma once
#include "pch.h"

enum Rank_Order {
	HIGH_CARD,
	ONE_PAIR,  
	TWO_PAIR,  
	THREE_OFAK,
	FULL_HOUSE,
	FOUR_OFAK, 
	FIVE_OFAK, 
};

struct hand {
	int bet;
	string cards;
	Rank_Order order;
	hand(int BET, string CARDS, Rank_Order ORDER) {
		cards = CARDS;
		bet = BET;
		order = ORDER;
	}
	hand() = default;
};

auto cardRank = [](char c) -> int {
	switch (c) {
	case 'A': return 14;
	case 'K': return 13;
	case 'Q': return 12;
	case 'J': return 11;
	case 'T': return 10;
	default: return c - '0'; // c >= '0' && c <= '9'
	}
};

auto getSetRank = [](int largest, bool fH, bool twoPair) -> Rank_Order {
	if (largest == 5) return FIVE_OFAK;
	if (largest == 4) return FOUR_OFAK;
	if (fH)			  return FULL_HOUSE;
	if (largest == 3) return THREE_OFAK;
	if (twoPair)	  return TWO_PAIR;
	if (largest == 2) return ONE_PAIR;
	return HIGH_CARD;
};

auto rankToStr = [](Rank_Order rank) -> string {
	switch (rank) {
	case FIVE_OFAK: return "Five of a Kind";
	case FOUR_OFAK: return "Four of a Kind";
	case FULL_HOUSE: return "Full House";
	case THREE_OFAK: return "Three of a Kind";
	case TWO_PAIR: return "Two Pair";
	case ONE_PAIR: return "One Pair";
	default: return "High Card";
	}
};


s64 Solutions::d7_p1(vector<string> input)
{
	auto cardRank = [](char c) -> int {
		switch (c) {
		case 'A': return 14;
		case 'K': return 13;
		case 'Q': return 12;
		case 'J': return 11;
		case 'T': return 10;
		default: return c - '0'; // c >= '0' && c <= '9'
		}
	};

	vector<vector<hand>> rankedHands(7);
	for (auto line : input) {
		auto str = split(line, ' ');
		
		// N of a kind Check.
		int largest = 0;
		bool fullHouse = false, pseudo = false, twoPair = false;
		unordered_map<char, int> umap;
		for (char c : str[0])
			umap[c]++;
		for (auto it : umap) {
			if (it.second > largest) 
				largest = it.second;
			if (it.second == 2 && pseudo) twoPair = true;
			else if (it.second == 2) pseudo = true;
		}
		// Full House Check
		if (umap.size() == 2 && largest == 3) 
			fullHouse = true;

		auto rank = getSetRank(largest, fullHouse, twoPair);
		rankedHands[rank].emplace_back(strToInt(str[1]), str[0], rank);
	}

	// cheeky little lambda statement for comparison
	// for each array of hands of the same rank, sort them.
	int size = 0;
	for (int i = 0; i < rankedHands.size(); i++) {
		sort(rankedHands[i].begin(), rankedHands[i].end(),
			[cardRank](const auto& lhs, const auto& rhs) {
				for (int j = 0; j < lhs.cards.size(); j++)
				if (lhs.cards[j] != rhs.cards[j])
					return cardRank(lhs.cards[j]) < cardRank(rhs.cards[j]);
				return false;
			});
		size += rankedHands[i].size();
	}

	int idx = 0;
	long long summation = 0;
	for (int i = 0; i < rankedHands.size(); i++)
		for (int j = 0; j < rankedHands[i].size(); j++) {
			idx++;
			summation += (idx * rankedHands[i][j].bet);
			//cout << "Rank: " << (idx) << " | "
			//	<< "Tier: " << rankedHands[i][j].order << " | "
			//	<< "Hand: " << rankedHands[i][j].cards << " | "
			//	<< "Bet: " << rankedHands[i][j].bet << " | "
			//	<< "Add: " << (idx * rankedHands[i][j].bet) << " | "
			//	//	<< "Summation: " << summation << " | "
			//	<< endl;
		}

	return summation;
}

// J == Joker, not Jack.
// don't work, idk
s64 Solutions::d7_p2(vector<string> input)
{
	auto cardRank = [](char c) -> int {
		switch (c) {
		case 'A': return 14;
		case 'K': return 13;
		case 'Q': return 12;
		case 'J': return -1;
		case 'T': return 10;
		default: return c - '0'; // c >= '0' && c <= '9'
		}
	};

	auto addJokers = [](Rank_Order rank, int jokers) -> Rank_Order {
		if (jokers == 0) return rank;
		rank = (Rank_Order)clamp(rank + jokers, 0, 5);
		if (rank == 4) rank == 5;
		return rank;
	};

	vector<vector<hand>> rankedHands(7);
	for (auto line : input) {
		vector<string> str = split(line, ' ');

		// N of a kind Check.
		int largest = 0;
		bool fullHouse = false, pseudo = false, twoPair = false;
		unordered_map<char, int> umap;
		for (char c : str[0]) {
			umap[c]++;
		}
		for (auto it : umap) {
			if (it.second > largest)
				largest = it.second;
			if (it.second == 2 && pseudo) twoPair = true;
			else if (it.second == 2) pseudo = true;
		}
		// Full House Check
		if (umap.size() == 2 && largest == 3)
			fullHouse = true;

		Rank_Order rank = getSetRank(largest, fullHouse, twoPair);
		rank = addJokers(rank, umap['J']);
		rankedHands[rank].emplace_back(strToInt(str[1]), str[0], rank);
	}

	// cheeky little lambda statement for comparison
// for each array of hands of the same rank, sort them.
	int size = 0;
	for (int i = 0; i < rankedHands.size(); i++) {
		sort(rankedHands[i].begin(), rankedHands[i].end(),
			[cardRank](const auto& lhs, const auto& rhs) {
				for (int j = 0; j < lhs.cards.size(); j++)
				if (lhs.cards[j] != rhs.cards[j])
					return cardRank(lhs.cards[j]) < cardRank(rhs.cards[j]);
				return false;
			});
		size += rankedHands[i].size();
	}

	long long summation = 0, idx = 0;
	for (int i = 0; i < rankedHands.size(); i++)
		for (int j = 0; j < rankedHands[i].size(); j++) {
			idx++;
			summation += (idx * rankedHands[i][j].bet);
			cout << "Rank: " << (idx) << " | "
				<< "Tier: " << rankedHands[i][j].order << " | "
				<< "Hand: " << rankedHands[i][j].cards << " | "
				<< "Bet: " << rankedHands[i][j].bet << " | "
				<< "Add: " << (idx * rankedHands[i][j].bet) << " | "
				//	<< "Summation: " << summation << " | "
				<< endl;
		}

	return summation;
}
