#include <iostream>
#include <fstream>
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <regex>
#include <cmath>
#include <iterator>         // std::(istream_iterator, back_inserter)
#include <sstream>          // std::(istringstream)
#include <list>

using namespace std;

struct layer {
	int p;
	int c;
	layer(int pp, int cc) : c(cc), p(pp) {}
};

vector<layer> v;

int s;

void attempt(int i) {
	for (int j = 0; j < s; j++) {
		if ((v[j].c + i) % v[j].p != 0) {
			return;
		}
	}
	cout << "The first second we can succeed is " << i << endl;
	exit(0);
}


int main(int argc, char * argv[])
{
	ifstream infile;
	infile.open("data.txt");
	if (infile.is_open())
	{
		int p;
		int c;
		int i = 1;
		while (infile >> p) {
			infile >> c;
			c += i;
			layer ll = layer(p, c);
			v.push_back(ll);
			i++;
		}
		layer l2 = layer(11, 7);
		v.push_back(l2); //this line can be commented out to get part 1
		s = v.size();
		i = 0;
		while (true) {
			attempt(i);
			i++;
		}
	}
	else {
		cout << "can't find file?\n";
	}
	return 0;
}