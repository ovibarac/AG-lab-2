//Lab2 problema 4
//4. Pentru un graf dat să se afișeze pe ecran vârfurile descoperite de algoritmul BFS și distanța față de vârful sursă (arborele descoperit).

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
queue<int> q;

void citireGraf(){
    f>>nrV;
    int x, y;
    while(f>>x>>y){
        ma[x][y] = ma[y][x] = 1;
    }
}

void printMA(){
    for(int i = 1; i <= nrV; i++){
        for( int j = 1; j<=nrV; j++){
            cout<<ma[i][j]<<' ';
        }
        cout<<'\n';
    }
}

void bfs(int start){
    for(int i = 1; i<= nrV; i++){
        dist[i] = INF;
    }

    q.push(start);
    viz[start] = true;
    dist[start] = 0;

    while(!q.empty()){
        int nod = q.front();
        q.pop();

        for(int i = 1; i<=nrV; i++){
            if(ma[nod][i] && !viz[i]){
                dist[i] = dist[nod]+1;
                viz[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    citireGraf();
    cout<<"Start: ";
    int s;
    cin>>s;
    bfs(s);
    for(int i = 1; i<=nrV; i++){
        if(viz[i]){
            cout<<i<<' '<< dist[i]<<'\n';
        }
    }
}
