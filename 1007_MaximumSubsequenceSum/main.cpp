#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
     int *num = new int[n];

    for(int i = 0;i < n;i++)
    {
        scanf("%d",&num[i]);
    }

    int begin = 0;
    int end = 0;
    int sum = 0;
    int max = 0;
    int maxLength = 0;
    int length = 0;
    int maxBegin = 0;
    int maxEnd = 0;
    int flagAllNonNegtive = 1;
    int flag = 0;
    for(int i = 0;i < n;i++)
    {
        sum += num[i];

        if(num[i] >= 0)
        {
            flagAllNonNegtive = 0;
        }


        if(sum < 0)
        {
            sum = 0;
            begin = i + 1;
        }

        if(sum == 0 && num[i] == 0)
        {
            if(flag == 0)
            {
                maxBegin = i;
                maxEnd = i;
                flag = 1;
            }
        }

        if(max < sum)
        {
            max = sum;
            end = i;
            length = end - begin + 1;
            if(length > maxLength)
            {
                maxLength = length;
                maxBegin = begin;
                maxEnd = end;
            }
        }
    }

    if(max == 0 && flagAllNonNegtive == 1)
    {
        maxBegin = 0;
        maxEnd = n - 1;
    }
    cout <<max<<" "<<num[maxBegin]<<" "<<num[maxEnd];
    return 0;
}
