#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void losuj (float tab[][8],int N);
void wypisz(float tab[][8],int N);
double average (float tab[][8], int N);
void createc (float tab[][8],float C[],int N);
void wypisz_tab (float t[], int N);
void created(float tab[][8],float D[],int N);
void sort_A(float tab[][8],int N);



int main()
{

	srand(time(0));
	const int N = 8;
    float tab_A[8][8];
    float tab_B[5][8];
    cout<<"Liczby tablicy A: \n\n";
    losuj(tab_A,N);
    wypisz(tab_A,N);
    cout<<"Liczby tablicy B: \n\n";
    losuj(tab_B,5);
    wypisz(tab_B,5);
    float result =average(tab_A,N);
    cout<<"Srednia elementow lezacych ponizej glownej przekatnej wynosi : "<<result<<"\n\n";
    cout<<"Liczby tablicy C : \n\n";
    float C[N];
    createc(tab_B,C,N);
    wypisz_tab(C,N);
    cout<<"Liczby tablicy D:\n\n";
    float D[5];
    created(tab_B,D,N);
    wypisz_tab(D,5);
    cout<<"Posortowana tablica A : \n\n";
    sort_A(tab_A,N);
    wypisz(tab_A,N);






    return 0;
}
void losuj (float tab[][8],int N)
    {
        for (int i=0;i<N;i++)
        for (int j=0;j<8;j++)
            {
                tab[i][j]=(float)(rand()%50)/10;
            }
    }
void wypisz(float tab[][8],int N)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < 8; j++)
                cout <<setw(4)<< tab[i][j] << "  ";
                cout << "\n\n\n";
            }


        }
double average (float tab[][8],int N)
{

    double value=0;
    int ile=0;
    for (int i = 0; i < N; i++)
    for (int j = 0;j < 8; j++)
    if(i<=j)
        {
            value=value+tab[i][j];
            ile++;
        }
        value=value/ile;
        return value;

}
void createc (float tab[][8],float C[],int N)
{
    int i, j;

    for (j = 0; j < N; j++)
    {
        for (i = 0; i < 5; i++)
        {
            C[j] += tab[i][j];
        }
    }
}
void wypisz_tab (float tab[], int N)
{
    for (int i = 0; i < N; i++)
    cout << tab[i] << "  ";
    cout << "\n\n\n";
}
void created(float tab[][8],float D[],int N)
{
    for (int i = 0; i < N; i++)
    {
        float min = tab[i][0];
        for (int j = 0; j < 5; j++)
        {
            if(min >= tab[i][j])
            {
                min = tab[i][j];
                D[i] = min;
            }
        }
    }
}
void sort_A(float tab[][8],int N)
{
    int i, j, result;

    for( j = 1; j <= N; j++ )
    {
        for( i = 0; i < N ; i++ )
        {
            if( tab[ i ][ i ] < tab[ i + 1 ][ i + 1 ] )
            {
                result = tab[ i ][ i ];
                tab[ i ][ i ] = tab[ i + 1 ][ i + 1 ];
                tab[ i + 1 ][ i + 1 ] = result;
            }
        }
    }
}




