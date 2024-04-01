#include "Ford.h"
Ford::Ford()
{
	FuelCapacity = 10000; //100 litri
	FuelConsuption = 10; //foloseste 5 litri per 100km
	AverageSpeedRainy = 800; // km/h
	AverageSpeedSnow = 500;
	AverageSpeedSunny = 500;
}
const char* Ford::GetName()
{
	return "Ford";
}
float Ford::GetRainSpeed()
{
	return AverageSpeedRainy;
}
float Ford::GetSnowSpeed()
{
	return AverageSpeedSnow;
}
float Ford::GetSunSpeed()
{
	return AverageSpeedSunny;
}
float Ford::GetSpeed(Car* masina, weather vreme)
{
	float AvgSpeed = 0;
	switch (vreme)
	{
	case Rain: AvgSpeed = masina->GetRainSpeed();
		break;
	case Snow: AvgSpeed = masina->GetSnowSpeed();
		break;
	case Sunny: AvgSpeed = masina->GetSunSpeed();
		break;
	}
	return AvgSpeed;
}
float Ford::GetMaxLength(Car* masina)
{
	return (FuelCapacity / FuelConsuption) * 100.0;
}