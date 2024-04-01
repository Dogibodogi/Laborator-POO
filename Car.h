#pragma once
#include "Weather.h"
class Car
{
protected:
	int FuelCapacity;
	int FuelConsuption;
	float AverageSpeedRainy;
	float AverageSpeedSnow;
	float AverageSpeedSunny;
public:
	Car();
	virtual const char* GetName() = 0;
	virtual float GetRainSpeed() = 0;
	virtual float GetSnowSpeed() = 0;
	virtual float GetSunSpeed() = 0;
	virtual float GetSpeed(Car* masina, weather vreme)= 0;
	virtual float GetMaxLength(Car* masina)= 0;
};
