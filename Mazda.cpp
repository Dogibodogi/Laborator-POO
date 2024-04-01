#include "Mazda.h"
Mazda::Mazda()
{
	FuelCapacity = 20; //100 litri
	FuelConsuption = 10; //foloseste 5 litri per 100km
	AverageSpeedRainy = 80; // km/h
	AverageSpeedSnow = 98;
	AverageSpeedSunny = 75;
}
const char* Mazda::GetName()
{
	return "Mazda";
}
float Mazda::GetRainSpeed()
{
	return AverageSpeedRainy;
}
float Mazda::GetSnowSpeed()
{
	return AverageSpeedSnow;
}
float Mazda::GetSunSpeed()
{
	return AverageSpeedSunny;
}
float Mazda::GetSpeed(Car* masina, weather vreme)
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
float Mazda::GetMaxLength(Car* masina)
{
	return (FuelCapacity / FuelConsuption) * 100.0;
}