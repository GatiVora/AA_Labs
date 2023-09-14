
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
struct Point{
    int x;
    int y;
}P[10];
int main()
{
   int n=3;
   float d_min = 100.00;
   int ans_i,ans_j;
   P[1].x = 2;
   P[1].y = 2;
   P[2].x = 4;
   P[2].y = 4;
   P[3].x = 5;
   P[3].y = 6;
   
   for(int i=1;i<=n-1;i++)
   {
       for(int j=i+1;j<=n;j++)
       {
           cout<<i<<" "<<j<<endl;
           int x1 = P[i].x;
           int y1 = P[i].y;
           int x2 = P[j].x;
           int y2 = P[j].y;
          // cout<<x1<<" "<<x2<<" "<<y1<<" "<<y2<<endl;
           float d = sqrt(pow((x1-x2),2) + pow((y1-y2),2));
           cout<<d<<endl;
           if(d<d_min)
           {
               d_min = d;
               ans_i = i;
               ans_j = j;
           }
           
       }
   }
   cout<<"Min Distance:"<<ans_i<<" "<<ans_j;
    return 0;
}
