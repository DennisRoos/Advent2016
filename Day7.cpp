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

string s;
bool c;

struct xyx {
	char a;
	char b;
	xyx(char aa, char bb) : a(aa), b(bb) {}
};

vector<xyx> v;

bool abba(int n) {
	return ((s[n] == s[n + 3]) && (s[n + 1] == s[n + 2]) && (s[n] != s[n + 1]));
}

void aba(int n) {
	if ((s[n] == s[n + 2]) && (s[n] != s[n + 1])){
		xyx x(s[n],s[n + 1]);
		v.push_back(x);
	}
}

void bab(int n) {
	if ((s[n] == s[n + 2]) && (s[n] != s[n + 1])) {
		for (int i = 0; i < v.size(); i++) {
			if (s[n] == v[i].b && s[n + 1] == v[i].a) {
				c = true;
			}
		}
	}
}

int main(int argc, char * argv[]) {

	ifstream infile;
	infile.open("data.txt");
	if (infile.is_open())
	{
		int abbacount = 0;
		int abacount = 0;
		while (infile >> s) {
			bool hypernet = false;
			bool a = false;
			bool b = false;
			c = false;
			for (int i = 0; i < s.size() - 2; i++) {
				if (s[i] == '[') {
					hypernet = true;
				}
				else if (s[i] == ']') {
					hypernet = false;
				}
				else {
					if (hypernet == false) {
						aba(i);
					}
					if (i != s.size() - 3) {
						if (abba(i)) {
							if (hypernet == false) {
								a = true;
							}
							else {
								if (hypernet) {
									b = true;
								}
							}
						}
					}
				}

			}
			hypernet = false;
			for (int i = 0; i < s.size() - 2; i++) {
				if (s[i] == '[') {
					hypernet = true;
				}
				else if (s[i] == ']') {
					hypernet = false;
				}
				else {
					if (hypernet) {
						bab(i);
					}
				}
			
			}

			v.clear();
			if (a && !b) {
				abbacount++;
			}
			if (c) {
				abacount++;
			}

		}
		cout << "There were " << abbacount << " valid TLS IPs\n";
		cout << "There were " << abacount << " valid SSL IPs\n";
	}

}