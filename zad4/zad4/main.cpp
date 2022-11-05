#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

struct STUDENT
{
    string nazwisko;
    float oceny[3];
    float srednia;
};

void students(STUDENT name[],int N);
float average (STUDENT name[],int N);
int maxi (STUDENT name[],int N, float max_avg);
void wypisz (STUDENT name[],int N);
void wypiszmaxi (STUDENT name[],int N);
void szukaj(STUDENT name[],int N);



int main()
{
    srand(time(0));
    const int N=4;
    cout<<setw(30)<<"*****DANE STUDENTOW*****\n\n";
    STUDENT dane[N];
    cout<<setw(15)<<"*** Podaj dane "<<N<<" studentow : ***\n\n";
    students(dane,N);
    cout<<"\n***Srednia ocen wszystkich studentow : ***\n\n";
    float result = 0;
    result = average (dane,N);
    cout<<setw(25)<<"Srednia wynosi : "<< result<<"\n\n";
    int ile = 0;
    ile = maxi(dane,N, result);
    cout<<"Wieksza srednia niz : "<<result<<" posiada : "<<ile<<" studentow\n\n";
    cout<<"*****DANE STUDENTOW*****\n\n";
    wypisz (dane,N);
    wypiszmaxi(dane,N);
    cout<<"\n*****WYSZUKIWARKA STUDENTA*****\n\n";
    szukaj (dane,N);

    return 0;

}
void students(STUDENT name[],int N)
{
    float ocena = 0;
    float srednia = 0;
    float result = 0;

    for(int i=0;i<N;i++)
    {
        cout<<"\n\Prosze podac nazwisko studenta : \n";
        cin>> name[i].nazwisko;
        for(int a = 0; a < 3; a++)
        {
            ocena = (rand() % 7)+4;
            name[i].oceny[a] = ocena / 2;
        }
        for(int b = 0; b < 3; b++)
        {
            result = result + name[i].oceny[b];
        }
            srednia = result / 3;
    }
}
float average (STUDENT name[],int N)
{
    float value=0;
    float greaters = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < 3; j++)
        {
            greaters = name[i].oceny[j];
            value = value + greaters;
        }
        return value/(N *3);
}
int maxi (STUDENT name[],int N, float max_avg)
{
    float value;
    int ile=0;
    float avg;
    float greaters;
    for(int i = 0; i < N; i++)
    {
        avg = 0;
        value = 0;
        greaters = 0;
        for(int j = 0; j < 3; j++)
        {
            greaters = name[i].oceny[j];
            value=value+greaters;

        }
        avg=value/3;

        if(avg>max_avg)
        {
            ile++;
        }

    }
    return ile;
}

void wypisz (STUDENT name[], int N)
{
    for(int i = 0; i < N; i++)
    {
        cout<<"**********************";
        cout << "\nNazwisko studenta: \n" <<setw(10)<< name[i].nazwisko << "\n\n";
        float result = 0;
        float srednia = 0;
        for(int b = 0; b < 3; b++)
        {
            result = result + name[i].oceny[b];
        }
            srednia = result / 3;
        cout<<"Srednia studenta : \n"<<setw(10)<<srednia<<"\n\n";
        cout<<"Oceny studenta : \n";
        for(int j = 0; j < 3; j++)
        {
            cout<<setw(10)<<name[i].oceny[j]<< "\n";

        }
    }cout<<"**********************";
}
void wypiszmaxi (STUDENT name[],int N)
{
    string nazwisko;
    float value = 0;
    float resul = 0;
    float max = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            value = value + name[i].oceny[j];
        }
        resul = value/(3*N) ;
        if(resul >= max)
        {
            max = resul;
            nazwisko = name[i].nazwisko;
        }
    }
    cout<<"\nNajwyzsza srednia posiada : "<< nazwisko << "\n      ktora wynosi : "<< max<<"\n\n";
    cout<<setw(27)<<"*****GRATULUJEMY*****\n";
}
void szukaj(STUDENT name[],int N)
{
   string nazwisko;
   cout<<"Podaj nazwisko poszukiwanego studenta : \n";
   cin>>nazwisko;
   for(int i = 0; i < N; i++)
   {
       if(nazwisko == name[i].nazwisko)
       {
         cout<<"Nazwisko studenta : "<< nazwisko <<"\n\n";
         cout<<"*****DANE STUDENTA*****\n\n";
         cout<<"Uzyskane oceny : \n";
         float value = 0;
         for (int j = 0; j < 3; j++)
         {
            float ocena = 0;
            ocena=name[i].oceny[j];
            cout<<ocena<<"\n";

            value=value+name[i].oceny[j];
         }
         value=value/3;
         cout<<"Uzyskana srednia : \n"<<value;

       }
   }
}
