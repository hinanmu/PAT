#include <iostream>
#include <algorithm>

using namespace std;

int *input,*cbt,n,index = 0;

void levelOrder(int i)
{
    if(i > n)
    {
        return;
    }

    levelOrder(2 * i);

    cbt[i] = input[index++];

    levelOrder(2 * i + 1);
}
int main()
{

    scanf("%d",&n);
    input = new int[n];
    cbt = new int[n + 1];

    for(int i = 0;i < n;i++)
    {
        scanf("%d",&input[i]);
    }
    sort(input,input + n);

    levelOrder(1);

    for(int i = 1;i <= n;i++)
    {

        if(i < n)
        {
            printf("%d ",cbt[i]);
        }
        else
        {
            printf("%d",cbt[i]);
        }
    }
    return 0;
}
