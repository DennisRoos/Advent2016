#include <iostream>
#include <fstream>
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <regex>
#include <algorithm>    // std::next_permutation, std::sort


#include <cmath>

using namespace std;

string code;

void rotateLeft(int d) {
	int n = code.size();
	reverse(code.begin(), code.begin() + d);
	reverse(code.begin() + d, code.end());
	reverse(code.begin(), code.end());
	return;
}

void rotateRight(int d)
{
	rotateLeft(code.size() - d);
}

void scrambleline(string s) {

	regex re1("swap position (\\d) with position (\\d)");
	regex re2("swap letter ([a-z]) with letter ([a-z])");
	regex re3("rotate left (\\d) steps?");
	regex re4("rotate right (\\d) steps?");
	regex re5("rotate based on position of letter ([a-z])");
	regex re6("reverse positions ([\\d]) through ([\\d])");
	regex re7("move position (\\d) to position (\\d)");
	smatch match;
	if (regex_search(s, match, re1) == true) {//swap position
		int x = stoi(match.str(1));
		int y = stoi(match.str(2));
		char t = code[x];
		code[x] = code[y];
		code[y] = t;
	}
	else if (regex_search(s, match, re2) == true) {//swap letter
		char x = match.str(1)[0];
		char y = match.str(2)[0];
		for (int i = 0; i < code.size(); i++) {
			if (code[i] == x) {
				code[i] = y;
			}
			else if (code[i] == y) {
				code[i] = x;
			}
		}
	}
	else if (regex_search(s, match, re3) == true) {//rotate left
		int x = stoi(match.str(1));
		rotateLeft(x);
	}
	else if (regex_search(s, match, re4) == true) {//rotate right
		int x = stoi(match.str(1));
		rotateRight(x);
	}

	else if (regex_search(s, match, re5) == true) {//rotate letter
		char x = match.str(1)[0];
		int index;
		for (int i = 0; i < code.size(); i++) {
			if (code[i] == x) {
				index = i;
			}
		}
		if (index >= 4) {
			index++;
		}
		index = index % code.size();
		rotateRight(index + 1);
	}
	else if (regex_search(s, match, re6) == true) {//reverse position
		int x = stoi(match.str(1));
		int y = stoi(match.str(2));
		reverse(code.begin() + x, code.begin() + y + 1);
	}
	else if (regex_search(s, match, re7) == true) {//move position
		int x = stoi(match.str(1));
		int y = stoi(match.str(2));

		char c = code[x];
		code.erase(code.begin() + x);
		code.insert(y, 1, c);
	}
}

int rot[8];

void unscramble(string s) {

	regex re1("swap position (\\d) with position (\\d)");
	regex re2("swap letter ([a-z]) with letter ([a-z])");
	regex re3("rotate left (\\d) steps?");
	regex re4("rotate right (\\d) steps?");
	regex re5("rotate based on position of letter ([a-z])");
	regex re6("reverse positions ([\\d]) through ([\\d])");
	regex re7("move position (\\d) to position (\\d)");
	smatch match;
	if (regex_search(s, match, re1) == true) {//swap position
		int x = stoi(match.str(1));
		int y = stoi(match.str(2));
		char t = code[x];
		code[x] = code[y];
		code[y] = t;
	}
	else if (regex_search(s, match, re2) == true) {//swap letter
		char x = match.str(1)[0];
		char y = match.str(2)[0];
		for (int i = 0; i < code.size(); i++) {
			if (code[i] == x) {
				code[i] = y;
			}
			else if (code[i] == y) {
				code[i] = x;
			}
		}
	}
	else if (regex_search(s, match, re3) == true) {//rotate left
		int x = stoi(match.str(1));
		rotateRight(x);
	}
	else if (regex_search(s, match, re4) == true) {//rotate right
		int x = stoi(match.str(1));
		rotateLeft(x);
	}

	else if (regex_search(s, match, re5) == true) {//rotate letter
		char x = match.str(1)[0];
		int index;
		for (int i = 0; i < code.size(); i++) {
			if (code[i] == x) {
				index = i;
			}
		}
		int old = rot[index];
		rotateLeft(old);
	}
	else if (regex_search(s, match, re6) == true) {//reverse position
		int x = stoi(match.str(1));
		int y = stoi(match.str(2));
		reverse(code.begin() + x, code.begin() + y + 1);
	}
	else if (regex_search(s, match, re7) == true) {//move position
		int x = stoi(match.str(1));
		int y = stoi(match.str(2));

		char c = code[y];
		code.erase(code.begin() + y);
		code.insert(x, 1, c);
	}
}


vector<string> v;

int main(int argc, char * argv[]) {

	string s;
	ifstream f("data.txt");
	rot[0] = 1;
	rot[1] = 1;
	rot[2] = 6;
	rot[3] = 2;
	rot[4] = 7;
	rot[5] = 3;
	rot[6] = 0;
	rot[7] = 4;



	code = "abcdefgh";

	while (getline(f, s)) {
		v.push_back(s);
		scrambleline(s);
	}

	cout << "Result of scrambling abcdefgh is " << code << endl;

	code.assign("fbgdceah");
	for (int i = v.size() - 1; i >= 0; i--) {
		unscramble(v[i]);
	}


	cout << "The original password was " << code << endl;

	return 0;
}