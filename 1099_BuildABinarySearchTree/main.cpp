#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int *input,index = 0;
struct node{

    int val;
    int left;
    int right;
}node[100];

void order(int i)
{
    if(node[i].left != -1)
    {
        order(node[i].left);
    }

    int temp= input[index++];
    node[i].val = temp;
    if(node[i].right != -1)
    {
        order(node[i].right);
    }
}

int main()
{
    int n;
    int left,right;

    scanf("%d",&n);
    input = new int[n];
    for(int i = 0;i < n;i++)
    {
        scanf("%d%d",&left,&right);
        node[i].left = left;
        node[i].right = right;
    }

    for(int i = 0;i < n;i++)
    {
        scanf("%d",&input[i]);
    }

    sort(input,input + n);
    order(0);

    queue<int> q;
    index = 0;
    q.push(0);

    while(!q.empty())
    {
        int temp = q.front();
        q.pop();

        input[index++] = node[temp].val;
        if(node[temp].left != -1)
        {
            q.push(node[temp].left);
        }
        if(node[temp].right != -1)
        {
            q.push(node[temp].right);
        }
    }

    for(int i = 0;i < n;i++)
    {
        if(i == n - 1)
        {
            printf("%d",input[i]);
        }
        else
        {
            printf("%d ",input[i]);
        }
    }
    return 0;
}
