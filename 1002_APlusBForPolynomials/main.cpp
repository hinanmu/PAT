#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    int line1Length = 0;
    int line2Length = 0;
    int index = 0;
    double value = 0.0;
    double p[1111];
    int count = 0;

    for(int i = 0;i < 1111;i++)
    {
        p[i] = 0.0;
    }
    cin>>line1Length;
    for(int i = 0;i < line1Length;i++)
    {
        cin>>index;
        cin>>value;
        p[index] += value;
    }

    cin>>line2Length;
    for(int i = 0;i < line2Length;i++)
    {
        cin>>index;
        cin>>value;
        p[index] += value;
    }

    for(int i = 0;i < 1111;i++)
    {
        if(p[i] != 0)
        {
            count++;
        }
    }
    cout<<count;

    for(int i = 1110 ;i > -1 ;i--)
    {
        if(p[i] != 0)
        {
            cout<<" ";
            cout<<i<<" ";
            cout<<fixed<<setprecision(1)<<p[i];
        }
    }
    return 0;
}

