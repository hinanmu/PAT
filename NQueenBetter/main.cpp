#include <iostream>

using namespace std;

const int maxn = 11;
int n,P[maxn],hashTable[maxn] = {false};
int count;

void generateP(int index)
{
    if(index == n + 1)
    {
        count++;
        return;
    }
    for(int x = 1; x <= n; x++)
    {
        if(hashTable[x] == false)
        {
            bool flag = true;
            for(int pre = 1; pre < index; pre++)
            {
                if(abs(index - pre) == abs(x - P[pre]))
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                P[index] = x;
                hashTable[x] = true;
                generateP(index + 1);
                hashTable[x] = false;
            }
        }

    }
}


int main()
{
    n = 8;
    generateP(1);
    printf("%d",count);
    return 0;
}
