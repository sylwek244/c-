#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

struct Kot
{
	char imie[10];
	char rasa[20];
	int wiek;
	double waga;
};


int wczytaj_dane(Kot Koty[], int ilosc)
{
	ifstream fin;
	fin.open("kotki.txt", ios::in);

	int result = 0;

	if (fin.is_open())
	{
		string temp;

		while (fin.good() && result < ilosc)
		{
			getline(fin, temp);
			strcpy(Koty[result].imie, temp.c_str());

			getline(fin, temp);
			strcpy(Koty[result].rasa, temp.c_str());

			fin >> Koty[result].wiek;
			fin >> Koty[result].waga;

			fin.get();

			result++;
		}

		fin.close();
	}

	return result ;
}

void wyswietl_dane(const Kot& kot)
{
	cout << "Imie: " <<setw(10)<< kot.imie
		<< " Rasa: " <<setw(10)<< kot.rasa
		<< " Wiek: " <<setw(10)<< kot.wiek
		<< " Waga: " <<setw(10)<< kot.waga << "\n";
}

void szukaj_kotow(Kot Koty[], int ilosc, const string& rasa)
{
	for (int i = 0; i < ilosc; i++)
	{
		if (rasa == Koty[i].rasa)
		{
			wyswietl_dane(Koty[i]);
		}
	}
}

void sortuj_tablice(Kot Koty[], int ilosc)
{
	for (int i = 0; i < ilosc - 1; i++)
	{
		int pmin = i;
		for (int j = i + 1; j < ilosc; j++)
		{
			if (strcmp(Koty[j].rasa, Koty[pmin].rasa) < 0)
			{
				pmin = j;
			}
		}

		Kot temp = Koty[i];
		Koty[i] = Koty[pmin];
		Koty[pmin] = temp;
	}

	for (int i = 0; i < ilosc; i++)
	{
		wyswietl_dane(Koty[i]);
	}
}

double srednia_waga(Kot Koty[], int ilosc)
{
	double suma = 0.0;

	for (int i = 0; i < ilosc; i++)
	{
		suma += Koty[i].waga;
	}

	if (ilosc > 0)
	{
		return suma / ilosc;
	}

	return 0.0;
}

void wypisz_waga_powyzej(Kot Koty[], int ilosc, double srednia)
{
	ofstream fout;
	fout.open("kotki_duze.txt", ios::out);

	for (int i = 0; i < ilosc; i++)
	{
		if (Koty[i].waga > srednia)
		{
			wyswietl_dane(Koty[i]);

			fout << Koty[i].imie << '\n'
				<< Koty[i].rasa << '\n'
				<< Koty[i].wiek << '\n'
				<< Koty[i].waga << '\n';
		}
	}

	fout.close();
}

void najstarszy_najmlodszy(Kot Koty[], int ilosc, Kot& najstarszy, Kot& najmlodszy)
{
	int imin = 0;
	int wiek_min = Koty[0].wiek;

	int imax = 0;
	int wiek_max = Koty[0].wiek;

	for (int i = 1; i < ilosc; i++)
	{
		if (Koty[i].wiek < wiek_min)
		{
			imin = i;
			wiek_min = Koty[i].wiek;
		}

		if (Koty[i].wiek > wiek_max)
		{
			imax = i;
			wiek_max = Koty[i].wiek;
		}
	}

//	strcpy(najmlodszy.imie, Koty[imin].imie);
//	strcpy(najmlodszy.rasa, Koty[imin].rasa);
//	najmlodszy.waga = Koty[imin].waga;
//	najmlodszy.wiek = Koty[imin].wiek;
    najmlodszy=Koty[imin];
//	strcpy(najstarszy.imie, Koty[imax].imie);
//	strcpy(najstarszy.rasa, Koty[imax].rasa);
//	najstarszy.waga = Koty[imax].waga;
//	najstarszy.wiek = Koty[imax].wiek;
    najstarszy=Koty[imax];
}



int main()
{
	const int N = 8;

	Kot Koty[N] = {0};

	int ilosc = wczytaj_dane(Koty, N);

	for (int i = 0; i < ilosc; i++)
	{
		wyswietl_dane(Koty[i]);
	}

	string rasa;
	cout<<"\n\n*****Wyszukaj rase*****\n\n";
	cout<<"Podaj rase z ras podanych powyzej\n\n";
	cout << "Podaj nazwe rasy: ";
	getline(cin, rasa);

	szukaj_kotow(Koty, ilosc, rasa);

	cout << "\nDane posortowane wzgledem rasy:\n\n";
	sortuj_tablice(Koty, ilosc);

	double srednia = srednia_waga(Koty, ilosc);
	cout<<"\nSrednia waga kota wynosi : "<<srednia<<"\n";

	cout << "\nDane kotow powyzej sredniej wagi:\n\n";
	wypisz_waga_powyzej(Koty, ilosc, srednia);

	Kot najstarszy{ };
	Kot najmlodszy{ };

	najstarszy_najmlodszy(Koty, ilosc, najstarszy, najmlodszy);

	cout << "\nDane najstarszego kotka:\n\n";
	wyswietl_dane(najstarszy);

	cout << "\nDane najmlodszego kotka:\n\n";
	wyswietl_dane(najmlodszy);


	return 0;
}
