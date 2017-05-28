#include <iostream>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);

    int *list = new int[n + 1];
    list[0] = 0;
    for(int i = 1;i < n + 1;i++)
    {
        scanf("%d",&list[i]);
    }
    int cost = 0;

    for(int i = 1;i < n + 1;i++)
    {
        if(list[i] > list[i - 1])
        {
            cost += (list[i] - list[i - 1]) * 6 + 5;
        }
        if(list[i] < list[i - 1])
        {
            cost += (list[i - 1] - list[i]) * 4 + 5;
        }
        if(list[i] == list[i - 1])
        {
            cost += 5;
        }
    }


    cout <<cost;
    return 0;
}
