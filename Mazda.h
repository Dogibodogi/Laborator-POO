#pragma once
#include "Car.h"
class Mazda : public Car
{
public:
	Mazda();
	const char* GetName() override;
	float GetRainSpeed() override;
	float GetSnowSpeed() override;
	float GetSunSpeed() override;
	float GetMaxLength(Car* masina) override;
	float GetSpeed(Car* masina, weather vreme) override;
};