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

struct range {
	long long a;
	long long b;
	range(long long aa, long long bb) : a(aa), b(bb) {}
};

vector<range> v;

struct less_than_angle
{
	inline bool operator() (const range& a1, const range& a2)
	{
		return (a1.a < a2.a);
	}
};

long long total;

void count() {
	long long n = 0;
	bool b = true;
	for (int i = 0; i < v.size(); i++) {
		if (n < v[i].a) {
			if (b) {
				cout << "First allowed value is " << n << endl;
				b = false;
			}
			total += (v[i].a - n);
			n = v[i].b + 1;
		}
		else if (n <= v[i].b) {
			n = v[i].b + 1;
		}
	}
}

int main(int argc, char * argv[]) {

	ifstream infile;
	infile.open("data.txt");
	if (infile.is_open())
	{
		long long a;
		long long b;
		while (infile >> a) {
			infile >> b;
			range r = range(a, b);
			v.push_back(r);
		}
	}
	sort(v.begin(), v.end(), less_than_angle());
	total = 0;
	count();
	cout << "Total allowed addresses is " << total << endl;
	return 0;
}