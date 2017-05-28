#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int maxn = 100010;
const int mod = 1000000007;
char str[maxn];
int leftNumP[maxn] = {0};
int main()
{
    gets(str);
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if(i > 0){
            leftNumP[i] = leftNumP[i - 1];
        }

        if(str[i] == 'P'){
            leftNumP[i]++;
        }
    }

    int ans = 0;
    int rightNumT = 0;
    for(int i = len - 1; i >= 0; i--){
        if(str[i] == 'T'){
            rightNumT++;
        }else if(str[i] == 'A'){
            ans = (ans + leftNumP[i] * rightNumT) % mod;
        }
    }
    cout <<ans;
    return 0;
}
