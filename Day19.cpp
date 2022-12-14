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

struct elf {
	int ID;
	elf* left;
	elf(int i) : ID(i), left(NULL){}

};

int main(int argc, char * argv[]) {
	int count = 3014603;
	elf* first = new elf(1);
	elf* last = first;
	for (int i = 2; i <= count; i++) {
		elf* next = new elf(i);
		last->left = next;
		last = next;
	}
	last->left = first;
	elf*current = first;

	//for part 1
	/*for (int i = 0; i < count - 1; i++) {
		elf* t = current->left->left;
		delete current->left;
		current->left = t;
		current = current->left;
	}*/

	//part 2
	elf* o = current;//o is the opposite to current
	int c = count / 2;
	for (int i = 0; i < c - 1; i++) {
		o = o->left;
	}
	while (count > 1) {
		int c = count / 2;
		elf* temp = o->left;
		o->left = temp->left;
		if (count % 2 == 1) {
			o = o->left;
		}
		delete temp;
		current = current->left;
		count--;
	}


	std::cout << current->ID << std::endl;
	return 0;
}