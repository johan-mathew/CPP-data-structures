#include <iostream>
using namespace std;
int main()
{
    int a[] = {4,6,1,3,8};
    int n = 5;
    int flag,temp;
    for(int i = 0; i< n-1; i++){
        flag = 0;
        for(int j = 0; j < n-i-1; j++){
            if(a[j]>a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        if(!flag)
            break;
    }
    for(int i = 0; i<5; i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
