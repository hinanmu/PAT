#include <iostream>

using namespace std;

void megeSort(int A[]) {
    for(int step = 2; step / 2 <= n;step *= 2)
    {
        for(int i = 1; i <= n; i += step) {
            int mid = i + step / 2 - 1;
            if(mid + 1 <= n) {
                merge(A, i, mid,mid + 1, min(i + step - 1, n));
            }
        }
    }
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
