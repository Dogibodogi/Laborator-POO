#pragma once
#include "Car.h"
class Mercedes : public Car
{
public:
	Mercedes();
	const char* GetName() override;
	float GetRainSpeed() override;
	float GetSnowSpeed() override;
	float GetSunSpeed() override;
	float GetMaxLength(Car* masina) override;
	float GetSpeed(Car* masina, weather vreme) override;
};