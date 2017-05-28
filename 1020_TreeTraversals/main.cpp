#include <iostream>
#include <queue>

using namespace std;

struct Node{
    Node(){
        left = NULL;
        right = NULL;
    }
    int val;
    Node* left;
    Node* right;
};

Node* constructTree(int* postOrder,int* inOrder,int postStart,int postEnd,int inStart,int inEnd)
{
    Node* root = new Node();

    if(postStart > postEnd || inStart > inEnd)
    {
        return NULL;
    }

    root->val = postOrder[postEnd];

    int val = root->val;

    if(postStart == postEnd)
    {
        return root;
    }
    for(int i = inStart;i <= inEnd;i++)
    {
        if(inOrder[i] == postOrder[postEnd])
        {
            root->left = constructTree(postOrder,inOrder,postStart,postStart + i - inStart - 1,inStart,i - 1);
            root->right = constructTree(postOrder,inOrder,postStart + i - inStart,postEnd - 1,i + 1,inEnd);
            break;
        }
    }

    return root;
}
int main()
{
    int n;
    scanf("%d",&n);
    int* postOrder = new int[n];
    int* inOrder = new int[n];

    for(int i = 0;i < n;i++)
    {
        scanf("%d",&postOrder[i]);
    }
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&inOrder[i]);
    }

    Node* root = new Node();
    root->val = postOrder[n - 1];
    int val = root->val;

    for(int i = 0;i < n;i++)
    {
        if(postOrder[n - 1] == inOrder[i])
        {
            root->left = constructTree(postOrder,inOrder,0,i - 1,0,i - 1);
            root->right = constructTree(postOrder,inOrder,i,n - 2,i + 1,n - 1);
        }
    }

    queue<Node*> level;
    level.push(root);
    int num = 0;
    while(!level.empty())
    {
        Node* temp = new Node();
        temp = level.front();
        level.pop();
        int val2 = temp->val;
        if(temp->left != NULL)
        {
            level.push(temp->left);
        }
        if(temp->right != NULL)
        {
            level.push(temp->right);
        }

        num++;
        if(num == n)
        {
            printf("%d",temp->val);
        }
        else
        {
            printf("%d ",temp->val);
        }
    }


    return 0;
}
