#include <iostream>
#include<bits/stdc++.h>

using namespace std;

#define N 6

int G[N][N]={{0,1,0,0,0,0},{1,0,1,0,1,0},{0,1,0,1,0,0},{0,0,1,0,1,0},{0,1,0,1,0,1},{0,0,0,0,1,0}};


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



int main()
{
   
    srand(time(NULL));

    int m=count_edges();
    
    cout<<"Number of Edges:"<<m<<endl;   
    
    int i,j;int n=N;
    int edges[m][2];
    create_edge_matrix(edges);
    for(int i=0;i<m;i++)
    {
        for(j=0;j<2;j++)
        {
            cout<<edges[i][j];
        }
        cout<<endl;
    }

    vector<int> res;
    int temp = m;
    
    while(temp>0){
        
        int x=rand()%m;
        int u = edges[x][0];
        int v = edges[x][1];
        cout<<"Edge selected:"<<u<<v<<endl; 
        
        if(u == -1 || v == -1){
           temp --;
            continue;
        }
        res.push_back(u);
        res.push_back(v);
        for(int i=0;i<m;i++){
            for(int j=0;j<2;j++){
                if(edges[i][j] == u || edges[i][j] == v)
                {
                    if(j==0){
                      edges[i][j]=-1;
                      edges[i][j+1]=-1;
                    }else{
                       edges[i][j]=-1;
                      edges[i][j-1]=-1;
                    }
                    
                }
            }
        }
        
         for(int i=0;i<m;i++)
        {
            for(j=0;j<2;j++)
            {
                cout<<edges[i][j];
            }
            cout<<endl;
        }
        
       
        temp--;
    }
    
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    
    


    return 0;
}


