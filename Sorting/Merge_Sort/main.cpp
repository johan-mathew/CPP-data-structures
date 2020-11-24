#include<iostream>
using namespace std;
void merge(int [],int,int,int);
void mergesort(int a[], int beg, int end){
    if(beg < end){
        int mid = (beg + end)/2;
        mergesort(a,beg,mid);
        mergesort(a,mid+1,end);
        merge(a,beg,mid,end);
    }
}
void merge(int a[], int beg, int mid, int end){
    int i,j,k;
    i = beg;
    j = mid+1;
    k = 0;
    int *b = new int[end-beg+1];
    while(i <= mid && j <= end)
        b[k++] = a[i] < a[j] ? a[i++] : a[j++];
    while(i <= mid)
        b[k++] = a[i++];
    while(j <= end)
        b[k++] = a[j++];
    for(i = beg,k = 0; i <= end;i++,k++)
     a[i] = b[k];
}
int main(){
    int a[] = {4,5,7,2,1,3,6};
    mergesort(a,0,6);
    for(int i = 0; i < 7; i++)
       cout<<a[i]<<" ";
    return 0;
}