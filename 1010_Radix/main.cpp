#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <string.h>

using namespace std;

int main()
{

    char n1[10];
    char n2[10];
    int tag;
    long long radix;
    scanf("%s%s%d%d",n1,n2,&tag,&radix);

    long long int num1 = 0;
    char n[10];
    if(tag == 1)
    {
        for(int i = strlen(n1) - 1;i >= 0;i--)
        {
            int temp;
            if(n1[i] > '9')
            {
                temp = n1[i] - 'a' + 10;
            }
            else
            {
                temp = n1[i] - '0';
            }
            num1 +=  pow(radix,strlen(n1) - 1 - i) * temp;
        }
        memcpy(n, n2, sizeof(n2));
    }
    else
    {
        for(int i = strlen(n2) - 1;i >= 0;i--)
        {
            int temp;
            if(n2[i] > '9')
            {
                temp = n2[i] - 'a' + 10;
            }
            else
            {
                temp = n2[i] - '0';
            }
            num1 +=  pow(radix,strlen(n2) - 1 - i) * temp;
        }
        memcpy(n, n1, sizeof(n1));
    }

  //  cout<<num1;
    long long int num2 = 0;
    long long minRadix = 1;
    long long maxRadix = num1 + 1;
    while(minRadix <= maxRadix)
    {
        num2 = 0;
        radix = (minRadix + maxRadix) / 2;

        for(int i = strlen(n) - 1;i >= 0;i--)
        {
            int temp;
            if(n[i] > '9')
            {
                temp = n[i] - 'a' + 10;
            }
            else
            {
                temp = n[i] - '0';
            }
            num2 +=  pow(radix,strlen(n) - 1 - i) * temp;
        }

        if(num1 == num2)
        {
            printf("%lld",radix);
            break;
        }

        if(num1 > num2 && num2 > 0)
        {
            minRadix = radix + 1;
        }
        else
        {
            maxRadix = radix - 1;
        }

    }


    if(num1 != num2)
    {
        printf("%s","Impossible");
    }
    return 0;
}
