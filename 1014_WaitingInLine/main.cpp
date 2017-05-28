#include <iostream>
#include <queue>
#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

void format(int n)
{
    if(n == 0)
        printf("Sorry\n");
    else
        printf("%02d:%02d\n",8+n/60,n%60);
}

int main()
{
    int n,m,k,q;
    int customers[1001];
    int queries[1001];
    int time = 0;
    int finishedtTime[1001];

    scanf("%d%d%d%d",&n,&m,&k,&q);

    for(int i = 1;i <= k;i++)
    {
        scanf("%d",&customers[i]);
    }
    for(int i = 1;i <= q;i++)
    {
        scanf("%d",&queries[i]);
    }

    queue<int> wait;
    vector<queue<int> > service(n + 1);
    queue<int> nextWindow;
    int presentWin = 1;
    int presentPersition = 1;
    int minTime = 0;

    for(int i = 1; i <= k; i++)
    {
        if(i <= n * m)
        {
            int index = 0;
            index =  (i - 1) % n + 1;
           service[index].push(i);
        }
        else
        {
            wait.push(i);
        }
    }

    int *line = new int[n + 1];
    memset(line,0,sizeof(line));
    for(int i = 0; i < n + 1;i++)
    {
        line[i] = 0;
    }

    while(!wait.empty())
    {
        int tempMin = 9999;
        for(int i = 1;i <= n;i++)
        {
            if(line[i] == 0)
            {
                int temp = service[i].front();
                line[i] = customers[service[i].front()];
            }

            if(tempMin > line[i])
            {
                tempMin = line[i];
            }
        }

        time = time + tempMin;

        for(int i = 1;i <= n;i++)
        {

            line[i] = line[i] - tempMin;
            if(line[i] == 0)
            {
                int temp = service[i].front();
                finishedtTime[service[i].front()] = time;
                service[i].pop();
                if(!wait.empty())
                {
                    int tempW = wait.front();
                    service[i].push(wait.front());
                    wait.pop();
                }
            }
        }

    }

    for(int i = 1;i <= n;i++)
    {
        if(line[i] != 0)
        {
             finishedtTime[service[i].front()] = time + line[i];
             service[i].pop();
        }
    }


    for(int i = 1;i <= n;i++)
    {
        for(int j = 0;j < service[i].size();)
        {
            int temp =
            finishedtTime[service[i].front()] = customers[service[i].front()] + time + line[i];
            line[i] = line[i] + customers[service[i].front()];
            service[i].pop();
        }
    }

    for(int j = 1;j <= q;j++)
    {
        int i = queries[j];

        if(finishedtTime[i] - customers[i] >= 540)
        {
            finishedtTime[i] = 0;
        }
        format(finishedtTime[i]);
    }

    return 0;
}
