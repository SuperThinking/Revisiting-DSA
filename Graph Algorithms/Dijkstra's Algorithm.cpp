#include<iostream>
#include<stdio.h>
using namespace std;

#define loop(i, b, a) for(int i=b; i<a; i++)

//Number of Vertices => N
#define N 9

//Denotes Infinite Distance/Disjoint Vertices => INF
#define INF 9999

int main()
{
    //a => Stores the Input Matrix
    int a[N][N];

    //distStore => Stores the final distance
    int distStore[N];

    //Taking Input and if the 2 vertices are disjoint, changing their value to INF
    loop(i, 0, N)
    {
        loop(j, 0, N)
        {
            cin>>a[i][j];
            if(a[i][j]==0){a[i][j]=INF;}
        }
        distStore[i] = 0;
    }

    ///Changed Matrix///
    /*
    loop(i, 0, N)
    {
        loop(j, 0, N)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    */

    //distFrom => Calculate Distance From 0 (Here)
    int distFrom = 0;

    //b => Stores distances one by one
    //o => Counter for b
    //lastSum => Stores the last smallest value (Used in the loops below)
    int o = 0, b[N][N], lastSum=0;

    while(o!=N)
    {
        int m = INF, mIndex = 0;
        loop(i, 0, N)
        {
            if(o==0)
            {
                b[o][i] = a[distFrom][i];
            }
            else
            {
                //Inserting Values only if the usually calculated value is less than original
                int usual = lastSum + a[distFrom][i];
                if(b[o-1][i]>usual && b[o-1][i]!=-1)
                {
                    b[o][i] = usual;
                }
                else if(b[o-1][i]==-1)
                {
                    b[o][i] = -1;
                }
                else
                {
                    b[o][i] = b[o-1][i];
                }
            }

            //Put -1 showing it is done
            if(i==distFrom){b[o][i]=-1;}

            //For Finding Minimum from the Row
            if(b[o][i]<m && b[o][i]!=-1)
            {
                m = b[o][i];
                mIndex = i;
            }

            //PRINTING//
            //cout<<b[o][i]<<"\t";
        }
        //cout<<endl;
        distStore[distFrom] = lastSum;
        lastSum = m;
        distFrom = mIndex;
        o++;
    }

    //Final Distance Output!!
    for(int i=0; i<N; i++)
    {
        cout<<i<<" => "<<distStore[i]<<endl;
    }
}