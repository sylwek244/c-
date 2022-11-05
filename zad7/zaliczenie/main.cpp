#include <iostream>
#include <cstdlib>
#include<bitset>

using namespace std;

int oblicz_dlugosc(char* napis);
int szukaj(char* napis, char znak);
void male_na_duze(char* napis);
bool is_palindrom(char* napis);
void wlacz_bit();
void wylacz_bit();
void zmien_bit();

unsigned long long SilniaIter(int n);
unsigned long long SilniaRekur(int n);

int main()
{
	const short N = 80;
	char napis[N];

	cout << "Podaj wybrany tekst:\n\n";
	cin.getline(napis, N);
	cout << "\nTwoj tekst : \n\n" << napis << "\n\n";

	int dlugosc = oblicz_dlugosc(napis);

	if (dlugosc > 0)
		cout << "Dlugosc podanego wyrazu: \n\n" << dlugosc << "\n\n";


	cout << "Podaj znak:\n\n";
	char znak;
	cin >> znak;

	int ilosc_wystapien = szukaj(napis, znak);

	if (ilosc_wystapien > 0)
		cout << "\nZnak " << znak << " wystapil "<< ilosc_wystapien << " razy\n\n";
	else
		cout << "\nZnak " << znak << " nie wystapil w podanym tekscie\n\n";

	male_na_duze(napis);

	cout << "\nTekst po zamianie malych liter na duze: \n\n" << napis << "\n\n";

	if (is_palindrom(napis))
		cout << "\nPodany tekst jest palindromem\n\n";
	else
		cout << "\nPodany tekst nie jest palindromem\n\n";

	cout << "\nPodaj liczbe naturalna: ";

	int liczba = 0;
	cin >> liczba;

	cout << "\nSilnia z " << liczba << " obliczona iteracyjnie: " << SilniaIter(liczba) << "\n";
	cout << "\nSilnia z " << liczba << " obliczona rekurencyjnie: " << SilniaRekur(liczba) << "\n\n";

	cout<<"*****Operacje na bitach : *****\n\n";
	cout<<"\n\n*****WLACZ BIT*****\n\n";
            wlacz_bit();
	cout<<"\n\n*****WYLACZ BIT*****\n\n";
            wylacz_bit();
	cout<<"\n\n*****ZMIEN BIT*****\n\n";
            zmien_bit();



	return 0;
}


int oblicz_dlugosc(char* napis)
{
	if (napis == NULL)
	{
		return -1;
	}

	int dlugosc = 0;

	while (napis[dlugosc] != '\0')
	{
		dlugosc++;
	}

	return dlugosc;
}

int szukaj(char* napis, char znak)
{
	if (napis == NULL)
	{
		return -1;
	}

	int wynik = 0;

	int k = 0;

	while (napis[k] != '\0')
	{
		if (napis[k] == znak)
		{
			wynik++;
		}

		k++;
	}

	return wynik;
}

void male_na_duze(char* napis)
{
	if (napis == NULL)
	{
		return;
	}

	int przesuniecie = 'a' - 'A';

	int k = 0;

	while (napis[k] != '\0')
	{
		if (napis[k] >= 'a' && napis[k] <= 'z')
		{
			napis[k] -= przesuniecie;
		}

		k++;
	}
}

bool is_palindrom(char* napis)
{
	if (napis == NULL)
	{
		return false;
	}

	int n = oblicz_dlugosc(napis);

	for (int k = 0; k < n; k++)
	{
		if (napis[k] != napis[n-1-k])
			return false;
	}

	return true;
}

unsigned long long SilniaIter(int n)
{
	unsigned long long wynik = 1;

	for (int k = 2; k <= n; k++)
	{
		wynik = wynik * k;
	}

	return wynik;
}

unsigned long long SilniaRekur(int n)
{
	if (n < 2)
		return 1;

	return n * SilniaRekur(n - 1);
}
void wlacz_bit()
{
  int N=0;
  cout<<"Podaj liczbe od 0 do 255\n";
  cin>>N;
  cout << bitset <8> (N);
  cout<<"\nPodaj bit ktory chcesz wlaczyc : \n";
  int a = 0;
  cin>>a;
  int maska=0;
  maska = 1<<a;
  cout<<"\n\nMaska : \n\n";
  cout << bitset <8> (maska);
  N = N|maska;
  cout<<"\n\nWlaczony bit : \n\n";
  cout << bitset <8> (N);
}
void wylacz_bit()
{
  int N=0;
  cout<<"Podaj liczbe od 0 do 255\n";
  cin>>N;
  cout << bitset <8> (N);
  cout<<"\nPodaj bit ktory chcesz wylaczyc : \n";
  int a = 0;
  cin>>a;
  int maska=0;
  maska = 1<<a;
  maska =~maska;
  cout<<"\n\nMaska : \n\n";
  cout << bitset <8> (maska);
  N = N&maska;
  cout<<"\n\nWylaczony bit : \n\n";
  cout << bitset <8> (N);
}
void zmien_bit()
{
  int N=0;
  cout<<"Podaj liczbe od 0 do 255\n";
  cin>>N;
  cout << bitset <8> (N);
  cout<<"\nPodaj bit ktory chcesz zmienic : \n";
  int a = 0;
  cin>>a;
  int maska=0;
  maska = 1<<a;
  cout<<"\n\nMaska : \n\n";
  cout << bitset <8> (maska);
  N = N^maska;
  cout<<"\n\nZmieniony bit : \n\n";
  cout << bitset <8> (N);
}
