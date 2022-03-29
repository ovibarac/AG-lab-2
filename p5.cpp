//Lab2 problema 5
//5. Pentru un graf dat să se afișeze pe ecran vârfurile descoperite de apelul recursiv al procedurii DFS_VISIT(G, u) (padurea descoperită de DFS).

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
int dist[MAX];
bool viz[MAX];

void citireGraf(){
    f>>nrV;
    int x, y;
    while(f>>x>>y){
        ma[x][y] = ma[y][x] = 1;
    }
}

void dfs_visit(int nod){
    viz[nod] = 1;
    cout<< nod<< ' ';
    for(int i = 1; i<=nrV; i++){
        if(ma[nod][i] && !viz[i]){
            dfs_visit(i);
        }
    }
}

void dfs(){
    for(int i = 1; i<= nrV; i++){
        if(!viz[i]){
            dfs_visit(i);
        }
    }
}

int main() {
    citireGraf();
    dfs();
}
