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

int A[100][100];

void wall(int x, int y) {
	int t = x*x + 3 * x + 2 * x*y + y + y*y;
	t += 1358;
	int count = 0;
	while (t > 0) {
		if (t % 2 == 1) {
			count++;
		}
		t = t / 2;
	}
	if (count % 2 == 1) {
		A[x][y] = -999;
	}
	else {
		A[x][y] = 99999;
	}
}

void find(int x, int y, int d) {
	if (x < 0 || x == 100 || y < 0 || y == 100) {
		return;
	}

	if (d >= A[x][y]) {
		return;
	}
	else {
		A[x][y] = d;
		find(x + 1, y, d + 1);
		find(x - 1, y, d + 1);
		find(x, y + 1, d + 1);
		find(x, y - 1, d + 1);
	}
}




int main(int argc, char * argv[]) {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			wall(i, j);
		}
	}

	find(1, 1, 0);
	cout << "The shortest path is " << A[31][39] << endl;
	
	int count = 0;
	for (int j = 0; j < 100; j++) {
		for (int i = 0; i < 100; i++) {
			if (A[i][j] != -999 && A[i][j] <= 50) {
				count++;
			}
		}
	}


	cout << count << " locations can be reached in 50 steps." << endl;

	return 0;
}