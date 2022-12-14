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
	int reg;//for inc, dec, also target of cpy
	bool reg1;//whether reg1 for cpy, jnz, is a register or value
	int source;//cpy, jnz source
	int offset;//jnz offset
	instruction(int o) :op(o){}
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

		regs[2] = 1;

		while (infile >> s) {
			int op;
			if (s.compare("cpy") == 0) {
				op = 0;
				infile >> s2;
				instruction ins = instruction(op);
				if (s2[0] >= 'a') {
					i2 = s2[0] - 'a';
					ins.reg1 = true;
				}
				else {
					ins.reg1 = false;
					i2 = stoi(s2);
				}
				ins.source = i2;
				infile >> s3;
				i3 = s3[0] - 'a';
				ins.reg = i3;
				prog.push_back(ins);
			}
			else if (s.compare("inc") == 0) {
				op = 1;
				infile >> s2;
				instruction ins = instruction(op);
				i2 = s2[0] - 'a';
				ins.reg = i2;
				prog.push_back(ins);
			}
			else if (s.compare("dec") == 0) {
				op = 2;
				infile >> s2;
				instruction ins = instruction(op);
				i2 = s2[0] - 'a';
				ins.reg = i2;
				prog.push_back(ins);
			}
			else if (s.compare("jnz") == 0) {
				op = 3;
				infile >> s2;
				instruction ins = instruction(op);
				if (s2[0] >= 'a') {
					i2 = s2[0] - 'a';
					ins.reg1 = true;
				}
				else {
					ins.reg1 = false;
					i2 = stoi(s2);
				}
				ins.source = i2;
				infile >> i3;
				ins.offset = i3;
				prog.push_back(ins);
			}
		}
		int size = prog.size();
		while (ic < size) {
			if (prog[ic].op == 0){
				if (prog[ic].reg1) {
					regs[prog[ic].reg] = regs[prog[ic].source];
				}
				else {
					regs[prog[ic].reg] = prog[ic].source;
				}
				ic++;
			}
			else if (prog[ic].op == 1) {
				regs[prog[ic].reg]++;
				ic++;
			}
			else if (prog[ic].op == 2) {
				regs[prog[ic].reg]--;
				ic++;
			}
			else if (prog[ic].op == 3) {
				int value;
				if (prog[ic].reg1) {
					value = regs[prog[ic].source];
				}
				else {
					value = prog[ic].source;
				}
				if (value != 0) {
					ic += prog[ic].offset;
				}
				else {
					ic++;
				}
			}
		}
		cout << "The result is " << regs[0] << endl;

	}
	else {
		cout << "can't find file?\n";
	}
	return 0;
}