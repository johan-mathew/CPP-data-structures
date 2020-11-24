#include <iostream>
#include<algorithm>
using namespace std;

int t[100][100] ;

int knapsack(int wgt[], int val[], int n, int w){
    if( n == 0 || w == 0 )
        return 0;
    if(t[n][w]!=-1)
        return t[n][w];
    if( wgt[n-1] <= w){
        t[n][w] = max( (val[n-1] + knapsack(wgt,val,n-1, w - wgt[n-1])) , knapsack(wgt,val,n-1,w));
        return t[n][w];
    }
    else{
        t[n][w] = knapsack(wgt,val,n-1,w);
        return t[n][w];
    }
}
int bottom_up(int wgt[], int val[], int n ,int w){
    for(int i = 0; i < n+1; i++)
    for(int j = 0; j < w+1; j++){
        if(i == 0 || j == 0)
            t[i][j] = 0;
        else if ( wgt[i-1] <= j )
            t[i][j] = max ( val[i-1] + t[i-1][j - wgt[i-1]],
                                t[i-1][j]
                           );
        else
            t[i][j] = t[i-1][j];
    }
    return t[n][w];

}

int main()
{
    int wgt[] = {1,3,4,5};
    int val[] = {1,4,5,7};
    int n (4);
    int w {7};
    for(int i = 0; i < n+1; i++)
        for(int j = 0; j < w+1; j++)
            t[i][j] = -1;
    //cout<< knapsack(wgt,val,n,w)<<endl;
    cout<< bottom_up(wgt,val,n,w);
    return 0;
}
