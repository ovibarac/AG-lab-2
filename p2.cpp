/*
2. Sa se determine închiderea transitivã a unui graf orientat.
(Închiderea tranzitivã poate fi reprezentatã ca matricea care descrie, pentru fiecare vârf în parte, care sunt
vârfurile accesibile din acest vârf. Matricea inchiderii tranzitive aratã unde se poate ajunge din fiecare vârf.)
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
