#include <iostream>

using namespace std;

 int power(int a,  int n,  int p){
    
      int res=1;
    
    a=a%p;
    
    while(n>0){
        if(n&1){
            res=(res*a)%p;
            
          
        }
        n=n/2;
          a=(a*a)%p;
    }
    
    return res;
    
}


void Rabin_Karp(string p,string t ,int d, int q){
    
    int m=p.length();
    int n=t.length();
    
    int h= power(d,m-1,q);
    
    int temp=m+n-1;
    
    int pt=0;
    int t_s[temp]={0};
    
    for(int i=0;i<m;i++){
        pt=((d * pt)+(p[i]-'0')) % q;
        t_s[0]=((d * t_s[0])+(t[i]-'0'))%q;
        
        
    }
    // cout<<pt<<t_s[0];
    
    for(int s=0;s<=(n-m);s++){
        if(pt == t_s[s]){
            cout << s;
        }
        else{
            if(s< n-m ){
                t_s[s+1]=(d *( t_s[s] -( t[s+1 ] - '0')* h) + t[s+m+1]) % q;
                
                if(t_s[s+1] < 0 ){
                    t_s[s+1]+=q;
                }
            }
        }
    }
    
}

int main()
{
    string p="789";
    string t="415789802";
    
    int d=10;
    int q=13;
    
    Rabin_Karp(p,t,d,q);
    
    
    

    return 0;
}
