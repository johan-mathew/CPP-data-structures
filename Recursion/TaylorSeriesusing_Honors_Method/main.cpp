#include <iostream>
using namespace std;

double Taylor(int x, int n)
{
	static double s=1,r;
	if(n!=0)
	{
		s=1+(x*s/n);
		r=Taylor(x,n-1);
	}
	return s;
}

int main(int argc, char **argv)
{
	cout<<Taylor(1,10);
	return 0;
}
