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
		int A[500][500];
		int i;
		string s;
		int d = 0;
		int x = 250;
		int y = 250;
		A[250][250] = 1;
		bool b = true;
		while (infile >> s) {
			infile >> i;
			if (s.compare("R") == 0) {
				d = (d + 1) % 4;
			}
			else {
				d--;
				if (d < 0) {
					d = 3;
				}
			}

			if (d == 0) {
				for (int j = 0; j < i; j++) {
					y--;
					if (A[x][y] == 1 && b) {
						cout << "Location visited twice, at distance " << abs(x - 250) + abs(y - 250) << endl;
						b = false;
					}
					A[x][y] = 1;
				}
			}
			else if (d == 1) {
				for (int j = 0; j < i; j++) {
					x++;
					if (A[x][y] == 1 && b) {
						cout << "Location visited twice, at distance " << abs(x - 250) + abs(y - 250) << endl;
						b = false;
					}
					A[x][y] = 1;
				}
			}
			else if (d == 2) {
				for (int j = 0; j < i; j++) {
					y++;
					if (A[x][y] == 1 && b) {
						cout << "Location visited twice, at distance " << abs(x - 250) + abs(y - 250) << endl;
						b = false;
					}
					A[x][y] = 1;
				}
			}
			else if (d == 3) {
				for (int j = 0; j < i; j++) {
					x--;
					if (A[x][y] == 1 && b) {
						cout << "Location visited twice, at distance " << abs(x - 250) + abs(y - 250) << endl;
						b = false;
					}
					A[x][y] = 1;
				}
			}
		}

		cout << "Final Distance is " << abs(x -250) + abs(y -250) << endl;
	}
	return 0;
}