#include <iostream>
#include <string.h>

using namespace std;


int main()
{
    int k1 = 0;
    int k2 = 0;
    scanf("%d",&k1);
    int *num1 = new int[k1];
    double *a = new double[k1];
    int maxIndex1;
    int maxIndex2;
    for(int i = 0;i < k1;i++)
    {
        scanf("%d",&num1[i]);
        scanf("%lf",&a[i]);
    }


    cin>>k2;
    double *b = new double[k2];
    int *num2 = new int[k2];
    for(int i = 0;i < k2;i++)
    {
        scanf("%d",&num2[i]);
        scanf("%lf",&b[i]);
    }

    double *result = new double[k1 * k2];
    int *resultNum = new int[k1 * k2];

    memset(resultNum,0,sizeof(resultNum));
    for(int i = 0;i < k1 * k2;i++)
    {
        result[i] = 0.0;
    }

    int count = 0;
    for(int i = 0;i < k1;i++)
    {
        for(int j = 0;j < k2;j++)
        {
            for(int k = 0;k < k1 * k2;k++)
            {
                if(num1[i] + num2[j] == resultNum[k])
                {
                    if(resultNum[k] == 0)
                    {
                        count++;
                    }
                    result[k] = result[k] + a[i] * b[j];
                    break;
                }
                else
                {
                    if(resultNum[k] == 0)
                    {
                        count++;
                        resultNum[k] = num1[i] + num2[j];
                        result[k] = a[i] * b[j];
                        break;
                    }
                }
            }
        }
    }

    for(int i = 0;i < k1 * k2 - 1;i++)
    {
        for(int j = 0;j < k1 * k2 - 1 - i;j++)
        {
            if(resultNum[j] < resultNum[j + 1])
            {
                double temp = resultNum[j];
                resultNum[j] = resultNum[j + 1];
                resultNum[j + 1] = temp;

                temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }

    printf("%d",count);
    for(int i = 0;i < k1 * k2;i++)
    {
        double temp = 0.0;
        if(result[i] != temp)
        {
            printf(" %d %.1f",resultNum[i],result[i]);
        }

    }

    return 0;
}
