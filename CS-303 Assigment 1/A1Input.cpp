
#include <iostream>
#include <fstream>
#include "A1input.h"
using namespace std;

//function for looking for specific integer, target, in the array
//if found, returns true. otherwise false
bool findInteger(const int arr[], int size, int target, int& index) { 
    for (int i = 0; i < size; ++i) { 
        if (arr[i] == target) {
            index = i;
            return true;
        }
    }
    return false;
}

//changes a value at an index in the array
bool modifyValue(int arr[], int index, int newValue, int& oldValue) {
    if (index >= 0 && index < MAX_SIZE) {
        oldValue = arr[index];
        arr[index] = newValue;
        return true;
    }
    return false;
}

//adds an integer to the array IF the current size is not at its max size
bool addInteger(int arr[], int& size, int value) {
    if (size >= MAX_SIZE) return false;
    arr[size++] = value;
    return true;
}

//removes an integer from some index of an array IF the index is found 
bool removeAtIndex(int arr[], int& size, int index) {
    if (index < 0 || index >= size) return false;
    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --size; 
    return true;
}