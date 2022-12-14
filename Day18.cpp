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

int A[400000][102];


int main(int argc, char * argv[]) {

	ifstream infile;
	infile.open("data.txt");
	if (infile.is_open())
	{

		int safe = 0;

		for (int row = 0; row < 400000; row++) {
			for (int i = 0; i <= 101; i++) {
				A[row][i] = 0;
			}
		}
		string s;
		infile >> s;
		for (int i = 0; i < 100; i++) {
			if (s[i] == '^') {
				A[0][i + 1] = -999;
			}
			else { 
				safe++; 
			}
		}

		for (int row = 1; row < 400000; row++) {
			for (int i = 1; i <= 100; i++) {
				int left = A[row - 1][i - 1];
				int right = A[row - 1][i + 1];
				if (left != right) {
					A[row][i] = -999;
				}
				else {
					safe++;
				}
			}
		}


		cout << "There are " << safe << " safe tiles." << endl;
	}

}