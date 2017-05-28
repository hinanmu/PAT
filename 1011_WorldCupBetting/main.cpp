#include <iostream>

using namespace std;

int main()
{
    double game1[3];
    double game2[3];
    double game3[3];
    double money = 1.00;
    double max = 0.00;
    char result;

    scanf("%lf%lf%lf",&game1[0],&game1[1],&game2[2]);
    scanf("%lf%lf%lf",&game2[0],&game2[1],&game2[2]);
    scanf("%lf%lf%lf",&game3[0],&game3[1],&game3[2]);

    for(int i = 0; i < 3;i++)
    {
        if(max < game1[i])
        {
            max = game1[i];
            switch(i)
            {
            case 0:
                result = 'W';
                break;
            case 1:
                result = 'T';
                break;
            case 2:
                result = 'L';
                break;
            }
        }
    }
    printf("%c ",result);
    money *=max;
    max = 0.0;
    for(int i = 0; i < 3;i++)
    {
        if(max < game2[i])
        {
            max = game2[i];
            switch(i)
            {
            case 0:
                result = 'W';
                break;
            case 1:
                result = 'T';
                break;
            case 2:
                result = 'L';
                break;
            }
        }
    }
    printf("%c ",result);
    money *= max;
    max = 0.0;
    for(int i = 0; i < 3;i++)
    {
        if(max < game3[i])
        {
            max = game3[i];
            switch(i)
            {
            case 0:
                result = 'W';
                break;
            case 1:
                result = 'T';
                break;
            case 2:
                result = 'L';
                break;
            }
        }
    }

    printf("%c ",result);
    money *= max;

    money = (money * 0.65 - 1) * 2.0;
    printf("%.2f",money);
    return 0;
}
