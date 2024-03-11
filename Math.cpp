#include "Math.h"
#include <cstdarg>
#include <cstdlib>
int Math::Add(int a, int b)
{
	return a + b;
}
int Math::Add(int a, int b, int c)
{
	return a + b + c;
}
int Math::Add(double a, double b)
{
	return a + b;
}
int Math::Add(double a, double b, double c)
{
	return a + b + c;

}
int Math::Mul(int a, int b)
{
	return a * b;
}
int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}
int Math::Mul(double a, double b)
{
	return a * b;
}
int Math::Mul(double a, double b, double c)
{
	return a * b * c;

}
char* Math::Add(const char* a, const char* b)
{
	if (a == nullptr or b == nullptr)
		return nullptr;
	int i = 0;
	int x = atoi(a);
	int y = atoi(b);
	y = y + x;
	x = y;
	while (x)
	{
		x = x / 10;
		i++;
	}
	char* p = new char[i+2];
	_itoa(y, p, 10);
	return p;
}
int Math::Add(int count, ...)
{
	int val = 0;
	va_list ap;
	int i;

	va_start(ap, count);
	for (i = 0; i < count; i++) {
		val += va_arg(ap, int);
	}
	va_end(ap);

	return val;
}
