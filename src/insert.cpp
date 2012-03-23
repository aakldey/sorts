#include <stdlib.h>
#include <iostream>
#include <vector>
#include <windows.h>
#include <stdio.h>
using namespace std;


void insertSort(int a[], int size) 
{ int tmp;int j;
for (int i=2;i<size;i++) {
    tmp=a[i];  j=i-1;
    a[0]=tmp;  
    while (tmp<a[j])
	{
      a[j+1]=a[j];
      j=j-1;
    }
    a[j+1]=tmp; 
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
      insertSort(a,n);
     QueryPerformanceCounter(&timeStop);
     
     double const t(static_cast<double>(timeStop.QuadPart-timeStart.QuadPart)/timerFrequency.QuadPart);
     
     cout <<t;
       if(n==0)
    //for (int i=1;i<n;i++)
     //cout<<a[i]<<"\n";
    //else
     cout<<"File not read";
}
