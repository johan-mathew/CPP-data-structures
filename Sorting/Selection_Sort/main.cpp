#include <iostream>
using namespace std;

int main()
{
    int a[] = {4,6,1,3,8};
    int n = 5;
    int min,i,j,temp;
    for(i =0; i<n-1;i++){
        min = i;
        for(j = i+1; j<n;j++){
            if(a[j]<a[min])
                min = j;
        }
        if(min!=i){
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }


    for( int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
