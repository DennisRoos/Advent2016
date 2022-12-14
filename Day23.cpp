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

int regs[4];
int ic;

struct instruction {
	int op;
	int v1;
	int v2;
	bool b1;//true if it's a register, not an immediate
	bool b2;
	bool valid;
	instruction(int o) :op(o), valid(true) {}
};

vector<instruction> prog;

int main(int argc, char * argv[])
{
	ic = 0;
	ifstream infile;
	infile.open("data.txt");
	if (infile.is_open())
	{

		string s;
		string s2;
		string s3;
		int i2;
		int i3;

		regs[0] = 12;

		while (infile >> s) {
			int op;
			if (s.compare("cpy") == 0) {
				op = 0;
				infile >> s2;
				instruction ins = instruction(op);
				if (s2[0] >= 'a') {
					i2 = s2[0] - 'a';
					ins.b1 = true;
				}
				else {
					ins.b1 = false;
					i2 = stoi(s2);
				}
				ins.v1 = i2;
				infile >> s3;
				i3 = s3[0] - 'a';
				ins.v2 = i3;
				ins.b2 = true;
				prog.push_back(ins);
			}
			else if (s.compare("inc") == 0) {
				op = 1;
				infile >> s2;
				instruction ins = instruction(op);
				i2 = s2[0] - 'a';
				ins.v1 = i2;
				ins.b1 = true;
				prog.push_back(ins);
			}
			else if (s.compare("dec") == 0) {
				op = 2;
				infile >> s2;
				instruction ins = instruction(op);
				i2 = s2[0] - 'a';
				ins.v1 = i2;
				ins.b1 = true;
				prog.push_back(ins);
			}
			else if (s.compare("jnz") == 0) {
				op = 3;
				infile >> s2;
				instruction ins = instruction(op);
				if (s2[0] >= 'a') {
					i2 = s2[0] - 'a';
					ins.b1 = true;
				}
				else {
					ins.b1 = false;
					i2 = stoi(s2);
				}
				infile >> s3;
				if (s3[0] >= 'a') {
					i3 = s3[0] - 'a';
					ins.b2 = true;
				}
				else {
					ins.b2 = false;
					i3 = stoi(s3);
				}
				ins.v1 = i2;
				ins.v2 = i3;
				prog.push_back(ins);
			}
			else if (s.compare("tgl") == 0) {
				op = 4;
				infile >> s2;
				instruction ins = instruction(op);
				if (s2[0] >= 'a') {
					i2 = s2[0] - 'a';
					ins.b1 = true;
				}
				else {
					ins.b1 = false;
					i2 = stoi(s2);
				}
				ins.v1 = i2;
				prog.push_back(ins);
			}
		}
		cout << "reading in program done." << endl;
		int size = prog.size();
		while (ic < size) {
			if (prog[ic].valid) {
				if (prog[ic].op == 0) {
					if (prog[ic].b1) {//cpy
						regs[prog[ic].v2] = regs[prog[ic].v1];
					}
					else {
						regs[prog[ic].v2] = prog[ic].v1;
					}
					ic++;
				}
				else if (prog[ic].op == 1) {//inc
					regs[prog[ic].v1]++;
					ic++;
				}
				else if (prog[ic].op == 2) {//dec
					regs[prog[ic].v1]--;
					ic++;
				}
				else if (prog[ic].op == 3) {//jnz
					int value;
					if (prog[ic].b1) {
						value = regs[prog[ic].v1];
					}
					else {
						value = prog[ic].v1;
					}
					if (value != 0) {
						int offset;
						if (prog[ic].b2) {
							offset = regs[prog[ic].v2];
						}
						else {
							offset = prog[ic].v2;
						}
						ic += offset;
					}
					else {
						ic++;
					}
				}
				else if (prog[ic].op == 4) {//tgl
					int value;
					if (prog[ic].b1) {
						value = regs[prog[ic].v1];
					}
					else {
						value = prog[ic].v1;
					}
					int pointer = ic + value;
					if (pointer >= 0 && pointer < size) {
						cout << "toggled instruction " << pointer << " from " << prog[pointer].op;
						if (prog[pointer].op == 1) {//increment
							prog[pointer].op = 2;
						}
						else if (prog[pointer].op == 2) {//decrement
							prog[pointer].op = 1;
						}
						else if (prog[pointer].op == 4) {//toggle
							prog[pointer].op = 1;
							if (prog[pointer].b1 == false) {
								prog[pointer].valid = false;
							}
						}
						else if (prog[pointer].op == 0) {//copy
							prog[pointer].op = 3;
							prog[pointer].valid = true;
						}
						else if (prog[pointer].op == 3) {//copy
							prog[pointer].op = 0;
							if (prog[pointer].b2 == false) {
								prog[pointer].valid = false;
							}
						}
						cout << " to " << prog[pointer].op << endl;
					}
					ic++;
				}
			}
			else {
				ic++;
			}
		}
		cout << "The result is " << regs[0] << endl;

	}
	else {
		cout << "can't find file?\n";
	}
	return 0;
}