#include <iostream>
using namespace std;

int rsum(int n)
{
	if(n==0)
		return	0;
	else
		return rsum(n-1)+n;
}
int main(int argc, char **argv)
{
	cout<<rsum(2);
	return 0;
}
