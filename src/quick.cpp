#include <stdlib.h>
#include <iostream>
#include <vector>
#include <windows.h>
#include <stdio.h>
using namespace std;


void qs(int *items, int left, int right)
{
   int i, j;
  char x, y;
 
  i = left; j = right;
  x = items[(left+right)/2];
 
  do {
    while((items[i] < x) && (i < right)) i++;
    while((x < items[j]) && (j > left)) j--;
 
    if(i <= j) {
      y = items[i];
      items[i] = items[j];
      items[j] = y;
      i++; j--;
    }
  } while(i <= j);
 
  if(left < j) qs(items, left, j);
  if(i < right) qs(items, i, right);
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
      qs(a,0,n-1);
     QueryPerformanceCounter(&timeStop);
     
     double const t(static_cast<double>(timeStop.QuadPart-timeStart.QuadPart)/timerFrequency.QuadPart);
     
     cout <<t;
       if(n==0)
    //for (int i=1;i<n;i++)
     //cout<<a[i]<<"\n";
    //else
     cout<<"File not read";
}
