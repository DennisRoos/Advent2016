#include <iostream>
#include <fstream>
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <regex>

#include <cmath>
#include "MD5.h"

using namespace std;

int shortestdepth;
string shortestpath;

void search(int x, int y, int depth, string s) {
	if (x == 3 && y == 3) {
		if (depth < shortestdepth) {
			shortestdepth = depth;
			shortestpath = s;
		}
		return;
	}
	if (depth >= shortestdepth) {
		return;
	}
	string hash = md5(s);
	if (y > 1 && hash[0] > 'b') {
		string u = s.assign;
		u.push_back("U");
		search(x, y - 1, depth + 1, u);
	}
	if (y < 3 && hash[1] > 'b') {
		string d = s.assign;
		u.push_back("D");
		search(x, y + 1, depth + 1, d);
	}
	if (x > 1 && hash[2] > 'b') {
		string l = s.assign;
		u.push_back("L");
		search(x - 1, y, depth + 1, l);
	}
	if (x < 3 && hash[3] > 'b') {
		string r = s.assign;
		u.push_back("R");
		search(x + 1, y, depth + 1, r);
	}
	return;
}



int main(int argc, char * argv[]) {
	string passcode = "ihgpwlah";
	shortestdepth = 10;
	shortestpath = "No path found";
	search(0, 0, 0, passcode);
	cout << "The shortest path was " << shortestpath << " with length " << shortestdepth << endl;


	return 0;
}