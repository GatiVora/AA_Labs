#include <cstdio>
#include <ctime>
#include<iostream>

using namespace std;

int count=0;
void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}
 



int partition(int arr[],int p,int r){
    int x=arr[r];
    int i=p-1;
    int j;
  
    for(int j=p;j<=(r-1);j++){
        count++;
        if(arr[j]<=x){
            i++;
            swap(&arr[i],&arr[j]);
        }
        swap(&arr[i+1],&arr[r]);
    }
    return(i+1);
}

int R_partition(int arr[] ,int p,int r){
    int i=p+rand()%(r-p+1);
    swap(&arr[i],&arr[r]);
    return(partition(arr,p,r));
}


void Randomised_QS(int arr[],int p,int r){
    if(p<r){
        int q=R_partition(arr,p,r);
        Randomised_QS(arr,p,q-1);
        Randomised_QS(arr,q+1,r);
    }
}


int main() {

    //printf("%d",rand());
    // int p=3,r=15;
    // srand(time(NULL));
    // for(int i=0;i<5;i++){
    //     printf("%d\n",p+rand()0%(r-p+1));
    // }
    srand(time(NULL));
    int arr[1002];
   
    for(int i=1;i<=1000;i++){
        arr[i]=i;
    }
    int n = sizeof(arr) / sizeof(arr[0]);
     Randomised_QS(arr,1,1000);
     
    //  printf("%d",count);
     cout<<count;


    //  for(int i=0;i<=n;i++){
    //      printf("%d ",arr[i]);
    //  }
    

    return 0;
}

