#include "Mercedes.h"
Mercedes::Mercedes()
{
	FuelCapacity = 999; //100 litri
	FuelConsuption = 8; //foloseste 5 litri per 100km
	AverageSpeedRainy = 179; // km/h
	AverageSpeedSnow = 140;
	AverageSpeedSunny = 230;
}
const char* Mercedes::GetName()
{
	return "Mercedes";
}
float Mercedes::GetRainSpeed()
{
	return AverageSpeedRainy;
}
float Mercedes::GetSnowSpeed()
{
	return AverageSpeedSnow;
}
float Mercedes::GetSunSpeed()
{
	return AverageSpeedSunny;
}
float Mercedes::GetSpeed(Car* masina, weather vreme)
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
float Mercedes::GetMaxLength(Car* masina)
{
	return (FuelCapacity / FuelConsuption) * 100.0;
}