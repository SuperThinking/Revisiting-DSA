#include<iostream>
using namespace std;

/*
Macro for For-Loop
*/
#define loop(i, b, a) for(int i=b; i<a; i++)

int main()
{
    int n, sorted=1;
    cout<<"Number of elements : ";
    cin>>n;
    int a[n];
    loop(i, 0, n){cin>>a[i];}

    loop(i, 0, n)
    {
        sorted = 1;
        loop(j, 0, n-1)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j], a[j+1]);
                sorted=0;
            }
        }

        if(sorted)
        {
            break;
        }
    }

    loop(i, 0, n)
    {
        cout<<a[i]<<"\t";
    }
}