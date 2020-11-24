#include <iostream>
using namespace std;

int main()
{
    int a[]={4,1,7,2,4,9};
    int n = 6;
    int temp,j;
    for(int i = 1; i<n; i++){
        temp = a[i];
        j = i-1;
        while(j>=0 && a[j]>temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
    for( int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
