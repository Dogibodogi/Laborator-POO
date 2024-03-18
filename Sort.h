#pragma once
class Sort
{
    int count;
    int* vector;
public:
    ~Sort();
    Sort(int c, int min, int max);
    Sort(int vec[], int c);
    Sort(char vec[], int c);
    Sort(int c, ...);
    void InsertSort(bool ascendent = false);
    void QuickSort(int st, int dr, bool ascendent);
    void BubbleSort();
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

