#include <cstring>
#pragma once
class student
{
private:
	char name[101];
	float MathGrade;
	float HistoryGrade;
	float EnglishGrade;
public:
	void SetName(const char *name);
	void SetMathGrade(int x);
	void SetHistoryGrade(int x);
	void SetEnglishGrade(int x);
	char *GetName();
	float GetMathGrade();
	float GetHistoryGrade();
	float GetEnglishGrade();
	float RetrieveAverageGrade();

};

