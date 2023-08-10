// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define N 4
int G[N][N]={{0,1,1,1},{1,0,1,0},{1,1,0,1},{1,0,1,0}};
int G1[N][N];

int count_edges()
{
    int counter=0;
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=i+1;j<N;j++)
        {
            if(G[i][j]==1)
               counter++;
        }
    }
    return counter;
}

void create_edge_matrix(int E[][2])
{
    int i,j;int x=0;
    for(i=0;i<N;i++)
    {
        for(j=i+1;j<N;j++)
        {
            if(G[i][j]==1)
            {
               E[x][0]=i;
               E[x][1]=j;
               x++;
            }
        }
    }
    
}

int main() {
    
     srand(time(NULL));
    // int parent[N]={0,1,2,3};
    int m=count_edges();
    cout<<"Number of Edges"<<m<<endl;   
    int i,j;int n=N;
    int edges[m][2];
    create_edge_matrix(edges);
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<2;j++){
    //         cout<<edges[i][j];
    //     }
    //     cout<<endl;
    // }
    
   
    // cout<<u<<v;
    int k=0;
    int mini=INT_MAX;
    while(k< 100 * n *(n)){
    
    while(n>2){
        int x=rand()%m;
        int u=edges[x][0];
        int v=edges[x][1];
        
        
         int cnt=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            cnt=0;
            if(i==u && j==v)
              G1[i][j]=G1[j][i]=0;
            else if(i==u || i==v)
            {
                if(G[u][j]>0)
                {
                    cnt+=G[u][j];
                }
                if(G[v][j]>0)
                {
                    cnt+=G[v][j];
                }
                if(u<j)
                {
                   G1[u][j]=cnt; 
                }
                else
                {
                    G1[j][u]=cnt;
                }
                if(v<j)
                {
                   G1[v][j]=cnt; 
                }
                else
                {
                    G1[j][v]=cnt;
                }
                //G1[u][j]=G1[v][j]=cnt;
            }
            else if (j==u || j==v)
            {
                if(G[u][i]>0)
                {
                    cnt+=G[u][i];
                }
                if(G[v][i]>0)
                {
                    cnt+=G[v][i];
                }
                if(i<u)
                {
                    G1[i][u]=cnt;
                }
                else
                {
                    G1[u][i]=cnt;
                }
                if(i<v)
                {
                    G1[i][v]=cnt;
                }
                else
                {
                    G1[v][i]=cnt;
                }
                //G1[i][u]=G1[i][v]=cnt;
                
            }
            else
            {
                G1[i][j]=G[i][j];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<G1[i][j]<<" ";
        }
        cout<<endl;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i>=j)
            {
                G1[i][j]=G1[j][i];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<G1[i][j]<<" ";
        }
        cout<<endl;
    }
     x=n-1;
    int G2[x][x];
    int a=0,b=0;
    for(i=0;i<n;i++)
    {
        if (i==v) continue;
        b=0;
        for(j=0;j<n;j++)
        {
            if (j==v) continue;
            else
            //if(i!=v and j!=v)
            {
                G2[a][b]=G1[i][j];
                b++;
            }
        }
        a++;
    }
    for(i=0;i<x;i++)
    {
        for(j=0;j<x;j++)
        {
          cout<<G2[i][j]<<" ";
        }
        cout<<endl;
    }
    for(i=0;i<x;i++)
    {
        for(j=0;j<x;j++)
        {
          G[i][j]=G2[i][j];
        }
    }
    n=n-1;
    }
    
    
    // cout<<"Min-Cut="<<" "<<G[0][1];
    mini=min(mini,G[0][1]);
    k++;
    }
    
    cout<<"Min-Cut="<<" "<<mini;
    return 0;
        
        
    }


