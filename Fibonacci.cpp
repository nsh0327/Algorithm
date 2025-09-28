#include<iostream>

using std::cout;
using std::endl;

int fibo(int n)
{
	if (n <= 1)
	{
		return n;
	}
	int x = 0;
	int y = 1;
	int z = 0;


	for (int i = 2; i <= n; ++i)
	{
		z = x + y;
		x = y;
		y = z;
	}
	return z;
}

int fibo_re(int n)
{
	if (n <= 1)
	{
		return n;
	}
	else
		return fibo_re(n - 1) + fibo_re(n - 2);
}


int main()
{

	int a = 11;
	fibo_re(a);
	for (int i = 0; i < a; i++)
	{
		cout << fibo_re(i) << endl;
	}

	cout << "------------------------" << endl;

	int b = 11;
	fibo(b);
	for (int i = 0; i < b; ++i)
	{
		cout << fibo(i) << endl;
	}




}