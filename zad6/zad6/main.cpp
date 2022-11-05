#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int ROW = 5;
const int COL = 5;

void wczytaj_dane(int numbers[ROW][COL])
{
	ifstream fin;
	fin.open("dane.txt", ios::in);

	if (fin.is_open())
	{
		for (int i = 0; i < ROW; i++)
		{
			for (int j = 0; j < COL; j++)
			{
				if (fin.good())
				{
					fin >> numbers[i][j];
				}
				else
				{
					break;
				}
			}
		}
		fin.close();
	}
}

void wypisz_dane(int numbers[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << setw(5) << numbers[i][j];
		}
		cout << '\n';
	}
}

void zamien_wiersze(int numbers[ROW][COL], int wiersz1, int wiersz2)
{
	if (wiersz1 >= 0 && wiersz1 < ROW && wiersz2 >= 0 && wiersz2 < ROW)
	{
		for (int j = 0; j < COL; j++)
		{
			int temp = numbers[wiersz1][j];
			numbers[wiersz1][j] = numbers[wiersz2][j];
			numbers[wiersz2][j] = temp;
		}
	}
	else
	{
		cout << "Numery wiersz spoza dozwolonego zakresu\n";
	}
}

int minimum_glownej_przekatnej(int numbers[ROW][COL])
{
	int result = numbers[0][0];

	for (int i = 1; i < ROW; i++)
	{
		if (numbers[i][i] < result)
		{
			result = numbers[i][i];
		}
	}

	return result;
}

void zapisz_elementy_powyzej_przekatnej(int numbers[ROW][COL])
{
	ofstream fout;
	fout.open("powyzej.txt", ios::out);

	for (int i = 0; i < ROW; i++)
	{
		for (int j = i + 1; j < COL; j++)
		{
			fout << setw(5) << numbers[i][j];
		}
		fout << '\n';
	}

	fout.close();
}

void ilosc_parzystych_nieparzystych(int numbers[ROW][COL], int& parzyste, int& nieparzyste)
{
	parzyste = 0;
	nieparzyste = 0;

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (numbers[i][j] == 0)
			{
				continue;
			}

			if (numbers[i][j] % 2 == 0)
			{
				parzyste++;
			}
			else
			{
				nieparzyste++;
			}
		}
	}
}

int main()
{
	int numbers[ROW][COL] = { 0 };

	wczytaj_dane(numbers);

	cout << "Wczytane elementy tablicy:\n";

	wypisz_dane(numbers);

	int wiersz1 = 0;
	int wiersz2 = 0;

	cout << "\nPodaj numery wierszy do zamiany: ";

	cin >> wiersz1 >> wiersz2;

	zamien_wiersze(numbers, wiersz1 - 1, wiersz2 - 1);

	cout << "\nElementy tablicy po zamianie wierszy:\n";

	wypisz_dane(numbers);

	int min = minimum_glownej_przekatnej(numbers);

	cout << "\nMinimum glownej przekatnej: " << min << "\n\n";

	zapisz_elementy_powyzej_przekatnej(numbers);

	int parzyste = 0;
	int nieparzyste = 0;

	ilosc_parzystych_nieparzystych(numbers, parzyste, nieparzyste);

	cout << "Ilosc elementow parzystych: " << parzyste << "\n";
	cout << "Ilosc elementow nieparzystych: " << nieparzyste << "\n\n";


	int* A = new int[parzyste];
	int* B = new int[nieparzyste];

	int even = 0;
	int odd = 0;

	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (numbers[i][j] == 0)
				continue;

			if (numbers[i][j] % 2 == 0)
			{
				A[even] = numbers[i][j];
				even++;
			}
			else
			{
				B[odd] = numbers[i][j];
				odd++;
			}
		}
	}

	cout << "\nElementy parzyste: \n";

	for (int i = 0; i < parzyste; i++)
	{
			cout << setw(5) << A[i];
	}

	cout << "\nElementy nieparzyste: \n";

	for (int i = 0; i < nieparzyste; i++)
	{
		cout << setw(5) << B[i];
	}

	cout << "\n\n";

	delete[] A;
	delete[] B;

	return 0;
}
