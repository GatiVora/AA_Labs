// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
#define n 6
using namespace std;

int parent[n];

bool bfs(int rgraph[n][n],int s,int t,int parent[n]){
    int visited[n];
    for(int i=0;i<=n-1;i++){
    
        visited[i]=0;
    }
    queue<int> q;
    q.push(s);
    visited[s]=1;
    parent[s]=-1;
    
    while(!q.empty()){
        int u= q.back();
        q.pop();
        for(int v=0;v<n;v++){
            if(visited[v]==0 && rgraph[u][v]>0){
                if(v==t){
                    parent[v]=u;
                    return true;
                }
                q.push(v);
                visited[v]=1;
                parent[v]=u;
            }
        }
    }
    return false;
    
    
    
}

int ford_fulkerson(int G[n][n],int s,int t){
    int rgraph[n][n];
    for(int u=0;u<n;u++){
        for(int v=0;v<n;v++){
            rgraph[u][v]=G[u][v];
        }
    }
    // int parent[n];
    int max_flow=0;
    int path_flow;
    while(bfs(rgraph,s,t,parent)){
        path_flow=INT_MAX;
        int u;
        for(int v=t;v!=s;v=parent[v]){
            u=parent[v];
            path_flow=min(path_flow,rgraph[u][v]);
        }
        for(int v=t;v!=s;v=parent[v]){
            u=parent[v];
            rgraph[u][v]-=path_flow;
            rgraph[v][u]+=path_flow;
        }
        max_flow+=path_flow;
    }
    return max_flow;
}

int main() {
    
    int G[n][n]={{0,16,13,0,0,0},
                     {0,0,10,12,0,0},
                     {0,4,0,0,14,0},
                     {0,0,9,0,0,20},
                     {0,0,0,7,0,4},
                     {0,0,0,0,0,0}};
                     
    int result=ford_fulkerson(G,0,5);
    cout<<result;

    return 0;
}