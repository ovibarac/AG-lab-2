//Lab2 problema 1
//1. Implementați algoritmul lui Moore pentru un graf neorientat neponderat (algoritm bazat pe Breath-first search, vezi cursul 2).
// Datele sunt citete din fisierul graf.txt. Primul rând din graf.txt conține numărul vârfurilor, iar următoarele rânduri conțin muchiile grafului.
// Programul trebuie să afiseze lanțul cel mai scurt dintr-un vârf (vârful sursa poate fi citit de la tastatura).

/*
Exemplu input:
5
1 2
2 3
4 5
1 3
5 2
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

ifstream f("graf.txt");

const int MAX = 101;
const int INF = 1e9;

int ma[MAX][MAX];
int nrV;
int lg[MAX];
int p[MAX];
queue<int> q;

void citireGraf() {
    f >> nrV;
    int x, y;
    while (f >> x >> y) {
        ma[x][y] = ma[y][x] = 1;
    }
}

void moore(int nod) {
    for (int i = 1; i <= nrV; i++) {
        lg[i] = INF;
    }
    lg[nod] = 0;
    q.push(nod);
    int x;
    while (!q.empty()) {
        x = q.front();
        q.pop();

        for (int i = 1; i <= nrV; i++) {
            if (ma[x][i] == 1) {
                if (lg[i] == INF) {
                    p[i] = x;
                    lg[i] = lg[x] + 1;
                    q.push(i);
                }
            }
        }
    }
}

void moore_drum(int nod) {
    if(nod == 0){
        return;
    }else{
        moore_drum(p[nod]);
    }
    cout<< nod << ' ';
}

int main() {
    citireGraf();
    cout << "Nodul sursa: " << '\n';
    int s;
    cin >> s;
    cout<< "Nodul final: "<<'\n';
    int f;
    cin>>f;
    moore(s);
    moore_drum(f);
}
