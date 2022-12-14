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

string dragon(string a) {
	string b;
	for (int i = a.size() - 1; i >= 0; i--) {
		if (a[i] == '1') {
			b.push_back('0');
		}
		else {
			b.push_back('1');
		}
	}
	a.push_back('0');
	a.append(b);
	return a;
}

int main(int argc, char * argv[]) {
	string a = "01111010110010011";
	//int size = 272;
	int size = 35651584;
	while (a.size() < size) {
		a = dragon(a);
	}
	a = a.substr(0, size);
	string checksum;
	while (a.size() % 2 == 0) {
		for (int i = 0; i < a.size(); i = i + 2) {
			if (a[i] == a[i + 1]) {
				checksum.push_back('1');
			}
			else {
				checksum.push_back('0');
			}
		}
		a = checksum;
		checksum.clear();
	}
	cout << "The final checksum is " << a << endl;
	return 0;
}