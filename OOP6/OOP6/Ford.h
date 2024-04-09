#pragma once
#include "Car.h"
class Ford : public Car
{
public:
	Ford();
	const char* GetName() override;
	float GetRainSpeed() override;
	float GetSnowSpeed() override;
	float GetSunSpeed() override;
	float GetMaxLength(Car* masina) override;
	float GetSpeed(Car* masina, weather vreme) override;
};