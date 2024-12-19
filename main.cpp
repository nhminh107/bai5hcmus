#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;

struct Bill {
	int code; 
	char name[50];
	int quantity;
	int unit;
	int total; 
};
void PartB(Bill* array[], int n, ostream &os) {
	int maxcode = -1; 
	int maxprice = -1;
	int demcode = 0; 
	int demgia = 0; 
	for (int i = 0; i < n; i++) {
		if (array[i]->code > maxcode) 
			maxcode = array[i]->code;
			demcode++; 
		if (array[i]->total > maxprice)
			maxprice = array[i]->total; 
			demgia++; 
	}
	for (int i = 0; i < n; i++) {
		if (demgia > 1) {
			if (array[i]->code == maxcode && array[i]->total == maxprice) {
				os << array[i]->code << "-" << array[i]->name << endl; 
			}
		}
	}
}
int main() {
	ifstream FIn("input.txt"); 
	ofstream FOut("output.txt"); 
	Bill* array[10]; 
	int n = 0;
	for (int i = 0; i < 10; i++) {
		array[i] = new Bill();  
	}
	char* temp = new char[100];
	while (FIn.getline(temp, 100)) {
		char* tempcpy = new char[strlen(temp) + 1];
		strcpy(tempcpy, temp); 
		char* token = strtok(tempcpy, "-");
		if (token != nullptr) array[n]->code = atoi(token); 
		 token = strtok(NULL, "-"); 
		if (token != NULL) strcpy(array[n]->name, token); 
		token = strtok(NULL, "-");
		if (token != NULL) array[n]->quantity = atoi(token);
		token = strtok(NULL, "-");
		if (token != NULL) array[n]->unit = atoi(token);
		token = strtok(NULL, "-");
		if (token != NULL) array[n]->total = atoi(token); 
		n++; 
	}
	PartB(array, n, FOut); 
}
