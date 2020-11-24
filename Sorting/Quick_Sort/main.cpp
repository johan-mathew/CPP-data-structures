#include <iostream>
using namespace std;

int partitionqs(int a[], int lb, int ub){
    int pivot = a[lb];
    int start = lb;
    int endqs = ub;
    int temp;
    while(start < endqs){
        while(a[start] <= pivot)
            start++;
        while(a[endqs] > pivot)
            endqs--;
        if(start < endqs){
            temp = a[start];
            a[start] = a[endqs];
            a[endqs] = temp;
        }
    }
    temp = a[lb];
    a[lb] = a[endqs];
    a[endqs] = temp;
    return endqs;

}
void quicksort(int a[], int lb, int ub){
    int loc;
    if(lb<ub){
            loc = partitionqs(a,lb,ub);
            quicksort(a,lb,loc-1);
            quicksort(a,loc+1,ub);
    }
}
int main()
{
    int a[] = { 1,5,2,8,5,6,3,1,9,4};
    int n = 10;
    quicksort(a,0,n-1);
    for(int i = 0; i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
