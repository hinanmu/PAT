#include <iostream>

using namespace std;

const int maxn = 100;

//������A��[L1,R1]��[L2,R2]����ϲ�Ϊ�������䣨�˴�L2��ΪL1 + 1
void merge(int A[],int L1,int R1,int L2,int R2)
{
    int i = L1,j = L2;//iָ��A[L1]��jָ��A[L2]
    int temp[maxn],index = 0;//temp��ʱ��źϲ�������飬indexΪ���±�
    while(i <= R1 && j <= R2) {
        if(A[i] <= A[j]) {
            temp[index++] = A[i++];//��A[i]����temp����
        } else {
            temp[index++] = A[j++];//��A[j]����temp����
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
        A[L1 + i] = temp[i];//���ϲ�������и�ֵ�ظ�����A
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
