#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    long long p,r,cp,maxp,q;
    maxp = 0;
    int k;
    for(int i = 999; i > 99; i--)
    {
        for(int j = 999; j > 99; j--){
            p = i*j;
            cp = p;
            r = 0;
            k = 0;
            while(cp!=0){
                q = cp % 10;
                r = r * 10 + q;
                k++;
                cp /= 10;
            }
            if(r == p){
                if(p > maxp)
                    maxp = p;
            }
        }
    }
    cout<<maxp;
    return 0;
}
