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

int Size[39][25];
int Used[39][25];
int Avail[39][25];
char grid[39][25];

bool viable(int Ax, int Ay, int Bx, int By) {
	if (Ax == Bx && Ay == By) {
		return false;
	}
	if (Used[Ax][Ay] != 0 && Used[Ax][Ay] <= Avail[Bx][By]) {
		return true;
	}
	else {
		return false;
	}
}

int main(int argc, char * argv[]) {

	regex re("\/dev\/grid\/node-x([\\d]+)-y([\\d]+)[ ]+([\\d]+)T[ ]+([\\d]+)T[ ]+([\\d]+)T[ ]+([\\d]+)%");
	string s;
	smatch match;
	ifstream f("data.txt");
	while (getline(f, s)) {
		if (regex_search(s, match, re) == true) {
			int x = stoi(match.str(1));
			int y = stoi(match.str(2));
			int size = stoi(match.str(3));
			int used = stoi(match.str(4));
			int avail = stoi(match.str(5));

			Size[x][y] = size;
			Used[x][y] = used;
			Avail[x][y] = avail;
			if (used > 100) {
				grid[x][y] = '#';
				cout << "wall at " << x << "," << y << endl;
			}
			else if (size < 80) {
				grid[x][y] = 'T';
			}
			else if (used >= 80) {
				grid[x][y] = 'B';
			}
			else if (avail > 60) {
				grid[x][y] = '_';
				cout << "free node at " << x << "," << y << endl;
			}
			else {
				grid[x][y] = '.';
			}
		}
	}
	int count = 0;
	for (int ax = 0; ax < 39; ax++) {
		for (int ay = 0; ay < 25; ay++) {
			for (int bx = 0; bx < 39; bx++) {
				for (int by = 0; by < 25; by++) {
					if (viable(ax, ay, bx, by)) {
						count++;
					}
				}
			}
		}
	}
	cout << endl << "There were " << count << " viable node pairs." << endl << endl;

	for (int y = 0; y < 25; y++) {
		for (int x = 0; x < 39; x++) {
			cout << grid[x][y];
		}
		cout << endl;
	}


	return 0;
}