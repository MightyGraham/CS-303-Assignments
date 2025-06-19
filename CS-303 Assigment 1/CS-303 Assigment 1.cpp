// CS-303 Assigment 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <stdexcept> //error handling
#include "A1input.h"
using namespace std;

int main() {
	int array[MAX_SIZE];
	int size = 0;

	ifstream arrayfile("A1input.txt"); //ifstream = input file, ofstream = output file
	if (!arrayfile) {
		cerr << "Unable to open file" << endl;
		return 1;
	}
	while (arrayfile >> array[size]) {
		size++;
		if (size >= MAX_SIZE) break;
	}
	arrayfile.close();

	cout << "a total of " << size << " integers found in file.\n" << endl;
	
	try {

		int index;
		cout << "locating number 89..."; 
		if (findInteger(array, size, 89, index)) {
			cout << "\nthe number 89 was found at index " << index << "!\n" << endl;
		}
		else {
			throw runtime_error("unable to find number 89.");
		}

		/*cout << "locating number 777...\n";
		if (findInteger(array, size, 777, index)) {
			cout << "\nthe number 777 was found at index " << index << "!\n" << endl;
		}
		else {
			throw runtime_error("unable to find number 777.");
		}*/

		int oldVal;
		cout << "modifying value at index 12...\n";
		if (modifyValue(array, 12, 999, oldVal)) {
			cout << "at index 12, " << oldVal << " is now " << array[12] << "\n" << endl;
		}
		else {
			throw out_of_range("Index is out of range");
		}

		/*cout << "modifying value at index 101...\n";
		if (modifyValue(array, 101, 999, oldVal)) {
			cout << "index 101: " << oldVal << " is now " << array[101] << endl;
		}
		else {
			throw out_of_range("Index is out of range");
		}*/

		cout << "let's remove a value...\n";
		if (removeAtIndex(array, size, 47)) {
			cout << "removed value at index 47. New array size is: " << size << "\n" << endl;
		}
		else {
			throw out_of_range("Invalid index.");
		}
		
		cout << "let's add 101 to the end of the array...\n";
		if (addInteger(array, size, 101)) {
			cout << "added 101 at end; New array size is: " << size << "\n" << endl;
		}
		else {
			throw overflow_error("Array is full. Cannot add more integers.");
		} //when you add an integer before removing, overflow_error occurs because the size is full
		

	}
	catch (exception &e) {
		cerr << "Exception: " << e.what() << endl; //where error message displays
    }
	return 0;

}

