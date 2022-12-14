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


struct entry
{
	char c;
	int count;

	entry() : count(0) {}
};

struct less_than_angle
{
	inline bool operator() (const entry& a1, const entry& a2)
	{
		if (a1.count != a2.count) {
			return (a1.count > a2.count);
		}
		else return (a1.c < a2.c);
	}
};



int main(int argc, char * argv[]) {

	regex re("([a-z\-]+)([\\d]+)\\[([a-z]+)");
	string s;
	int total = 0;
	vector<entry> A;
	smatch match;
	ifstream f("data.txt");
	while (getline(f, s)) {
		if (regex_search(s, match, re) == true) {
			string name = match.str(1);
			int ID = stoi(match.str(2));
			string checksum = match.str(3);
			A.clear();
			for (int i = 0; i < 26; i++) {
				entry e = entry();
				e.c = i + 'a';
				A.push_back(e);
			}
			for (int i = 0; i < name.size(); i++) {
				char car = name[i];
				if (car != '-') {
					int j = car - 'a';
					A[j].count++;
				}
			}
			sort(A.begin(), A.end(),less_than_angle());
			bool b = true;
			for (int i = 0; i < 5; i++) {
				if (A[i].c != checksum[i]) {
					b = false;
				}
			}
			if (b) {
				total += ID;
			}


			for (int i = 0; i < name.size(); i++) {
				if (name[i] != '-') {
					name[i] = (((name[i] - 'a') + ID) % 26) + 'a';
				}
				else {
					name[i] = ' ';
				}
			}
			//cout << name << endl;
			if (name.compare("northpole object storage ") == 0) {//Found it!
				cout << "The objects are in room " << ID << endl;
			}

		}
	}
	cout << "Total is " << total << endl;
	return 0;
}