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


int possible;

void pos(int a, int b, int c) {
	if (a + b > c && b + c > a && a + c > b) {
		possible++;
	}
}

int main(int argc, char * argv[]) {

	ifstream infile;
	infile.open("data.txt");
	if (infile.is_open())
	{
		int a1;
		int b1;
		int c1;
		int a2;
		int b2;
		int c2;
		int a3;
		int b3;
		int c3;
		possible = 0;
		while (infile >> a1) {
			infile >> b1;
			infile >> c1;
			infile >> a2;
			infile >> b2;
			infile >> c2;
			infile >> a3;
			infile >> b3;
			infile >> c3;
			pos(a1, a2, a3);
			pos(b1, b2, b3);
			pos(c1, c2, c3);

		}
		cout << "there are " << possible << " possible triangles" << endl;
	}
	return 0;
}