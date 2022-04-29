/*
CSCI 3333 93L
Jonathan Gonzalez
ID: [omitted]
Project 2 due 02/05/2021 @ 11:59 pm
After a thorough look into how the code runs, I've gathered that the given code returns the
biggest difference between two consecutive elements
Sources: https://www.cplusplus.com/reference/vector/vector/?kw=vector, https://www.cplusplus.com/reference/algorithm/		
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Implementing the given pseudocode using a vector
int someAlgo(vector<int> A) {
	int n = A.size();

	if (n < 2) {
		cout << "Invalid input" << endl;
		return 0;
	}

	int value = A[1] - A[0];
	int curMin = min(A[0], A[1]); // compares both and returns the smallest. If both are equal, returns A[0]

	for (int i = 2; i < n; i++) {
		if (A[i] - curMin > value)	// checks if there's a bigger difference
			value = A[i] - curMin;
		if (A[i] < curMin)			// checks if current element is smaller than curMin
			curMin = A[i];
	}

	return value;
}

int main()
{
	// Initialize different vectors to test the code

	vector<int> v1 = { 1 };								// Invalid input
	vector<int> v2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };	// maximum difference (10 - 1) = 9
	vector<int> v3 = { 2, 1, 6, 9, -2, 13, 5, 42, 5 };	// maximum difference (42 - (-2)) = 44
	vector<int> v4 = { 21, 12, 31, 10, 26, 4, 77, 12 }; // maximum difference (77 - 4) = 73
	vector<int> v5 = { 5, 2, 3, 4, 1 };					// maximum difference (4 - 2) = 2

	someAlgo(v1);
	cout << someAlgo(v2) << endl;
	cout << someAlgo(v3) << endl;
	cout << someAlgo(v4) << endl;
	cout << someAlgo(v5) << endl;
}