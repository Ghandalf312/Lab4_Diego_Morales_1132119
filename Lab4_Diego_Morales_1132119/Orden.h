#pragma once
//#include <iostream>
//#include <string>
//using namespace std;
class Orden
{
public:
	void Burbuja(int* A[], int n);

	int divide(int* array, int start, int end);
	void Quick(int* array, int start, int end);

	bool IsSorted(int* data, int count);
	void Shuffle(int* data, int count);
	void Stupid(int* data, int count);
};

