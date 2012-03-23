#include <stdlib.h>
#include <iostream>
#include <vector>
#include <windows.h>
#include <stdio.h>
using namespace std;


void SortShell (int a[], int n) {
       
int i,j,k,step;
  int tmp;
  step=n / 2; 
  while (step>=1){
    k=step;
    for (int i=k+1;i<n;i++)
     {
      tmp=a[i]; j=i-k;
      while ((j>0) && (tmp<a[j])){
        a[j+k]=a[j]; j=j-k;
        }
      a[j+k]=tmp;
                 }

    step=3*step / 5;  
}
} 

int main(int argc, char *argv[])
{
    FILE* f;
     vector<int> values;
     int dat;
     char buf[10];
     f = fopen(argv[1], "r");
     values.push_back(0);
     while (fscanf(f,"%i",&dat)!=EOF)
     { 
             values.push_back(dat);
     }
     int a[values.size()];
     for (int i=0;i<values.size();i++)
     a[i]=values[i];
     int n=values.size();
    
    LARGE_INTEGER timerFrequency ,timeStart,timeStop;
     QueryPerformanceFrequency(&timerFrequency);
     QueryPerformanceCounter(&timeStart);
      SortShell(a,n);
     QueryPerformanceCounter(&timeStop);
     
     double const t(static_cast<double>(timeStop.QuadPart-timeStart.QuadPart)/timerFrequency.QuadPart);
     
     cout <<t;
       if(n==0)
    //for (int i=1;i<n;i++)
     //cout<<a[i]<<"\n";
    //else
     cout<<"File not read";
}
