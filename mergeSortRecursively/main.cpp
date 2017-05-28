#include <iostream>

using namespace std;

const int maxn = 100;

//将数组A的[L1,R1]与[L2,R2]区间合并为有序区间（此处L2即为L1 + 1
void merge(int A[],int L1,int R1,int L2,int R2)
{
    int i = L1,j = L2;//i指向A[L1]，j指向A[L2]
    int temp[maxn],index = 0;//temp临时存放合并后的数组，index为其下标
    while(i <= R1 && j <= R2) {
        if(A[i] <= A[j]) {
            temp[index++] = A[i++];//将A[i]加入temp序列
        } else {
            temp[index++] = A[j++];//将A[j]加入temp序列
        }
    }

    while(i <= R1)
    {
        temp[index++] = A[i++];
    }
    while(j <= R2)
    {
        temp[index++] = A[j++];
    }
    for(i = 0; i < index; i++) {
        A[L1 + i] = temp[i];//将合并后的序列赋值回给数组A
    }
}

void mergeSort(int A[], int left, int right) {
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(A,left,mid);
        mergeSort(A,mid + 1,right);
        merge(A, left, mid, mid + 1, right);
    }
}
int main()
{
    int a[] = {3,2,1};
    mergeSort(a,0,2);

    for(int i = 0; i < 3; i++)
    {
        printf("%d",a[i]);
    }

    return 0;
}
