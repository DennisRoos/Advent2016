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


int main(int argc, char * argv[]) {
	string ID = "ffykfhsq";
	int index = 0;
	string password = "________";
	int reps = 0;
	while (reps < 8) {
		string indexs = to_string(index);
		string s;
		s.assign(ID);
		s = s.append(indexs);
		string hash = md5(s);
		//cout << s << " -> " << hash << endl;
		bool b = true;
		for (int i = 0; i < 5; i++) {
			if (hash[i] != '0') {
				b = false;
			}
		}
		if (b) {
			int intval = (hash[5] >= 'a') ? (hash[5] - 'a' + 10) : (hash[5] - '0');
			if (intval < 8) {
				if (password[intval] == '_') {
					cout << password << endl;
					cout << "Found one at index " << index << ": " << hash[5] << " " << hash[6] << endl;
					password[intval] = hash[6];
					cout << password << endl << endl;
					reps++;
				}
			}
		}
		index++;
	}

	cout << "the password is " << password << endl;

	return 0;
}