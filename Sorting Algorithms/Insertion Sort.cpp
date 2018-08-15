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

    loop(i, 0, n-1)
    {
        if(a[i]>a[i+1])
        {
            int j=i+1;
            while(j>0 && a[j]<a[j-1])
            {
                swap(a[j], a[j-1]);
                j--;
            }

            //Remove comment below to see each step
            // loop(u, 0, n)
            // {
            //     cout<<a[u]<<"\t";
            // }
            // cout<<endl;
        }
    }

    loop(i, 0, n)
    {
        cout<<a[i]<<"\t";
    }
}