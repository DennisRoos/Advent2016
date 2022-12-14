#include <iostream>
#include <fstream>
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <regex>

#include <cmath>

using namespace std;

struct bot {
	int card;
	bool lowbot;
	int lowtarget;
	bool highbot;
	int hightarget;
	bot() : lowbot(true), lowtarget(0), highbot(true), hightarget(0), card(0) {}
};


vector<bot> bots;
int output[200];

void give(int n, int value) {
	if (bots[n].card == 0) {
		bots[n].card = value;
		return;
	}
	else {
		int low;
		int high;
		if (bots[n].card < value) {
			low = bots[n].card;
			high = value;
		}
		else {
			high = bots[n].card;
			low = value;
		}
		//check for part 1
		if (low == 17 && high == 61) {
			cout << "The bot comparing 17 and 61 is bot " << n << endl;
		}


		bots[n].card = 0;
		if (bots[n].lowbot) {
			give(bots[n].lowtarget, low);
		}
		else {
			output[bots[n].lowtarget] = low;
		}

		if (bots[n].highbot) {
			give(bots[n].hightarget, high);
		}
		else {
			output[bots[n].hightarget] = high;
		}
	}
}

int main(int argc, char * argv[]) {

	for (int i = 0; i < 250; i++) {
		bot newbot = bot();
		bots.push_back(newbot);
	}

	regex re1("value ([\\d]+) goes to bot ([\\d]+)");
	regex re2("bot ([\\d]+) gives low to (bot|output) ([\\d]+) and high to (bot|output) ([\\d]+)");
	string s;
	smatch match;
	ifstream f("data.txt");
	int k = 0;
	int initbot;
	int initval;
	while (getline(f, s)) {
		k++;
		if (regex_search(s, match, re1) == true) {
			int v = stoi(match.str(1));
			int b = stoi(match.str(2));
			if (bots[b].card == 0) {
				bots[b].card = v;
			}
			else {
				initbot = b;
				initval = v;
			}
		}
		else if (regex_search(s, match, re2) == true) {
			int b = stoi(match.str(1));
			bool l;
			bool h;
			if (match.str(2).compare("bot") == 0) {
				l = true;
			}
			else {
				l = false;
			}
			int lt = stoi(match.str(3));

			if (match.str(4).compare("bot") == 0) {
				h = true;
			}
			else {
				h = false;
			}
			int ht = stoi(match.str(5));
			bots[b].highbot = h;
			bots[b].hightarget = ht;
			bots[b].lowbot = l;
			bots[b].lowtarget = lt;
		}
	}
	give(initbot, initval);
	cout << "the product is " << output[0] * output[1] * output[2] << endl;

	return 0;
}