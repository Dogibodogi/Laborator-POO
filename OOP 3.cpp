#include <iostream>
#include <cmath>
#include "Canvas.h"
#include "Math.h"
using namespace std;
int main()
{
	int a = 2;
	int b = 3;
	int c = 4;
	double x = 6.3;
	double y = 3.8;
	Math A;
	cout << A.Mul(x, y) << endl;
	cout << A.Add(5, 1, 2, 3, 4, 5) << endl;
	cout << A.Add(x, y) << endl;
	cout << A.Add("5", "7") << endl;
	cout << A.Add(a, b, c) << endl;
	cout << A.Add(a, b) << endl;
	cout << A.Mul(a, b) << endl;
	cout << A.Mul(a, b, c) << endl;
	cout << endl;
	Canvas B(50, 50);
	B.FillCircle(25, 25, 10, '@');

	B.Print();
	return 0;
}

