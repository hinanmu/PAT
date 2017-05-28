#include <iostream>

#define infinity 9999
using namespace std;

//extern int findRouteFlag[500];


int main()
{

    int eNum;
    int vNum;
    int fromV;
    int toV;

    cin>>vNum>>eNum>>fromV>>toV;

    int *dis = new int[vNum];
    int *flag = new int[vNum];
    int *rescueNum = new int[vNum];
    int **edg = new int*[vNum];
    int *totalRescueNum = new int[vNum];
    int *pathNum = new int[vNum];

    for(int i = 0; i < vNum; i++)
    {
        edg[i] = new int[vNum];
    }

    for(int i = 0; i < vNum; i++)
    {
        cin>>rescueNum[i];
    }
    for (int i = 0; i < vNum; i++)
    {
        for (int j = 0; j < vNum; j++)
        {
            edg[i][j]=infinity;
        }
    }

    for(int i = 0; i < eNum; i++)
    {
        int from;
        int to;
        int length;
        cin>>from>>to>>length;
        edg[from][to] = length;
        edg[to][from] = length;
    }

    for(int i = 0; i < vNum; i++)
    {
        flag[i] = 0;
    }

    for(int i = 0; i < vNum; i++)
    {
        dis[i] = infinity;
    }

    /*    for(int i = 0;i < vNum;i++)
        {
            for(int j = 0;j < vNum;j++)
            {
                printf("%d ",edg[i][j]);
            }
            printf("\n");
        }
    */
    for(int i = 0; i < vNum; i++)
    {
         totalRescueNum[i] = 0;
         pathNum[i] = 0;
    }

//    for(int i = 0; i < vNum; i++)
//    {
//        cout<<totalRescueNum[i]<<" ";
//    }

    cout<<endl;
    dis[fromV] = 0;
    totalRescueNum[fromV] = rescueNum[fromV];
    pathNum[fromV] = 1;
    int min;
    int u;

    for(int i = 0; i < vNum; i++)
    {

        min = infinity;
        for(int j = 0; j < vNum; j++)
        {
            if(flag[j] == 0 && dis[j] < min)
            {
                min = dis[j];
                u = j;
            }
        }
        flag[u] = 1;

        for(int j = 0; j < vNum; j++)
        {

            if(edg[u][j] < infinity && flag[j] == 0)
            {
                if(dis[j] > dis[u] + edg[u][j])
                {
                    dis[j] = dis[u] + edg[u][j];
                    totalRescueNum[j] = totalRescueNum[u] + rescueNum[j];
                    pathNum[j] = pathNum[u];

                }
                else if(dis[j] == dis[u] + edg[u][j])
                {
                    if (totalRescueNum[j] < totalRescueNum[u] + rescueNum[j])
                    {
                        totalRescueNum[j] = totalRescueNum[u] + rescueNum[j];
                    }
                    pathNum[j] += pathNum[u];
                }

            }

        }
    }


//    for(int i = 0; i < vNum; i++)
//    {
//        printf("%d ",dis[i]);
//    }
//    for(int i = 0; i < vNum; i++)
//    {
//        printf("%d ",totalRescueNum[i]);
//    }

    cout<<pathNum[toV]<<" "<<totalRescueNum[toV];

    return 0;
}
