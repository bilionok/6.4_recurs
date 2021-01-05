// Lab_06_4.cpp
// < Біліонок Ярослав >
// Лабораторна робота № 6.4(2)
// Опрацювання одновимірних масивів рекурсивним способoм
// Варіант 1

#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const  int High, int i) // Функція, що формує масив
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);

}

void Print(int* a, const int size, int i) //  Функція, яка вивиодить масив на екран
{
	cout << setw(4) << a[i];

	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;

}
int Sum(int* a, const int size, int S, int i) // Функція, яка обчислює суму від’ємних елементів масиву.
{
	if (a[i] < 0)
		S += a[i];

	if (i < size - 1)
		return Sum(a, size, S, i + 1);
	else
		return S;
}
int FindMin(int* a, const int size, int min, int imin, int i) // Функція, яка шукає мінімальний елемент масиву
{

	if (a[i] < min)
	{
		min = a[i];
		imin = i;
	}
	if (i < size - 1)
		FindMin(a, size, min, imin, i + 1);
	else
		return imin;
}
int FindMax(int* a, const int size, int max, int imax, int i) // Функція, яка шукає максимальний елемент масиву
{
	if (a[i] > max)
	{
		max = a[i];
		imax = i;
	}
	if (i < size - 1)
		FindMax(a, size, max, imax, i + 1);
	else
		return imax;
}
int P1(int* a, int ix, int P, int i) //  Функція, яка шукає добуток елементів масиву, розташованих між максимальним і мінімальним елементами.
{   
	if (i < ix)
	{
		P = P * a[i];
		return P1(a, ix, P, i + 1);
	}
	else
		return P;
}

void Sort(int* a, const int size, int i)  // Функція, яка впорядковує елементи масиву за зростанням.
{
	for (int j = 0; j < size - i; j++) 
		if (a[j] > a[j + 1]) 
		{ 
			int tmp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = tmp;
		}
	if (i < size - 1) 
		Sort(a, size, i + 1);
}

int main()
{
	srand((unsigned)time(NULL));


	int Low, High, iMin, iMax, n, P = 1;

	cout << "Array size ="; cin >> n;

	int* a = new int[n];


	cout << "Low ="; cin >> Low;
	cout << "High ="; cin >> High;
	cout << endl;

	Create(a, n, Low, High, 0);
	cout << "Array =";
	Print(a, n, 0);
	cout << endl;
	

	int S = Sum(a, n, 0, 0);
	cout << "1.1)Sum = " << S << endl;
	cout << endl;

	iMin = FindMin(a, n, a[0], 0, 0);
	iMax = FindMax(a, n, a[0], 0, 0);

	cout << "Min a[" << iMin << "]=" << a[iMin] << endl;
	cout << "Max a[" << iMax << "]=" << a[iMax] << endl;
	cout << endl;

	
	
	
	if (iMin < iMax)
	{
		P = P1(a, iMax, P, iMin + 1);
	}
	else
	{
		P = P1(a, iMin, P, iMax + 1);
	}
		
	
		
	cout << "1.2)P = " << P << endl;
	cout << endl;

	Sort(a, n, 1);
	cout << "Array =";
	Print(a, n, 0);

	return 0;
}