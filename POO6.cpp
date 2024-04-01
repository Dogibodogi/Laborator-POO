#include <iostream>
#include "Car.h"
#include "Dacia.h"
#include "Ford.h"
#include "Mazda.h"
#include "Circuit.h"
#include "Weather.h"
#include "Mercedes.h"
using namespace std;
int main()
{
	weather a = Snow;
	Dacia B;
	Ford C;
	Mazda D;
	Mercedes E;
	Circuit jocilol;
	jocilol.SetLenght(500);
	jocilol.AddCar(&B);
	jocilol.AddCar(&C);
	jocilol.AddCar(&D);
	jocilol.AddCar(&E);
	jocilol.PrintCarList();
	jocilol.SetWeather(a);
	jocilol.Race();
	jocilol.ShowFinalRanks();
	jocilol.ShowWhoDidNotFinish();
	return 0;
}