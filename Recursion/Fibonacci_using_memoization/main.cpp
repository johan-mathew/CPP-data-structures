#include <iostream>
#include <vector>
using namespace std;
int fibo(int n)
{
	static vector<int> F(10,-1);  //10 spaces each element set as -1
	if(n<=1)
	{
		F.at(n)=n;
		return n;
	}
	else
	{
		if(F.at(n-1)==-1)
			F.at(n-1)=fibo(n-1);
		if(F.at(n-2)==-1)
			F.at(n-2)=fibo(n-2);
		F.at(n)=F.at(n-1)+F.at(n-2);
		return F.at(n);	
	}
	
	
}

int main(int argc, char **argv)
{
	cout<<fibo(5);
	return 0;
}
