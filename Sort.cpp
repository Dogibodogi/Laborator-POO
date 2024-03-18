#include "Sort.h"
#include <iostream>
#include <ctime>
#include<stdarg.h>
#include <cstdlib>
#include <cstring>
#include <stdlib.h> 
#include <initializer_list>
Sort::Sort(int c, ...)
{
	vector = new int[c];
	count = c;
	va_list args;
	va_start(args, c);
	for (int i = 0; i < c; i++) {
		vector[i] = va_arg(args, int);
	}
	va_end(args);
}
Sort::Sort(int c, int min, int max)
{
	count = c;
	int i=0;
	vector = new int[c];
	while (c)
	{
		vector[i++] = rand()%(max-min+1)+min;
		c--;
	}
}
Sort::Sort(int vec[], int c)
{
	count = c;
	int i = 0;
	vector = new int[c];
	for (int i = 0; i < c; i++)
		vector[i] = vec[i];

}
Sort::Sort(char vec[], int c)
{
	int j = 0;
	int ii = 0;
	char* a = new char[strlen(vec)];
	vector = new int[c];
	for (int i = 0; i < strlen(vec); i++)
	{
		if (vec[i] != ',')
			a[j++] = vec[i];
		else if(vec[i]==',')
		{
			vector[ii++] = atoi(a);
			while (j)
			{
				a[j] = ' ';
				j--;
			}
			
		}
	}
	count = ii;
}
void Sort::InsertSort(bool ascendent)
{
	int i, key, j;
	for (i = 1; i < count; i++) {
		key = vector[i];
		j = i - 1;
		while (j >= 0 && vector[j] > key) {
			vector[j + 1] = vector[j];
			j = j - 1;
		}
		vector[j + 1] = key;
	}

}

void Sort::QuickSort(int st, int dr, bool ascendent) {
	if (st < dr)
	{

		int m = (st + dr) / 2;
		int aux = vector[st];
		vector[st] = vector[m];
		vector[m] = aux;
		int i = st, j = dr, d = 0;
		while (i < j)
		{
			if ((ascendent && vector[i] > vector[j]) || (!ascendent && vector[i] < vector[j]))
			{
				aux = vector[i];
				vector[i] = vector[j];
				vector[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		QuickSort(st, i - 1, ascendent);
		QuickSort(i + 1, dr, ascendent);
	}
}

void Sort::BubbleSort()
{
	bool sorted;
	do {
		sorted = true;
		for (int i = 1; i < count; i++)
			if (vector[i] > vector[i + 1]) {
				int aux = vector[i];
				vector[i] = vector[i + 1];
				vector[i + 1] = aux;
				sorted = false;
			}
	} while (!sorted);

}
void Sort:: Print()
{
	for (int i = 0; i < count; i++)
		std::cout << vector[i]<<' ';
	std::cout << std:: endl;
}
int Sort:: GetElementsCount()
{
	return count;
}
int Sort::GetElementFromIndex(int index)
{
	return vector[index];
}
Sort::~Sort()
{
	delete[] vector;
}
