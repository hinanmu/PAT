#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> tree;
int n;
int m;

vector<int> BFS(int root)
{
    queue<int> q;
    q.push(root);
    vector<int> result(n,0);

    int levelCount = 0;
    while(!q.empty())
    {

        int length = q.size();
        for(int i = 0;i < length;i++)
        {
            int temp = q.front();
            q.pop();

            if(tree[temp].size() == 0)
            {
                result[levelCount] += 1;
            }
            else
            {
                for(int j = 0;j < tree[temp].size();j++)
                {
                    q.push(tree[temp][j]);
                }

            }
        }

        levelCount++;
    }
    result.resize(levelCount);
    return result;
}

int main()
{
    scanf("%d%d",&n,&m);
    tree.resize(n + 1);
    for(int i = 0;i < m;i++)
    {
        int nodeIndex;
        int childNum;
        scanf("%d%d",&nodeIndex,&childNum);

        for(int j = 0;j < childNum;j++)
        {
            int childIndex;
            scanf("%d",&childIndex);

            tree[nodeIndex].push_back(childIndex);
        }
    }

//    for(int i = 1;i < tree.size();i++)
//    {
//        for(int j =0;j < tree[i].size();j++)
//        {
//            printf("%d ",tree[i][j]);
//        }
//        printf("\n");
//    }

    vector<int> result = BFS(1);

     printf("%d",result[0]);
    for(int i = 1;i < result.size();i++)
    {
        printf(" %d",result[i]);
    }

    return 0;
}
