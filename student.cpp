#include "student.h"
#include <iostream>
void student::SetName(const char* y) {
	int i = 0;
	int j = 0;
	while (y[i] != '\0')
		i++;
	for (j = 0; j < i; j++)
		name[j] = y[j];
	name[j] = '\0';
}
void student::SetEnglishGrade(int x)
{
	EnglishGrade = x;
}
void student::SetHistoryGrade(int x)
{
	HistoryGrade = x;
}
void student::SetMathGrade(int x)
{
	MathGrade = x;
}
char *student::GetName()
{
	return name;
}
float student::GetMathGrade()
{
	return MathGrade;
}

float student::GetHistoryGrade()
{
	return HistoryGrade;
}
float student::GetEnglishGrade()
{
	return EnglishGrade;
}
float student::RetrieveAverageGrade()
{

	return (EnglishGrade + MathGrade + HistoryGrade) / 3.0;
}
