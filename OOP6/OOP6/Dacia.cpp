#include "Dacia.h"
Dacia::Dacia()
{
	FuelCapacity = 100; //100 litri
	FuelConsuption = 5; //foloseste 5 litri per 100km
	AverageSpeedRainy = 90; // km/h
	AverageSpeedSnow = 100;
	AverageSpeedSunny = 110;
}
const char* Dacia::GetName()
{
	return "Dacia";
}
float Dacia::GetRainSpeed()
{
	return AverageSpeedRainy;
}
float Dacia::GetSnowSpeed()
{
	return AverageSpeedSnow;
}
float Dacia::GetSunSpeed()
{
	return AverageSpeedSunny;
}
float Dacia::GetSpeed(Car* masina, weather vreme)
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
float Dacia::GetMaxLength(Car* masina)
{
	return (FuelCapacity / FuelConsuption) * 100.0;
}