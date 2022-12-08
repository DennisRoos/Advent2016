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

int main(int argc, char * argv[]) {

	ifstream infile;
	infile.open("data.txt");
	if (infile.is_open())
	{
		string s;
		int row = 2;
		int col = 0;
		while (infile >> s) {
			for (int i = 0; i < s.size(); i++) {
				bool b = false;
				char c = s[i];
				if (c == 'U') {
					row--;
				}
				else if (c == 'L') {
					col--;
				}
				else if (c == 'R') {
					col++;
				}
				else if (c == 'D') {
					row++;
				}

				if (row < 0 || row > 4 || col < 0 || col > 4) {
					b = true;
				}
				if ((row == 0 && col != 2) ||
					(row == 4 && col != 2) ||
					(row != 2 && col == 0) ||
					(row != 2 && col == 4)
					) {
					b = true;
				}

				if (b) {
					if (c == 'D') {
						row--;
					}
					else if (c == 'R') {
						col--;
					}
					else if (c == 'L') {
						col++;
					}
					else if (c == 'U') {
						row++;
					}
				}
			}
			if (row == 0) {
				cout << '1';
			}
			else if (row == 1) {
				cout << col + 1;
			}
			else if (row == 2) {
				cout << col + 5;
			}
			else if (row == 3) {
				if (col == 1) {
					cout << "A";
				}
				else if (col == 2) {
					cout << "B";
				}
				else {
					cout << "C";
				}
			}
			else {
				cout << "D";
			}

		}
		cout << endl;
	}
	return 0;
}