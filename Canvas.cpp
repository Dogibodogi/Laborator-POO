#include "Canvas.h"
#include <cmath>
#include <iostream>
using namespace std;
Canvas:: Canvas(int a, int b)
{
	height = b;
	width = a;
	canvas = new char* [height];
	for (unsigned i = 0; i < height; i++) {
		canvas[i] = new char[width];
	}
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
			canvas[i][j] = ' ';
	}
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	int aux = 0, aux2=0, aux3=0;
	for (int i = y - ray; i <= y + ray; i++)
		for (int j = x - ray; j <= x + ray; j++)
			if (pow(j - x, 2) + pow(i - y, 2) <= pow(ray, 2) && i >= 0 && j >= 0 && i < height && j < width)
				canvas[i][j] = ch;
	for (int i = y - ray+1; i < y + ray; i++)
	{
		for (int j = x - ray; j <= x + ray; j++)
		{
			if (canvas[i][j] == ch and aux==0)
			{
				aux++;
				aux2++;
				continue;
			}
			if (aux > 0 and canvas[i][j]==ch and j!= x + ray)
			{
				canvas[i][j] = ' ';
			}
			else
			if (canvas[i][j] == ' ' and aux2 > 0 and aux3==0)
			{
				canvas[i][j - 1] = ch;
				aux3 = 1;
			}
	
		}
		aux = 0;
		aux2 = 0;
		aux3 = 0;
	}


}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = y - ray; i <= y + ray; i++)
		for (int j = x - ray; j <= x + ray; j++)
			if (pow(j - x, 2) + pow(i - y, 2) <= pow(ray, 2) && i >= 0 && j >= 0 && i < height && j < width)
				canvas[i][j] = ch;

}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++)
	{
		canvas[i][top] = ch;
		canvas[i][bottom] = ch;
	}
	for (int j = top; j <= bottom; j++)
	{
		canvas[left][j] = ch;
		canvas[right][j] = ch;
	}
		

}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++)
		for (int j = top; j <= bottom; j++)
			canvas[j][i] = ch;
}
void Canvas::SetPoint(int x, int y, char ch)
{
	canvas[x][y] = ch;
}
void Canvas::DrawLine(int x0, int y0, int x1, int y1, char ch) {


	int dx = abs(x1 - x0);
	int sx = x0 < x1 ? 1 : -1;
	int dy = -abs(y1 - y0);
	int sy = y0 < y1 ? 1 : -1;
	int error = dx + dy;

	while (true)
	{
		SetPoint(x0, y0, ch);
		if (x0 == x1 && y0 == y1) break;
		int e2 = 2 * error;
		if (e2 >= dy)
			if (x0 == x1) break;
		{error = error + dy;
		x0 = x0 + sx;
		}
		if (e2 <= dx)
			if (y0 == y1) break;
		{error = error + dx;
		y0 = y0 + sy;
		}
	}
}
void Canvas::Print()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			cout << canvas[i][j];
		}
		cout << endl;
	}
}
void Canvas::Clear()
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			canvas[i][j] = ' ';
		}
	}

}
Canvas::~Canvas() {
	for (unsigned i = 0; i < height; ++i) {
		delete[] canvas[i];
	}

	delete[] canvas;
}