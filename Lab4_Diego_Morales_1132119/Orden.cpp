#include "Orden.h"
#include<stdlib.h>
#include<time.h>

void Orden::Burbuja(int A[], int n) {
	int aux, i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n - 1; j++)
		{
			if (A[i] > A[j])
			{
				aux = A[i];
				A[i] = A[j];
				A[j] = aux;
			}
		}
	}
}
int Orden::divide(int* array, int start, int end) {
	int left, right, pivot, temp;

	pivot = array[start];
	left = start;
	right = end;

	while (left < right)
	{
		while (array[right] > pivot)
		{
			right--;
		}
		while ((left < right) && (array[left] <= pivot))
		{
			left++;
		}
		if (left < right)
		{
			temp = array[left];
			array[left] = array[right];
			array[right] = temp;
		}
	}
	temp = array[right];
	array[right] = array[start];
	array[start] = temp;
	return right;
}
void Orden::Quick(int* array, int start, int end) {
	int pivot;
	if (start < end)
	{
		pivot = divide(array, start, end);
		Quick(array, start, pivot - 1);
		Quick(array, pivot + 1, end);
	}
}
bool Orden::IsSorted(int* data, int count) {
	while (--count >= 1)
	{
		if (data[count] < data[count - 1])
		{
			return false;
		}
		else {
			return true;
		}
	}
}
void Orden::Shuffle(int* data, int count) {
	int temp, rnd;
	for (int i = 0; i < count; i++)
	{
		rnd = rand() % count;
		temp = data[i];
		data[i] = data[rnd];
		data[rnd] = temp;
	}
}
void Orden::Stupid(int* data, int count) {
	while (!IsSorted(data, count))
	{
		Shuffle(data, count);
	}
}