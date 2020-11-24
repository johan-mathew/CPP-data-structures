#include <iostream>
using namespace std;

enum table { True,False,Null }; 

table t[100][100];
bool tm[100][100];
table subsetTarget(int arr[], int target, int n){
    if( t[n][target] != Null)
        return t[n][target];
    if(target == 0)
        return True;
    if( n == 0 )
        return False;    
    if( t[n][target] == Null )
      {     
        if(arr[n-1] <= target)
            t[n][target] =  (subsetTarget(arr,target - arr[n-1],n-1) == True) || (subsetTarget(arr,target,n-1) == True) ? True:False;
        else
            t[n][target] =  subsetTarget(arr,target,n-1);
      }         
    return t[n][target];
}
bool subsetTargetMemo(int arr[], int target, int n){
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= target; j++){
                if( i == 0)
                    tm[i][j] = false;
                if( j == 0)
                    tm[i][j] = true;
                if( i!= 0 && j!=0) 
                   {
                    if( arr[i-1] <= j )
                        tm[i][j] = tm[i-1][j-arr[i-1]] || tm[i-1][j];
                    else
                        tm[i][j] = tm[i-1][j];
                   } 
        }
    }
    return t[n][target];
}
int main(){

    int arr[] = { 1,2,5,3,7 };
    int target = 18;
    int size = 5;
    for(int i = 0; i <= size; i++){
        for(int j = 0; j <= target; j++){
                t[i][j] = Null;
        }
    }
        if(subsetTarget(arr,target,size) == True)
            cout<<"Present";
        else
            cout<<"Not Present";
        cout<<endl;
        if(subsetTargetMemo(arr,target,size))
            cout<<"Present";
        else
            cout<<"Not Present";
        cout<<endl;    
    return 0;
}