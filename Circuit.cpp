#include "Circuit.h"
#include "Weather.h"
#include "Dacia.h"
#include "Car.h"
#include <iostream>
using namespace std;
Circuit::Circuit()
{
	Length = 0;
	CurrentWeather = Sunny;
	count = 0;
	ListaMasini = new Car*; 
	ListaMasiniSortata = new Car*;
}
void Circuit::SetWeather(weather vreme)
{
	CurrentWeather = vreme;
}
void Circuit:: SetLenght(int a)
{
	Length = a;
}
void Circuit::AddCar(Car* masina)
{
	Car** ListaMasiniFake = new Car * [++count];
	if (count == 1)
		ListaMasiniFake[0] = masina;
	else
	{
		ListaMasiniFake[count-1] = masina;
		for (int i = 0; i < count-1; i++)
			ListaMasiniFake[i] = ListaMasini[i];
	}
	delete[] ListaMasini;
		ListaMasini = ListaMasiniFake;

}
void Circuit:: PrintCarList()
{
	if (count == 0)
		return;
	for(int i=0; i<count; i++)
	cout << ListaMasini[i]->GetName()<<endl;
}
void Circuit::Race()
{
	delete[] ListaMasiniSortata;
	ListaMasiniSortata = ListaMasini;
	float viteza[100];
	for (int k = 0; k < count; k++)
	{
		if (ListaMasini[k]->GetMaxLength(ListaMasini[k]) >= Length)
		{
			viteza[k] = ListaMasini[k]->GetSpeed(ListaMasini[k], CurrentWeather);
		}
		else
			viteza[k] = 0;
	}
	int i, j;
	bool swapped;
	Car* aux;
	for (i = 0; i < count - 1; i++)
	{
		swapped = false;
		for (j = 0; j < count - i - 1; j++)
		{
			if (viteza[j] > viteza[j + 1])
			{
				aux = ListaMasiniSortata[j];
				ListaMasiniSortata[j] = ListaMasiniSortata[j + 1];
				ListaMasiniSortata[j + 1] = aux;
				swap(viteza[j], viteza[j + 1]);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}
void Circuit::ShowFinalRanks()
{
	int i = count - 1;
	int k = 1;
	while(i>=0)
	{
		if (ListaMasini[i]->GetMaxLength(ListaMasini[i]) >= Length)
		cout << ListaMasiniSortata[i]->GetName() << " A luat locul " << k++ << " Cu timpul " << Length/ListaMasiniSortata[i]->GetSpeed(ListaMasiniSortata[i], CurrentWeather)<<endl;
		i--;
	}
}
void Circuit::ShowWhoDidNotFinish()
{
	int i = count-1;
	while(i>=0)
	{
		if (ListaMasini[i]->GetMaxLength(ListaMasini[i]) < Length)
			cout << ListaMasini[i]->GetName() << " nu a terminat cursa"<<endl;
		i--;
	}
}
Circuit::~Circuit()
{

	delete[] ListaMasini;
}


