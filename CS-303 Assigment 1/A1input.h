#pragma once

#include <iostream>
#include <fstream>
using namespace std;
const int MAX_SIZE = 100;

bool findInteger(const int arr[], int size, int target, int& index);
bool modifyValue(int arr[], int index, int newValue, int& oldValue);
bool addInteger(int arr[], int& size, int value);
bool removeAtIndex(int arr[], int& size, int index);