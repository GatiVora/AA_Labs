#include <iostream>
using namespace std;
int pi[5];
void kmp_pi(string P)
{
    int m = P.length()-1;
    int k=0,cnt = 0;
    pi[1] = 0;
    for(int q=2;q<=m;q++)
    {
        bool t = P[k+1]!=P[q];
        cnt++;
        
     while(k>0 && t)
     {
        k = pi[k];
        t = P[k+1]!=P[q];
        cnt++;
     }
     if(!t)
     {
         k++;
     }
     pi[q] = k;
    }
    cout<<"Count:"<<cnt<<endl;
    
}
void kmp(string P,string T)
{
    int n = T.length()-1;
    int m = P.length()-1;
    kmp_pi(P);
    int q = 0;
    for(int i=1;i<n;i++)
    {
        while(q>0 and P[q+1]!=T[i])
        {
            q = pi[q];
        }
        if(P[q+1]==T[i])
        {
            q++;
          //  cout<<q<<endl;
        }
        if(q==m)
        {
            cout<<"Pattern occurs with shift:"<<i-m<<endl;
            q = pi[q];
        }
    }
}

int main()
{
   string P = {"0acac"};
   string T = {"0acacacacacac"};
    
    kmp(P,T);

    return 0;
}



