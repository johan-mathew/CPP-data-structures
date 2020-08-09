#include <iostream>
using namespace std;
int nCr(int n, int r)
{
	if(r==n||r==0)
		return 1;		//extremes of a pascal tree are 1
	else
		return nCr(n-1,r-1)+nCr(n-1,r);
}

int main(int argc, char **argv)
{
	cout<<nCr(4,3);
	return 0;
}
