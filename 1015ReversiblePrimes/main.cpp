#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

bool isPrime(long x)
{
    if(x == 0 || x == 1)
    {
        return false;
    }
    else
    {
        int sqrtX = sqrt(x);
        for(long j = 2;j <= sqrtX;j++)
        {
            if(x % j == 0)
            {
                return false;
            }
        }
    }
    return true;
}

long cal(long x,int radix)
{
    long temp;
    temp = x % radix;
    while(x / radix > 0)
    {
        x = x / radix;
        temp = temp * radix + x % radix;

    }
    return temp;

}
int main()
{
    char numChar[6];
    long num2 = 0;
    int radix;
    long num;
    vector<long> inputNum;
    vector<long> inputRadix;

    scanf("%ld",&num);
    while(num >= 0)
    {
        scanf("%d",&radix);
        inputNum.push_back(num);
        inputRadix.push_back(radix);

        scanf("%ld",&num);
    }

    for(int i = 0;i < inputNum.size();i++)
    {
        num = inputNum[i];
        sprintf(numChar,"%ld",num);
        radix = inputRadix[i];

        num2 = cal(num,radix);
        if(isPrime(num) && isPrime(num2))
        {
            printf("%s\n","Yes");
        }
        else
        {
             printf("%s\n","No");
        }


    }
    return 0;
}
