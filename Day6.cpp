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

vector<string> v;

int main(int argc, char * argv[]) {

	ifstream infile;
	infile.open("data.txt");
	if (infile.is_open())
	{
		string s;
		string first;
		string second;
		while (infile >> s) {
			v.push_back(s);
		}
		int size = s.size();
		int A[26];
		for (int i = 0; i < size; i++) {
			for (int k = 0; k < 26; k++) {
				A[k] = 0;
			}
			for (int j = 0; j < v.size(); j++) {
				string str = v[j];
				char c = str[i];
				int a = c - 'a';
				A[a]++;
			}
			int largest = 0;
			int smallest = 9999;
			int index2 = 0;
			int index1 = 0;
			for (int k = 0; k < 26; k++) {
				if (A[k] > largest) {
					index1 = k;
					largest = A[k];
				}
				if (A[k] < smallest) {
					index2 = k;
					smallest = A[k];
				}
			}
			char c = index1 + 'a';
			first.push_back(c);
			c = index2 + 'a';
			second.push_back(c);

		}
		cout << "first password is: " << first << endl;
		cout << "second password is: " << second << endl;
	}

}