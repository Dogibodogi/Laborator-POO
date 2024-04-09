#pragma once
#include "Car.h"
class Dacia : public Car
{
public:
	Dacia();
	const char* GetName() override;
	float GetRainSpeed() override;
	float GetSnowSpeed() override;
	float GetSunSpeed() override;
	float GetMaxLength(Car* masina) override;
	float GetSpeed(Car* masina, weather vreme) override;
};
