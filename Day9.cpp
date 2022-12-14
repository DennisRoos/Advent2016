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

string d;
string c;

bool decompress() {
	bool b = false;
	int i = 0;
	while (i < d.size()) {
		if (d[i] == '(') {//marker
			b = true;
			int s = 0;
			i++;
			while (d[i] != 'x') {
				s = s * 10 + (d[i] - '0');
				i++;
			}
			i++;
			int t = 0;
			while (d[i] != ')') {
				t = t * 10 + (d[i] - '0');
				i++;
			}
			i++;
			string sub = d.substr(i, s);
			for (int j = 0; j < t; j++) {
				c.append(sub);
			}
			i += s;
		}
		else {
			c.push_back(d[i]);
			i++;
		}
	}
	return b;
}

int main(int argc, char * argv[]) {

	ifstream infile;
	infile.open("data.txt");
	if (infile.is_open())
	{
		infile >> d;
		decompress();

	}
	cout << "the initial decompressed length is " << c.size() << endl << endl;

	long long count = 0;
	vector<long long> v;
	for (int i = 0; i < d.size(); i++) {
		v.push_back(1);
	}


	int i = 0;
	while (i < d.size()) {
		if (d[i] == '(') {//marker
			int s = 0;
			i++;
			while (d[i] != 'x') {
				s = s * 10 + (d[i] - '0');
				i++;
			}
			i++;
			int t = 0;
			while (d[i] != ')') {
				t = t * 10 + (d[i] - '0');
				i++;
			}
			i++;
			int j = i;
			while (j < i + s) {
				if (d[j] == '(') {//skip other markers
					while (d[j] != ')') {
						j++;
					}
					j++;
				}
				else {//regular character
					v[j] *= t;
					j++;
				}
			}
		}
		else {
			count += v[i];
			i++;
		}
	}

	cout << "the final decompressed length is " << count << endl;
}