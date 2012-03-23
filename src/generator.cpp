// *************Generator*************
//usage: generator.exe filename number_of_elements

#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{   ofstream file;
    file.open(argv[1]);
    int n=atoi(argv[2]);
    int a[n];
    for (int i=0;i<n;i++)
    {
          a[i]=rand()%20 + 1;
    }
     
   
   for (int i=0;i<n;i++)
   {
      // cout<<a[i]<<"\n";
         file<<a[i]<<"\n";

   }
   file.close();
}
