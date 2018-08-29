#include<iostream>
#include<stdio.h>
#include<omp.h>
using namespace std;

#define loop(i, b, a) for(int i=b; i<a; i++)

#define N 4

int main()
{
    int a[N][N];
    loop(i, 0, N)
    {
        loop(j, 0, N)
        {
            cin>>a[i][j];
        }
    }
    
    
}