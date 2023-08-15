#include <iostream>
#include<bits/stdc++.h>


using namespace std;

void Naive(string t,string p){
    int n=t.length();
    int m=p.length();
    
    for(int s=0;s<=(n-m);s++){
        int i=0,j=0;
        
        while(j<m && t[s+i]==p[j]){
            i++;j++;
        }
        if(j==m){
            cout<<"Pattern occurs with shift "<<s;
        }
    }
}

int Horsepool(string t,string p){
    int n=t.length();
    int m=p.length();
    
    int sigma[26]={m};
    
    for(int i=0;i<26;i++){
        sigma[i]=m;
    }
    
    for(int i=0;i<m-1;i++){
        sigma[p[i]-'a']=m-1-i;
    }
    // for(int i=0;i<26;i++){
    //     cout<<sigma[i]<<" ";
    // }
    int j=0;
    // int cnt=0;
    while(j+m<=n){
        if(p[m-1]==t[j+m-1]){
            int i=m-2;
            while(i>=0 &&p[i]==t[j+i]){
                i=i-1;
                
            }
            if(i==-1)
                return j;
        }
        if(t[j+m-1] == ' ')
           j=j+m;
        else{
            
            j=j+sigma[t[j+m-1]-'a'];
        }
    }
    return j;
}

int main()
{
    
    string t="jim saw me in a book shop";
    string p="book";
    
    // Naive(t,p);
    cout<<Horsepool(t,p);

    return 0;
}

