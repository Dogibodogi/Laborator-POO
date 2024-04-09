#pragma once
#include "weather.h"
#include "Car.h"
class Circuit
{
private:
	weather CurrentWeather;
	int Length;
	int count;
	Car** ListaMasini;
	Car** ListaMasiniSortata;
public:
	Circuit();
	~Circuit();
	void SetWeather(weather vreme);
	void SetLenght(int a);
	void AddCar(Car* masina);
	void PrintCarList();
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

