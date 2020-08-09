#include <iostream>
using namespace	std;
int pow(int m,int n)
{
	if(n==0)
		return 1;
	if(n%2==0)
		return pow(m*m,n/2);
	if(n%2==1)
		return pow(m*m,(n-1)/2)*m;
}
int main(int argc, char **argv)
{
	cout<<pow(2,4);
	return 0;
}
