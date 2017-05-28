#include <iostream>
#include <cstring>

using namespace std;

int citiesMap[1000][1000];
int visited[1000];
int n,m,k;

void dfs(int v)
{
    visited[v] = 1;
    for(int i = 1;i <= n;i++)
    {
        if(citiesMap[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}
int main()
{

    scanf("%d%d%d",&n,&m,&k);

    int a,b;
    for(int i = 0;i < m;i++)
    {
        scanf("%d%d",&a,&b);
        citiesMap[a][b] = 1;
        citiesMap[b][a] = 1;
    }

    int c;
    while(k >0 && m > 0)
     {
        k--;
        scanf("%d",&c);
        int count=0;
        memset(visited,0,sizeof(visited));
        int temp[n+1];
        for(int i = 1;i <= n;i++)
        {
            temp[i]=citiesMap[i][c];
            citiesMap[i][c] = 0;
            citiesMap[c][i] = 0;
        }


        for(int i = 1;i<= n;i++)
        {
            if(visited[i] == 0)
            {
                dfs(i);
                count++;
            }
        }

        for(int i = 1;i <= n;i++)
        {
            citiesMap[i][c] = temp[i];
            citiesMap[c][i] = temp[i];
        }
        cout << count-2 << endl;
    }
    if(m == 0)
    {
        printf("%d",0);
    }
    return 0;
}
