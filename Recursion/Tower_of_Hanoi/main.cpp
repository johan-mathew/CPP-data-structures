#include <iostream>
using namespace std;
void move(int n, int A, int B, int C)
{
	if(n>0)
	{
		move(n-1,A,C,B);
		cout<<"From "<<A<<" to "<<C<<endl;
		move(n-1,B,A,C);
	}
}

int main(int argc, char **argv)
{
	move(3,1,2,3);
	return 0;
}
