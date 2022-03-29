/*
2. Sa se determine �nchiderea transitiv� a unui graf orientat.
(�nchiderea tranzitiv� poate fi reprezentat� ca matricea care descrie, pentru fiecare v�rf �n parte, care sunt
v�rfurile accesibile din acest v�rf. Matricea inchiderii tranzitive arat� unde se poate ajunge din fiecare v�rf.)
ex. figura inchidere_tranzitiva.png - pentru graful de sus se construieste matricea de jos care arata inchiderea tranzitiva.
*/

#include<iostream>
#include<fstream>
using namespace std;
ifstream f("graf.txt");
int m[100][100]={0},nr,i,j,k,x,y;
int main()
{
    f>>nr;
    while(f>>x and f>>y)
        m[x][y]=1;

    for(i=0;i<nr;i++){
        m[i][i]=1;
    }

    cout<<"Matricea initiala:\n";
    for(i=0;i<nr;i++)
    {
        for(j=0;j<nr;j++)
            cout<<m[i][j]<<" ";
        cout<<'\n';
    }

    for (int k = 0; k < nr; k++)
        for (int i = 0; i < nr; i++)
            for (int j = 0; j < nr; j++)
                if (m[i][j] == 0)
                    m[i][j] = (m[i][k] && m[k][j]);

    cout<<"Matricea inchiderii tranzitive:\n";
    for(i=0;i<nr;i++)
    {
        for(j=0;j<nr;j++)
            cout<<m[i][j]<<" ";
        cout<<'\n';
    }
    return 0;
}
