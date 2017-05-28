#include <iostream>
#include <string>

using namespace std;

char cal(int n)
{
    char temp;
    if(n >= 10)
    {
        temp = n - 10 + 'A';

    }
    else
    {
        temp = '0' + n;
    }
     return temp;
}


int main()
{
    int r,g,b;
    scanf("%d%d%d",&r,&g,&b);
    cout<<"#"<<cal(r / 13)<<cal(r % 13)<<cal(g / 13)<<cal(g % 13)<<cal(b / 13)<<cal(b % 13);

    return 0;
}

