#include<iostream>
#include<algorithm>
using namespace std;

void heapify(int a[],int n,int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l <= n && a[l] > a[largest])
        largest = l;
    if( r<= n && a[r] > a[largest])
        largest = r;
    if( largest!= i){
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }
}
void heapsort(int a[], int n){
    for(int i = n/2-1; i>=0; i--)
        heapify(a,n,i);
    for(int i = n; i >= 0; i--){
        swap(a[i],a[0]);
        heapify(a,i-1,0);
    }
}
int main(){
    int a[] = {7,4,5,6,2,3,1};
    heapsort(a,6);
    for(int i = 0; i < 7; i++)
    cout<<a[i]<<" ";
    return 0;
}