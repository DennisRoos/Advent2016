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
int longestdepth;
string longestpath;

void search(int x, int y, int depth, string s) {
	if (x == 3 && y == 3) {
		if (depth < shortestdepth) {
			shortestdepth = depth;
			shortestpath = s;
		}
		if (depth > longestdepth) {
			longestdepth = depth;
			longestpath = s;
		}
		return;
	}
	string hash = md5(s);
	//cout << s << " -> " << hash << endl;
	if (y > 0 && hash[0] >= 'b') {
		string u;
		u.assign(s);
		u.push_back('U');
		search(x, y - 1, depth + 1, u);
	}
	if (y < 3 && hash[1] >= 'b') {
		string d;
		d.assign(s);
		d.push_back('D');
		search(x, y + 1, depth + 1, d);
	}
	if (x > 0 && hash[2] >= 'b') {
		string l;
		l.assign(s);
		l.push_back('L');
		search(x - 1, y, depth + 1, l);
	}
	if (x < 3 && hash[3] >= 'b') {
		string r;
		r.assign(s);
		r.push_back('R');
		search(x + 1, y, depth + 1, r);
	}
	return;
}



int main(int argc, char * argv[]) {
	string passcode = "qtetzkpl";
	shortestdepth = 380;
	shortestpath = "No path found";
	longestdepth = 0;
	search(0, 0, 0, passcode);
	cout << "The shortest path was " << shortestpath << " with length " << shortestdepth << endl;
	cout << "The longest path was " << longestpath << " with length " << longestdepth << endl;


	return 0;
}