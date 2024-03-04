#include <iostream>
#include "NumberList.h"
#include "student.h"
#include "functii.h"
using namespace std;
int main()
{
	NumberList ListaNumere;
	ListaNumere.Init();
	ListaNumere.Add(10);
	ListaNumere.Add(7);
	ListaNumere.Add(9);
	ListaNumere.Print();
	ListaNumere.Sort();
	ListaNumere.Print();
	cout << endl;
	student andrei;
	student ion;
	andrei.SetName("Andrei");
	andrei.SetEnglishGrade(7);
	andrei.SetHistoryGrade(5);
	andrei.SetMathGrade(10);
	cout << "Media studentului este:" << andrei.RetrieveAverageGrade()<<endl;
	cout <<"Numele studentului este:"<<andrei.GetName()<<endl;
	cout << "Nota studentului la matematica este:" << andrei.GetMathGrade() << endl;
	ion.SetName("Ion");
	ion.SetEnglishGrade(6);
	ion.SetHistoryGrade(5);
	ion.SetMathGrade(3);
	cout<<CompareAverageGrades(ion, andrei)<<endl;
	cout<<CompareAverageGrades(andrei, ion)<<endl;
	cout << CompareNames(andrei, ion) << endl;
	return 0;
}