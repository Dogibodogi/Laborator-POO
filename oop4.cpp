#include <iostream>
#include <cstring>
#include "Sort.h"
int main()
{
	/*int a[5] = { 1,2,4,3,5 };
	Sort lista(a, 5);
	lista.InsertSort();
	lista.Print();*/
	char b[101] = "10,11,13,12,";
	Sort lista2(b, strlen(b));
	lista2.BubbleSort();
	lista2.Print();
	Sort lista3(15, 1, 10);
	lista3.InsertSort();
	lista3.Print();

}
