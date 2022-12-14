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

char A[43][180];
int D[43][180];
int KX[8];
int KY[8];
int Dist[8][8];
int shortestPath;
int current;
bool G[8];

void move(int x, int y, int d) {
	if (d >= D[x][y]) {
		return;
	}
	D[x][y] = d;
	move(x + 1, y, d + 1);
	move(x - 1, y, d + 1);
	move(x, y + 1, d + 1);
	move(x, y - 1, d + 1);
}

void find(int cur, int d, int amount) {
	if (amount == 7) {
		d += Dist[cur][0];
		if (d < shortestPath) {
			shortestPath = d;
			return;
		}
	}
	for (int i = 1; i < 8; i++) {
		if (G[i] == false){
			G[i] = true;
			find(i, d + Dist[cur][i], amount + 1);
			G[i] = false;
		}
	}
	return;
}

int main(int argc, char * argv[])
{


	ifstream infile;
	infile.open("data.txt");
	if (infile.is_open())
	{
		string s;
		int i = 0;
		while (infile >> s) {
			for(int j = 0; j < s.size(); j++){
				char c = s[j];
				A[i][j] = c;
				if (c <= '9' && c >= '0') {
					int k = c - '0';
					KX[k] = i;
					KY[k] = j;
					cout << c << ": " << i << "," << j << endl;
				}
			}
			i++;
		}


		bool b = true;
		while (b) {
			b = false;
			for (int j = 1; j < 179; j++) {//close all dead ends, including gates leading to dead ends
				for (int i = 1; i < 42; i++) {
					if (A[i][j] == '.') {
						int k = 0;
						if (A[i + 1][j] == '#') {
							k++;
						}
						if (A[i - 1][j] == '#') {
							k++;
						}
						if (A[i][j + 1] == '#') {
							k++;
						}
						if (A[i][j - 1] == '#') {
							k++;
						}

						if (k >= 3) {
							A[i][j] = '#';
							b = true;
						}
					}
				}
			}
		}

		cout << endl;
		for (int j = 0; j < 43; j++) {
			for (int i = 0; i < 180; i++) {
				cout << A[j][i];
			}
			cout << endl;
		}
		cout << endl;

		for (current = 0; current < 8; current++) {

			for (int j = 0; j < 43; j++) {
				for (int i = 0; i < 180; i++) {
					if (A[j][i] == '#') {
						D[j][i] = -1000;
					}
					else {
						D[j][i] = 9999999;
					}
				}
			}
			move(KX[current], KY[current], 0);
			for (int i = 0; i < 8; i++) {
				Dist[current][i] = D[KX[i]][KY[i]];
				cout << Dist[current][i] << " ";
			}
			cout << endl;
		}


		shortestPath = 99999999;
		for (int i = 0; i < 8; i++) {
			G[i] = false;
		}
		G[0] = true;
		find(0, 0, 0);

		cout << "The shortest path is " << shortestPath << endl;

	}
	else {
		cout << "can't find file?\n";
	}
	return 0;
}