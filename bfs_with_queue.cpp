/*
END THE CONFUSION: visited[v]=1 is used during the adjacent node exploration rather than poping
otherwise, same node can get in the queue, and will be visited multiple times
*/

#include <bits/stdc++.h>
#define MAX_NODES 1003
using namespace std;
//queue
int q[MAX_NODES];
int sz = 0, front, rear;
int max_size = MAX_NODES;

//bfs
int adj[MAX_NODES][MAX_NODES];
int nV, nE;

bool isFull()
{
    if(sz >= max_size){
        return true;
    }
    return false;
}

bool isEmpty()
{
    if(sz == 0){
        return true;
    }
    return false;
}

void push(int x)
{
    if(isFull()){
        cout << "Overflow" << endl;
        return;
    }
    q[rear] = x;
    rear++;
    sz++;
    if(rear >= max_size){
        rear %= max_size;
    }
}

int pop()
{
    if(isEmpty()){
        cout << "Empty" << endl;
        return -1;
    }
    int ret =q[front];
    sz--;
    front++;
    if(front >= max_size){
        front%= max_size;
    }
    return ret;
}


void init()
{
    front = rear = 0;
    sz = 0;
    max_size = 5;
}

void display_queue()
{
    int f=front, r=rear;

    for(int i=0; i<sz; i++){
        cout << q[f] << " ";
        f++;
        if(f >= max_size){
            f%= max_size;
        }
    }
    cout << endl;

}

void bfs(int start)
{
    int vis[MAX_NODES];
    for(int i=0; i<MAX_NODES; i++)vis[i] = 0;
    push(start);
    vis[start] = 1;

    while(!isEmpty()){
        int u = pop();
        cout << u << " ";
        for(int i=0; i<nV; i++){
            if(adj[u][i]){ //enter if value is not zero
                int v = i;
                if(!vis[v]){
                    push(v);
                    vis[v] = 1;

                }
            }
        }
    }
    cout << endl;
}

void display_adj()
{
    for(int i=0; i<nV; i++){
        for(int j=0; j<nE; j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    init();
    cin >> nV >> nE;
    for(int i=0; i<nE; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;


    }
    display_adj();
    bfs(0);



}
