#include <iostream>
using namespace std;

unsigned int power(unsigned long int a,unsigned long int n,unsigned long int p){
    
    unsigned long int res=1;
    
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

unsigned int gcd(unsigned int a,unsigned int b){
    
 
    
    while (b != 0) {
    
     	int Temp = b;
     	b = a % b;
     	a = Temp;
    }
     return a;
}

bool isPrime(unsigned int n){
    if(n<=1 || n==4)
        return false;
    if(n<=3)
        return true;
    int k=100;
    while(k>0){
        int a=2+rand()%(n-4);
        
        if(gcd(n,a)!=1)
            return false;
        if(power(a,n-1,n)!=1)
            return false;
        k--;
    }
    return true;
}



int main() {
    // Write C++ code here
    
    srand(time(NULL));
    cout<<isPrime(1000000007);

    return 0;
}

