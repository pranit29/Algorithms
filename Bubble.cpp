#include<iostream>
#include<stdlib.h>
#include<omp.h>
using namespace std;

void bubble(int *, int);
void swap(int &, int &);

void bubble(int *a, int n)
{
      
          int i, j;
    for (i = 0; i < n-1; i++)    
    #pragma omp parallel for shared(a,i)
    for (j = 0; j < n-i-1; j++)
        if (a[j] > a[j+1])
            swap(a[j], a[j+1]);
}

void swap(int &a, int &b)
    {
        int test;
           test=a;
           a=b;
           b=test;
    }

  int main()
{
       int *a,n;
                 cout<<"\n enter total no of elements=>"; 
                 cin>>n;
                 a=new int[n];
       
       cout<<"\n enter elements=>";
       for(int i=0;i<n;i++)
          {
            cin>>a[i]; 
           }
       
        bubble(a,n);

         cout<<"\n sorted array is=>";
      
         for(int i=0;i<n;i++)
            {
                cout<<a[i]<<"\t";
            }
      return 0;
}