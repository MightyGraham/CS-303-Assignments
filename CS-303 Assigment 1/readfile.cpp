
#include <iostream>
#include <fstream>
#include "A1input.h"
using namespace std;

bool findInteger(const int arr[], int size, int target, int& index) { 
    for (int i = 0; i < size; ++i) { 
        if (arr[i] == target) {
            index = i;
            return true;
        }
    }
    return false;
}

bool modifyValue(int arr[], int index, int newValue, int& oldValue) {
    if (index >= 0 && index < MAX_SIZE) {
        oldValue = arr[index];
        arr[index] = newValue;
        return true;
    }
    return false;
}

bool addInteger(int arr[], int& size, int value) {
    if (size >= MAX_SIZE) return false;
    arr[size++] = value;
    return true;
}

bool removeAtIndex(int arr[], int& size, int index) {
    if (index < 0 || index >= size) return false;
    for (int i = index; i < size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --size;
    return true;
}