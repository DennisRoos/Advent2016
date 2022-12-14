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

int A[50][6];

int main(int argc, char * argv[]) {
	
	regex re1("rect ([\\d]+)x([\\d]+)");
	regex re2("rotate column x=([\\d]+) by ([\\d]+)");
	regex re3("rotate row y=([\\d]+) by ([\\d]+)");
	string s;
	smatch match;
	ifstream f("data.txt");
	int k = 0;
	while (getline(f, s)) {
		k++;
		if (regex_search(s, match, re1) == true) {
			int x = stoi(match.str(1));
			int y = stoi(match.str(2));
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					A[i][j] = 1;
				}
			}

		}
		else if (regex_search(s, match, re2) == true) {
			int i = stoi(match.str(1));
			int offset = stoi(match.str(2));
			int B[6];
			for (int j = 0; j < 6; j++) {
				B[(j + offset) % 6] = A[i][j];
			}

			for (int j = 0; j < 6; j++) {
				A[i][j] = B[j];
			}

		}
		else if (regex_search(s, match, re3) == true) {
			int i = stoi(match.str(1));
			int offset = stoi(match.str(2));
			int B[50];
			for (int j = 0; j < 50; j++) {
				B[(j + offset) % 50] = A[j][i];
			}

			for (int j = 0; j < 50; j++) {
				A[j][i] = B[j];
			}
		}
	}
	int count = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 50; j++) {
			if (A[j][i] == 1) {
				cout << "#";
				count++;
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}

	cout << endl << "There were " << count << " cells turned on.\n";

	return 0;
}